#include "../rsa_attack.hpp"
#include <bits/stdc++.h>
#include <cassert>
#include <NTL/ZZ.h>

using namespace NTL;
using namespace std;

int main() {
    //fermat attack
    attackRSA* attacker = new attackRSA();
    FILE* f1 = freopen("testcase/internalAttack.txt","r",stdin);
    FILE* f2 = freopen("result/internalAttack.txt","w",stdout);
    string n;
    cin >> n;
    string e;
    cin >> e;
    string d;
    cin >> d;
    string e_victim;
    cin >> e_victim;

    ZZ my_n(NTL::INIT_VAL, n.c_str());
    ZZ my_e(NTL::INIT_VAL, e.c_str());
    ZZ my_d(NTL::INIT_VAL, d.c_str());
    ZZ my_e_victim(NTL::INIT_VAL, e_victim.c_str());

    attacker->computeTotient(my_n,my_e,my_d);
    ZZ d_victim = attacker->getDvictim(my_e_victim);
    cout << "e_victim: " << my_e_victim << endl;
    cout << "d_victim: " << d_victim << endl;

    return 0;
}