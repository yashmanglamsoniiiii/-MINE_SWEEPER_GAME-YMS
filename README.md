# <MINE_SWEEPER_GAME> ~"YMS"
I created my first game using dsa logics , and it was a whole new experience to learn something new which obviously helped to to improve my lopics and critical thinking abiltiy.
The GAME description:-

💣 Minesweeper Game in C++

A simple console-based Minesweeper game built in C++, using basic DSA concepts and recursion for revealing cells.
This project helped me understand 2D arrays, recursion, and logic-building in depth.

🎯 Game Objective

The goal is simple:
Reveal all cells that are not mines (9).
Avoid revealing any mine — or 💥 BOOM! Game Over!

⚙️ How It Works

The board is a 2D grid (size n × n), containing:
Randomly placed mines ('9')
Numbered cells ('1'–'8') showing how many mines are around them
Empty cells ('0')
The player chooses a cell to reveal (r) or flag (f):
r row col → Reveal the cell
f row col → Flag the cell as a suspected mine
If a mine is revealed → Game Over!
If all non-mine cells are revealed → You Win! 🎉

🧠 Concepts Used

2D Vectors for board representation
Randomization using rand() and srand(time(0))
Recursion for revealing empty areas
Visited Matrix to avoid infinite recursion
Input Validation for 1-based indexing
