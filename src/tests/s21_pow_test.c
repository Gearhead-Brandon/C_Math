#include <check.h>
#include <math.h>

#include "../s21_math.h"

double test_exponent[26] = {4,
                            3,
                            7,
                            8,
                            6.6,
                            4.2,
                            3,
                            NAN,
                            -NAN,
                            NAN,
                            -NAN,
                            INFINITY,
                            INFINITY,  /////
                            -INFINITY,
                            -INFINITY,  // 14
                            0.125,
                            2 * S21_M_PI,
                            S21_M_PI - 2,
                            2 * 3.14,
                            S21_M_PI,
                            S21_M_PI * 0.5,
                            S21_M_PI,
                            S21_M_PI / 4,
                            -1,
                            -4,
                            -2};

double test_base[26] = {-50,
                        500.4,
                        -9.239,
                        5,
                        5.5,
                        14.6,
                        100000.123,  // 6
                        NAN,
                        NAN,
                        -NAN,
                        -NAN,
                        INFINITY,
                        -INFINITY,
                        -INFINITY,
                        INFINITY,
                        0.125,
                        2 * S21_M_PI,
                        S21_M_PI - 2,
                        2 * 3.14,
                        S21_M_PI * 4,
                        S21_M_PI * 0.5,
                        S21_M_PI,
                        S21_M_PI / 4,
                        5,
                        2,
                        16};

double test_values[24] = {
    0,
    1,
    2.71828182846,
    4e9,
    -4e9,
    -4e-9,  // 5
    4e-9,
    0.125,  // 7-
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

START_TEST(test_pow1) {
  ck_assert_ldouble_eq_tol(s21_pow(test_base[_i], test_exponent[_i]),
                           pow(test_base[_i], test_exponent[_i]), 0.000001);
}
END_TEST

START_TEST(test_pow2) {
  ck_assert(s21_is_nan(s21_pow(test_values[_i], test_values[_i])) ==
            s21_is_nan(pow(test_values[_i], test_values[_i])));
}
END_TEST

START_TEST(test_pow3) {
  ck_assert(s21_is_nan(s21_pow(test_base[_i], test_exponent[_i])) ==
            s21_is_nan(pow(test_base[_i], test_exponent[_i])));
}
END_TEST
START_TEST(test_pow4) {
  ck_assert_ldouble_eq_tol(s21_pow(test_base[_i], test_exponent[_i]),
                           pow(test_base[_i], test_exponent[_i]), 0.000001);
}
END_TEST

Suite *s21_pow_suite(void) {
  Suite *s5 = suite_create("s21_pow");
  TCase *tc5_1 = tcase_create("case_pow");
  s5 = suite_create("s21_pow");
  tc5_1 = tcase_create("case_pow");
  suite_add_tcase(s5, tc5_1);
  tcase_add_loop_test(tc5_1, test_pow1, 0, 6);
  tcase_add_loop_test(tc5_1, test_pow2, 19, 22);
  tcase_add_loop_test(tc5_1, test_pow3, 7, 13);
  tcase_add_loop_test(tc5_1, test_pow4, 15, 25);

  return s5;
}

int main(void) {
  int no_failed = 0;
  Suite *s5 = suite_create("s21_pow");
  SRunner *sr;

  s5 = s21_pow_suite();
  sr = srunner_create(s5);

  srunner_run_all(sr, CK_NORMAL);
  no_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}