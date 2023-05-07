#include "rsa.hpp"
#include <bits/stdc++.h>
#include <cassert>
#include <NTL/ZZ.h>

using namespace std::chrono;
using namespace NTL;
using namespace std;

int main() {
	std::chrono::time_point<std::chrono::system_clock> start, end;
	double elapsed_seconds;
	FILE* f1 = freopen("input.txt","r",stdin);
	FILE* f2 = freopen("output.txt","w",stdout);
	int bits;
	cin >> bits;
	//cout << "BEGIN GET GO" << endl;
	genPrime* generator = new genPrime();
	start = std::chrono::system_clock::now();
	//cout << "========================" << endl;
	ZZ p = generator->getPrime(bits);
	//cout << "firstPrime DONE!" << endl;
	ZZ q = generator->getPrime(bits);
	end = std::chrono::system_clock::now();

	elapsed_seconds = duration_cast<microseconds> (end - start).count() * pow(10, -6);
	cout << "time genPrime: " << elapsed_seconds << endl;
	//cout << "secondPrime DONE!" << endl;

	start = std::chrono::system_clock::now();
	RSA* rsa_gen = new RSA(p,q);
	//cout << "debut key" << endl;
	ZZ e = rsa_gen->getPublicKey();
	ZZ d = rsa_gen->getPrivateKey();

	ZZ n = rsa_gen->getN();
	end = std::chrono::system_clock::now();
	elapsed_seconds = duration_cast<microseconds> (end - start).count() * pow(10, -6);
	cout << "time genKey: " << elapsed_seconds << endl;	

	cout << "p: " << p << "\n";
	cout << "q: " << q << "\n";
	cout << "public key - e: " << e << "\n";
	cout << "private key - d: " << d << "\n";
	cout << "n: " << n << "\n";

	ZZ m = RandomBnd(min(p,q));
	cout << "m: " << m << endl;
	ZZ c = rsa_gen->encrypt(m);
	cout << "Encrypt:" << c << "\n";
	cout << "Decrypt:" << rsa_gen->decrypt(c) << "\n";

	return 0;
}


