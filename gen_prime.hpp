#include "util.hpp"
#include <NTL/ZZ.h>
#include <bits/stdc++.h>

using namespace NTL;
using namespace std;

#define ll long long

class genPrime{
private:
	vector<ZZ>primes;
public:
	genPrime() {
		ll maxN = 1e7;
		primes.push_back(ZZ(2));
		vector<bool> is_prime(maxN + 1,1);
		is_prime[0] = is_prime[1] = false;
		for (int i = 3; i * i <= maxN; i += 2) {
			if (is_prime[i]) {
				primes.push_back(ZZ(i));
				for (int j = i * i; j <= maxN; j += i) is_prime[j] = false;
			}
		}
	}

	ZZ getPrime(int bits) {
		ZZ MAX, MIN, gen;
		MAX = powerUtil1(ZZ(2),ZZ(bits));
		MIN = powerUtil1(ZZ(2),ZZ(bits - 1));
		while (true) {
			gen = RandomBnd(MAX);
			if (gen < MIN) continue;
			//cout << gen << endl;
			if (test_prime(gen)) {
				//cout << "BREAK HERE" << endl;
				break;
			}
		}
		return gen;
	}

	bool test_prime(const ZZ& gen,int n_iter = 100) {
		for (ZZ& p : primes) if (gen != p && gen % p == 0) return false;
		//decompose gen
		int s = 0;
		ZZ d = gen - ZZ(1);
		//gen - 1 = 2^s * d;
		while ((d & 1) == 0) {
			d >>= 1;
			s++;
			//cout << "<<<<<>>>>>" << endl;
		}
		//cout << "<<>>" << endl;
		for (int i = 0; i < n_iter; ++i)
			if (!rabin_miller(gen,s,d)) return false;
		return true;
	}

	bool rabin_miller(const ZZ& gen,const int& s,const ZZ& d) {
		ZZ N1 = gen - ZZ(1);
		ZZ a = RandomBnd(gen - ZZ(2)) + ZZ(2);
		if (gcdUtil1(a,gen) != 1) return false;
		if (modpowUtil1(a,N1,gen) != 1) return false;
		ZZ b0, b1;
		b0 = modpowUtil1(a, d, gen); //a^d mod gen
		if (b0 == 1) return true;
		int i = 1;
		while (i <= s) {
			b1 = (b0 * b0) % gen;
			if (b1 == 1) {
				//is the smallest bi == 1 mode N => b[i - 1] == n - 1 (mode N)
				if (b0 == N1) return true;
				return false;
			}
			i++;
		}
		return false;
	}

	vector<ZZ> getPrimes(){return this->primes;}
};
