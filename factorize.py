#!/usr/local/bin/python3
from get_next_block import get_next_block

def factorize(num, param, factors):
    l = len(num)
    factor = ""
    c = ""
    ctr = 0
    while True:
        c, ctr = get_next_block(num, param, c, ctr)
