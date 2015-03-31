#include <stdio.h>

void test_int(int expected, int actual);

void io0(void)
{
    int ch;
    while ((ch = getchar()) != EOF){
       putchar(ch);
    } 
}
void io1(void)
{
    char str[100];
    while(gets(str) != NULL){
        puts(str);
    }        
}

void io2(void)
{
    char str[100];
    while(scanf("%s",str) != EOF) {
        printf("%s ", str);
    }
     printf("\n");
 }
// returns the number of ch in the string str
int count_ch(const char *str, const char ch)
{
    int count = 0; 
    int i;
    for (i = 0; *str != '\0'; i++) {
        if(*str == ch) count ++;
    }
    return count;
}
void test(void)
{
    char *s = "hello i love you";
    test_int(3, count_ch(s, 'o'));
    test_int(0, count_ch(s, 'p'));
    test_int(0, count_ch(s, 'I'));
}

void test_int(int expected, int actual)
{
    if (expected == actual) {
        printf("Pass \n");
    }
      else {
          printf("Fail: expected = %d, actual = %d\n", expected, actual);
      }
} 
int main(int argc, char* argv[])
{
    char name[6] = "David";
    char *p = name;
    printf("name = %s\n", p);
    test();
}
