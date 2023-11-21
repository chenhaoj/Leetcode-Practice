n, k = map(int, input().split())
a = []
for i in range(k):
    b, c = map(int, input().split())
    a.append((c, b))
res = 0
mod=10**9+7
while (True):
    b = []
    s = 0
    for i in range(0, len(a)):
        f = 0
        if i >= 1 and s % 2 == 1:
            f = 1
            b.append((a[i - 1][0] + a[i][0], 1))
        s += a[i][1]
        if (a[i][1] - f) // 2 > 0:
            b.append((a[i][0] * 2, (a[i][1] - f) // 2))
        if i == len(a) - 1 and s % 2 == 1:
            b.append((a[i][0], 1))
    a = list(b)
    if (len(a) == 1 and a[0][1] == 1):
        break
    res += a[0][0]
    res%=mod
print(res)