#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 512

int top = 0;
char buf[STACK_SIZE];

char pop(void)
{
    if ( is_empty() )
        stack_underflow();
    else
        return buf[--top];

}

void push(char a)
{
    if( is_full() )
        stack_overfow();
    else
        buf[top++] = a;

}

void peek(char buf[top],int STACK_SIZE)
{
    return top == STACK_SIZE; 
}
int main(int argc, char* args[]) {

    char stk[STACK_SIZE];
    int length = sizeof(buf)/sizeof(buf[0]);
    int i = 0;
    int pass = 1;
    int stp =0;


    fgets(buf, length, stdin); //reads an entire line into buf, no more chars than length
    while(1){
        if(buf[i] == '\n') { //most likely, you did not put in exactly 512 characters, so there is empty space in your array that we don't want to loop through. The last relevant character will be a new line char.
            break;
        }
        
            if(buf[i] == '\n'){
              if(stp !=0){
                  printf("%i \n", stp);
                  pass = 0;
                  } 
        printf("Char: %c passed", buf[i]);
        i++;
    }
    
    return 0;
}
