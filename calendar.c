#include "calendar.h"

// Function to display the calendar for a particular month
void display_calendar(int month, int year) {
    int days_in_month[] = {31, (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int start_day_of_week = (year + (year / 4) - (year / 100) + (year / 400) + (31 * month) / 12) % 7;
    
    printf("\n\n\t\t\tCalendar for %d-%d\n\n", month, year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    
    for (int i = 0; i < start_day_of_week; i++) {
        printf("    ");
    }
    
    for (int day = 1; day <= days_in_month[month - 1]; day++) {
        printf("%3d ", day);
        if ((start_day_of_week + day) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n\n");
}

// Function to add an event to a specific date
void add_event(int day, int month, int year, const char *event_desc) {
    FILE *file = fopen("events/events.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(file, "%d/%d/%d: %s\n", day, month, year, event_desc);
    fclose(file);
    printf("Event added successfully!\n");
}

// Function to view events for a specific month and year
void view_events(int month, int year) {
    FILE *file = fopen("events/events.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    char line[512];
    printf("\nEvents for %d-%d:\n", month, year);
    while (fgets(line, sizeof(line), file)) {
        int d, m, y;
        sscanf(line, "%d/%d/%d", &d, &m, &y);
        if (m == month && y == year) {
            printf("%s", line);
        }
    }
    fclose(file);
}

// Function to show events for a specific date
void show_date(int month, int year, int day) {
    FILE *file = fopen("events/events.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    char line[512];
    printf("\nEvents for %d/%d/%d:\n", day, month, year);
    while (fgets(line, sizeof(line), file)) {
        int d, m, y;
        sscanf(line, "%d/%d/%d", &d, &m, &y);
        if (d == day && m == month && y == year) {
            printf("%s", line);
        }
    }
    fclose(file);
}
