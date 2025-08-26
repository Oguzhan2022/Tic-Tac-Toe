# Tic-Tac-Toe Game in C

This is a classic Tic-Tac-Toe game implemented in C. It's a console-based application where a human player competes against a simple computer AI.

## Features

-   **Player vs. Computer:** Play against an AI opponent.
-   **Interactive Console Interface:** The game board is printed in the console after every move.
-   **Simple AI Logic:** The computer will:
    1.  Play a winning move if available.
    2.  Block the player's winning move if necessary.
    3.  Make a random available move otherwise.
-   **Win/Loss/Draw Detection:** The game automatically detects and announces if the player wins, loses, or if the game is a draw.
-   **Input Validation:** Checks if a selected cell is already occupied and prompts the player for a new move.
-   **Play Again:** Option to start a new game after the current one finishes.

## How to Compile and Run

You will need a C compiler like GCC installed on your system.

1.  **Clone the repository or download the `TicTacToe.c` file.**

2.  **Open a terminal or command prompt** and navigate to the directory where the file is saved.

3.  **Compile the code** using the following command:
    ```bash
    gcc TicTacToe.c -o TicTacToe
    ```

4.  **Run the executable:**
    -   On Windows:
        ```bash
        TicTacToe.exe
        ```
    -   On macOS or Linux:
        ```bash
        ./TicTacToe
        ```

## How to Play

1.  The game will start, and an empty 3x3 grid will be displayed.
2.  You are the 'X' player, and the computer is 'O'.
3.  You will be prompted to enter your move.
4.  Enter your desired cell using `row,column` format (e.g., `1,1` for the top-left corner, `3,3` for the bottom-right).
5.  The game continues with alternating turns until one player gets three marks in a row (horizontally, vertically, or diagonally), or until the board is full (a draw).
6.  After the game ends, you will be asked if you want to play again. Press `c` to continue or any other key to exit.


## Code Structure

The program is organized into several key functions:

-   `main()`: Contains the main game loop that controls the flow of the game.
-   `printTable()`: Renders the current state of the 3x3 game board to the console.
-   `playerMove()`: Prompts the player for input, validates it, and updates the board with the player's move ('X').
-   `computerXY()`: Implements the computer's logic to decide its next move.
-   `computerMove()`: Updates the board with the computer's move ('O').
-   `win()`: Checks the board for any winning conditions (three marks in a row, column, or diagonal).
-   `equal()`: Checks if the board is full, resulting in a draw.
-   `playAgain()`: Asks the user if they want to restart the game.
-   `emptyArray()`: Resets the game board to its initial empty state for a new game.
