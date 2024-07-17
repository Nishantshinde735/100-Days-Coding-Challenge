def canPartition(nums):
    total_sum = sum(nums)
    
    # If the total sum is odd, it's not possible to partition it into two equal subsets
    if total_sum % 2 != 0:
        return False
    
    target = total_sum // 2
    dp = [False] * (target + 1)
    dp[0] = True
    
    for num in nums:
        for i in range(target, num - 1, -1):
            dp[i] = dp[i] or dp[i - num]
    
    return dp[target]

# Example usage:
nums = [1, 5, 11, 5]
print(canPartition(nums))  # Output: True
