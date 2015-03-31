#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 512



bool anagrams(const char *w1, const char *w2)
{
      int letters[26] = {0};

        while (*w1) {
                if (isalpha(*w1))
                          letters[tolower(*w1) - 'a']++;
                    w1++;
                      }

        while (*w2) {
                if (isalpha(*w2))
                          letters[tolower(*w2) - 'a']--;
                    w2++;
                      }

            for (int i = 0; i < 26; i++) {
                    if (letters[i] != 0)
                              return false;
                      }
              return true;

                if (anagrams(w1, w2))
                        printf("The words are anagrams\n");
                  else
                          printf("The words are not anagrams\n");
}
int main(int argc, char* args[])
{
      char w1[SIZE], w2[SIZE];
      
int i;
char tmp1, tmp2;

        printf("Enter the first word: ");   
        for(int i = 0; i< SIZE ; i++){
            scanf("%c", &tmp1);
            if( isalpha(tmp1) )
               w1[i] = tmp1;
            else
                break;              
                          
        }
          
        printf("Enter the Second word: ");   
        for(int i = 0; i< SIZE ; i++){
            scanf("%c", &tmp2);
            if( isalpha(tmp2) )
               w2[i] = tmp2;
            else
                break;              
                          
        }


                if (anagrams(w1, w2))
                        printf("The words are anagrams\n");
                  else
                          printf("The words are not anagrams\n");

                    return 0;
}
