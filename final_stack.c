#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXLEN 512


typedef struct {
    char element[MAXLEN];
    int size;
    int position;
} stack;

stack init (void)
{
    stack S;
    S.element[0] = 'c';
    S.size = 0;
    S.position = -1;
    
    return S;
}

bool is_empty(stack *S);
char peek(stack *S);
bool is_full(stack *S);
stack push(stack *S, char ch, int i);
char  pop (stack *S);
void exit_stack_overflow(void);
void exit_stack_underflow(void);
void exit_incorrect_nesting(stack *S, int i);


int main(void)
{
    
    char ch;
    stack S;
    char buf[MAXLEN];
    int i = 0;
    S = init();
    int length = sizeof(buf)/sizeof(buf[0]);
    printf("Enter parentheses and/or braces: ");
    
    
    fgets(buf, length, stdin); //reads an entire line into stack, no more chars than length
    while (1) {
        if(buf[i] == '\n'){
            break;
        }
        
        
        
        
        ch = buf[i];
        i++;
        
        
        if(ch == '"'){
            push(&S, ch, i);
            if(peek(&S) != '\''){
                
                if (peek(&S) == '"') {
                    pop(&S);
                    
                }
                else{
                    push(&S, ch, i);
                    
                    
                }
            }
            
            
        }
        else if(ch == '\''){
            if(peek(&S) != '"'){
                if (peek(&S) == '\'') {
                    pop(&S);
                }
                else
                    push(&S, ch, i);
            }
        }
        else if(peek(&S) != '\'' && peek(&S) != '"') {
            switch(ch) {
                case '(':
                    push(&S, ch, i);
                case '{':
                    if(peek(&S) == '('){
                        exit_incorrect_nesting(&S, i);
                    }
                    else 
                    push(&S, ch, i);
                    
                    break;
                case ')':
                    
                    if (is_empty(&S) || pop(&S) != '(')
                        exit_incorrect_nesting(&S, i);
                    break;
                    
                case '}' :
                    
                    if (is_empty(&S) || pop(&S) != '{'){
                        
                        exit_incorrect_nesting(&S, i);
                        
                    }
                   
                    break;
            }
        }
    }
    
    
    if (is_empty(&S))
        printf("Nesting is correct\n");
    else {
        
        exit_incorrect_nesting(&S, i);
        
    }
    
    return 0;
}


bool is_empty( stack  *S )
{
    return (S->size == 0);
}

bool is_full( stack * S )
{
    return (S->size == MAXLEN - 1);
}

char peek( stack *S )
{
    
    return S->element[S->size];
}

stack push( stack *S , char ch, int i )
{
    if (is_full(S)) {
        fprintf(stderr, "push: Full stack\n");
        return *S;
    }
    ++S->size;
    S->position = i;
    S->element[S->size] = ch;
    return *S;
}

char pop( stack * S )
{
    int i = S->size;
    if(is_empty(S)) {
        fprintf(stderr, "pop: Empty stack\n");
        return S->element[i];
    }
    --S->size;
    return S->element[i];
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

void exit_incorrect_nesting(stack *S, int i)
{
    printf("Nesting is NOT correct and the location of the error is character # %d \n", i);
    exit(EXIT_SUCCESS);
}
