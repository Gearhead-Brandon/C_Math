#include <check.h>
#include <math.h>

#include "../s21_math.h"

double test_values[24] = {
    0,
    1,
    2.71828182846,
    4e9,
    -4e9,
    -4e-9,  // 5
    4e-9,
    0.125,
    -0.125,
    2 * S21_M_PI,
    -2 * S21_M_PI,
    S21_M_PI - 2,
    2 * 3.14,
    S21_M_PI *S21_M_PI,
    S21_M_PI * 0.5,
    -S21_M_PI * 0.5,  // 15
    S21_M_PI,
    -S21_M_PI,
    S21_M_PI / 4,
    -S21_M_PI / 4,  // 19
    NAN,
    -NAN,
    INFINITY,
    -INFINITY  // 23
};

double test_exponent[15] = {
    4,         3.5, 7, 8, 6.6, 4.2, 3, NAN, -NAN, NAN, -NAN, INFINITY,
    INFINITY,  /////
    -INFINITY,
    -INFINITY  // 14
};

double test_base[15] = {
    -50,        500.4, -9.239, 5,    5.5,      14.6,
    100000.123,  // 6
    NAN,        NAN,   -NAN,   -NAN, INFINITY,
    -INFINITY,  /////////////
    -INFINITY,
    INFINITY  // 14
};

START_TEST(test_fmod1) {
  ck_assert_ldouble_eq_tol(s21_fmod(test_base[_i], test_exponent[_i]),
                           fmod(test_base[_i], test_exponent[_i]), 0.000001);
}
END_TEST

START_TEST(test_fmod3) {
  ck_assert(s21_is_nan(s21_fmod(test_values[_i], test_values[_i])) ==
            s21_is_nan(fmod(test_values[_i], test_values[_i])));
}
END_TEST

Suite *s21_fmod_suite(void) {
  Suite *s6 = suite_create("s21_fmod");
  TCase *tc6_1 = tcase_create("case_fmod");

  s6 = suite_create("s21_fmod");
  tc6_1 = tcase_create("case_fmod");
  suite_add_tcase(s6, tc6_1);
  tcase_add_loop_test(tc6_1, test_fmod1, 0, 6);
  tcase_add_loop_test(tc6_1, test_fmod3, 19, 22);
  return s6;
}

int main(void) {
  int no_failed = 0;
  Suite *s6 = suite_create("s21_fmod");
  SRunner *sr;

  s6 = s21_fmod_suite();
  sr = srunner_create(s6);

  srunner_run_all(sr, CK_NORMAL);
  no_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}