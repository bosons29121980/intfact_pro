#!/usr/local/bin/python3
import sys

if __name__ == "__main__":
	num = str(sys.argv[1])
	f=open("./pi.dat","r")
	f2=open("./pi.dat","r")
	g=open("./e.dat","r")
	g2=open("./e.dat","r")
	f.read(2)
	f2.read(2)
	g.read(2)
	g2.read(2)
	l = len(num)
	nr_ctr = 0
	dr_ctr = 0
	nr_state = 1
	dr_state = 1
	while True:
	  c = str(f.read(1))
	  d = str(g.read(1))
	  if nr_state == 1:
	     p = num[nr_ctr]
	     nr_ctr = (nr_ctr + 1) % l
	  else:
	     p = str(f2.read(1))
	  e1 = 0
	  e2 = 1
	  if p == c:
	     nr_state = 1 - nr_state
	     e1 = 1
	  if dr_state == 1:
	     q = num[dr_ctr]
	     dr_ctr = (dr_ctr + 1) % l
	  else:
	     q = str(g2.read(1))
	  if q == d:
	     dr_state = 1 - dr_state
	     e2 = 1 
	  if e1 == e2 and e1 == 1:
             if nr_ctr == dr_ctr and nr_ctr == 0:
	         input([nr_state, dr_state])
	f.close()
	f2.close()
	g.close()
	g2.close()
