#include <stdio.h>

int main(){

struct customer {
  char firm[20];
  char contact[25];
  };

struct sale {
  struct customer buyer;
  char item[20];
  float amount;
  };

struct sale y1990[100] = {

  {{ "Acme Industries", 
     "George Adams" },
     "Left-handed widget",
     1000.00
    }
  {{ "Wilson & Co.", 
     "Ed Wilson" },
     "Type 12 gizmo",
     290.00
    }
  };
}
  