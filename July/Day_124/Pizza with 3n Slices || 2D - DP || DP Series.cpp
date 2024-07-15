def maxSizeSlices(slices):
    def maxSum(slices, n):
        m = len(slices)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        
        for i in range(1, m + 1):
            for j in range(1, min(n, i // 2) + 1):
                if i >= 2:
                    dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + slices[i - 1])
                else:
                    dp[i][j] = max(dp[i - 1][j], slices[i - 1])
        return dp[m][n]
    
    n = len(slices) // 3
    return max(maxSum(slices[1:], n), maxSum(slices[:-1], n))

# Example usage:
slices = [1, 2, 3, 4, 5, 6]
print(maxSizeSlices(slices))  # Output should be the maximum sum of n non-adjacent slices
