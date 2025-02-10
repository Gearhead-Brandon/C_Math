#include "s21_math.h"

long double s21_factorial(long long int x) {
  if (x == 0 || x == 1) return 1;
  long double res = 1;
  for (int i = 1; i <= x; i++) {
    res *= i;
  }
  return res;
}

long double s21_sin(double x) {
  if ((s21_is_nan(x)) || s21_is_inf(x)) return S21_NAN;
  if (s21_is_nan(x)) return S21_POSITIVE_NAN;

  const long double eps = 1e-12;
  long double s = 0;
  x = s21_fmod(x, 2 * S21_M_PI);
  long double d = 1;
  long double xt = x;

  int n = 0;
  do {
    d = xt / s21_factorial(2 * n + 1);
    s += d;
    n++;
    xt *= -x * x;

  } while (s21_fabs(d) > eps);
  return s;
}