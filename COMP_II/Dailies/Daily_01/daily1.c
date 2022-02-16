#include <stdio.h>

char* reverse(char pWord[]);

int main(int argc, char* argv[])
{
char word[] = "Happy Birthday!";

 printf("%s\n", word);
 reverse(word);
 printf("%s\n", word);
 printf("%s\n", reverse(word));
 printf("%s\n", word);
 return 0;
}

char* reverse(char pWord[])
{
    int start = 0;
    int end = 0;
    int size;
    char temp;
 
   
    while (pWord[end]!='\0'){
       end++;
    }
    size = end;
    end--;
    
    while(start <= end){
        temp = pWord[end];
        pWord[end] = pWord[start];
        pWord[start] = temp;
        
        end--;
        start++;
    }
    pWord[size] = '\0';
    return pWord;
}
    
    

   
