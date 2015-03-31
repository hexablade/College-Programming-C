#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXLEN 512


typedef struct {
    char element[MAXLEN];
    int size;
    int trac;
} stack;

stack init (void)
{
    stack S;
    S.element[0] = 'c';
    S.size = 0;
    S.trac = 0;
    return S;
}

bool is_empty(stack *S);
char peek(stack *S);
bool is_full(stack *S);
stack push(stack *S, char ch);
char  pop (stack *S);
void exit_stack_overflow(void);
void exit_stack_underflow(void);
void exit_incorrect_nesting(stack *S);

int track(stack *S, int t);


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
        track(&S, i);
        i++;
        
        
        if(ch == '"'){
            push(&S, ch);
            if(peek(&S) != '\''){
                
                if (peek(&S) == '"') {
                    pop(&S);
                    
                }
                else{
                    push(&S, ch);
                                      
                    
                }
            }
            
            
        }
        else if(ch == '\''){
            if(peek(&S) != '"'){
                if (peek(&S) == '\'') {
                    pop(&S);
                }
                else
                    push(&S, ch);
            }
        }
        else if(peek(&S) != '\'' && peek(&S) != '"') {
            switch(ch) {
                case '(':
              
                case '{':
                   
                    push(&S, ch);
                    
                    break;
                case ')':
                    
                    if (is_empty(&S) || pop(&S) != '(')
                        exit_incorrect_nesting(&S);
                    break;
                    
                case '}' :
                    if (is_empty(&S) || pop(&S) != '{'){
                        
                        exit_incorrect_nesting(&S);
                        
                    }
                    break;
            }
        }
    }
    
    
    if (is_empty(&S))
        printf("Nesting is correct\n");
    else {
        
        exit_incorrect_nesting(&S);
        
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

stack push( stack *S , char ch )
{
    if (is_full(S)) {
        fprintf(stderr, "push: Full stack\n");
        return *S;
    }
    ++S->size;
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

void exit_incorrect_nesting(stack *S)
{
    int p;
    p = S->size;
    printf("Nesting is NOT correct\n and the error is in character %i\n", p);
    exit(EXIT_SUCCESS);
}
int track( stack *S , int t)
{
    int i = -1;
    i++;
    S->trac = i;
   return  S->trac; 
}
