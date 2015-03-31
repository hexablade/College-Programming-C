#include <stdio.h>

/*
 * Should add 2 fractions
 *
 */
int main(void){ 
    int numl, denom1, num2, denom2, result_num, result_denom
    printf("Enter first fraction: ")
    scanf("%d/%d", &numl, &denom1)
    printf("Enter secfind fraction: ")
    scanf("%d/%d", &num2, &denom2)
    result_num = numl * denom2 + num2 * denom1
    result_denom = denom1 * denom2
    printf("The num is %d/%d\n", result_num, result_denom)
    return 1
}
