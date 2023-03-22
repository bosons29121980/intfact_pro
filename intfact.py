#!/usr/local/bin/python3
import sys
import threading
from factorize import factorize

if __name__ == "__main__":
     num = str(sys.argv[1])
     prec = 512
     factor=factorize(num, prec)
     if factor > 0:
         print(str(factor) + " is a factor of " + str(num))  
     else:
         print(num + " is a Prime Number.")
