/*
Program Description: This program does task 1 from Assignment 1

Author: Ian Miller

Date: 28/03/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30
#define MAX_ISSUES 100

// Structures
struct DateTime {
    int hour;
    int minute;
    int day;
    int month;
    int year;
};

struct Issue {
    int issue_code;
    char description[SIZE];
};

struct Resolution {
    int resolution_code;
    char description[SIZE];
};


struct QaLog {
    int line_code;
    int batch_code;
    struct DateTime date_time;
    int product_id;
    struct Issue issue;
    struct Resolution resolution;
    int reporting_employee_id;
};

// Prototypes
int compare_logs(const void *qa_log1, const void *qa_log2);
void generate_report(struct QaLog qa_logs[], int size_of_logs, int product_id);

int main()
{
    // Sample QA logs
    struct QaLog qa_logs[] = {
        // QA Logs for line 1
        {1, 1001, {10, 20, 28, 3, 2023}, 1, {1, "Some issue"}, {1, "Some resolution"}, 2142},
        {1, 1001, {8, 45, 28, 3, 2023}, 2, {1, "Some isue"}, {1, "Some resolution"}, 1342},
        {1, 1002, {2, 5, 28, 3, 2023}, 3, {1, "Some issue"}, {1, "Some resolution"}, 1524},

        {1, 1003, {4, 0, 29, 3, 2023}, 4, {1, "Some issue"}, {1, "Some resolution"}, 9884},
        {1, 1004, {6, 45, 29, 3, 2023}, 5, {1, "Some isue"}, {1, "Some resolution"}, 2423},
        {1, 1005, {17, 5, 29, 3, 2023}, 6, {1, "Some issue"}, {1, "Some resolution"}, 8941},

        {1, 1006, {11, 33, 30, 3, 2024}, 7, {1, "Some issue"}, {1, "Some resolution"}, 2412},
        {1, 1007, {13, 45, 30, 3, 2024}, 8, {1, "Some isue"}, {1, "Some resolution"}, 9724},
        {1, 1008, {14, 5, 30, 3, 2024}, 9, {1, "Some issue"}, {1, "Some resolution"}, 6427},

        {1, 1001, {9, 23, 31, 3, 2024}, 1, {2, "Some issue"}, {1, "Some resolution"}, 2141},
        {1, 1004, {11, 45, 31, 3, 2024}, 5, {1, "Some isue"}, {1, "Some resolution"}, 7489},
        {1, 1008, {22, 5, 31, 3, 2024}, 6, {1, "Some issue"}, {1, "Some resolution"}, 9884},

        {1, 1003, {7, 20, 1, 4, 2024}, 4, {1, "Some issue"}, {1, "Some resolution"}, 2141},
        {1, 1002, {11, 35, 1, 4, 2024}, 3, {1, "Some isue"}, {1, "Some resolution"}, 7489},
        {1, 1001, {19, 5, 1, 4, 2024}, 1, {3, "Some issue"}, {1, "Some resolution"}, 9884},


        // QA Logs for line 2
        {2, 1001, {10, 20, 28, 5, 2023}, 1, {1, "Some issue"}, {1, "Some resolution"}, 2142},
        {2, 1001, {8, 45, 28, 5, 2023}, 2, {1, "Some isue"}, {1, "Some resolution"}, 1342},
        {2, 1002, {2, 5, 28, 5, 2023}, 3, {1, "Some issue"}, {1, "Some resolution"}, 1524},

        {2, 1003, {4, 0, 29, 5, 2023}, 4, {1, "Some issue"}, {1, "Some resolution"}, 9884},
        {2, 1004, {6, 45, 29, 5, 2023}, 5, {1, "Some isue"}, {1, "Some resolution"}, 2423},
        {2, 1005, {17, 5, 29, 5, 2023}, 6, {1, "Some issue"}, {1, "Some resolution"}, 8941},

        {2, 1006, {11, 33, 30, 5, 2024}, 7, {1, "Some issue"}, {1, "Some resolution"}, 2412},
        {2, 1007, {13, 45, 30, 5, 2024}, 8, {1, "Some isue"}, {1, "Some resolution"}, 9724},
        {2, 1008, {14, 5, 30, 5, 2024}, 9, {1, "Some issue"}, {1, "Some resolution"}, 6427},

        {2, 1001, {9, 23, 31, 5, 2024}, 1, {1, "Some issue"}, {1, "Some resolution"}, 2141},
        {2, 1004, {11, 45, 31, 5, 2024}, 5, {1, "Some isue"}, {1, "Some resolution"}, 7489},
        {2, 1008, {22, 5, 31, 5, 2024}, 6, {1, "Some issue"}, {1, "Some resolution"}, 9884},

        {2, 1003, {7, 20, 1, 6, 2024}, 4, {1, "Some issue"}, {1, "Some resolution"}, 2141},
        {2, 1002, {11, 35, 1, 6, 2024}, 3, {1, "Some isue"}, {1, "Some resolution"}, 7489},
        {2, 1001, {19, 5, 1, 6, 2024}, 1, {1, "Some issue"}, {1, "Some resolution"}, 9884},
    };

    int size_of_logs = sizeof(qa_logs) / sizeof(qa_logs[0]);
    int product_id = 6;
    generate_report(qa_logs, size_of_logs, product_id);

    return 0;
}


int compare_logs(const void *qa_log1, const void *qa_log2) {
    const struct QaLog *log1 = (const struct QaLog *)qa_log1;
    const struct QaLog *log2 = (const struct QaLog *)qa_log2;

    if (log1->product_id != log2->product_id) {
        return log1->product_id - log2->product_id;
    } else if (log1->issue.issue_code != log2->issue.issue_code) {
        return log1->issue.issue_code - log2->issue.issue_code;
    } else if (log1->date_time.year != log2->date_time.year) {
        return log1->date_time.year - log2->date_time.year;
    } else if (log1->date_time.month != log2->date_time.month) {
        return log1->date_time.month - log2->date_time.month;
    } else if (log1->date_time.day != log2->date_time.day) {
        return log1->date_time.day - log2->date_time.day;
    } else if (log1->date_time.hour != log2->date_time.hour) {
        return log1->date_time.hour - log2->date_time.hour;
    } else if (log1->date_time.minute != log2->date_time.minute) {
        return log1->date_time.minute - log2->date_time.minute;
    } else {
        return 0;
    }
}


void generate_report(struct QaLog qa_logs[], int size_of_logs, int product_id)
{
    int issue_count = 0;
    for (int i = 0; i < size_of_logs; i++)
    {
        if (qa_logs[i].product_id == product_id)
        {
            issue_count++;
        }
    }
    printf("Report\n");
    printf("Issues count: %d\n", issue_count);
}