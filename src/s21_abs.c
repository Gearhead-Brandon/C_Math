#include "s21_math.h"

int s21_abs(int x) {
  int temp = x >> 31;
  return (x ^ temp) - temp;
}