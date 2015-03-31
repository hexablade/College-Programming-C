#include <stdio.h>

int main(void) {

    char buf[512];
    int length = sizeof(buf)/sizeof(buf[0]);
    int i = 0;

    fgets(buf, length, stdin); //reads an entire line into buf, no more chars than length
    while(1){
        if(buf[i] == '\n') { //most likely, you did not put in exactly 512 characters, so there is empty space in your array that we don't want to loop through. The last relevant character will be a new line char.
            break;
        }
        printf("Char: %c\n", buf[i]);
        i++;
    }

    return 0;
}
