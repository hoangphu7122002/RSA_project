str_result = ""
with open('res.txt','r') as f:
    input = f.read()
    for i in range(0,len(input),3):
        temp_res = input[i:i+3]
        str_result += chr(int(temp_res))
print(str_result)