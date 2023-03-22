#!/usr/local/bin/python3
from get_next_block import get_next_block
from mpmath import mp
from mpmath import zetazero
import sys
import gmpy2

def either_8_or_7(x):
    if x == '7' or x == '8':
        return True
    return False

def get_zero(zero_index, base):
    mp.prec = base
    mp.dps = base
    zero = str(zetazero(zero_index).imag)
    idx = zero.index(".")
    zero = zero[idx + 1:]
    return zero

def divides(num, d):
    nz = gmpy2.mpz(num)
    dz = gmpy2.mpz(d)
    if dz <= gmpy2.mpz("1"):
         return False, True
    if dz >= nz:
         return False, False
    r = gmpy2.f_mod(nz, dz)
    if r == 0:
         return True, True
    return False, True
    
def factorize(num, param, factors, base):
    l = len(num)
    factor = ""
    snippet = ""
    ctr = 0
    if param == 0:
        f = open("./e.dat", "r")
    else:
        f = open("./pi.dat", "r")
    f.read(2)
    position = 0
    zero_index = 1
    while True:
        position, ctr, is_the_same = get_next_block(num, 1 - param, position, ctr)
        if is_the_same == 1:
            zero_index = zero_index + 1
            factor = factor + snippet
            continue
        else:
            snippet = ""
            f.seek(position)
            zero = get_zero(zero_index, base)
            cnt = 0
            z = len(zero)
            n87 = 0
            while True:
                c = str(f.read(1))
                d = zero[cnt]
                cnt = cnt + 1
                if cnt >= z:
                    print("Out of Precision Exception !!")
                    sys.exit(2)
                b87c = either_8_or_7(c)
                b87d = either_8_or_7(d)
                if  b87c == True and  b87d == True:
                    if c == '8' and d == '7' and n87 > 0:
                        snippet = str(bin(n87)[2:]) 
                        if param == 1:
                            factor = factor + snippet[::-1]
                        else:
                            factor = factor + snippet
                        if param == 0:
                            decimal = int(factor[::-1], 2)
                            decision, possible = divides(num, decimal)
                            if decision == True: 
                                 factors[param] = decimal
                                 f.close()
                                 return
                            elif possible == False:
                                 factors[param] = 0
                                 f.close()
                                 return
                        elif param == 1:
                           decimal = int(factor, 2)
                           if decimal == int(num):
                               factors[param] = decimal
                               f.close()
                               return
                           elif decimal > int(num):
                               factors[param] = 0
                               f.close()
                               return
                        input(["param", param, "factor", factor, "n87", n87, "ctr", ctr])
                    break
                elif b87c == True:
                    n87 = n87 + 1 
            zero_index = zero_index + 1
