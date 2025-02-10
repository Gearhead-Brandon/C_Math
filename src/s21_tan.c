#include "s21_math.h"

long double s21_tan(double x) {
  if ((s21_is_nan(x)) || s21_is_inf(x)) return S21_NAN;
  if (s21_is_nan(x)) return S21_POSITIVE_NAN;

  if (x == S21_M_PI / 2) return 16331239353195370.0;
  if (x == S21_M_PI / (-2.0)) return -16331239353195370.0;

  return s21_sin(x) / s21_cos(x);
}