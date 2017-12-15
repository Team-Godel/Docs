#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a = 10;
    int b = 5;

    __asm__("movl\t%1, %0"
          : "=&r" (a) : "r" (b)
    );

        printf("a = b = %d \n", a);

    return 0;
}
