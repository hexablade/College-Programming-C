#include <stdio.h>
#include <ctype.h>
#define SIZE 80

int read_line(char s[], int n);
void print_header(char *header);

int main(void)
{
  char str[SIZE + 1];
  int len;
  printf("Enter a string:\n");
  print_header("+---------");

  len = read_line(str, SIZE);
  printf("Your %d character string, Sir:\n%s\n", len, str);

  print_header("0123456789");

  return 0;
}

/* Reads an entire line, but only stores up to n characters */
int read_line(char s[], int n)
{
  int ch, i;

  /* ignore leading whitespace */
  while (isspace(ch = getchar()));

  /* the first non-whitespace character */
  s[0] = ch;

  i = 1;
  while ((ch = getchar()) != '\n')
    if (i < n) {
      s[i] = ch;
      i += 1;
    }

  /* store the newline if there's room */
  if (i < n) {
    s[i] = ch;
    i += 1;
  }

  /* terminate the string */
  s[i] = '\0';

  return i;
}
void print_header(char *header)
{
  for (int i = 0; i < SIZE / 10; i++) printf(header);
  puts("");
}
