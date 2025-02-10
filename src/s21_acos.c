#include "s21_math.h"

long double s21_acos(double x) {
  if ((s21_is_nan(x)) || s21_is_inf(x)) return S21_POSITIVE_NAN;
  if (x < -1.0 || x > 1.0) return S21_POSITIVE_NAN;

  return S21_M_PI / 2 - s21_asin(x);
}