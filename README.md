# TicTacToe
# 🎮 Tic Tac Toe in C++

A simple **Tic Tac Toe game built in C++** that can be played in two modes:

* 👥 Player vs Player
* 🤖 Player vs Computer

The project is implemented using basic C++ concepts such as **functions, arrays, loops, conditional statements, switch cases, random number generation, and game logic**.

## 📌 Features

* 3 × 3 Tic Tac Toe board
* Player X and Player O gameplay
* Player vs Player mode
* Player vs Computer mode
* Computer makes random valid moves
* Prevents players from selecting occupied positions
* Automatically detects the winner
* Detects all rows, columns, and diagonals for winning combinations
* Displays the board after every move

## 🕹️ How to Play

When the game starts, you will be asked to choose a game mode:

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

### Player vs Player

* Player X plays first.
* Player O plays second.
* Players take turns entering their positions.
* The first player to get three marks in a row wins.

### Player vs Computer

* Player X plays first.
* The computer plays as O.
* The computer randomly selects an available position.
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

These numbers allow the player to easily choose a position.

### 2. Checking Empty Positions

The `isEmpty()` function checks whether a selected position is still available.

If the position already contains `X` or `O`, the player cannot select it again.

### 3. Making Moves

Two functions are used to place marks on the board:

* `takeIPx()` → places `X`
* `takeIPo()` → places `O`

### 4. Checking the Winner

The `winner()` function checks:

* Three X/O marks in the same row
* Three X/O marks in the same column
* Three X/O marks diagonally

If there is a winner, it returns either `X` or `O`.

### 5. Computer AI

The current computer player uses a simple random-move strategy.

```cpp
pos = rand() % 9 + 1;
```

The program keeps generating positions until it finds an empty one.

This is currently an **easy/random AI**, rather than a strategic AI.

## 🛠️ Technologies Used

* **Language:** C++
* **Compiler:** Any standard C++ compiler
* **Libraries:**

  * `<iostream>`
  * `<cstdlib>`
  * `<ctime>`

## ▶️ How to Run

### 1. Clone the repository

```bash
git clone <your-repository-url>
```

### 2. Navigate to the project folder

```bash
cd TicTacToe
```

### 3. Compile the program

Using `g++`:

```bash
g++ main.cpp -o tictactoe
```

### 4. Run the game

On macOS/Linux:

```bash
./tictactoe
```

On Windows:

```bash
tictactoe.exe
```

## 📂 Project Structure

```text
TicTacToe/
│
├── main.cpp
└── README.md
```

## 🚀 Future Improvements

The project can be extended with more advanced features:

* 🧠 Smart AI using the **Minimax algorithm**
* 🎚️ Easy, Medium, and Hard difficulty levels
* 🔄 Option to play another game without restarting the program
* 🏆 Score tracking
* ❌ Better input validation
* 🎨 Improved console interface
* 👤 Option for the player to choose X or O
* 🤖 Unbeatable AI using Minimax

## 📚 Concepts Practiced

This project helped practice:

* 2D arrays
* Functions
* `switch` statements
* `if-else` conditions
* Loops
* User input
* Random number generation
* Boolean functions
* Game-state checking
* Basic AI concepts

## 👩‍💻 Author

**Nehal Kashyap**

A beginner C++ project created to understand game development fundamentals and gradually explore **AI implementation in games**.
