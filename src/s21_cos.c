#include "s21_math.h"

long double s21_cos(double x) {
  if ((s21_is_nan(x)) || s21_is_inf(x)) return S21_NAN;
  if (s21_is_nan(x)) return S21_POSITIVE_NAN;

  const long double eps = 1e-200;
  int i;
  long double s = 1, n = 0, a = 1;

  x = s21_fmod(x, 2 * S21_M_PI);

  for (i = 1; s21_fabs(a) > eps; i++) {
    a = -(a * x * x) / ((2 * n + 2) * (2 * n + 1));
    s = s + a;
    n++;
  }

  return s;
}