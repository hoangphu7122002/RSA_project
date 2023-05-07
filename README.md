# RSA_project

Install [NTL library](https://libntl.org/doc/tour-unix.html) on your machine. if you don't use visual studio to compile, you can use wsl and virtual machine to compile with vscode 

### Usecases
* Implement program takes the number of bits for the prime numbers as input (from input.txt), generates two prime numbers (observer thourgh output.txt), and uses them to create an RSA encryption. [1]
* Test encrypt and decrypt with keys from the RSA algorithm via a text message. [2]
* Implement a few common rsa attacks such as an external attack, internal attack, broadcast attack, and fermat attack on a case-by-case basis. [3]
* Implement from scratch some arithmetic related algorithms such as: power_mod, gcd, euler_gcd, chinese_remainder_theorem, rabin_miller test, ... to assist in the problem of the topic.

### Usecase [1] encrypt/decrypt with RSA algorithm
#### Input file (write in input.txt):
     one line: number of bits of prime number you want to generate (example: 512, 1024)
#### Run thourgh makefile:
     make rsa
#### Output has some information such as (observer thourgh output.txt):
     - first frime number (p)
     - second frime number (q)
     - public key (e)
     - private key (d)
     - product of p,q (n)
     - message random (m)
     - encrypt of message (Encrypt)
     - decrypt of message (Decrypt)
#### File source:
```bash
── Makefile
── input.txt
── main.cpp
── output.txt
```

### Usecase [2] test encrypt/decrypt through message input from the user
#### Input file (write in genText/text.txt):
     You enter the text message you want to be decoded for example "Hello, I'm Nguyen Dac Hoang Phu" into this file
     Then run the file asciiToText.py in the same directory, the output will be file: res.txt and file This will be the input of the program
     Note: add bit_gen in fristLine of res.txt (same as input usecase 1)
#### Run thourgh makefile:
     make message
#### Output has some information such as (print in commandline):
     - message read from input
     - message decrypt
#### File source:
```bash
── genText
    └──asciiToText.py
    └──res.txt
    └──text.txt
── Makefile
── message.cpp
```

### Usecase [3] some common RSA attacks
Note: Since 4 attack methods are set up such as:

* External Attack (has same n, different e,c)
* Internal Attack (has n,e,d => to compute totient, give e_victim => d_victime)
* Fermat Attack (p,q close: abs(p - q) < n^1/4)
* Broadcast Attack (same e, diff n, c)

But the way they work is the same, we only need to take an example set up for one attack. Ex: broadcast Attack
#### Input file (write in attackMethod/testcase):
     - externalAttack (5 lines: n, e1, e2, c1, c2)
     - internalAttack (3 lines: n,e,d)
     - broadcastAttack (7 lines: e, n1, n2, n3, c1, c2, c3 - save in crt.txt)
     - fermatAttack (1 lines: n)
#### Run thourgh makefile (Makefile in folder attackMethod):
     cd attackMethod
     make broadcastAttack
#### Output has some information such as (write in attackMethod/result folder):
     - Fields have been decrypted depending on attack needs
     - Some attack such as (broadcast attack run readM_e.py same folder to get final result)
#### File source:
```bash
── attackMethod
    └──result
          ├── broadcastAttack.txt
          ├── readM_e.py
          ...
    └──testcase
          ├── crt.txt
          ...
    └──Makefile
    └──broadcastAttack.cpp
    ...
── rsa_attack.hpp
```
### Conclusion
Thourgh project, Team understand deep in RSA mechansim such as: genKey algorithm, encrypt, decrypt,... Besides, team have more arithmetic knowledge and was able to apply it to programming. We hope this open-source may be of help to those who are initially learning about RSA and its related mechanisms.

### Future Work
* Learn more about implementing Hash, MAC, and implementing digital signature applications with the above base fields have been decrypted depending on attack needs
* Take from scratch to better understand the mechanism in DES, AES encryption
* Package the app and deploy it to another platform
