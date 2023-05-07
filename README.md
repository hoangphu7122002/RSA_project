# RSA_project

Install [NTL library](https://libntl.org/doc/tour-unix.html) on your machine. if you don't use visual studio to compile, you can use wsl and virtual machine to compile with vscode 

### Usecases
* Implement program takes the number of bits for the prime numbers as input (from input.txt), generates two prime numbers (observer thourgh output.txt), and uses them to create an RSA encryption. [1]
* Test encrypt and decrypt with keys from the RSA algorithm via a text message. [2]
* Implement a few common rsa attacks such as an external attack, internal attack, broadcast attack, and fermat attack on a case-by-case basis. [3]
* Implement from scratch some arithmetic related algorithms such as: power_mod, gcd, euler_gcd, chinese_remainder_theorem, rabin_miller test, ... to assist in the problem of the topic.

### Usecase [1]
#### Input file (write in input.txt):
     one line: number of bits of prime number you want to generate (example: 512, 1024)
#### Run thourgh makefile:
     make rsa
#### Output has some information such as:
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
