rsa:
	g++ -g -O2 -pthread -march=native main.cpp -o main.o -lntl -lgmp -lm
	./main.o
	rm main.o
