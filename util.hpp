#include <NTL/ZZ.h>
#include <bits/stdc++.h>
#include <cassert>

using namespace std;
using namespace NTL;

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
		x = n;
		y = (x + n/x)/2;
	}
	return n;
}

//O(sqrt(M))
ZZ discreteLog(ZZ a,ZZ b,ZZ m){
		a %= m;
		b %= m;

		ZZ n = sqrt(m) + 1;
		ZZ an = modPowUtil1(a,n,m);
		unordered_map<ZZ,ZZ>vals;
		for (ZZ q = 0, cur = b; q <= n; ++q){
			vals[cur] = q;
			cur = (cur * a) % m;
		}

		for (ZZ p = 1, cur = 1; p <= n; ++p){
			cur = (cur * an) % m;
			if (vals.count(cur)) {
				ZZ ans = n * p - vals[cur];
				return ans;
			}
		}
		return -1;
}
