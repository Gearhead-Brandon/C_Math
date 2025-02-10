#include "s21_math.h"

long double s21_fmod(double x, double y) {
  typedef union {
    double d;
    long int i;
    unsigned long int u;
  } con;

  con ux = {x}, uy = {y};

  // выделяем экспоненту без знака
  int ex = ux.u >> 52 & 2047;
  int ey = uy.u >> 52 & 2047;
  // смотрим, какой у нас знак
  int sx = ux.u >> 63;

  unsigned long int i;

  /* in the followings uxu should be ux.u, but then gcc wrongly adds */
  /* float load/store to inner loops ruining performance and code size */
  // просто чтоб было быстрее, иначе внутренние лупы подзалупливаются
  unsigned long int uxu = ux.u;

  // сначала убеждаемся, что 0 равен нулю. и что минус ноль тоже равен нулю (для
  // делителя) делитель должен не быть равен нулю, нану и инфинити
  if (uy.u << 1 == 0 || s21_is_nan(y) || ex == 2047) return (x * y) / (x * y);

  //
  if (uxu << 1 <= uy.u << 1) {
    // умножаем на x чтоб у нас 0 был записан в правильный тип данных (дабл)
    if (uxu << 1 == uy.u << 1) return 0 * x;
    // если делитель больше делимого - возвращаем делимое - он целиком влезает в
    // делитель
    return x;
  }

  // bin(uxu << (-ex + 1));
  /* normalize x and y */
  // если экспонента вся нули - у нас денормализованное число
  if (!ex) {
    // вычисляем количество нулевых бит в мантиссе (денормализованной)
    for (i = uxu << 12; i >> 63 == 0; ex--, i <<= 1)
      ;

    // тут мы сдвигаем пока не попадем в последний бит экспоненты, таким
    // образомм нормализовав число
    uxu <<= -ex + 1;
  } else {
    // нулим экспоненту
    uxu &= -1ULL >> 12;

    // добавляем один бит в 1 в конец экспоненты
    uxu |= 1ULL << 52;
  }

  if (!ey) {
    for (i = uy.u << 12; i >> 63 == 0; ey--, i <<= 1)
      ;
    uy.u <<= -ey + 1;
  } else {
    uy.u &= -1ULL >> 12;
    uy.u |= 1ULL << 52;
  }

  /* x mod y */
  // идем в цикле пока мы не станем одной степени
  for (; ex > ey; ex--) {
    i = uxu - uy.u;

    // если у нас положительный результат вычитания - глядим внимательнее
    if (i >> 63 == 0) {
      // если делимое делится на делитель без остатка(разница между ними - ноль,
      // то выдаем ноль и валим
      if (i == 0) return 0 * x;
      // если нет - делимое становится равно результату вычитания
      uxu = i;
    }
    // умножаем на 2 (догоняем экспоненту)
    uxu <<= 1;
  }

  // если у них одинаковая экспонента
  i = uxu - uy.u;
  if (i >> 63 == 0) {
    if (i == 0) return 0 * x;
    uxu = i;
  }

  // нормализуем - двигаемся влево, и убираем экспоненту пока в
  // последнем бите экспоненты не будет 1 (в нашем безэкспонентном инте)
  for (; uxu >> 52 == 0; uxu <<= 1, ex--) {
  };

  /* scale result */
  // если экспонента положительная
  if (ex > 0) {
    // сносим старую псевдоэкспоненту
    uxu -= 1ULL << 52;

    // впиливаем обратно экспоненту
    uxu |= (unsigned long int)ex << 52;

  } else {
    uxu >>= -ex + 1;
  }

  // возвращаем знак
  uxu |= (unsigned long int)sx << 63;
  // заливаем обратно в юнион
  ux.u = uxu;
  //  возвращаем из юниона
  return ux.d;
}