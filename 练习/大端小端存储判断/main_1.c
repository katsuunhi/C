#include<stdio.h>

int main()
{
     int a=0x44434241; // D C B A
     int* pa=&a;
     printf("%c\n", *((char*)pa));
     return 0;
}
