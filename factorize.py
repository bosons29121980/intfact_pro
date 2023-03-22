#!/usr/local/bin/python3
from get_next_block import get_next_block
from mpmath import mp
from mpmath import zetazero
import sys

BASE = 64
def get_zero(zero_index, l):
    global BASE
    mp.prec = BASE + 2*l
    mp.dps = BASE + 2*l
    zero = str(zetazero(zero_index).imag)
    idx = zero.index(".")
    zero = zero[idx + 1:]
    return zero

def factorize(num, param, factors):
    l = len(num)
    factor = ""
    snippet = ""
    c = ""
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
                d = int(input(pp))
                if d == 0:
                    break
            print(pp)
            zero_index = zero_index + 1
