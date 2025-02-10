#include <check.h>
#include <math.h>

#include "../s21_math.h"

int arr_abs[14] = {
    // abs
    0,     1,      -1,   -7,    -400000000,    -0.00006, -11025,
    0.125, -0.125, 14.6, -14.6, -10000000.123, -4e-9,
    9.239  // 13
};

START_TEST(test_abs1) {
  ck_assert_ldouble_eq_tol(s21_abs(arr_abs[_i]), abs(arr_abs[_i]), 0.000001);
}
END_TEST

Suite *s21_abs_suite(void) {
  Suite *s1;
  TCase *tc1_1;
  s1 = suite_create("s21_abs");
  tc1_1 = tcase_create("case_abs");
  suite_add_tcase(s1, tc1_1);
  tcase_add_loop_test(tc1_1, test_abs1, 0, 13);

  return s1;
}

int main(void) {
  int no_failed = 0;
  Suite *s1;
  SRunner *sr;

  s1 = s21_abs_suite();
  sr = srunner_create(s1);

  srunner_run_all(sr, CK_NORMAL);
  no_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}