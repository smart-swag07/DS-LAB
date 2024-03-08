#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a day in the calendar
struct Day {
    char* dayName;
    int date;
    char* activity;
};

// Function to create the calendar
struct Day* createCalendar() {
    struct Day* calendar = (struct Day*)malloc(7 * sizeof(struct Day));
    if (calendar == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 7; i++) {
        calendar[i].dayName = (char*)malloc(21 * sizeof(char)); // Assuming a maximum of 20 characters for day name plus '\0'
        if (calendar[i].dayName == NULL) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        calendar[i].activity = (char*)malloc(101 * sizeof(char)); // Assuming a maximum of 100 characters for activity description plus '\0'
        if (calendar[i].activity == NULL) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }
    return calendar;
}

// Function to read data from the keyboard
void readCalendarData(struct Day* calendar) {
    for (int i = 0; i < 7; i++) {
        printf("Enter the day name for Day %d: ", i + 1);
        scanf("%20s", calendar[i].dayName); // Limiting input to 20 characters to prevent buffer overflow
        printf("Enter the date for Day %d: ", i + 1);
        scanf("%d", &calendar[i].date);
        printf("Enter the activity for Day %d: ", i + 1);
        scanf(" %[^\n]", calendar[i].activity); // Reading input until newline
    }
}

// Function to display the calendar
void displayCalendar(struct Day* calendar) {
    printf("Weekly Activity Report:\n\n");
    for (int i = 0; i < 7; i++) {
        printf("Day %d: %s\n", i + 1, calendar[i].dayName);
        printf("Date: %d\n", calendar[i].date);
        printf("Activity: %s\n", calendar[i].activity);
        printf("\n");
    }
}

int main() {
    struct Day* calendar = createCalendar();
    readCalendarData(calendar);
    displayCalendar(calendar);
    // Free memory
    for (int i = 0; i < 7; i++) {
        free(calendar[i].dayName);
        free(calendar[i].activity);
    }
    free(calendar);
    return 0;
}
