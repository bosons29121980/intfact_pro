#!/usr/local/bin/python3
g=open("./e.dat","r")
f=open("./e.txt","w")
for x in range(0, 1000000):
    f.write(g.read(1))
g.close()
f.close()
