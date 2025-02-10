#include <check.h>
#include <math.h>

#include "../s21_math.h"

double test_cos[3] = {4e9, 7000000000, 2500000000};

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

START_TEST(test_ceil1) {
  ck_assert_ldouble_eq_tol(s21_ceil(test_values[_i]), ceil(test_values[_i]),
                           0.000001);
}
END_TEST

START_TEST(test_ceil2) {
  ck_assert_ldouble_eq_tol(s21_ceil(test_cos[_i]), ceil(test_cos[_i]),
                           0.000001);
}
END_TEST

START_TEST(test_ceil3) {
  ck_assert(s21_is_nan(s21_ceil(test_values[_i])) ==
            s21_is_nan(ceil(test_values[_i])));
}
END_TEST

Suite *s21_ceil_suite(void) {
  Suite *s3 = suite_create("s21_ceil");
  TCase *tc3_1 = tcase_create("case_ceil");
  s3 = suite_create("s21_ceil");
  tc3_1 = tcase_create("case_ceil");
  suite_add_tcase(s3, tc3_1);
  tcase_add_loop_test(tc3_1, test_ceil1, 0, 19);
  tcase_add_loop_test(tc3_1, test_ceil2, 0, 2);
  tcase_add_loop_test(tc3_1, test_ceil3, 19, 22);

  return s3;
}

int main(void) {
  int no_failed = 0;
  Suite *s3 = suite_create("s21_ceil");
  SRunner *sr;

  s3 = s21_ceil_suite();
  sr = srunner_create(s3);

  srunner_run_all(sr, CK_NORMAL);
  no_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}