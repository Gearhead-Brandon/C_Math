#include "s21_math.h"

long double s21_fabs(double x) {
  unsigned long int *i = (unsigned long int *)&x;
  *i = *i & ~(1UL << 63);
  return x;
}