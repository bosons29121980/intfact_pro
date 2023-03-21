#!/usr/local/bin/python3
import sys
import threading
from factorize import factorize

if __name__ == "__main__":
     num = str(sys.argv[1])
     factors = dict([])
     t1 = threading.Thread(target=factorize, args=(num, 0, factors,))
     t2 = threading.Thread(target=factorize, args=(num, 1, factors,))
     t1.start()
     t2.start()
     if factors[0]*factors[1] == num:
         print(num + " = " + str(factor1) + " X " + str(factor2))
     else:
         print(num + " is a Prime Number.")
