def isMatch(s, p):
    m, n = len(s), len(p)
    dp = [[False] * (n + 1) for _ in range(m + 1)]
    
    # Base case: empty pattern matches empty text
    dp[0][0] = True
    
    # Base case: pattern with only '*' can match empty text
    for j in range(1, n + 1):
        if p[j - 1] == '*':
            dp[0][j] = dp[0][j - 1]
    
    # Fill the dp table
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if p[j - 1] == '*':
                dp[i][j] = dp[i - 1][j] or dp[i][j - 1]
            elif p[j - 1] == '?' or p[j - 1] == s[i - 1]:
                dp[i][j] = dp[i - 1][j - 1]
    
    return dp[m][n]

# Example usage:
s = "adceb"
p = "*a*b"
print(isMatch(s, p))  # Output: True
