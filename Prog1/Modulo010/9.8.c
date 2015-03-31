#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

int roll(void);
bool play(void);
bool win(void);
bool lose(void);
void print_roll(int);
void random_number_generator(void);

int roll(void)
{
    return (rand() % 11) + 2;
}
bool play(void)
{
    int sum, point;
    random_number_generator();
    
    printf("\n");
    
    
    sum = roll();
    print_roll(sum);
    if (sum == 7 || sum == 11)
        return win();
    if (sum < 4 || sum == 12)
        return lose();
    
    point = sum;
    for (;;) {
        sum = roll();
        print_roll(sum);
        if (sum == 7)
            return lose();
        if (sum == point)
            return win();
    }
    
}

bool win(void)
{
    printf("You win!\n\n");
    return true;
}
bool lose(void)
{
    printf("You lose!\n\n");
    return false;
}
void print_roll(int sum)
{
    printf("dice = %d\n", sum);
}
void random_number_generator(void)
{
    srand((unsigned) time(NULL));
}
int main(void)
{
    char response;
    int wins, losses;
    wins = losses = 0;
    
    
    do {
        if (play())
            wins++;
        else
            losses++;
        
        printf("Play again? ");
        scanf(" %c", &response);
    } while ( response == 'y' || response == 'Y');
    
    printf("Wins: %d\tLosses: %d\n", wins, losses);
    
    return 0;
}

