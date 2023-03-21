#!/usr/local/bin/python3
from get_next_block import get_next_block

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
    while True:
        position, ctr = get_next_block(num, 1 - param, c, ctr)
        f.seek(position)
        while True:
            pass
