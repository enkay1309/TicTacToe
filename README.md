# 🎮 Tic Tac Toe in C++

A console-based **Tic Tac Toe game built in C++**, featuring both Player vs Player and Player vs Computer modes.

The project started as a simple two-player game with a random-move computer opponent and is being progressively enhanced with **game-playing AI using the Minimax algorithm**.

## 📌 Features

* 3 × 3 Tic Tac Toe board
* Player X and Player O gameplay
* Player vs Player mode
* Player vs Computer mode
* Easy AI using random valid moves
* Strategic AI using the **Minimax algorithm**
* Prevents players from selecting occupied positions
* Automatic winner detection
* Detects rows, columns, and diagonals
* Displays the board after every move
* Modular game logic using functions

## 🕹️ How to Play

When the game starts, choose a game mode:

```text
Choose game mode:
1. Player vs Player
2. Player vs Computer
Enter choice (1/2):
```

The board positions are numbered from **1 to 9**:

```text
1 | 2 | 3
---------
4 | 5 | 6
---------
7 | 8 | 9
```

Enter the number corresponding to the position where you want to place your mark.

### 👥 Player vs Player

* Player X plays first.
* Player O plays second.
* Players take turns entering their positions.
* The first player to get three marks in a row wins.
* If all positions are filled without a winner, the game ends in a draw.

### 🤖 Player vs Computer

* Player X plays first.
* The computer plays as O.
* The computer can use either a random strategy or the Minimax-based strategy depending on the current implementation.
* The game continues until either X or O wins, or the board is full.

## 🧠 How the Program Works

### 1. Board Initialization

The `startBoard()` function initializes the board with numbers from 1 to 9.

```text
1 | 2 | 3
---------
4 | 5 | 6
---------
7 | 8 | 9
```

The numbers act as position identifiers and allow players to select their desired cells.

### 2. Checking Empty Positions

The `isEmpty()` function checks whether a selected position is available.

A position is considered occupied if it already contains either `X` or `O`.

### 3. Making Moves

The `makeMove()` function places a player's mark on the selected position.

```cpp
makeMove(pos, 'X');
makeMove(pos, 'O');
```

Using a single function for both players keeps the game logic simpler and avoids duplicate move functions.

### 4. Checking the Winner

The `winner()` function checks all possible winning combinations:

* Three marks in the same row
* Three marks in the same column
* Three marks diagonally

It returns:

```text
'X' → Player X wins
'O' → Player O wins
0   → No winner yet
```

### 5. Computer AI

The computer player is being developed in multiple stages.

#### Easy AI — Random Moves

The initial AI selects a random available position:

```cpp
pos = rand() % 9 + 1;
```

The program keeps generating positions until it finds an empty cell.

This provides a simple **Easy AI** suitable for the initial version of the game.

#### Hard AI — Minimax

The strategic AI uses the **Minimax algorithm** to evaluate possible future game states.

The algorithm simulates possible moves and assigns scores to the resulting positions:

```text
Computer wins → +10
Draw           →  0
Player wins    → -10
```

The computer attempts to maximize its score while assuming that the human player will make the best possible move to minimize it.

The general decision process is:

```text
Current Board
      ↓
Try every possible AI move
      ↓
Simulate player's responses
      ↓
Simulate AI's responses
      ↓
Continue until game ends
      ↓
Evaluate each outcome
      ↓
Choose the move with the best score
```

This allows the AI to play strategically instead of simply choosing a random cell.

## 🔬 AI Development

The AI is being developed incrementally:

```text
Random AI
    ↓
Minimax
    ↓
Minimax + Alpha-Beta Pruning
    ↓
Easy / Medium / Hard Difficulty
```

### Minimax

Minimax treats the game as a decision tree.

The AI acts as the **maximizing player**, while the human is treated as the **minimizing player**.

For example:

```text
AI wins  → +10
Draw     →   0
AI loses → -10
```

The AI selects the move that produces the best possible outcome assuming the opponent also plays optimally.

### Alpha-Beta Pruning

A planned optimization for the Minimax implementation is **Alpha-Beta pruning**.

Instead of evaluating every possible branch of the game tree, Alpha-Beta pruning eliminates branches that cannot influence the final decision.

This reduces unnecessary computation while producing the same optimal move as standard Minimax.

## 🛠️ Technologies Used

* **Language:** C++
* **Compiler:** `g++`
* **Libraries:**

  * `<iostream>`
  * `<cstdlib>`
  * `<ctime>`
  * `<algorithm>`

## ▶️ How to Run

### 1. Clone the repository

```bash
git clone https://github.com/enkay1309/TicTacToe.git
```

### 2. Navigate to the project

```bash
cd TicTacToe
```

### 3. Compile the program

Using `g++`:

```bash
g++ tictac.cpp -o tictac
```

### 4. Run the game

On macOS/Linux:

```bash
./tictac
```

On Windows:

```bash
tictac.exe
```

## 📂 Project Structure

```text
TicTacToe/
│
├── tictac.cpp
└── README.md
```

The project is currently maintained through separate Git branches as new AI functionality is developed.

For example:

```text
main
  │
  └── minimax
        ├── Minimax AI
        ├── Alpha-Beta Pruning
        ├── Difficulty Levels
        └── Game Statistics
```

## 🚀 Future Improvements

Planned improvements include:

* ⚡ Alpha-Beta pruning
* 🎚️ Easy, Medium, and Hard difficulty levels
* 🔄 Play multiple games without restarting the program
* 🏆 Win/loss/draw statistics
* 📊 Game statistics and win percentage
* ❌ Better input validation
* 🎨 Improved console interface
* 👤 Allow the player to choose X or O
* 🤖 Fully optimized unbeatable AI
* 🧩 Cleaner object-oriented game architecture
* 🖥️ Graphical user interface

## 📚 Concepts Practiced

This project provides practical experience with:

* 2D arrays
* Functions
* Loops
* Conditional statements
* `switch` statements
* User input
* Random number generation
* Boolean functions
* Game-state evaluation
* Recursion
* Game-tree search
* Minimax decision-making
* Algorithm optimization

## 🌱 Project Evolution

This project is being developed incrementally to explore how **AI can be applied to game development**.

The initial implementation focused on understanding fundamental C++ programming and game logic. The next stage introduces **Minimax**, transforming the computer player from a random opponent into a strategic decision-making system.

Future versions will optimize the algorithm using **Alpha-Beta pruning** and introduce multiple difficulty levels and game statistics.

## 👩‍💻 Author

**Nehal Kashyap**

A C++ project exploring **game development, algorithmic decision-making, and AI implementation** through progressively more advanced Tic Tac Toe opponents.
