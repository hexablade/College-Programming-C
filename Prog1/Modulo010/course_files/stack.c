#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

char stack[STACK_SIZE];
int size = 1;

void empty(void);
bool is_empty(void);
char peek();
bool is_full(void);
void push(char ch);
char pop(void);
void exit_stack_overflow(void);
void exit_stack_underflow(void);
void exit_incorrect_nesting(void);

char peek(){
    if (is_empty()){
        return 'c';
    }
    else
        return stack[size-1];
}
void empty(void)
{
    size = 0;
}
bool is_empty(void)
{
    return size == 0;
}
bool is_full(void)
{
    return size == STACK_SIZE;
}
void push(char ch)
{
    if (is_full())
        exit_stack_overflow();
    stack[size++] = ch;
    
    printf("whats inside: %c",ch);
}
char pop(void)
{
    if (is_empty())
        exit_stack_underflow();
    return stack[--size];
}
void exit_stack_overflow(void)
{
    fprintf(stderr, "Stack Overflow\n");
    exit(EXIT_FAILURE);
}
void exit_stack_underflow(void)
{
    fprintf(stderr, "Stack Underflow\n");
    exit(EXIT_FAILURE);
}
void exit_incorrect_nesting(void)
{
    printf("Nesting is NOT correct\n");
    exit(EXIT_SUCCESS);
}
int main(void)
{
    char ch;
    
    printf("Enter parentheses and/or braces: ");
   

 //   fgets(stack, length, stdin); //reads an entire line into stack, no more chars than length

    while ((ch = getchar()))  {
        printf("0");
        if(ch == '"'){
            printf("1");
            if(peek() != '\''){
                printf("2");
                if (peek() == '"') {
                    pop();
                    printf("3");
                }
                else{
                    push(ch);
                    printf("4");
            
                       }
                       }
                       
        }
        else if(ch == '\''){
            if(peek() != '"'){
                if (peek() == '\'') {
                    pop();
                }
                else
                    push(ch);
            }
        }
        else {
            switch(ch) {
                case '(':
                case '{':
                    
                    push(ch);
                    
                    break;
                case ')':
                    
                    if (is_empty() || pop() != '(')
                        exit_incorrect_nesting();
                    break;
                    
                case '}' :
                    if (is_empty() || pop() != '{')
                        exit_incorrect_nesting();
                    break;
            }
        }
    }
    
    if (is_empty())
        printf("Nesting is correct\n");
    else
        exit_incorrect_nesting();
    
    return 0;
}
