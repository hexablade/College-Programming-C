#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INPUTSIZE 512

typedef struct Syntax
{
    char line[INPUTSIZE];
    int size;
    int indices[INPUTSIZE];

} Stack;

//Function Prototypes
void empty(void);
bool is_empty(void);
char peek();
bool is_full(Stack *stack);
char pop(void);
void exit_stack_overflow(void);
void exit_stack_underflow(void);
void exit_incorrect_nesting(void);
void push (char ch, int i, Stack *stack);

int main()
{
      
    printf("Enter parentheses and/or braces: ");
   
    Stack stack;
    int i;
    char ch;

    fgets(stack.line, INPUTSIZE, stdin);   

    for( i = 0; i != '\n'; i++) {
       while (1){
            

       }        
    } 

}

bool is_full(Stack *stack)
{
    return  stack->size == INPUTSIZE;  

}
void push(char ch, int i, Stack *stack)
{
    if (is_full(stack))
        exit_stack_overflow();
    stack->line[i] = ch;
    stack->size = i;
    stack->indices[i] = i; 
            
                
}
void exit_stack_underflow(void)
{
        fprintf(stderr, "Stack Underflow\n");
            exit(EXIT_FAILURE);
}
void exit_stack_overflow(void)
{
        fprintf(stderr, "Stack Overflow\n");
            exit(EXIT_FAILURE);
}

