#include "s21_math.h"

long double s21_pow(double base, double exp) {
  if (s21_is_inf(base) && s21_is_inf(exp)) return 0.0;

  if (s21_is_inf(exp)) return S21_INFINITY;

  if ((base < 0 && (double)(int)exp != exp) || s21_is_nan(base)) return S21_NAN;

  if (!base) return !exp ? 1.0 : base;

  if (exp == -1.0) return 1.0 / base;
  if (exp == 2.0) return base * base;
  if (exp == 0) return 1.0;

  if (((s21_ceil(exp) == exp)) && exp > 0) {
    long double copy = base;
    long double result = base;
    for (int i = 1; i < exp; i++) {
      result *= copy;
    }
    return result;
  }

  long double res = 0;
  res = s21_exp(exp * s21_log(s21_fabs(base)));

  if (((long int)(exp) % 2 != 0) && base < 0.0) res *= -1;

  return res;
}