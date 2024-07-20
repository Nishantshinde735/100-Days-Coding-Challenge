def longestArithSeqLengthWithDiff(nums, d):
    if not nums:
        return 0
    
    dp = {}
    max_length = 1
    
    for num in nums:
        if num - d in dp:
            dp[num] = dp[num - d] + 1
        else:
            dp[num] = 1
        max_length = max(max_length, dp[num])
    
    return max_length

# Example usage:
nums = [1, 5, 7, 8, 5, 3, 4, 2, 1]
d = -2
print(longestArithSeqLengthWithDiff(nums, d))  # Output: 4
