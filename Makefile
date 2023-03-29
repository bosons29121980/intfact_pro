clean:
	-rm factorize

all:
	-g++ -g -o factorize intfact.cpp -I./ -lgmp
