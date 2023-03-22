#!/usr/local/bin/python3
import sys
import threading
from factorize import factorize

if __name__ == "__main__":
     num = str(sys.argv[1])
     factors = dict([])
     factors[0] = 0
     factors[1] = 0
     prec = 256
     t1 = threading.Thread(target=factorize, args=(num, 0, factors, prec,))
     t2 = threading.Thread(target=factorize, args=(num, 1, factors, prec,))
     t1.start()
     t2.start()
     t1.join()
     t2.join()
     input(["factor0", factors[0], "factor1", factors[1]])
     if factors[1] == int(num):
         print(str(factors[0]) + " is a factor of " + str(num))  
     else:
         print(num + " is a Prime Number.")
