#include "s21_math.h"

long double s21_log(double x) {
  if (s21_is_nan(x)) return S21_NAN;

  if (s21_is_inf(x)) return S21_INFINITY;

  if (x < 0.0) return S21_NAN;

  if (x == 0.0) return S21_NEGATIVE_INFINITY;
  if (x == 1.0) return 0.0;

  int A = 0;

  while (x > S21_EILER_E) {
    x /= S21_EILER_E;
    A++;
  }

  const long double eps = 1e-12;

  x = (x - 1) / (1 + x);
  long double sum = x;
  long double y = x;
  long double temp;
  int i = 1;

  do {
    y *= (x * x);
    i += 2;
    temp = y / i;

    sum += temp;

  } while (s21_fabs(temp) > eps);

  return 2 * sum + A;
}