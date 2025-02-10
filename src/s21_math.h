#ifndef S21_MATH_H
#define S21_MATH_H

#define S21_M_PI 3.14159265358979323846
#define S21_EILER_E 2.71828182845904

#define S21_NAN (0.0f / 0.0f)
#define S21_POSITIVE_NAN (-(0.0f / 0.0f))

#define S21_INFINITY (1.0f / 0.0f)
#define S21_NEGATIVE_INFINITY (-1.0f / 0.0f)

#define s21_is_nan(x) (x != x)
#define s21_is_inf(x) (x == S21_INFINITY || x == S21_NEGATIVE_INFINITY)

#include <stdio.h>
#include <stdlib.h>

long double s21_factorial(long long int x);

long double s21_calc_atan(double x);

int s21_abs(int x);

long double s21_fabs(double x);

long double s21_ceil(double x);
long double s21_floor(double x);

long double s21_pow(double base, double exp);

long double s21_exp(double x);

long double s21_sqrt(double n);

long double s21_log(double x);

long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);

long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);

long double s21_fmod(double x, double y);

#endif