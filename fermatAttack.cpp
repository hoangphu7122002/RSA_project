#include "rsa_attack.hpp"
#include <bits/stdc++.h>
#include <cassert>
#include <NTL/ZZ.h>

using namespace NTL;
using namespace std;

int main() {
    //fermat attack
    attackRSA* attacker = new attackRSA();
    FILE* f1 = freopen("testcase/fermatAttack.txt","r",stdin);
    FILE* f2 = freopen("result/fermatAttack.txt","w",stdout);
    string n;
    cin >> n;
    ZZ my_n(NTL::INIT_VAL, n.c_str());
    attacker->fermat(my_n);
    cout << "P: " << attacker->getP() << endl;
    cout << "Q: " << attacker->getQ() << endl;

    return 0;
}