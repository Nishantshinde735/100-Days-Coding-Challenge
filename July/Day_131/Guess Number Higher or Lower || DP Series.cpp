def getMoneyAmount(n):
    dp = [[0] * (n + 1) for _ in range(n + 1)]
    
    for length in range(2, n + 1):
        for l in range(1, n - length + 2):
            r = l + length - 1
            dp[l][r] = float('inf')
            for k in range(l, r + 1):
                cost = k + max(dp[l][k - 1] if k - 1 >= l else 0, dp[k + 1][r] if k + 1 <= r else 0)
                dp[l][r] = min(dp[l][r], cost)
    
    return dp[1][n]

# Example usage:
n = 10
print(getMoneyAmount(n))  # Output: 16

  
