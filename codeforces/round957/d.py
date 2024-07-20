from collections import deque

def can_ernkor_reach_bank(t, test_cases):
    results = []
    for case in test_cases:
        n, m, k = case[0]
        a = case[1]
        
        # BFS setup
        queue = deque([(0, 0)])  # (position, swimming distance used)
        visited = set((0, 0))
        
        found = False
        while queue:
            pos, swim = queue.popleft()
            
            # If he reaches the right bank
            if pos == n + 1:
                found = True
                break
            
            # If ErnKor is on the bank or on a log
            if pos == 0 or (pos > 0 and a[pos-1] == 'L'):
                for jump in range(1, m + 1):
                    new_pos = pos + jump
                    if new_pos > n:
                        new_pos = n + 1  # he jumps directly to the right bank
                    if new_pos <= n and a[new_pos-1] == 'C':
                        continue  # Can't land on crocodile
                    if (new_pos, swim) not in visited:
                        visited.add((new_pos, swim))
                        queue.append((new_pos, swim))
            
            # If ErnKor is in the water
            if pos > 0 and a[pos-1] == 'W':
                new_pos = pos + 1
                if swim + 1 <= k and new_pos <= n + 1:
                    if new_pos <= n and a[new_pos-1] != 'C' or new_pos == n + 1:
                        if (new_pos, swim + 1) not in visited:
                            visited.add((new_pos, swim + 1))
                            queue.append((new_pos, swim + 1))
        
        if found:
            results.append("YES")
        else:
            results.append("NO")
    
    return results

# Example usage
t = 2
test_cases = [
    [(6,2,15), "LWLLCC"],
    [(3, 2, 1), "WLC"]
]

results = can_ernkor_reach_bank(t, test_cases)
for result in results:
    print(result)
