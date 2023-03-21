#!/usr/local/bin/python3
from get_next_block import get_next_block
from mpmath import mp
from mpmath import zetazero
import sys
import gmpy2

def divides(num, d):
    nz = gmpy2.mpz(num)
    dz = gmpy2.mpz(d)
    if dz <= gmpy2.mpz("1"):
         return False, True
    if dz >= nz:
         return False, False
    r = gmpy2.f_mod(nz, dz)
    if r == gmpy2.mpz('0'):
          return True, True

def get_zero(zero_index, l):
    mp.prec = 2*l
    mp.dps = 2*l
    zero = str(zetazero.imag(zero_index))
    idx = zero.index(".")
    zero = zero[idx + 1:]
    return zero

def match(pp, zero_index):
    l = len(pp)
    nmatches = 0
    zero = get_zero(zero_index, l)
    for z in list(zip(pp, zero)):
          if z[1] == '' or len(z[1]) == 0:
              print("Insufficient Precision Supplied")
              sys.exit(2)
          if z[0] == z[1]:
              nmatches = nmatches + 1 
    return str(bin(nmatches)[2:])[::-1]

def factorize(num, param, factors):
    l = len(num)
    factor = ""
    c = ""
    ctr = 0
    if param == 0:
        f = open("./e.dat", "r")
        g = open("./pi.dat","r")
    else:
        f = open("./pi.dat", "r")
        g = open("./e.dat", "r")
    f.read(2)
    g.read(2)
    position = 0
    while True:
        position, ctr, is_the_same = get_next_block(num, 1 - param, position, ctr)
        if is_the_same == 1:
            zero_index = zero_index + 1
            continue
        else:
            f.seek(position)
            pp = ""
            while True:
                c = str(f.read(1))
                pp = pp + "c"
                d = str(g.read(1))
                if c == d:
                    break
            snippet = match(pp, zero_index)
            factor = factor + snippet
            dec = int(factor[::-1], 2)
            decision, is_possible = divides(num, dec) == True:
            if decision == True:
                  return dec, ctr
            elif decision == False and is_possible == True:
                  return 0, ctr
            zero_index = zero_index + 1
