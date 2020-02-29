#include<stdio.h>

union test
{
     int a; 
     char c;
};
int main()
{
     union test t={0x41424344};//A B C D
     printf("%c\n", t.c);
     return 0;
}
