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

double test_sqrt_log[20] = {
    // sqrt log
    667,
    9000000000,
    2.71828182846,
    4000000000,
    9999999999,
    3345789.995,  // 5
    100,
    0.125,
    1234,
    2 * S21_M_PI,
    1000 * S21_M_PI,
    S21_M_PI - 2,
    2 * 3.14,
    S21_M_PI *S21_M_PI,
    S21_M_PI * 0.5,
    S21_M_PI * 1000000,
    1,
    S21_M_PI,
    S21_M_PI / 4,
    S21_M_PI / 10  // 19
};

START_TEST(test_sqrt1) {
  ck_assert_ldouble_eq_tol(s21_sqrt(test_sqrt_log[_i]), sqrt(test_sqrt_log[_i]),
                           0.000001);
}
END_TEST

START_TEST(test_sqrt2) {
  ck_assert(s21_is_nan(s21_sqrt(test_values[_i])) ==
            s21_is_nan(sqrt(test_values[_i])));
}
END_TEST

Suite *s21_sqrt_suite(void) {
  Suite *s8 = suite_create("s21_sqrt");
  TCase *tc8_1 = tcase_create("case_sqrt");
  s8 = suite_create("s21_sqrt");
  tc8_1 = tcase_create("case_sqrt");
  suite_add_tcase(s8, tc8_1);
  tcase_add_loop_test(tc8_1, test_sqrt1, 0, 19);
  tcase_add_loop_test(tc8_1, test_sqrt2, 19, 22);
  return s8;
}

int main(void) {
  int no_failed = 0;
  Suite *s8 = suite_create("s21_sqrt");
  SRunner *sr;

  s8 = s21_sqrt_suite();
  sr = srunner_create(s8);

  srunner_run_all(sr, CK_NORMAL);
  no_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}