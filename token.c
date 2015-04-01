#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char* argv[]){

    char ch;
    char answer;

    printf("Enter the String to be parsed: \n");
    ch = getchar();
    while(ch != EOF){
       
        while(isspace(ch) || isblank(ch)){
            ch = getchar();
            }
        if(!isalnum(ch)){
          
            printf("%c\n", ch);
            ch = getchar();
        }
        else if(isdigit(ch)){
           
            putchar(ch);
            ch = getchar();
        
            if(!isdigit(ch)){
            printf("\n");
            }
        
        }

        else if(isalnum(ch)){  
            putchar(ch);
            ch = getchar();

        }
        if(ch == '\n'){           
            printf("\nWant to perform another operation...\n");
            scanf("%c",&answer);
            switch(answer){
                case 'y':
                    printf("Enter string: ");
                    continue;
                case 'n':
                    ch = EOF;
                    break;

            }
        }
    }
    printf("Closing program...\n");

}
