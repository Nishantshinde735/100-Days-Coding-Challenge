def fractional_knapsack(values, weights, capacity):
    index = list(range(len(values)))
    ratio = [v / w for v, w in zip(values, weights)]
    index.sort(key=lambda i: ratio[i], reverse=True)
    
    max_value = 0
    for i in index:
        if weights[i] <= capacity:
            max_value += values[i]
            capacity -= weights[i]
        else:
            max_value += values[i] * (capacity / weights[i])
            break
    
    return max_value

# Example usage:
values = [60, 100, 120]
weights = [10, 20, 30]
capacity = 
