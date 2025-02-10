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

START_TEST(test_exp1) {
  ck_assert_ldouble_eq_tol(s21_exp(test_values[_i]), exp(test_values[_i]),
                           0.000001);
}
END_TEST

START_TEST(test_exp2) {
  ck_assert_ldouble_eq_tol(s21_exp(test_values[_i]), exp(test_values[_i]),
                           0.000001);
}
END_TEST

START_TEST(test_exp3) {
  ck_assert(s21_is_nan(s21_exp(test_values[_i])) ==
            s21_is_nan(exp(test_values[_i])));
}
END_TEST

Suite *s21_exp_suite(void) {
  Suite *s7 = suite_create("s21_exp");
  TCase *tc7_1 = tcase_create("case_exp");
  s7 = suite_create("s21_exp");
  tc7_1 = tcase_create("case_exp");
  suite_add_tcase(s7, tc7_1);
  tcase_add_loop_test(tc7_1, test_exp1, 0, 2);
  tcase_add_loop_test(tc7_1, test_exp2, 5, 19);
  tcase_add_loop_test(tc7_1, test_exp3, 19, 22);

  return s7;
}

int main(void) {
  int no_failed = 0;
  Suite *s7 = suite_create("s21_exp");
  SRunner *sr;

  s7 = s21_exp_suite();
  sr = srunner_create(s7);

  srunner_run_all(sr, CK_NORMAL);
  no_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}