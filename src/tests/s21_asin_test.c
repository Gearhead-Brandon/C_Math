#include <check.h>
#include <math.h>

#include "../s21_math.h"

double test_arc[20] = {
    // arcsin arccos
    0,
    1,
    0.6892,
    -1,
    0.5,
    -0.40019,
    0.815,
    0.125,
    -0.125,
    -0.178,
    -0.000001,
    S21_M_PI - 3,
    -0.7,
    -0.5789,
    -0.9,
    -0.0875,
    0.345,
    0.9999,
    S21_M_PI / 4,
    -S21_M_PI / 4  // 19
};

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

START_TEST(test_asin1) {
  ck_assert_ldouble_eq_tol(s21_asin(test_arc[_i]), asin(test_arc[_i]),
                           0.000001);
}
END_TEST

START_TEST(test_asin2) {
  ck_assert(s21_is_nan(s21_asin(test_values[_i])) ==
            s21_is_nan(asin(test_values[_i])));
}
END_TEST

Suite *s21_asin_suite(void) {
  Suite *s13 = suite_create("s21_asin");
  TCase *tc13_1 = tcase_create("case_asin");
  tcase_add_loop_test(tc13_1, test_asin1, 0, 19);
  tcase_add_loop_test(tc13_1, test_asin2, 19, 22);

  suite_add_tcase(s13, tc13_1);

  return s13;
}

int main(void) {
  int no_failed = 0;
  Suite *s13;
  SRunner *sr;

  s13 = s21_asin_suite();
  sr = srunner_create(s13);

  srunner_run_all(sr, CK_NORMAL);
  no_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}