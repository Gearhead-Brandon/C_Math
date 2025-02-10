#include "s21_math.h"

long double s21_sqrt(double x) {
  if (s21_is_nan(x)) return S21_NAN;
  if (s21_is_nan(x)) return S21_POSITIVE_NAN;
  if (s21_is_inf(x)) return S21_INFINITY;

  if (x < 0) return S21_NAN;
  long double a = 1;
  long double na;
  for (;;) {
    na = (a + x / a) / 2.0;
    if (s21_fabs(a - na) < 1e-100) break;
    a = na;
  }
  return a;
}