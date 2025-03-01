Santorini Board Game Implementation in C
This repository contains a C implementation of the popular board game Santorini. Santorini is a strategic, abstract board game where players take on the roles of builders, constructing towers and trying to reach the third level to win. This implementation provides a text-based interface for playing the game, allowing two players to compete against each other on the command line. The game also includes special hero abilities inspired by the official Santorini game, adding an extra layer of strategy.

Features
Two-Player Gameplay: The game supports two players, each controlling two builder pieces (a boy and a girl).

Text-Based Interface: The game is played entirely in the terminal, with a simple and intuitive text-based interface.

Hero Abilities: Players can choose between two heroes, each with unique winning conditions:

Eros: Wins if their builders start in two of the four corners and later move to neighboring positions while both are on level 1.

Chronus: Wins if there are at least five complete towers (level 4) on the board.

Rules Enforcement: The game enforces all the rules of Santorini, including movement, building, and winning conditions.

Save and Load Game: Players can save their current game state and load it later to continue playing.

Unicode Emojis: The game uses Unicode emojis to represent the builders, making the board visually appealing.

Error Handling: The game includes robust error handling to ensure smooth gameplay and prevent invalid moves.

How to Play
Setup: The game starts by initializing a 5x5 grid and placing two builder pieces for each player.

Turns: Players take turns performing the following actions:

Move: Move one of their builders to an adjacent space (including diagonals).

Build: Construct a building level (up to 4 levels) on an adjacent space.

Winning Conditions:

A player wins if one of their builders reaches the third level of a tower.

Additional winning conditions are triggered based on the chosen hero's abilities.

Code Structure
The code is organized into modular functions for clarity and maintainability. Here's an overview of the key components:

main.c: The entry point of the program, handling the game loop, player input, and game state management.

PT_PROJECT.h: Contains the necessary headers, constants, and structure definitions.

Board Management:

resetBoard(): Initializes the game board with empty spaces.

printTable(): Displays the current state of the game board, including builder positions and tower levels.

Player Management:

selectPlayerName(): Allows players to choose their builder letters.

selectStartingPosition(): Lets players place their builders on the board.

movePlayer(): Handles the movement of builders and building actions.

Game Logic:

correctCoordinates(): Validates moves and builds based on game rules.

win(): Checks if a player has won by reaching level 3.

chronosAbility(): Implements Chronus's special winning condition.

erosAbility(): Implements Eros's special winning condition.

Save and Load:

saveGame(): Saves the current game state to a file.

loadGame(): Loads a previously saved game state.

How to Compile and Run
To compile and run the game, follow these steps:

Clone the repository:

bash
Copy
git clone https://github.com/your-username/santorini-c.git
cd santorini-c
Compile the code using a C compiler (e.g., gcc):

bash
Copy
gcc -o santorini PT_PROJECT.c
Run the game:

bash
Copy
./santorini
Example Gameplay
Copy
Welcome to Santorini!
Player 1 boy: 👦 , girl: 👧 
Player 2 boy: 🧔 , girl: 👵 

-----------------------------
  |   0|   1|   2|   3|   4|
-----------------------------
 0|   👦 |   👧 |    |    |    |
 1|    |    |    |    |    |
 2|    |    |    |    |    |
 3|    |    |    |    |    |
 4|    |    |    |    |    |
-----------------------------

Player 1, please choose your hero!
 0 - Eros
 1 - Chronus
 Hero = 0
...
Future Improvements
AI Opponent: Implement an AI player using a simple algorithm (e.g., minimax or random moves).

Graphical Interface: Add a graphical interface using a library like SDL or ncurses.

Multiplayer Support: Extend the game to support online multiplayer.

Additional Hero Powers: Implement more hero powers from the official Santorini game for advanced gameplay.

Contributions
Contributions are welcome! If you'd like to improve the game, fix bugs, or add new features, feel free to open an issue or submit a pull request.
