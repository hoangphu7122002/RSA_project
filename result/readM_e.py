import gmpy2

with open("broadcastAttack.txt","r") as f:
    e = None
    M_e = None
    for idx,line in enumerate(f.readlines()):
        if idx == 0:
            e = line[3:-1]
        if idx == 1:
            M_e = line[5:]
    x = gmpy2.mpz(int(M_e))
    result, exact = gmpy2.iroot(x, int(e))
    res = hex(result)[2:]
    str_res = ""
    # res = hex(int(M))[2:]
    for i in range(0,len(res),2):
        temp_res = res[i:i+2]
        str_res += chr(int(temp_res,16))
    print(str_res)