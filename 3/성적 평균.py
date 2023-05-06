import sys
n, k = map(int, input().split())
arr = list(map(int, input().split()))
prefix = []
prefix.append(0)
for i in range(1, len(arr) + 1):
    prefix.append(prefix[i - 1] + arr[i - 1])

for _ in range(k):
    a, b = map(int, input().split())
    val = prefix[b] - prefix[a - 1]
    ans = val / (b - a + 1)
    print("{:.2f}".format(ans))