#!/usr/local/bin/python3
import sys
import threading
from factorize import factorize

if __name__ == "__main__":
     num = str(sys.argv[1])
     prec = int(sys.argv[2])
     factors = dict([])
     factors[0] = 0
     factors[1] = 0
     t1 = threading.Thread(target=factorize, args=(num, 0, factors, prec,))
     t2 = threading.Thread(target=factorize, args=(num, 1, factors, prec,))
     t1.start()
     t2.start()
     if factors[0]*factors[1] == num:
         print(num + " = " + str(factor[0]) + " X " + str(factor[1]))
     else:
         print(num + " is a Prime Number.")
