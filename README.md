# 🧠 **Memory Card Game – C Implementation**

## 🎯 **Overview**
The **Memory Card Game** is a command-line, multiplayer matching game developed entirely in **C**.  
Players flip cards, test their memory, and compete for the highest score by finding matching pairs.  
This project showcases **structured programming**, **input validation**, and **dynamic memory handling** through arrays, strings, and pointer logic.

---

## 🕹️ **Game Objective**
Reveal all hidden pairs on the board by remembering card positions and matching identical objects.  
Each turn, players flip two cards:
- If they **match**, the cards stay visible and the player earns a point.  
- If they **don’t match**, they are flipped back, and the next player takes a turn.  
The game continues until all pairs are revealed — the player with the **most matches wins!**

---

## ✨ **Key Features**

- 🎲 **Configurable Board Size** – The grid size is determined dynamically from user input.  
- 👥 **Multiplayer Mode** – Supports up to **10 players**, with flexible name parsing via `#` separation.  
- 🖥️ **Interactive Command-Line Interface** – Clear prompts, instructions, and visual board updates.  
- 🧩 **Card Reveal System** – Cards start hidden and are revealed only when selected.  
- 🧮 **Real-Time Scoring** – Tracks scores and announces the winner or a tie at the end.  
- ✅ **Robust Input Validation** – Ensures unique positions, valid entries, and safe gameplay.  

---

## ⚙️ **Setup & Run Instructions**

### 1️⃣ **Compile the Program**
```bash
gcc -o cards_game src/cards_game.c
```

2️⃣ Run the Game
```bash
./cards_game <board_size> <num_players> <player_names> <objects> <positions>
```

🧠 Example Run
```bash
./cards_game 4 2 Alice#Bob Dog Cat Fan Hat Egg Box Car Tree 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
```

## Explanation:

4 → 4x4 board

2 → Number of players

Alice#Bob → Player names separated by #

Dog ... Tree → 8 unique objects (each appears twice)

0 1 2 ... 15 → Card positions mapped into pairs

```bash
🗂️ Project Structure
bash
Copy code
Memory_Card_Game/
│
├── src/
│   ├── cards_game.c         # Core logic and game loop
│   ├── cards_game.h         # Function declarations and constants
│
└── README.md                # Documentation and usage instructions
```

## 🧰 Technologies & Concepts
Category	Details
Language	C
Programming Concepts	Arrays, Structs, Pointers, Loops
Design Concepts	Modular programming with .h and .c files
Gameplay Logic	Game loops, user input parsing, memory simulation

## 🔄 Game Flow
Players are greeted and shown an empty grid with hidden cards (X).

The program initializes the board dynamically using user-provided inputs.

Each player selects two positions per turn.

If a match is found → Score increases and cards remain visible.

If not → Cards are hidden again, and the next player continues.

The game ends when all pairs are found — the player with the most matches wins!

## 🏁 Highlights
💡 Demonstrates memory-safe C programming with dynamic input handling.

🧱 Implements array-based board management with clean modular design.

⚙️ Reinforces user interaction, data validation, and turn-based logic.

🏆 A great example of problem-solving and logic design using fundamental C principles.

