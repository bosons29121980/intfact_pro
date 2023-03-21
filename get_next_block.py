#!/usr/local/bin/python3
def get_next_block(num, p, c, ctr):
    l = len(num)
    if p == 0:
        f=open("./pi.dat","r")
    else:
        f=open("./e.dat","r")
    f.read(2)
    while True:
        n = num[ctr]
        while len(c) > 0 and c[ctr] == n:
            ctr = (ctr + 1) % l
            f.close()
            return c, ctr
        while True:
            c = str(f.read(l))
            print(c)
            if c[ctr] == n:
                ctr = (ctr + 1) % l
                f.close()
                return c, ctr
