def minSwap(A, B):
    n = len(A)
    keep = [float('inf')] * n
    swap = [float('inf')] * n
    keep[0] = 0
    swap[0] = 1

    for i in range(1, n):
        if A[i] > A[i-1] and B[i] > B[i-1]:
            keep[i] = min(keep[i], keep[i-1])
            swap[i] = min(swap[i], swap[i-1] + 1)
        if A[i] > B[i-1] and B[i] > A[i-1]:
            keep[i] = min(keep[i], swap[i-1])
            swap[i] = min(swap[i], keep[i-1] + 1)
    
    return min(keep[-1], swap[-1])

# Example usage:
A = [1, 3, 5, 4]
B = [1, 2, 3, 7]
print(minSwap(A, B))  # Output: 1
