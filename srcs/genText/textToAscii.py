str_res = ""
with open('text.txt','r') as f:
    for line in f.readlines():
        for ele in line:
            x = format(ord(ele))
            if len(x) == 1: x = '00' + x
            elif len(x) == 2: x = '0' + x
            str_res += x
with open('res.txt','a') as w:
    w.write(str_res)
                