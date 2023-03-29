#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <gmp.h>
#define MAGIC 24

char* _int_(std::string d) {
    mpz_t prod;
    mpz_init(prod);
    mpz_t sum;
    mpz_init(sum);
    mpz_set_si(sum, 0);
    mpz_set_ui(prod, 1);
    mpz_t term;
    mpz_init(term);
    for (int i = 0 ; i < d.size(); ++i) {
         mpz_mul_ui(term, prod, d[i]-'0');
         mpz_add(sum, sum, term);
         mpz_mul_ui(prod, prod, 2);
    }
    char* ret = strdup(mpz_get_str(0, 10, sum));
    mpz_clear(sum);
    mpz_clear(prod);
    mpz_clear(term);
    return ret;
}

int divides(char* num, char* f) {
     mpz_t fz;
     mpz_t nz;
     mpz_init(fz);
     mpz_init(nz);
     mpz_set_str(fz, f, 10);
     mpz_set_str(nz, num, 10);
     if (mpz_cmp_si(fz, 1) <= 0) {
           mpz_clear(fz);
           mpz_clear(nz);
           return 1;
     } else if (mpz_cmp(fz, nz) >= 0) {
           mpz_clear(fz);
           mpz_clear(nz);
           return 2;
     }
     mpz_t rm;
     mpz_init(rm);
     mpz_div(rm, nz, fz);
     if (mpz_cmp_si(rm, 0) == 0) {
         mpz_clear(rm);
         mpz_clear(fz);
         mpz_clear(nz);
         return 0;
     }
     mpz_clear(fz);
     mpz_clear(nz);
     mpz_clear(rm);
     return 1;
}

int main(int argc, char* argv[]) {
     char* num = strdup(argv[1]);
     int l = strlen(num);
     FILE* fp = fopen("./pi.dat","r");
     FILE* fe = fopen("./e.dat","r");
     int ctr = 0;
     int sum = (num[ctr] - '0') + (num[(ctr + 1) % l] - '0');
     char* buf = (char*) calloc(3, sizeof(char));
     fread(buf, 2, sizeof(char), fp);
     fread(buf, 2, sizeof(char), fe);
     int sum2 = 0;
     int pos = 0;
     std::string factor = "";
     while (1) {
        unsigned long int pos1 = ftell(fp); 
        unsigned long int pos2 = ftell(fe); 
        char pp = 0, ee = 0;
        fscanf(fp, "%c", &pp);
        fscanf(fe, "%c", &ee);
        sum2 = (pp - '0') + (ee - '0');
        fscanf(fp, "%c", &pp);
        fscanf(fe, "%c", &ee);
        sum2 = sum2 + (pp - '0') + (ee - '0');
        int sum3 = sum + sum2;
        if (sum3 == MAGIC) {
             ctr += 2;
             ctr %= l;
             sum = (num[ctr] - '0') + (num[(ctr + 1) % l] - '0');
             if (pos == 0) {
                  factor = factor + "1";
             } else {
                  factor = factor + "0";
             }
             std::string _factor_ = factor;
             char* dec = _int_(_factor_);
             int is_prime = divides(num, dec);
             if (!is_prime) {
                  printf("%s is a factor of %s.\n", dec, num);
                  break;
             } else if (is_prime == 2) {
                  printf("%s is a prime number.\n", num);
                  break;
             } 
             free(dec);
        } else {
             fseek(fp, pos1 + 1, SEEK_SET);
             fseek(fe, pos2 + 1, SEEK_SET);
        }
        pos = (pos + 1) % 3;
     }
     fclose(fp);
     fclose(fe);
     free(num);
     return 0;
}
