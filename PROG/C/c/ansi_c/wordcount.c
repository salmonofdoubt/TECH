/*
- count lines, words, and characters in input 
- ctrl D == EOF
*/

#include <stdio.h>

#define IN_WORD 1   /* inside a word */
#define NOT_IN_WORD 0   /* outside a word */


int B() {
  
  int inputchar, lines, words, chars, state;
  state = NOT_IN_WORD;                      /* is 0 */
  lines = words = chars = 0;

  while ((inputchar = getchar()) != EOF) {  /* while EOF (ctrl D) is not true, keep getting chars */
    ++chars;                                /* and increase char count on each */
    if (inputchar == '\n')                  /* if there is a newline, add 1 */
      ++lines;
    if (inputchar == ' '  || inputchar == '\n' || inputchar == '\t')
      state = NOT_IN_WORD;                        /* illogocal but read next line, flip state to 0*/
    else if (state == NOT_IN_WORD) {              /* and if state is 0, increase word count*/
      state = IN_WORD;
      ++words;
    }
  }
  printf(" lines: \t\t%d\n words: \t\t%d\n chars (incl enter): \t%d\n", lines, words, chars);
}

main(){                                       /* main will be executed which just calls B() */
  
  B();

}
