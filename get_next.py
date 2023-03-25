#!/usr/local/bin/python3
import sys

if __name__ == "__main__":
    param = int(sys.argv[1])
    f = ""
    if param == 1:
       f = open("./pi.dat","r")
    else:
       f = open("./e.dat","r") 
    f.read(2)
    while True:
       k = int(input("get next?"))
       if k == 1:
           c = f.read(8)
           print(c)
       else:
           break
    f.close()
