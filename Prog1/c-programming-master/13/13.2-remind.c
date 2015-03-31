/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* remind.c (Chapter 13, page 294) */
/* Prints a one-month reminder list */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */
#define DATE_LEN 12     /* mm/dd + ' ' + HH:MM + ' ' */
int read_line(char str[], int n);
bool is_leap_year(void);
int this_year(void);
bool is_date_valid(int mm, int dd);
bool is_time_valid(int hh, int min);

int main(void)
{
  char reminders[MAX_REMIND][MSG_LEN+DATE_LEN];
  char date_str[DATE_LEN], msg_str[MSG_LEN+1];
  int hour, min, mm, dd, i, j, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      fprintf(stderr, "-- No space left --\n");
      break;
    }

    mm = dd = hour = min = -1;
    printf("Enter mm/dd and reminder: ");
    scanf("%2d", &mm);
    if (mm == 0)
      break;
    scanf("/%2d", &dd);

    scanf("%2d:%2d", &hour, &min);

    read_line(msg_str, MSG_LEN);

    if (!is_date_valid(mm, dd)) {
      fprintf(stderr, "Date %d/%d invalid for %d\n", mm, dd, this_year());
      continue;
    }

    if (!is_time_valid(hour, min))  {
      fprintf(stderr, "Time %d:%d invalid\n", hour, min);
      continue;
    }
    sprintf(date_str, "%.2d/%.2d %.2d:%.2d", mm, dd, hour, min);

    for (i = 0; i < num_remind; i++)
      if (strcmp(date_str, reminders[i]) < 0)
        break;
    for (j = num_remind; j > i; j--)
      strcpy(reminders[j], reminders[j-1]);

    strcpy(reminders[i], date_str);
    strcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\nDate  Time  Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf("%s\n", reminders[i]);

  return 0;
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
int this_year(void)
{
  static int year = 0;
  if (!year) {
    time_t t;
    time(&t);
    year = localtime(&t)->tm_year + 1900;
  }
  return year;
}
bool is_leap_year(void)
{
  int yyyy = this_year();
  return ((yyyy % 4 == 0 && yyyy % 100 != 0) || yyyy % 400 == 0);
}
bool is_date_valid(int mm, int dd)
{
  static int eom[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (!eom[2]) {
    eom[2] = 28;
    if (is_leap_year())
      eom[2] = 29;
  }

  if (mm > 0 && mm < 13)
    if (dd > 0 && dd <= eom[mm])
      return true;

  return false;
}
bool is_time_valid(int hh, int min)
{
  if (hh < 0 || hh > 23)
    return false;
  if (min < 0 || min > 59)
    return false;

  return true;
}
