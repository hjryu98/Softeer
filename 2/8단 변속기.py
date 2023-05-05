import sys
prv = 0
flag = True

arr = list(map(int,input().split()))

if arr[0] != 1 and arr[0] != 8:
    flag = False
elif arr[0] == 1:
    prv = 1
    for i in range(1, 8):
        if arr[i] == prv + 1:
            prv = arr[i]
        else:
            flag = False
            break
else:
    prv = 8
    for i in range(1, 8):
        if arr[i] == prv - 1:
            prv = arr[i]
        else:
            flag = False
            break

if flag == False:
    print("mixed")
else:
    if prv == 1:
        print("descending")
    else:
        print("ascending")