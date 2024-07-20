def find_subarray_with_min_sum(values, required_sum):
    n = len(values)
    current_sum = 0
    start = 0
    for end in range(n):
        current_sum += values[end]
        while current_sum >= required_sum:
            if current_sum >= required_sum:
                return start, end
            current_sum -= values[start]
            start += 1
    return -1, -1

def solve_cake_sharing(t, test_cases):
    results = []
    for case in test_cases:
        n, a, b, c = case
        total = sum(a)  # tot is same for a, b, c
        required_sum = (total + 2) // 3
        
        la, ra = find_subarray_with_min_sum(a, required_sum)
        if la == -1:
            results.append(-1)
            continue
        
        lb, rb = find_subarray_with_min_sum(b[ra+1:], required_sum)
        if lb == -1:
            results.append(-1)
            continue
        lb += ra + 1
        rb += ra + 1
        
        lc, rc = find_subarray_with_min_sum(c[rb+1:], required_sum)
        if lc == -1:
            results.append(-1)
            continue
        lc += rb + 1
        rc += rb + 1
        
        results.append((la + 1, ra + 1, lb + 1, rb + 1, lc + 1, rc + 1))
    
    return results

# Input reading
import sys
input = sys.stdin.read
data = input().split()

index = 0
t = int(data[index])
index += 1

test_cases = []
for _ in range(t):
    n = int(data[index])
    index += 1
    a = list(map(int, data[index:index + n]))
    index += n
    b = list(map(int, data[index:index + n]))
    index += n
    c = list(map(int, data[index:index + n]))
    index += n
    test_cases.append((n, a, b, c))

# Solve the problem
results = solve_cake_sharing(t, test_cases)

# Output results
for result in results:
    if result == -1:
        print(result)
    else:
        print(" ".join(map(str, result)))
