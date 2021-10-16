#include <stdio.h>
unsigned int reverse(unsigned int x) {
  unsigned int b = 0, c;
  while (x != 0) {
    c = x % 10;
    b = b * 10 + c;
    x /= 10;
  }
  return b;
}
int detectBits(int x) {
  return !(x & 2863311530 ^ 2863311530);
}
int main() {
  unsigned int result = reverse(108);
  printf("%u\n", result);
  return 0;
}