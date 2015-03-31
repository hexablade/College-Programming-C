#include <stdio.h>
#include <stdbool.h>

struct x
{
    int a;
}x;
int main()
{
    if(((&x) -> a)==(x.a)){
        printf("true\n");
    }
    else 
        printf("false\n");
}
