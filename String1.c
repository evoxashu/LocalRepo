#include <stdio.h>
#include <string.h>
int main()
{
    char str[100],str1[100];
    printf("Enter a string:\n");
    gets(str);
    printf("The String is :\n");
    puts(str);
    printf("Now enter the second string:\n");
    gets(str1);
    printf("The second string is :\n");
    puts(str1);
    printf("The length of the string is : %d\n", strlen(str));
    printf("Enter the value you want to search in the string 1:\n");
    char ch;
    scanf("%c",&ch);
     printf("The character is present at %d position :\n",strchr(str,ch)-str);
     printf("The reversed string will be %s\n",strrev(str));
     printf("The first string in uppercase is : %s\n",strupr(str));
     printf("The second string in lowercase is :%s\n",strlwr(str1));
    printf("The concatenated string is :%s\n",strcat(str,str1));
    return 0;
}