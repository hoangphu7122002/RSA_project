rsa:
	g++ -g -O2 -pthread -march=native main.cpp -o main.o -lntl -lgmp -lm
	./main.o
	rm main.o
fermatAttack:
	g++ -g -O2 -pthread -march=native fermatAttack.cpp -o main.o -lntl -lgmp -lm
	./main.o
	rm main.o
externalAttack:
	g++ -g -O2 -pthread -march=native externalAttack.cpp -o main.o -lntl -lgmp -lm
	./main.o
	rm main.o
internalAttack:
	g++ -g -O2 -pthread -march=native internalAttack.cpp -o main.o -lntl -lgmp -lm
	./main.o
	rm main.o
broadcastAttack:
	g++ -g -O2 -pthread -march=native broadcastAttack.cpp -o main.o -lntl -lgmp -lm
	./main.o
	rm main.o