#include <stdio.h>

int main(int argc, char* args[]) {

    char buf[512];
    char stk[512];
    int length = sizeof(buf)/sizeof(buf[0]);
    int i = 0;
    int pass;
    int stp;


    fgets(buf, length, stdin); //reads an entire line into buf, no more chars than length
    while(1){
        if(buf[i] == '\n') { //most likely, you did not put in exactly 512 characters, so there is empty space in your array that we don't want to loop through. The last relevant character will be a new line char.
            break;
        }
        
            if(buf[i] = '('){
                if(buf[i] = ')'){
                buf[i] = stk[i];
                stk[i] = ')';
                break;

                   
                  } 
        printf("Char: %c passed", buf[i]);
        i++;
    }
    
    return 0;
}
// int stp, i, pass;
// stp = 0
// i = 0
// pass = 1
//
// while same as above
// if(buf[i] == \n
//
//if stp != 0 
//printf lalala %i, stp
//pass = 0
//
//breal 
//
//else if buf[i] = '(' 
//stack[stp] = '('
//stp ++
//
//else if bufi == ')' 
//if stp == 0 bufstp == -1
//
//if pass
//printf repeat
//
//if getchar() == 'n'
//
//break

//while getchat != 

//return 0
//
