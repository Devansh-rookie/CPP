import sys

def matrix_chain_order(dimensions):
    n = len(dimensions) - 1  # Number of matrices
    m = [[0 for _ in range(n)] for _ in range(n)]  # DP table for costs
    s = [[0 for _ in range(n)] for _ in range(n)]  # Table for split points

    for l in range(2, n + 1):  # l is the chain length
        for i in range(n - l + 1):
            j = i + l - 1
            m[i][j] = sys.maxsize
            for k in range(i, j):
                cost = m[i][k] + m[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1]
                if cost < m[i][j]:
                    m[i][j] = cost
                    s[i][j] = k

    return m, s


def print_optimal_parens(s, i, j):
    if i == j:
        return f"M{i+1}"
    else:
        return f"({print_optimal_parens(s, i, s[i][j])} * {print_optimal_parens(s, s[i][j] + 1, j)})"


# Input dimensions
dimensions = [2, 25, 3, 16, 1, 1000]
m, s = matrix_chain_order(dimensions)

# Print the DP matrix (m)
print("DP Matrix (Minimum Costs):")
for row in m:
    print(row)

# Optimal parenthesization
optimal_parens = print_optimal_parens(s, 0, len(dimensions) - 2)
print("\nOptimal Parenthesization:")
print(optimal_parens)

for row in s:
    print(row)