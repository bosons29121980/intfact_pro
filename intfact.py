#!/usr/local/bin/python3
import sys
import threading
from factorize import factorize

if __name__ == "__main__":
     num = str(sys.argv[1])
     ctr = 0
     t1 = threading.Thread(target=factorize, args=(num, 0,))
     t2 = threading.Thread(target=factorize, args=(num, 1,))
     t1.start()
     t2.start()
     factor1 = t1.join()
     factor2 = t2.join()
      
