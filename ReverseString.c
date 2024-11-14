#include<stdio.h>
int main()
{
    int i,j,top;
    char str[]="Nasik";
    char stack[5];
    printf("\n\n\tString is:");
    for(j=0;j<5;j++)
    {
        printf("%c",str[j]);
    }
    i=-1;
    top=-1;
    i++;
    top++;
    stack[top]=str[i];
    i++;
    top++;
    stack[top]=str[i];
    i++;
    top++;
    stack[top]=str[i];
    i++;
    top++;
    stack[top]=str[i];
    i++;
    top++;
    stack[top]=str[i];
    i++;
    top++;
    stack[top]=str[i];
    printf("\nString operation is:");
    printf("%c",stack[top]);
    top--;
    printf("%c",stack[top]);
    top--;
    printf("%c",stack[top]);
    top--;
    printf("%c",stack[top]);
    top--;
    printf("%c",stack[top]);
    top--;
    printf("%c",stack[top]);
    top--;
    return 0;
}