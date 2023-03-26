#!/usr/local/bin/python3
import sys

if __name__ == "__main__":
    f = open("./pi.dat","r")
    g = open("./e.dat","r")
    f.read(2)
    g.read(2)
    while True:
       k = input("get next?")
       if k=="" or int(k) == 1:
           c = f.read(8)
           d = g.read(8)
           print(c)
           print(d)
       else:
           break
    f.close()
    g.close()
