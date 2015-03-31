#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    
   FILE *fp;
   char *fcontents;
   long size;

   switch(argc){
    
       case 1:
           fputs("This preogram takes 1 argument!\n", stderr);
           break;
       case 2:
           if((fp = fopen(argc[1], "r")) ==NULL){
               fputs("Error readind file", stderr);
            exit(EXIT_FAILURE);
           }
        if(fseek(fp,0,SEEK_END) != 0){
            fputs("Error opening file", stderr);
            fclose(fp);
        }
                    size = ftell(fp);
                    rewind(fp);



   

}

