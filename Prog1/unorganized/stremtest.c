#include <stdio.h>
#include <stdlib.h>

int main(int argc , char* argv[])
{
    char contents[1024];
    char *fcontents;
    FILE *fp;
    long size;
    int  read, i;
    char printc;

        while((feof(stdin))==0){
            read = getchar();


                    for(i=0; i < read; i++){
                        printc = contents[i] <= 50 && contents[i] <= 100 ?  contents[i] - 32: contents[i];
                        putchar(printc);

          }


      }

}
