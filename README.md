# DSA_project
Shortest path algorithm implementation in PACMAN game

This C++ project is designed to implement a game called PACMAN. This is a simple arcade type game. PACMAN is basically a character controlled by the user, by using the keyboard. The player guides PACMAN through a maze, while eating dots (called pac-dots) which adds to the score. When PACMAN eats enough pac-dots in a particular level, he is promoted to the next level.
A few enemies (called MONSTER) roam the maze, trying to catch Pac-Man. If an enemy touches PACMAN he withers and the game ends.
This game supports multiple players. Players can create accounts, and play independently. Each player’s progress is saved in a dat file in binary format, thus implementing file handling. The player can continue playing from where he last played by just logging in, using his username and password.
PACMAN, the MONSTERS and the player are treated as objects each with characteristic features, working independently and are integrated as a whole, thus enforcing Object Oriented Programming.
The game uses graphics to make the game-play more attractive and user friendly.