#ifndef __COMMON__
#define __COMMON__
#include <stdlib.h>
#include <gmp.h>
#include <string.h>
#include <string>

struct func_arg {
    char* num;
    int param;
};

int binarySearch(int array[], int x, int low, int high) {
  // Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }
  return -1;
}

int _divides_(char* num, char* f) {
    mpz_t nz;
    mpz_init(nz);
    mpz_t fz;
    mpz_init(fz);
    mpz_set_str(nz, num, 10);
    mpz_set_str(fz, f, 10);
    if (mpz_cmp_si(fz, 1) <= 0) {
           mpz_clear(nz);
           mpz_clear(fz);
           return 1;
    }
    if (mpz_cmp(fz, nz) >= 0) {
           mpz_clear(nz);
           mpz_clear(fz);
           return 2;
    }
    mpz_t r;
    mpz_init(r);
    mpz_mod(r, nz, fz);
    mpz_clear(nz);
    mpz_clear(fz);
    if (mpz_cmp_si(r, 0) == 0) {
          mpz_clear(r);
          return 0;
    }
    mpz_clear(r);
    return 1;
}
#endif
