#include <stdio.h>
#include <cs50.h>


int main(void)
{
    int i = get_int("How many times meowing? ");
    while (i > 0)
    {
        printf("meow\n");
        i--;
    }

    for (int i = 0; i < 3; i++)
    {
        printf("meow 3 times\n");
    }
}
