/*
Demonstarte else condition
*/

# include <stdio.h>


# define B_KEY 'b'
# define ENTER_KEY '/r'

int main(int argc, int *argv[]){
  char ch;
  printf("Press \'b\' to hear bell.\n");
  scanf("%s", &ch);
  if (ch == B_KEY)
    printf("Beep!\a\n");
  else if (ch = ENTER_KEY)
    printf("Boring Selection.\n");
  else 
    printf("Bye now.\n");
}