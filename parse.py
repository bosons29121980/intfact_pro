#!/usr/local/bin/python3
import sys
f=open("./zeros6","r")
g=open("zeros.py","w")
lines=f.readlines()
g.write("zeros=[")
for line in lines:
     print(line)
     l = line.rstrip().lstrip()
     idx = l.index(".")
     l = l[:idx]
     if line == lines[::-1]:
         g.write(str(l) + "\n")
     else:
         g.write(str(l) + ",")
g.write("]")
g.close()
f.close()
