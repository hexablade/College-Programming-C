#include <stdio.h>

/*
 */

int main(void){
    int height, length, volume, weight;

    height = 9;
    length = 12;
    width = 10;
    volume = height * length * width;
    weight = (volume + 165) / 166;

    printf("Dimensions: %dx%dx%d\n", length, width, height);
    printf("Volumne (cubic inches): %d\n", volume);
    printf("Dimensional weight (lbs): %d\n", weight);

    return 1;
}
