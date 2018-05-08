import sys

dp = [1, 2, 5]
for i in range(3, 1001):
    dp.append(dp[i - 1] * 2 + dp[i - 2] + dp[i - 3])

for x in sys.stdin:
    print(dp[int(x)])
