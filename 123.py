MOD = 998244353

# Function to compute x^y % MOD
def mod_pow(x, y, mod):
    res = 1
    while y > 0:
        if y % 2 == 1:
            res = res * x % mod
        x = x * x % mod
        y //= 2
    return res

# Function to compute the modular inverse of a number using Fermat's Little Theorem
def mod_inverse(x, mod):
    return mod_pow(x, mod - 2, mod)

# Function to calculate the expected number of days
def expected_days(W, G, L):
    if L == 0:
        # If L = 0, we can never gain weight, so it takes exactly W - G days
        return (W - G) % MOD
    else:
        # Probabilistic geometric series for random walk with a limit
        # Expected number of days = 2 * (W - G + 1)
        numerator = 2 * (W - G + 1) % MOD
        denominator = 1  # For p/q = numerator / denominator, denominator is 1
        return numerator % MOD

# Main function to solve the problem
def solve():
    T = int(input())
    for t in range(1, T + 1):
        W, G, L = map(int, input().split())
        result = expected_days(W, G, L)
        print(f"Case #{t}: {result}")

# Input and execution
solve()
