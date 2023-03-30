#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <gmp.h>
using namespace std;
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

int _divides_(char* num, char* f) {
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
     mpz_mod(rm, nz, fz);
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
     char* buf = (char*) calloc(3, sizeof(char));
     fread(buf, 2, sizeof(char), fp);
     fread(buf, 2, sizeof(char), fe);
     int sum = 0;
     int pos = 0;
     std::string factor = "";
     while (1) {
        char pp = 0, ee = 0;
        fscanf(fp, "%c", &pp);
        fscanf(fe, "%c", &ee);
        int _ctr_ = ctr;
        sum = (pp - '0') + (num[ctr] - '0') + (ee - '0');
        unsigned int pos1_ = ftell(fp);
        unsigned int pos2_ = ftell(fe);
        unsigned int pos1 = ftell(fp);
        unsigned int pos2 = ftell(fe);
        while (sum < MAGIC) {
              pos1 = ftell(fp);
              pos2 = ftell(fe);
              fscanf(fp, "%c", &pp);
              fscanf(fe, "%c", &ee);
              ctr = (ctr + 1) % l;
              sum = sum + (pp - '0') + (num[ctr] - '0') + (ee - '0');
        }
        if (sum == MAGIC) {
            if ((pos % 3) == 0) {
                 cout << "fits" << "\t" << pos / 3 << endl;
            } else { 
                 cout << "not fit" << "\t" << endl;
            } 
            system("a=1; read a");
            ctr = (ctr + 1) % l;
         } else {
            ctr = _ctr_;
	 }
        pos++;
	fseek(fp, pos1_, SEEK_SET);
	fseek(fe, pos2_, SEEK_SET);
     }
     fclose(fp);
     fclose(fe);
     free(num);
     return 0;
}
