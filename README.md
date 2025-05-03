# Memory Card Game (C Implementation)

A command-line memory matching game built entirely in **C**, where players flip cards, test their memory, and compete for the highest score.  
This project demonstrates structured programming, input validation, and dynamic memory simulation using simple arrays and strings.

---

## Game Objective

Reveal hidden pairs of matching objects on a board. Each turn, players select two cards by specifying their coordinates.  
If the cards match, they stay visible. The game continues until all pairs are found. The player with the most matches wins!

---

## Key Features

- **Fully Configurable Grid:** Board size is determined by user input.
- **Multiplayer Mode:** Supports up to 10 players with dynamic name parsing.
- **Interactive CLI:** Instructions, board display, and prompts are printed clearly.
- **Card Reveal Mechanism:** Cards are hidden at start and revealed upon selection.
- **Real-Time Scoring:** Player scores update as they find matches.
- **Input Validation:** Ensures positions are unique and all arguments are valid.

---

## How to Compile and Run

### Step 1: Compile

```bash
gcc -o cards_game cards_game.c
```
### Step 2: Run with Arguments
```bash
./cards_game <board_size> <num_players> <player_names> <objects> <positions>
```
### Example Run:
```bash
./cards_game 4 2 Alice#Bob Dog Cat Fan Hat Egg Box Car Tree 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

Breakdown:

4 → 4x4 board

2 → number of players

Alice#Bob → player names (separated by #)

Dog ... Tree → 8 objects (each appears twice)

0 1 2 ... 15 → 16 unique card positions in matching pairs
```

### Project Files
```bash
cards_game/
│
├── src/
│   ├── cards_game.c        # Core logic of the game
│   └── cards_game.h        # Function declarations and constants
│
└── README.md               # Game instructions and documentation
```

### Technologies and Concepts
---
Language: C

Concepts used:Arrays, Structs, Pointers, Game Loops

### Game Flow
---
Players are welcomed and shown a coordinate-based board.
The board is initialized with hidden "X" values.
Each player takes a turn to enter two positions.
If the selected cards match, the score is updated.
The game continues until all cards are revealed.
A winner is declared — or a tie, if scores match.

