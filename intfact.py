#!/usr/local/bin/python3
import sys

if __name__ == "__main__":
    num = str(sys.argv[1])
    l = len(num)
    p = int(sys.argv[2])
    if p == 0:
        f=open("./pi.dat","r")
    else:
        f=open("./e.dat","r")
    f.read(2)
    ctr = 0
    c = ""
    while True:
        n = num[ctr]
        while True:
            c = str(f.read(l))
            print(c)
            if c[ctr] == n:
                break
        k=int(input('get next?'))
        if k == 0:
            break
        ctr = (ctr + 1) % l
        n = num[ctr]
        while c[ctr] == n:
            print(c)
            input("same")
            ctr = (ctr + 1) % l
    f.read(2)
    f.close()
