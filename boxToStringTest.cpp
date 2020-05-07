#include "shapes.h"
#include "shapeFuncs.h"
#include "tddFuncs.h"




int main() {

  struct Box b1, b2;

  initBox(&b1,3.0,4.0, 5.0, 6.0);
  assertEquals("ul=(3,4),w=5,h=6", boxToString(b1), "boxToString(b1)");

  initBox(&b2,3.1415,6.28318, 0.4201, 6.6969);
  assertEquals("ul=(3.14,6.28),w=0.42,h=6.7", boxToString(b2), "boxToString(b2)");
  assertEquals("ul=(3,6),w=0.4,h=7", boxToString(b2,1), "boxToString(b2,1)");
  assertEquals("ul=(3.142,6.283),w=0.4201,h=6.697", boxToString(b2,4), "boxToString(b2,4)");
  assertEquals("ul=(3.1415,6.2832),w=0.4201,h=6.6969", boxToString(b2,5), "boxToString(b2,5)");

  return 0;
}
