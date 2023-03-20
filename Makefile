clean:
	-rm factorize

all:
	-g++ -o factorize intfact.cpp -I./ -lgmp -lpthread
