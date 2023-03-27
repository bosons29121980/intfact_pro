#!/usr/local/bin/python3
import sys
from mpmath import mp
from mpmath import zetazero

def get_zero(x):
    mp.dps = 512
    mp.prec = 512
    zero = str(zetazero(x).imag)
    idx = zero.index(".")
    zero = zero[idx + 1:]
    zero = zero[:8]
    return zero

if __name__ == "__main__":
    num = str(sys.argv[1])
    f = open("./pi.dat","r")
    g = open("./e.dat","r")
    f.read(2)
    g.read(2)
    i = 1
    nhigh = 0
    nlow = 0
    while True:
           c = f.read(8)
           d = g.read(8)
           p = 0
           q = 0
           for x in num:
              p = p + c.count(x)
              q = q + d.count(x)
           if (p + q) == 8 and p == 4:
               zero = get_zero(i)
               nr = 0
               dr = 0
               for z in list(zip(c, zero, d)):
                    if z[0] in zero:
                         nr = nr + 1
                    if z[2] in zero:
                         dr = dr + 1
               if nr == 2*dr:
                   nlow = nlow + 1
               if dr == 2*nr:
                   nhigh = nhigh + 1
               if nr == dr and (nhigh > 0 or nlow > 0):
                   input(["high", nhigh, "low", nlow])
                   nlow = 0
                   nhigh = 0
           i = i + 1
    f.close()
    g.close()
