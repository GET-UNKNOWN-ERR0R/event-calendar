#ifndef CALENDAR_H
#define CALENDAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 100

// storing an event
typedef struct {
    int day;
    int month;
    int year;
    char event_description[256];
} event;

// Function declarations
void display_calendar(int month, int year);
void add_event(int day, int month, int year, const char *event_desc);
void view_events(int month, int year);
void show_date(int month, int year, int day);

#endif
