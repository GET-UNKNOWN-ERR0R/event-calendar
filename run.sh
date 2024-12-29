#!/bin/bash

if [ ! -d "events" ]; then
  mkdir events
  echo "Events directory created."
fi

gcc main.c calendar.c -o event-calendar

if [ $? -eq 0 ]; then
  echo "Compilation successful."
 
  ./event-calendar
else
  echo "Compilation failed. Please check the code."
fi
