#!/usr/local/bin/python3
import sys
from mpmath import mp
from mpmath import zetazero

def get_zero(x):
    mp.dps = 256
    mp.prec = 256
    zero = str(zetazero(x).imag)
    idx = zero.index(".")
    mantissa = zero[:idx]
    zero = zero[idx + 1:]
    zero = zero[:8]
    return zero, mantissa

def get_next8(num, ctr):
    l = len(num)
    n = ""
    for x in range(0, 8):
       n = n + num[ctr % l]
       ctr = (ctr + 1) % l
    return n, ctr

if __name__ == "__main__":
    num = str(sys.argv[1])
    l = len(num)
    f = open("./pi.dat","r")
    g = open("./e.dat","r")
    f.read(2)
    g.read(2)
    i = 1
    ctr = -1
    while True:
           c = f.read(8)
           d = g.read(8)
           n, ctr = get_next8(num, ctr)
           p = 0
           q = 0
           for x in num:
              p = p + c.count(x)
              q = q + d.count(x)
           if p == q and p == 4:
               zero, mantissa = get_zero(i)
               nr = 0
               dr = 0
               for z in list(zip(c, zero, d)):
                    if z[0] in zero:
                         nr = nr + 1
                    if z[2] in zero:
                         dr = dr + 1
               if nr == 4 and nr == dr:
                   e1 = 0
                   for zz in list(zip(c, d)):
                        if (zz[0] == '7' or zz[0] == '8') and (zz[1] == '7' or zz[1] == '8'):
                              print([zz[0], zz[1]])
                              e1 = 1
                   if e1 == 1 and ctr == 0:
                        input("")
           i = i + 1
    f.close()
    g.close()
