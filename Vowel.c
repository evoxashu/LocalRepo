#include <stdio.h>
#include <string.h>
int main()
{
    char str[100],vol[100],con[100];
    printf("Enter your name \n");
    gets(str);
    puts(str);
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
        {
            vol[i]=str[i];
        }
        else
        {
            con[i]=str[i];
        }
    }
    printf("Vowels in your name are \n ");
    puts(vol);
    printf("Consonants in your name are \n ");
    puts(con);
    return 0;
}