#include <stdio.h>

int main()
{
    char s[100];
    char rev[100];
    int flag = 0;
    int length = 0;
    printf("Enter a string: ");
    fgets(s,sizeof(s),stdin);
    while (s[length]!='\0')
    {
        length++;
    }
    length--;
    int i = length;
    int j = 0;
    while (j<i)
    {
        if (s[i] == s[j])
        {
            flag = 1;
        }
        
    }
    if (flag == 1)
    {
        printf("Pallindrome");
    }
    else printf("np");
    
    
    

   return 0;
}