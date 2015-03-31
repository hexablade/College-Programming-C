#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum {INT, LONG, CHAR, FLOAT, NONE} TYPE;

bool sInts = false, sLongs = false, sChars = false, sFloats = false;
long numBytes;

//print out the allocated bits, seperated by \n at segsize
void print_memory(void *addr, int len, int segsize){
    int i,z;
    unsigned char *byte = (unsigned char*)addr;

    for(i=0; i<len; i++){
        if(i > 0 && i % segsize == 0){
            printf("\n");
        }
        for(z=1; z < 256; z <<= 1){
            printf("%c", (byte[i] & z) ? '1' : '0');
        }
        printf(" ");
    }
    printf("\n");
}

//print out the allocated as a type
void print_vals(void *ptr, TYPE t){
    int *iPtr = ptr;
    long *lPtr = ptr;
    char *cPtr = ptr;
    float *fPtr = ptr;
    int i;
    printf("\n*****\n");
    switch(t){
        case INT:
            for(i=0; i < numBytes / sizeof(int); i++){
                printf("* %i\n", iPtr[i]);
            }
            break;
        case LONG:
            for(i=0; i < numBytes / sizeof(long); i++){
                printf("* %li\n", lPtr[i]);
            }
            break;
        case CHAR:
            for(i=0; i < numBytes / sizeof(char); i++){
                printf("* %c\n", cPtr[i]);
            }

            break;
        case FLOAT:
            for(i=0; i < numBytes / sizeof(float); i++){
                printf("* %f\n", fPtr[i]);
            }

            break;
        default:
            printf("Bad type!\n");
    }
    printf("*****\n");
}

void print_help(){
    printf("\nYou have 3 commands:\n\tprintmem <type> -- prints binary of mem, seperated out by pointer type\n"
           "\tprint <type> -- prints a string rep. of the value in that location\n"
           "\tset <type> <loc> <val> -- sets memory at location to given value, based off\n\t\t of offset number and pointer type\n\n");
}

//determine type based off of user input str, ONLY assigns type if it is valid for our allocation size
TYPE type(char *typestr){
    if(strncmp(typestr, "int", 3) == 0 && sInts)
        return INT;
    if(strncmp(typestr, "long", 4) == 0 && sLongs)
        return LONG;
    if(strncmp(typestr, "char", 4) == 0 && sChars)
        return CHAR;
    if(strncmp(typestr, "float", 5) == 0 && sFloats)
        return FLOAT;

    return NONE;
}

//grab the sizeof associated with a type
long typeToSize(TYPE t){
    switch(t){
        case INT:
            return sizeof(int);
        case LONG:
            return sizeof(long);
        case CHAR:
            return sizeof(char);
        case FLOAT:
            return sizeof(float);
        default:
            return -1;
    }
}

//helper function, takes in a string and finds the index of the next char that represents in integer
int indexOfNextNum(char *ptr){
    int i = 0;
    while(ptr[i] != '\0'){
        if(ptr[i] >= '0' && ptr[i] <= '9')
            return i;
        i++;
    }
    return -1;
}

//toggles bits in our allocated memore based off of pointer type, offset, and value
bool setValue(void *ptr, TYPE t, long ind, long val){
    int *iPtr = ptr;
    long *lPtr = ptr;
    char *cPtr = ptr;
    float *fPtr = ptr;

    switch(t){
        case INT:
            if(ind < numBytes / sizeof(int)){
                iPtr[ind] = val;
                return true;
            }
            break;
        case LONG:
            if(ind < numBytes / sizeof(long)){
                lPtr[ind] = val;
                return true;
            }
            break;
        case CHAR:
            if(ind < numBytes / sizeof(char)){
                cPtr[ind] = val;
                return true;
            }
            break;
        case FLOAT:
            if(ind < numBytes / sizeof(float)){
                fPtr[ind] = val;
                return true;
            }
    }

    return false;
}

//keeps the loop going and interprets user input
void repl(void *ptr){
    char buffer[256];

    print_help();
    while(true){
        fgets(buffer, sizeof(buffer), stdin); // remember that userin will always end with a \n

        if(strcmp(buffer, "exit\n") == 0){
            break;
        }

        if(strncmp(buffer, "printmem ", 9) == 0){
            TYPE t = type(&buffer[9]);
            long size = typeToSize(t);

            if(size > 0){
                print_memory(ptr, numBytes, size);
                printf("\n");
            }else{
                printf("Bad format!\n\n");
            }
        }

        if(strncmp(buffer, "print ", 6) == 0){
            TYPE t = type(&buffer[6]);
            print_vals(ptr, t);
            printf("\n");
        }

        if(strncmp(buffer, "set ", 4) == 0){
            TYPE t = type(&buffer[4]);
            if(t != NONE){
                //get first input number
                int sInd = indexOfNextNum(buffer);
                if(sInd < 0){
                    printf("Bad input!\n\n");
                    continue;
                }
                
                char *str = &buffer[sInd];                
                char **end = &str;
                long ind = strtol(&buffer[sInd], end, 10);

                //get second input number
                sInd = indexOfNextNum(*end);
                if(ind < 0){
                    printf("Bad input!\n\n");
                    continue;
                }
                long val = strtol(*end+sInd, end, 10);
                if(!setValue(ptr, t, ind, val)){
                    printf("Out of bounds!\n");
                }
            }
        }
    }
}


int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Please enter number of bytes you want to allocate\n");
        return 1;
    }

    numBytes = strtol(argv[1], NULL, 10);

    printf("Sizeof types\n-int:%li\n-long:%li\n-char:%li\n-float:%li\n\n", sizeof(int), sizeof(long), sizeof(char), sizeof(float));

    //determine which types are ok for interpreting the space with
    printf("Data types matched: \n");
    if(numBytes % sizeof(int) == 0){
        printf("Int\n"); 
        sInts = true;
    }
    if(numBytes % sizeof(long) == 0){
        printf("Long\n"); 
        sLongs = true;
    }
    if(numBytes % sizeof(char) == 0){
        printf("Char\n"); 
        sChars = true;
    }
    if(numBytes % sizeof(float) == 0){
        printf("Float\n"); 
        sFloats = true;
    }

    void *ptr = malloc(numBytes);

    repl(ptr);
    
    free(ptr);

    return 0;
}
