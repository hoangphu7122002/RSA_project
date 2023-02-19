#include "gen_prime.hpp"
using namespace NTL;

class RSA {
private:
	ZZ n,e,d,totient; //n is mod, e is public key, d is private key, totient is phi(N)
public:
	RSA(ZZ p, ZZ q) {
		this->n = p * q;
		this->totient = (p - ZZ(1)) * (q - ZZ(1));
		calculate_key();
	}

	ZZ getPublicKey() {
		return e;
	}

	ZZ getPrivateKey() {
		return d;
	}

	ZZ getN() {
		return n;
	}

	ZZ encrypt(ZZ M) {
		return modpowUtil1(M,e,n);
	}

	ZZ decrypt(ZZ C) {
		return modpowUtil1(C,d,n);
	}

	void calculate_key() {
		ZZ temp = this->totient - ZZ(2);
		while (true){
			this->e = RandomBnd(temp) + ZZ(2);
			if (gcdUtil1(this->e,totient) == ZZ(1)) break;
		}
		this->d = inverseUtil1(e,totient);
	}
};
