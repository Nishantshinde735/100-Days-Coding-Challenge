def longestArithSeqLength(nums):
    if not nums:
        return 0
    
    n = len(nums)
    dp = [{} for _ in range(n)]
    max_length = 1
    
    for i in range(n):
        for j in range(i):
            diff = nums[i] - nums[j]
            if diff in dp[j]:
                dp[i][diff] = dp[j][diff] + 1
            else:
                dp[i][diff] = 2  # Starting a new subsequence with length 2
            max_length = max(max_length, dp[i][diff])
    
    return max_length

# Example usage:
nums = [3, 6, 9, 12]
print(longestArithSeqLength(nums))  # Output: 4

      
