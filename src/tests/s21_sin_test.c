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

START_TEST(test_sin1) {
  ck_assert_ldouble_eq_tol(s21_sin(test_values[_i]), sin(test_values[_i]),
                           0.000001);
}
END_TEST

START_TEST(test_sin2) {
  ck_assert(s21_is_nan(s21_sin(test_values[_i])) ==
            s21_is_nan(sin(test_values[_i])));
}
END_TEST

Suite *s21_sin_suite(void) {
  Suite *s10 = suite_create("s21_sin");
  TCase *tc10_1 = tcase_create("case_sin");

  tcase_add_loop_test(tc10_1, test_sin1, 0, 19);
  tcase_add_loop_test(tc10_1, test_sin2, 19, 22);

  suite_add_tcase(s10, tc10_1);

  return s10;
}

int main(void) {
  int no_failed = 0;
  Suite *s10;
  SRunner *sr;

  s10 = s21_sin_suite();
  sr = srunner_create(s10);

  srunner_run_all(sr, CK_NORMAL);
  no_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}