/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* inventory.c (Chapter 16, page 391) */
/* Maintains a parts database (array version) */
#include "inventory-view.h"

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(int argc, char *argv[])
{
  Parts db;
  char code;
  if (argc > 2)
    invocation_error(argv[0], "<file>");

  db = init_db((argc == 2 ? argv[1] : ""));
  init_locale();

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'e': erase(db);
                break;
      case 'i': insert(db);
                break;
      case 'l': db = load_db(db);
                break;
      case 'p': print(db);
                break;
      case 'q': destroy_db(db);
                return 0;
      case 's': search(db);
                break;
      case 'u': update(db);
                break;
      case 'w': save_db(db);
                break;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}
