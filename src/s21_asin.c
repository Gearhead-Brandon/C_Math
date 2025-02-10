#include "s21_math.h"

long double s21_asin(double x) {
  if ((s21_is_nan(x)) || s21_is_inf(x)) return S21_POSITIVE_NAN;
  if (s21_is_nan(x)) return S21_NAN;
  if (x < -1.0 || x > 1.0) return S21_POSITIVE_NAN;

  long double a0 = 1.5707288;
  long double a1 = -0.2121144;
  long double a2 = 0.0742610;
  long double a3 = -0.0187293;

  if (x == -1.0)
    return (S21_M_PI / 2 - s21_sqrt(1 + x) * (a0 + a1 * x + a2 * s21_pow(x, 2) +
                                              a3 * s21_pow(x, 3))) *
           -1;

  if (x == 1.000000)
    return S21_M_PI / 2 - s21_sqrt(1 - x) * (a0 + a1 * x + a2 * s21_pow(x, 2) +
                                             a3 * s21_pow(x, 3));

  long double eps = 1.0e-13;
  long double n = 1;
  long double a = x;
  long double s = 1;
  long double r = x;
  long double x2 = x;
  while (s > eps || -s > eps) {
    a = x2 * x2 * (a * (2.0 * n - 1)) / (2.0 * n);
    s = a / (2.0 * n + 1.0);
    r += s;
    n++;
  }
  return r;
}