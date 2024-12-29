#include <stdio.h>
#include "calendar.h"

int main() {
    int choice, day, month, year;
    char event_desc[256];

    do {
        printf("\n1. Display Calendar\n");
        printf("2. Add Event\n");
        printf("3. View Events by Month\n");
        printf("4. View Events by Date\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter month and year (MM YYYY): ");
                scanf("%d %d", &month, &year);
                display_calendar(month, year);
                break;
                
            case 2:
                printf("Enter day, month, year and event description (DD MM YYYY): ");
                scanf("%d %d %d", &day, &month, &year);
                getchar(); 
                printf("Enter event description: ");
                fgets(event_desc, sizeof(event_desc), stdin);
                add_event(day, month, year, event_desc);
                break;
                
            case 3:
                printf("Enter month and year (MM YYYY): ");
                scanf("%d %d", &month, &year);
                view_events(month, year);
                break;
                
            case 4:
                printf("Enter day, month, year (DD MM YYYY): ");
                scanf("%d %d %d", &day, &month, &year);
                show_date(month, year, day);
                break;
                
            case 5:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}
