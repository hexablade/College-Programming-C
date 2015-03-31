/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* qsort.c (Chapter 9, page 207) */
/* Sorts an array of integers using Quicksort algorithm */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "quicksort.h"

#define RANGE 1024

void print_array(int a[], int n);
void fill_array(int *a, int n);

int main(int argc, char *argv[])
{
  if (argc < 2) {
    fprintf(stderr, "Enter an integer array size.\n");
    return 1;
  }

  int size = atoi(argv[1]);

  int a[size];

  fill_array(a, size);

  print_array(a, size);
  quicksort(a, a + (size-1));
  printf("\n");
  print_array(a, size);

  return 0;
}

void print_array(int a[], int n)
{
  int i;
  for (i = 0; i < n; i++)  {
    /*print the newline first, otherwise the first row is an odd length*/
    if (i > 0 && i % 12 == 0)
      printf("\n");
    printf("%d\t", a[i]);
    }

  printf("\n");
}
void fill_array(int *a, int n)
{
  /*
   * Populate a test array with
   * a random series of integers
   */
  srand((unsigned) time(NULL));
  for (int i = 0; i < n; i++)  {
    a[i] = rand() % RANGE;
  }

}
