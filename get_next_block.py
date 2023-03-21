#!/usr/local/bin/python3
def get_next_block(num, p, pos, ctr):
    l = len(num)
    if p == 0:
        f=open("./pi.dat","r")
    else:
        f=open("./e.dat","r")
    f.read(2)
    if position > 0:
       f.seek(position)
       c = str(f.read(l))
    while True:
        n = num[ctr]
        while len(c) > 0 and c[ctr] == n:
            ctr = (ctr + 1) % l
            f.close()
            return pos, ctr, True
        while True:
            _pos_ = f.tell()
            c = str(f.read(l))
            print(c)
            if c[ctr] == n:
                ctr = (ctr + 1) % l
                f.close()
                return _pos_, ctr, False
