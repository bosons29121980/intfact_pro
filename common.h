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

char* _int_(std::string factor) {
    mpz_t sum;
    mpz_init(sum);
    mpz_t prod;
    mpz_init(prod);
    mpz_set_si(sum, 0);
    mpz_set_ui(prod, 1);
    mpz_t term;
    mpz_init(term);
    for (int i = 0; i < factor.size(); ++i) {
        mpz_mul_ui(term, prod, factor[i]-'0');
        mpz_add(sum, sum, term);
        mpz_mul_ui(prod, prod, 2);
    }
    char* ret = strdup(mpz_get_str(0, 10, sum));
    mpz_clear(sum);
    mpz_clear(prod);
    mpz_clear(term);
    return ret;
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
