#include "rsa.hpp"
#include <bits/stdc++.h>
#include <cassert>
#include <NTL/ZZ.h>

using namespace NTL;
using namespace std;
using namespace std::chrono;

string convertString(ZZ num) {
    NTL::ZZ newNum = ZZ(0);
    string res = "";
    while (num > 0) {
        NTL::ZZ digit = num % ZZ(1000);
        num /= ZZ(1000);
        int tempNum = conv<int>(digit);
        res = static_cast<char>(tempNum) + res; 
    }

    return res;
}


int main() {
	FILE* f1 = freopen("genText/res.txt","r",stdin);
	// FILE* f2 = freopen("output.txt","w",stdout);
	int bits;
	cin >> bits;
	//cout << "BEGIN GET GO" << endl;
	genPrime* generator = new genPrime();
	//cout << "========================" << endl;
	ZZ p = generator->getPrime(bits);
	//cout << "firstPrime DONE!" << endl;
	ZZ q = generator->getPrime(bits);
	//cout << "secondPrime DONE!" << endl;

	RSA* rsa_gen = new RSA(p,q);
	//cout << "debut key" << endl;
	ZZ e = rsa_gen->getPublicKey();
	ZZ d = rsa_gen->getPrivateKey();

	ZZ n = rsa_gen->getN();

	// cout << "p: " << p << "\n";
	// cout << "q: " << q << "\n";
	// cout << "public key - e: " << e << "\n";
	// cout << "private key - d: " << d << "\n";
	// cout << "n: " << n << "\n";
    string my_m;
    cin >> my_m;
    
	std::chrono::time_point<std::chrono::system_clock> start, end;
	double elapsed_seconds;

	ZZ m(NTL::INIT_VAL, my_m.c_str());;
	cout << "m: " << m << endl;
	start = std::chrono::system_clock::now();
	ZZ c = rsa_gen->encrypt(m);
    ZZ text_descrypt = rsa_gen->decrypt(c);
	// cout << "Encrypt:" << c << "\n";
	// cout << "Decrypt:" << text_descrypt << "\n";
	end = std::chrono::system_clock::now();

	elapsed_seconds = duration_cast<microseconds> (end - start).count() * pow(10, -6);
	cout << "time Encrypt Decrypt Process: " << elapsed_seconds << endl;
    cout << "Message:" << convertString(text_descrypt) << "\n";
	return 0;
}


