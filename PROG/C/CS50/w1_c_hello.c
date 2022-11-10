#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string answer = get_string("What's your name? ");
    int percent = 33;
    printf("Hello, %s! You are at %d%% \n", answer, percent);
}

