def mctFromLeafValues(arr):
    n = len(arr)
    dp = [[0] * n for _ in range(n)]
    max_leaf = [[0] * n for _ in range(n)]
    
    for i in range(n):
        max_leaf[i][i] = arr[i]
    
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            max_leaf[i][j] = max(max_leaf[i][j-1], arr[j])
            dp[i][j] = float('inf')
            for k in range(i, j):
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + max_leaf[i][k] * max_leaf[k+1][j])
    
    return dp[0][n-1]

# Example usage:
arr = [6, 2, 4]
print(mctFromLeafValues(arr))  # Output: 32
