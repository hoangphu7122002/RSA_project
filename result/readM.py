with open("externalAttack.txt","r") as f:
    M = f.read()[2:]
    str_res = ""
    res = hex(int(M))[2:]
    for i in range(0,len(res),2):
        temp_res = res[i:i+2]
        str_res += chr(int(temp_res,16))
    print(str_res)