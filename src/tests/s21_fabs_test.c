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

START_TEST(test_fabs1) {
  ck_assert_ldouble_eq_tol(s21_fabs(test_values[_i]), fabs(test_values[_i]),
                           0.000001);
}
END_TEST

START_TEST(test_fabs2) {
  ck_assert(s21_is_nan(s21_fabs(test_values[_i])) ==
            s21_is_nan(fabs(test_values[_i])));
}
END_TEST

Suite *s21_fabs_suite(void) {
  Suite *s2 = suite_create("s21_fabs");
  TCase *tc2_1 = tcase_create("case_fabs");
  s2 = suite_create("s21_fabs");
  tc2_1 = tcase_create("case_fabs");

  tcase_add_loop_test(tc2_1, test_fabs1, 0, 19);
  tcase_add_loop_test(tc2_1, test_fabs2, 19, 22);
  suite_add_tcase(s2, tc2_1);

  return s2;
}

int main(void) {
  int no_failed = 0;
  Suite *s2 = suite_create("s21_fabs");
  SRunner *sr;

  s2 = s21_fabs_suite();
  sr = srunner_create(s2);

  srunner_run_all(sr, CK_NORMAL);
  no_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}