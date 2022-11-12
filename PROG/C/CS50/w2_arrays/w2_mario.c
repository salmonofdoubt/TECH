#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_grid(int size);

int main(void)
{
   // Get size
   int n = get_size();
   
   // Print bricks
   print_grid(n);
}

int get_size(void)
{
    int n;
    do 
    {
        n = get_int("Size: ");
    }
    while (n < 1);
    return n;
}

void print_grid(int size)
{   
   for (int i = 0; i < size; i++)
   {
       for (int i = 0; i < size; i++)
           {
               printf("#");
           }
       printf("\n");
   }
}