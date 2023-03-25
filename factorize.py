#!/usr/local/bin/python3
from get_next_block import get_next_block
import sys

def factorize(num,pos):
    l = len(num)
    position1 = pos
    ctr1 = 0
    ctra = 0
    while True:
        position1, ctr1, is_the_same1 = get_next_block(num, 1, position1, ctr1, 0)
        print(position1)
        print("")
