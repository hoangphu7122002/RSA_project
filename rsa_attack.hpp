#include "gen_prime.hpp"
#include <bits/stdc++.h>

struct pairAM{
	ZZ a,m;
	pairAM(ZZ a, ZZ m) {
		this->a = a;
		this->m = m;
	}
	pairAM(const pairAM& a1) {
		this->a = a1.a;
		this->m = a1.m;
	}
};

struct pairEC{
	ZZ e,c;
	pairEC(ZZ e, ZZ c) {
		this->e = e;
		this->c = c;
	}
};

class attackRSA{
private:
	ZZ n,p,q,e,d,M,totient;
	genPrime* testPrime;
public:
	attackRSA() : n(-1),p(-1),q(-1),e(-1),d(-1),M(-1),totient(-1){
		testPrime = new genPrime();
	}

	void reset() {
		n = -1;
		p = -1;
		q = -1;
		e = -1;
		d = -1;
		M = -1;
		totient = -1;
	}
	//method to find
	//small n, n < 10^9, n has 32, 64 bits
	void getPQ(int n){
		int minPrime[(ll)1e9 + 1];
		for (int i = 2; i * i <= n; ++i)
			for (int j = i * i; j <= n; j += i)
       	if (minPrime[j] == 0) minPrime[j] = i;

		for (int i = 2; i <= n; ++i)
    	if (minPrime[i] == 0)
        minPrime[i] = i;
		vector<int> res;
		while (n != 1) {
			res.push_back(minPrime[n]);
			n /= minPrime[n];
		}
		if (res.size() != 2) cout << "FAIL\n";
		else {
			p = res[0];
			q = res[1];
			cout << "SUCCESS\n";
		}
	}

	//p,q close: abs(p - q) < n^1/4
	void fermat(ZZ n) {
		ZZ a = square_root(n);
		ZZ b2 = a*a - n;
		ZZ b = a;
		while (b * b != b2) {
			a = a + 1;
			b2 = a * a - n;
			b = square_root(b2);
		}
		p = a + b;
		q = a - b;
		assert(n == p * q);
		// assert(testPrime->test_prime(p,10)==1);
		// assert(testPrime->test_prime(q,10)==1);
		cout << "Success\n" << endl;
	}

	//same e, diff a, diff m (same e, diff n, c)
	//a^e === a1 (mod m1)
	//a^e === a2 (mod m2)
	//a^e === a3 (mod m3)
	//=> use crt method

	void crt(const ZZ& e, const vector<pairAM>& info) {
		ZZ M = ZZ(1);
		for (auto& inf: info){
			M *= inf.m;
		}

		ZZ ae = ZZ(0);
		for (auto& inf: info){
			ZZ a_i = inf.a;
			ZZ M_i = M / inf.m;
			ZZ N_i = inverseUtil1(M_i,inf.m);
			ae = (ae + a_i * M_i % M * N_i % M) % M;
		}
		assert(gcdUtil1(ae,info[0].m) == 1);
		//solve problem: a^e === a1 (mod m1) to find a)
		ZZ a1 = discreteLog(ae,info[0].a,info[0].m);
		ZZ a2 = discreteLog(ae,info[1].a,info[1].m);
		assert(a1 == a2);
		this->M = a1;
	}

	//has n,e,d => to compute totient, give e_victim => d_victime
	void computeTotient(ZZ n, ZZ e, ZZ d){
		ZZ k = (e * d - 1) / n;
		ZZ tot = ZZ(1);
		while(true){
			tot = (e * d - 1)/k;
			if (tot * k == e * d - 1)	break;
			k += 1;
		}
		this->totient = tot;
	}

	ZZ getDvictim(ZZ e_victim){
		assert(gcdUtil1(e_victim,this->totient) == 1);
		ZZ dVictim = inverseUtil1(e_victim,this->totient);
		return dVictim;
	}

	//has same n, different e,c
	void external_attack(ZZ n, pairEC info1, pairEC info2) {
		//use 2 info
		ZZ e1 = info1.e;
		ZZ e2 = info2.e;
		ZZ c1 = info1.c;
		ZZ c2 = info2.c;

		ZZ u,v;
		ZZ d = extendedGcd(e1,e2,u,v);
		if (u < 0){
			ZZ c1_inv = inverseUtil1(c1,n);
			M = (modpowUtil1(c1_inv,-u,n) * modpowUtil1(c2,v,n) % n);
		}
		else {
			ZZ c2_inv = inverseUtil1(c2,n);
			M = (modpowUtil1(c2_inv,-v,n) * modpowUtil1(c1,u,n) % n);
		}
	}

	//getMethod
	ZZ getP() {return p;}
	ZZ getQ() {return q;}
	ZZ getN() {return n;}
	ZZ getPublicKey() {return e;}
	ZZ getPrivateKey() {return d;}
	ZZ getTotient() {return totient;}
	ZZ getM() {return M;}
};
