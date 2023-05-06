str_result = ""
with open('res.txt','r') as f:
    input = f.read()
    for i in range(0,len(input),2):
        temp_res = input[i:i+2]
        str_result += chr(int(temp_res, 16))
print(str_result)