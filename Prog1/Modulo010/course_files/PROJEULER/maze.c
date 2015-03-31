#include <stdio.h>
#include <stdlib.h>

#define N 8
int main(int argc, char*args[]){

    char m[N][N] = {"--"};
    int row;
    int col;

    for(row = 0; row < N; row++){
        for(col = 0; col < N; col++){
        if( row == col)
            m[row][col] = 1.0;
        else
            m[row][col] = 0.0;
        }
    }
    printf("%c \n", m[row][col]);
}
