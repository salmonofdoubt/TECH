#include <stdio.h>

static int s; // This is the global s

void f(int a) {
  static int s;       // This here is the local s.
  s += a;             // It just happens to have the 
  printf("%d\n", s);  // same name as the global one.
}

int callcount() {           // Every time this function runs,
  static int callcount = 0; // it will return a higher value
  return ++callcount;       // since the callcount value is retained
}                           // between calls.

int main() {
  int i;
  s = 10; // This is the global s
  f(2);   // It will use the local s and print out 2 (and not 10);

  for (i = 0; i < 10; ++i) {     // We should get numbers from 1 to 10
    printf("%d\n", callcount());
  }
}

