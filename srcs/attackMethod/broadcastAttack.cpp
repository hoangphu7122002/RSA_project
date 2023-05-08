#include <NTL/ZZ.h>
#include <bits/stdc++.h>

#include <cassert>

#include "../rsa_attack.hpp"

using namespace NTL;
using namespace std;

int main() {
    attackRSA* attacker = new attackRSA();
    FILE* f1 = freopen("testcase/crt.txt", "r", stdin);
    FILE* f2 = freopen("result/broadcastAttack.txt", "w", stdout);
    string e;
    cin >> e;
    string n1;
    cin >> n1;
    string n2;
    cin >> n2;
    string n3;
    cin >> n3;
    string c1;
    cin >> c1;
    string c2;
    cin >> c2;
    string c3;
    cin >> c3;
    ZZ my_e(NTL::INIT_VAL, e.c_str());
    ZZ my_n1(NTL::INIT_VAL, n1.c_str());
    ZZ my_n2(NTL::INIT_VAL, n2.c_str());
    ZZ my_n3(NTL::INIT_VAL, n3.c_str());
    ZZ my_c1(NTL::INIT_VAL, c1.c_str());
    ZZ my_c2(NTL::INIT_VAL, c2.c_str());
    ZZ my_c3(NTL::INIT_VAL, c3.c_str());
    vector<pairAM> pairLst;
    pairAM pair1(my_c1, my_n1);
    pairAM pair2(my_c2, my_n2);
    pairAM pair3(my_c3, my_n3);
    pairLst.push_back(pair1);
    pairLst.push_back(pair2);
    pairLst.push_back(pair3);

    attacker->crt(my_e, pairLst);

    cout << "e: " << my_e << endl;
    cout << "M^e: " << attacker->getM() << endl;
    return 0;
}