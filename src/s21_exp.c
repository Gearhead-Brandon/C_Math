#include "s21_math.h"

long double s21_exp(double x) {
  if (s21_is_nan(x)) return S21_NAN;

  if (s21_is_inf(x)) return S21_INFINITY;

  if (x < -29.9) return 0;
  const long double eps = 1e-60;
  long double s = 1, d = x;
  long double x2 = x;

  for (int n = 2; d > eps || d < -eps; n++) {
    s += d;
    d *= x2 / n;
  }
  return s < 0 ? -s : s;
}