#include "s21_math.h"

long double s21_atan(double x) {
  if ((s21_is_nan(x))) return S21_POSITIVE_NAN;
  if (s21_is_nan(x)) return S21_NAN;

  long double sum = S21_NAN;
  if (s21_fabs(x) == 1)
    sum = S21_M_PI / 4 * x;
  else if (s21_fabs(x) < 1)
    sum = s21_calc_atan(x);
  else if (x > 0)
    sum = S21_M_PI / 2 - s21_calc_atan(1 / x);
  else if (x < 0)
    sum = -S21_M_PI / 2 - s21_calc_atan(1 / x);
  return sum;
}

long double s21_calc_atan(double x) {
  long double sum = 0;
  long double term;
  long double xt = x;
  const long double eps = 1.0e-12;
  int n = 1;
  do {
    term = xt / (2 * n - 1);
    sum += term;
    n++;
    xt *= -x * x;
  } while (s21_fabs(term) > eps);

  return sum;
}