#include "../rsa_attack.hpp"
#include <bits/stdc++.h>
#include <cassert>
#include <NTL/ZZ.h>

using namespace NTL;
using namespace std;

int main() {
    //fermat attack
    attackRSA* attacker = new attackRSA();
    FILE* f1 = freopen("testcase/externalAttack.txt","r",stdin);
    FILE* f2 = freopen("result/externalAttack.txt","w",stdout);
    string n;
    cin >> n;
    string e1; cin >> e1;
    string e2; cin >> e2;
    string c1; cin >> c1;
    string c2; cin >> c2;

    ZZ my_n(NTL::INIT_VAL, n.c_str());
    ZZ my_e1(NTL::INIT_VAL, e1.c_str());
    ZZ my_e2(NTL::INIT_VAL, e2.c_str());
    ZZ my_c1(NTL::INIT_VAL, c1.c_str());
    ZZ my_c2(NTL::INIT_VAL, c2.c_str());
    pairEC pair1(my_e1,my_c1);
    pairEC pair2(my_e2,my_c2);

    attacker->external_attack(my_n, pair1, pair2);
    cout << "M: " << attacker->getM() << endl;

    return 0;
}