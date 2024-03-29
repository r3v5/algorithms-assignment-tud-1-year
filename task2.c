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
void generate_report(struct QaLog qa_logs[], int size_of_logs ,int product_id, int line_code);
void display_qa_logs(struct QaLog qa_logs[], int size_of_logs);


int main()
{
    // Sample QA logs
    struct QaLog qa_logs[] = {
        // QA Logs for line 1
        {1, 1001, {10, 20, 28, 3, 2023}, 1, {1, "Some issue"}, {1, "Some resolution"}, 2142},
        {1, 1001, {8, 45, 28, 3, 2023}, 2, {1, "Some issue"}, {1, "Some resolution"}, 1342},
        {1, 1002, {2, 5, 28, 3, 2023}, 3, {1, "Some issue"}, {1, "Some resolution"}, 1524},

        {1, 1003, {4, 0, 29, 3, 2023}, 4, {1, "Some issue"}, {1, "Some resolution"}, 9884},
        {1, 1004, {6, 45, 29, 3, 2023}, 5, {1, "Some issue"}, {1, "Some resolution"}, 2423},
        {1, 1005, {17, 5, 29, 3, 2023}, 6, {1, "Some issue"}, {1, "Some resolution"}, 8941},

        {1, 1006, {11, 33, 30, 3, 2024}, 7, {1, "Some issue"}, {1, "Some resolution"}, 2412},
        {1, 1007, {13, 45, 30, 3, 2024}, 8, {1, "Some issue"}, {1, "Some resolution"}, 9724},
        {1, 1008, {14, 5, 30, 3, 2024}, 9, {1, "Some issue"}, {1, "Some resolution"}, 6427},

        {1, 1001, {9, 23, 31, 3, 2024}, 1, {2, "Some issue"}, {1, "Some resolution"}, 2141},
        {1, 1004, {11, 45, 31, 3, 2024}, 5, {1, "Some issue"}, {1, "Some resolution"}, 7489},
        {1, 1008, {22, 5, 31, 3, 2024}, 6, {1, "Some issue"}, {1, "Some resolution"}, 9884},

        {1, 1003, {7, 20, 1, 4, 2024}, 4, {1, "Some issue"}, {1, "Some resolution"}, 2141},
        {1, 1002, {11, 35, 1, 4, 2024}, 3, {1, "Some issue"}, {1, "Some resolution"}, 7489},
        {1, 1001, {19, 5, 1, 4, 2024}, 1, {3, "Some issue"}, {1, "Some resolution"}, 9884},


        // QA Logs for line 2
        {2, 1001, {10, 20, 28, 5, 2023}, 1, {1, "Some issue"}, {1, "Some resolution"}, 2142},
        {2, 1001, {8, 45, 28, 5, 2023}, 2, {1, "Some issue"}, {1, "Some resolution"}, 1342},
        {2, 1002, {2, 5, 28, 5, 2023}, 3, {1, "Some issue"}, {1, "Some resolution"}, 1524},

        {2, 1003, {4, 0, 29, 5, 2023}, 4, {1, "Some issue"}, {1, "Some resolution"}, 9884},
        {2, 1004, {6, 45, 29, 5, 2023}, 5, {1, "Some issue"}, {1, "Some resolution"}, 2423},
        {2, 1005, {17, 5, 29, 5, 2023}, 6, {1, "Some issue"}, {1, "Some resolution"}, 8941},

        {2, 1006, {11, 33, 30, 5, 2024}, 7, {1, "Some issue"}, {1, "Some resolution"}, 2412},
        {2, 1007, {13, 45, 30, 5, 2024}, 8, {1, "Some issue"}, {1, "Some resolution"}, 9724},
        {2, 1008, {14, 5, 30, 5, 2024}, 9, {1, "Some issue"}, {1, "Some resolution"}, 6427},

        {2, 1001, {9, 23, 31, 5, 2024}, 1, {1, "Some issue"}, {1, "Some resolution"}, 2141},
        {2, 1004, {11, 45, 31, 5, 2024}, 5, {1, "Some issue"}, {1, "Some resolution"}, 7489},
        {2, 1008, {22, 5, 31, 5, 2024}, 6, {1, "Some issue"}, {1, "Some resolution"}, 9884},

        {2, 1003, {7, 20, 1, 6, 2024}, 4, {1, "Some issue"}, {1, "Some resolution"}, 2141},
        {2, 1002, {11, 35, 1, 6, 2024}, 3, {1, "Some issue"}, {1, "Some resolution"}, 7489},
        {2, 1001, {19, 5, 1, 6, 2024}, 1, {1, "Some issue"}, {1, "Some resolution"}, 9884},
    };
    int size_of_logs = sizeof(qa_logs) / sizeof(qa_logs[0]);
    int product_id;
    int line_code;
    
    // Display QA logs
    display_qa_logs(qa_logs, size_of_logs);

    // Enter the product id and line code
    printf("Enter the Product ID from 1 to 9:\n");
    scanf("%d", &product_id);
    printf("Enter the Line Code from 1 to 2:\n");
    scanf("%d", &line_code);

    generate_report(qa_logs, size_of_logs, product_id, line_code);

    return 0;
}


void generate_report(struct QaLog qa_logs[], int size_of_logs, int product_id, int line_code)
{
    int issue_codes[MAX_ISSUES];
    int issue_count = 0;

    // Aggregate and collect all issue codes for the specified product and line
    for (int i = 0; i < size_of_logs; i++) {
        if (qa_logs[i].line_code == line_code && qa_logs[i].product_id == product_id) {
            int issue_code = qa_logs[i].issue.issue_code;

            // Check if the issue code is already present in the array
            int found = 0;
            for (int j = 0; j < issue_count; j++) {
                if (issue_codes[j] == issue_code) {
                    found = 1;
                    break;
                }
            }

            // If the issue code is not found, add it to the array
            if (!found) {
                issue_codes[issue_count++] = issue_code;
                if (issue_count == MAX_ISSUES) {
                    fprintf(stderr, "Maximum number of issues reached for product %d on line %d.\n", product_id, line_code);
                    break;
                }
            }
        }
    }

    // Display all issue codes for the specified product and line
    printf("All issue codes for Product ID %d on Line Code %d:", product_id, line_code);
    for (int i = 0; i < issue_count; i++) {
        printf(" %d", issue_codes[i]);
    }
    printf("\n");
}

void display_qa_logs(struct QaLog *qa_logs, int size_of_logs)
{
    printf("Line Code | Batch Code | Date & Time | Product ID | Issue Code | Issue Description | Resolution Code | Resolution Description | Reporting Employee ID\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < size_of_logs; i++) {
        printf("%9d | %10d | %02d/%02d/%04d %02d:%02d | %10d | %10d | %-20s | %15d | %-20s | %20d\n",
               qa_logs[i].line_code, qa_logs[i].batch_code,
               qa_logs[i].date_time.day, qa_logs[i].date_time.month, qa_logs[i].date_time.year,
               qa_logs[i].date_time.hour, qa_logs[i].date_time.minute,
               qa_logs[i].product_id,
               qa_logs[i].issue.issue_code, qa_logs[i].issue.description,
               qa_logs[i].resolution.resolution_code, qa_logs[i].resolution.description,
               qa_logs[i].reporting_employee_id);
    }
}