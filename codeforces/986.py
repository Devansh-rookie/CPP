def will_meet_red_queen(n, a, b, moves):
    # Initialize starting position of Alice
    x, y = 0, 0
    visited_positions = set()
    visited_positions.add((x, y))

    # Simulate one cycle of moves
    for move in moves:
        if move == 'N':
            y += 1
        elif move == 'E':
            x += 1
        elif move == 'S':
            y -= 1
        elif move == 'W':
            x -= 1
        # Check if Alice has reached the Red Queen's position
        if (x, y) == (a, b):
            return "YES"
        # Record visited positions in the cycle
        
        visited_positions.add((x, y))
    
    # If one cycle is completed and Red Queen's position wasn't reached
    return "NO"

# Input processing
t = int(input())
results = []
for _ in range(t):
    n, a, b = map(int, input().split())
    moves = input().strip()
    results.append(will_meet_red_queen(n, a, b, moves))

# Output results
print("\n".join(results))
