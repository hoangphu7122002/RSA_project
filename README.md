# RSA_project

Install [NTL library](https://libntl.org/doc/tour-unix.html) on your machine. if you don't use visual studio to compile, you can use wsl and virtual machine to compile with vscode 

### Usecases
* Implement program takes the number of bits for the prime numbers as input (from input.txt), generates two prime numbers (observer thourgh output.txt), and uses them to create an RSA encryption. [1]
* Test encrypt and decrypt with keys from the RSA algorithm via a text message. [2]
* Implement a few common rsa attacks such as an external attack, internal attack, broadcast attack, and fermat attack on a case-by-case basis. [3]
* Implement from scratch some arithmetic related algorithms such as: power_mod, gcd, euler_gcd, chinese_remainder_theorem, rabin_miller test, ... to assist in the problem of the topic.

### Usecase [1]
#### Input file contains 1 lines (write in input.txt):
      number of bits of prime number you want to generate (example: 512 bits, 1024 bits)
