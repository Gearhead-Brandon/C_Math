CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBS = -lcheck -lsubunit -lm
FUNC_FILES_C = *.c
FUNC_FILES_O = *.o
CHECKFLAGS = $(shell pkg-config --cflags --libs check)
GCOVFLAGS =-fprofile-arcs -ftest-coverage
LIBNAME = s21_math.a
GLFLAGS =--coverage

all: s21_math.a

peer: gcov_report gcov_html

object:
	$(CC) $(FLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $(FUNC_FILES_C)

lib:
	ar rcs $(LIBNAME) $(FUNC_FILES_O)

s21_math.a:
	$(CC) $(FLAGS) -c $(FUNC_FILES_C)
	make lib
	rm -rf *.o

test: s21_math.a

	$(CC) tests/s21_abs_test.c -L. s21_math.a $(CHECKFLAGS) $(GCOVFLAGS) $(GLFLAGS)  -o s21_abs_test
	$(CC) tests/s21_acos_test.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_acos_test
	$(CC) tests/s21_asin_test.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_asin_test
	$(CC) tests/s21_atan_test.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_atan_test
	$(CC) tests/s21_ceil_test.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_ceil_test
	$(CC) tests/s21_cos_test.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_cos_test
	$(CC) tests/s21_exp_test.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_exp_test
	$(CC) tests/s21_fabs_test.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_fabs_test
	$(CC) tests/s21_floor_test.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_floor_test
	$(CC) tests/s21_fmod_test.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_fmod_test
	$(CC) tests/s21_log_test.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_log_test
	$(CC) tests/s21_pow_test.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_pow_test
	$(CC) tests/s21_sin_test.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_sin_test
	$(CC) tests/s21_sqrt_test.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_sqrt_test
	$(CC) tests/s21_tan_test.c -L. s21_math.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_tan_test
	make st
st:
	./s21_abs_test
	./s21_atan_test
	./s21_asin_test
	./s21_acos_test
	./s21_ceil_test
	./s21_cos_test
	./s21_exp_test
	./s21_fabs_test
	./s21_floor_test
	./s21_fmod_test
	./s21_log_test
	./s21_sin_test
	./s21_sqrt_test
	./s21_tan_test
	./s21_pow_test

gcov_report:  object lib test
	gcov $(FUNC_FILES_C)
#	pip install git+https://github.com/gcovr/gcovr.git
	~/.local/bin/gcovr -r . --exclude "test/*" --html --html-details -o s21_math.html

gcov_html: st gcov_report
	xdg-open s21_math.html

clean:
	rm -rf *.o *.gcno *.gcov *.gcda *.a *.info *.html *.css
	rm -rf s21_*_test s21_test

rebuild:
	make clean
	make