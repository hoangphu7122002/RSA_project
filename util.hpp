#include <NTL/ZZ.h>
#include <bits/stdc++.h>
#include <cassert>
#include <cstring>

using namespace std;
using namespace NTL;

std::string zToString(const ZZ &z) {
    std::stringstream buffer;
    buffer << z;
    return buffer.str();
}

struct ZZHash {
    size_t operator()(const NTL::ZZ& key) const {
        return std::hash<std::string>()(strdup(zToString(key).c_str()));
    }
};

struct ZZEqual {
    bool operator()(const NTL::ZZ& lhs, const NTL::ZZ& rhs) const {
        return lhs == rhs;
    }
};

ZZ gcdUtil1(ZZ a, ZZ b) {
	while (b != 0) {
		a %= b;
		swap(a,b);
	}
	return a;
}

//a^b mod M
ZZ modpowUtil1(ZZ a, ZZ b, ZZ M) {
	a %= M;
	ZZ res = ZZ(1);
	while (b > 0) {
		if (b % 2 == 1) res = (res * a) % M;
		a = (a * a) % M;
		b >>= 1;
	}
	return res;
}

//a^b
ZZ powerUtil1(ZZ a,ZZ b) {
	ZZ res = ZZ(1);
	while (b > 0) {
		if (b % 2 == 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

//ax + by = gcd
ZZ extendedGcd(ZZ a, ZZ b, ZZ &x, ZZ &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ZZ x1, y1;
	ZZ d = extendedGcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

//a * a^-1 == 1 (mod b), find a^-1
ZZ inverseUtil1(ZZ a, ZZ b) {
	ZZ x, y;
	ZZ g = extendedGcd(a,b,x,y);
	assert(g == 1);
	return (x % b + b) % b;
}

//============attack RSA helper function================
//Heron method to compute sqr: x[n+1] = 1/2(x[n] + S/x[n]); x[0] = S;
ZZ square_root(ZZ n) {
	ZZ x = n;
	ZZ y = (x + n/x)/2;
	while (y < x) {
		x = y;
		y = (x + n/x)/2;
		// cout << x << " " << y << endl;
	}
	return x;
}

//O(sqrt(M))
ZZ discreteLog(ZZ a,ZZ b,ZZ m){
		a %= m;
		b %= m;

		ZZ n = square_root(m) +ZZ(1);
		cout << "=======" << endl;
		ZZ an = modpowUtil1(a,n,m);
		cout << "!!!!SSS!!!" << endl;
		unordered_map<ZZ,ZZ,ZZHash, ZZEqual>vals;
		for (ZZ q = ZZ(0), cur = b; q <= n; ++q){
			vals[cur] = q;
			cur = (cur * a) % m;
		}
		cout << "<<>>" << endl;
		for (ZZ p = ZZ(1), cur = ZZ(1); p <= n; ++p){
			cur = (cur * an) % m;
			if (vals.count(cur)) {
				ZZ ans = n * p - vals[cur];
				return ans;
			}
		}
		cout << "!!!!!!!!!!!!!" << endl;
		return ZZ(-1);
}
