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

zeros_hash = dict([])
def get_zero(zero_index, base):
    global zeros_hash
    if zero_index in zeros_hash:
       return zeros_hash[zero_index]
    else:
       mp.prec = base
       mp.dps = base
       zero = str(zetazero(zero_index).imag)
       idx = zero.index(".")
       zero = zero[idx + 1:]
       zeros_hash[zero_index] = zero
       return zero

def factorize(num, base):
    l = len(num)
    snippet1 = ""
    snippet2 = ""
    ctr1 = 0
    ctr2 = 0
    f1 = open("./e.dat", "r")
    f1.read(2)
    f2 = open("./pi.dat", "r")
    f2.read(2)
    position1 = 0
    zero_index1 = 1
    position2 = 0
    zero_index2 = 1
    c = ""
    z = ""
    while True:
        position1, ctr1, is_the_same1 = get_next_block(num, 1, position1, ctr1)
        position2, ctr2, is_the_same2 = get_next_block(num, 0, position2, ctr2)
        print("")
        print("")
        if is_the_same1 == 1:
            zero_index1 = zero_index1 + 1
            zero = get_zero(zero_index1, base)
            z = zero[ctr1]
            input(["1",c, z])
            continue
        else:
            snippet1 = ""
            f1.seek(position1)
            zero = get_zero(zero_index1, base)
            cnt = 0
            c = str(f1.read(l))[ctr1]
            z = zero[ctr1]
            input(["1",c, z])
            zero_index1 = zero_index1 + 1
        if is_the_same2 == 1:
            zero_index2 = zero_index2 + 1
            zero = get_zero(zero_index2, base)
            z = zero[ctr1]
            input(["2",c, z])
            continue
        else:
            snippet2 = ""
            f2.seek(position2)
            zero = get_zero(zero_index2, base)
            cnt = 0
            c = str(f1.read(l))[ctr2]
            z = zero[ctr2]
            input(["2", c, z])
            zero_index2 = zero_index2 + 1
