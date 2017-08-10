//ctrl D == EOF

#include <stdio.h>
  
int B(){
  
  int c;
  
  while ((c = getchar()) != EOF) {          
    putchar(c);
  }
}
    
int main(){

  B();

}
