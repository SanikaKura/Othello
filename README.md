# OTHELLO C++ with SFML
This project is a C++ implementation of the board game Othello, also known as Reversi, using SFML (Simple and Fast Multimedia Library) for graphics. It includes both single-player mode with a computer opponent, as well as two-player mode. The opponent functions in single player mode analyzes the effectiveness of all possible moves, and uses known strategies such as keeping moves in the center of the board and only flipping few tiles, then expanding out slowly as opportunities arise. This creates a challenging and engaging experience for the user.

The program first launches this SFML page, prompting the user to select single or two player mode:

<img width="205" height="226" alt="othello 1" src="https://github.com/user-attachments/assets/0db80ca7-db1a-450c-bab2-3aa89dada3d4" />

Once a mode is selected, the user is taken to the board with the starting position. In the example below, the human user is playing black pieces against the computer playing whites:

![Untitled video - Made with Clipchamp (2)](https://github.com/user-attachments/assets/b2959aae-bb3c-4473-b6ff-235e1b16c83e)

Once the program detects that the board is filled, or there are no possible moves left, the bottom right corner of the screen indicates either the black or white icon next to a trophy for the winner!

![Untitled video - Made with Clipchamp (2) (1)](https://github.com/user-attachments/assets/e0fd6999-a538-4b19-83be-bef00d9d043c)
