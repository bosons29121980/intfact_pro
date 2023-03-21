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
        ctr = 0
        c = ""
        while True:
            n = num[ctr]
            while True:
                c = str(f.read(l))
                if c[ctr] == n:
                   blk = c
                   break
            print(blk)
            k=int(input('get next?'))
            if k == 0:
               break
            ctr = ctr + 1
            while c[ctr] == n:
                input("same")
                ctr = ctr + 1
	f.read(2)
	f.close()
