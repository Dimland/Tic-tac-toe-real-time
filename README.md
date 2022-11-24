This is my first game.

Description of the rules of the game, as well as download the finished version of the game, you can follow the link - https://dimaq21.itch.io/tik-tak-toe

A presentation about the creation of the game can be viewed here https://www.slideshare.net/ssuseree887e1/tiktaktoe-sovlanutpptx

I used WINAPI technology. I implemented a unique gameplay with unique rules for the well-known Tic-Tac-Toe game.

The algorithm of the game:
- Resolution changes
- Initial values are assigned to global variables and structures.
- The main while loop is created in which messages are exchanged.

The following functions are performed in the main loop:
- drawing in a virtual context using the Alldraw function.
- Also in the "Alldraw" function, functions are called for counting points ("sumPoint"), for drawing a victory.
- Using the GetCursor function, the position of the mouse on the screen is tracked
- The "changeMenu" function is responsible for all the functional buttons in the game and the actions that should occur when they are pressed
- To make moves for drawing game elements (x or o), use the MouseInput, KeyboardInput, or BotMoves functions
- Using the addEnergy function, the timer adds the energy needed for moves.
- The convertPointInCoolO and "convertWatch" functions convert the actual time and points scored into a drawn font.
