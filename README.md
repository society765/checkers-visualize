# Checkers


## Comments 
The original `js` repo was written by **codethejason**, and I "borrowed" this `js` 
repo as a checkers front-end to play with my `C++` back-end bot in 
[checkers](https://github.com/society765/bot-build/tree/master/checkers-cpp/). 

As I was adding the compatibility for the communication with my `C++` back-end 
(using [dlib](https://github.com/davisking/dlib) for networking), 
I also fixed several bugs for this repo. Most of them are related to the rules of checkers. 

You may visit my demo [here](https://society765.github.io/checkers-visualize/). 

The below part of the README is from the original author. Many thanks! 

## Using It
Play by selecting your piece and clicking on the tile you want to move to. Click [here](http://www.itsyourturn.com/t_helptopic2030.html) to learn how to play checkers. Jumping when available is enforced.

## Code
The code supports all the features of checkers including kingship and double/triple/quadruple jumping. The Board object controls the board and therefore the game. The pieces and tiles instances are used in the game for checking whether a piece can be moved, moving a piece, deleting a piece, checking whether tile is in range, and much more. The script is fully commented and original.

If you find any bugs, please make a Pull Request or an Issue.


## Live Demo
[DEMO](http://codethejason.github.io/checkers/index.html)
