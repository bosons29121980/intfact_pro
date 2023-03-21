#!/usr/local/bin/python3
from get_next_block import get_next_block
from mpmath import mp
from mpmath import zetazero
import sys
import gmpy2

BASE = 64
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
    else:
          return False, True

def get_zero(zero_index, l):
    global BASE
    mp.prec = BASE + 2*l
    mp.dps = BASE + 2*l
    zero = str(zetazero(zero_index).imag)
    idx = zero.index(".")
    zero = zero[idx + 1:]
    return zero

def match(pp, zero_index):
    l = len(pp)
    nmatches = 0
    zero = get_zero(zero_index, l)
    input(["zero index", zero_index])
    for z in list(zip(pp, zero)):
          input(["z0", z[0], "z1", z[1], "nmatches", nmatches])
          if z[1] == '' or len(z[1]) == 0:
              print("Insufficient Precision Supplied")
              sys.exit(2)
          if z[0] == z[1]:
              nmatches = nmatches + 1 
    if nmatches > 0:
        return str(bin(nmatches)[2:])[::-1]
    else:
        return ""

def factorize(num, param, factors):
    l = len(num)
    factor = ""
    snippet = ""
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
    zero_index = 1
    while True:
        position, ctr, is_the_same = get_next_block(num, 1 - param, position, ctr)
        input(["position", position, "ctr", ctr, "is the same", is_the_same]) 
        if is_the_same == 1:
            zero_index = zero_index + 1
            factor = factor + snippet
            continue
        else:
            f.seek(position)
            pp = ""
            while True:
                c = str(f.read(1))
                pp = pp + c
                d = str(g.read(1))
                if c == d:
                    break
            print(pp)
            snippet = match(pp, zero_index)
            input(["zero index", zero_index, "snippet", snippet])
            factor = factor + snippet
            if len(factor) > 0 and factor != "":
                dec = int(factor[::-1], 2)
                decision, is_possible = divides(num, dec)
                if decision == True:
                    return dec, ctr
                elif decision == False and is_possible == False:
                    return 0, ctr
                zero_index = zero_index + 1
