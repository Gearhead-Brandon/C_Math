#include "s21_math.h"

long double s21_floor(double x) {
  if (s21_is_nan(x)) return S21_NAN;

  if (s21_is_inf(x)) return S21_INFINITY;

  if ((long long int)x == x) return x;
  if (x < 0 && (s21_abs(x) != x) && (s21_abs(x) != -x))
    return (long long int)(x - 1);

  return (long long int)(x < 0 ? x - 0.9 : x);
}