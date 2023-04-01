#ifndef __FACTORIZE__
#define __FACTORIZE__
#include "common.h"
#include "zeros.h"
#include "zeros2.h"
#include <string>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
const int MAGIC = 24;
const int PART_MAGIC = 12;
const int START = 2;
const int PART = 8;
const int MAGIC2 = 3;
int zero_count[2];

void* factorize(void* arg) {
	struct func_arg* a = (struct func_arg*) arg;
        pthread_mutex_t lock;
        pthread_mutex_init(&lock, NULL);
	char* num = a->num;
	unsigned long long int l = strlen(num);
	int param = a->param;
	FILE* fp = 0, *fe = 0;
	if (param) {
		fp = fopen("./pi.dat", "r");
		fe = fopen("./e.dat", "r");
	} else {
		fp = fopen("./e.dat", "r");
		fe = fopen("./pi.dat", "r");
	}
	char* buf = (char*) calloc(3, sizeof(char));
	fread(buf, 2, sizeof(char), fp);
	fread(buf, 2, sizeof(char), fe);
	free(buf);
	std::string factor = "";
	unsigned long long int ctr = 0;
	char* ret = 0;
	char pp = 0, ee = 0;
	fscanf(fp, "%c", &pp);
	char n = num[ctr % l];
	fscanf(fe, "%c", &ee);
	int sum = (pp - '0') + (n - '0') + (ee - '0');
	++ctr;
	while (1) {
		char pp2 = 0, ee2 = 0;
		fscanf(fp, "%c", &pp2);
		char n2 = num[ctr % l];
		fscanf(fe, "%c", &ee2);
		int sum2 = (pp2 - '0') + (n2 - '0') + (ee2 - '0'); 
		sum += sum2; 
		if (sum == MAGIC && sum2 == PART_MAGIC) {
			if ((ctr + 1) % PART == 0) {
				pthread_t x = pthread_self();
                                double frac1 = zeros[ctr-1] - ((long) zeros[ctr-1]);
                                double frac2 = zeros[ctr] - ((long) zeros[ctr]);
                                char* frac_string1 = (char*) calloc(10, sizeof(char));
                                char* frac_string2 = (char*) calloc(10, sizeof(char));
                                sprintf(frac_string1, "%.8lf", frac1);
                                sprintf(frac_string2, "%.8lf", frac2);
                                ++frac_string1;
                                ++frac_string2;
                                int nzeros = 0;
                                for (int i = 0; i < 8; ++i) {
                                     char ss[3];
                                     ss[0] = frac_string1[i];
                                     ss[1] = frac_string2[i];
                                     ss[2] = '\0';
                                     int ret = binarySearch(zeros2, atoi(ss), 0, 28);
                                     if (ret > -1) {
                                          nzeros = nzeros + 1;
                                     }
                                }
                                pthread_mutex_lock(&lock);
                                zero_count[param] = nzeros;
                                pthread_mutex_unlock(&lock);
                                while (zero_count[0] == -1 || zero_count[1] == -1) {
                                    sleep(2);
                                }
                                if (zero_count[0] == zero_count[1] && zero_count[0] == MAGIC2) { 
				printf("pid %p\tpp %c n %c ee %c\n", x, pp, n, ee);
				printf("pid %p\tpp2 %c n2 %c ee %c\n", x, pp2, n2, ee2);
                                printf("pid %p nzeros %d\n", x, nzeros);
       }
                                zero_count[0] = zero_count[1] = -1;
				ctr++;
				fseek(fe, START,  SEEK_SET);
				fscanf(fp, "%c", &pp);
				n = num[ctr % l];
				fscanf(fe, "%c", &ee);
				sum = (pp - '0') + (n - '0') + (ee - '0');
		                system("a=1;read a");
			} else {
				sum = sum2;
			}
		} else {
			sum = sum2;
                        n = n2;
                        pp = pp2;
                        ee = ee2;
		}
		ctr++; 
	}
	fclose(fp);
	fclose(fe);
	return ret;
}
#endif
