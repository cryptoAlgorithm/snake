
#include <iostream>
#include "snake.h"

#define H 20
#define W 20

/**
 * Print map on console screen row-by-row.
 * 
 * @param  map      - integer array containing information of empty squares, snake and food positions.
 * @param  posHead  - coordinates of snake's head position
 * @return void
 */
void render(int map[H][W], int posHead[2]) {

    /* 1st row */
    for (int j = 0; j < W + 2; j++) std::cout << "# "; // Print top wall
    std::cout << "\n"; // line break;
    
    /* 2nd row to (H+1) rows */
    for (int i = 0; i < H; i++) { 
        
        std::cout << "# "; // Print left wall
        
        for (int j = 0; j < W; j++) {

            std::cout << map[i][j] << " "; // Print number map. Comment this out if printing the appropriate characters instead.
            
            // TODO: Instead of printing the number map above, convert the numbers and print the appropriate characters (approx ~5 lines of code)
            // 0: Empty square ' '
            // -1: Food '$'
            // +ve (but not snake head): '*'
            // +ve (snake head): '@'
            // Remember to comment out the above number map


        }

        std::cout << "#\n"; // Print right wall and line break
    }

    /* Last row */
    for (int j = 0; j < W + 2; j++) std::cout << "# "; // Print bottom wall
    std::cout << "Length = "<< map[posHead[0]][posHead[1]];
    std::cout << "\n"; // line break;
}

/**
 * Update position of snake's head from commanded direction
 *
 * @param  posHead  - coordinates of snake's head position
 * @param  dir      - 0: UP, 1: DOWN, 2: LEFT, 3: RIGHT
 * @return void
 */
void updateHeadPosition(int posHead[2], int dir) {
    // TODO: Update position of head based on the value of dir  (~4 lines of code)

}

/**
 * Extend length of snake by updating the map with its new head position.
 * The final length of snake = current length + 1.
 *
 * @param  posHeadNew - coordinates of snake's head new position
 * @return void
 */
void extendSnake(int map[H][W], int posHeadNew[2], int length) {
    // TODO: Assign the value of length + 1 to the position of the new head  (~1-3 line of code)


}

/**
 * Reduce length of snake by 1 by subtracting 1 from all +ve squares in map
 *
 * @param  map      - integer array containing information of empty squares, snake and food positions.
 * @return void
 */
void reduceSnake(int map[H][W]) {
    // TODO: Minus one from all +ve squares in the map (~5 lines of code)


}

/**
 * Generate random XY coordinates for food on an empty square on the map and name it -1
 *
 * @param  map      - integer array containing information of empty squares, snake and food positions.
 * @param  posFood  - coordinates of food position
 * @return void
 */
void generateFood(int map[H][W], int posFood[2])
{
    // TODO: Generate a random XY coordinate for food within the map (~5 lines of code)
    // You should keep generating a XY coordinate until you get a valid solution (i.e. food should only appear on empty square)


}

/**
 * Check if snake head and food has collided.
 *
 * @param  posHead  - coordinates of snake's head position
 * @param  posFood  - coordinates of food position
 * @return bool     - True if both X and Y values are equal
 */
bool isCollisionFood(int posHead[2], int posFood[2]) {
    // TODO: Return true if collision has occured (~1-3 line of code)

    return false; 
}

/**
 * Check if snake head and walls has collided.
 *
 * @param  posHead  - coordinates of snake's head position
 * @return bool     - True if either X or Y position of head reaches wall coordinates.
 */
bool isCollisionWall(int posHead[2]) {
    // TODO: Return true if collision has occured (~1-3 line of code)

    return false;
}

/**
 * Check if snake head and body has collided.
 *
 * @param  map      - integer array containing information of empty squares, snake and food positions.
   @param  posHead  - coordinates of snake's head position
 * @return bool     - True if both X and Y coordinates of head reaches a +ve square.
 */
bool isCollisionSelf(int map[H][W], int posHead[2]) {
    // TODO: Return true if collision has occured (~1-3 line of code)

    return false;
}

/**
 * Update snake's growth / movement
 *
 * @param  map      - integer array containing information of empty squares, snake and food positions.
   @param  posHead  - coordinates of snake's head position
   @param  posFood  - coordinates of food's position
   @param  length   - current length of snake
 * @return void
 */
void update(int map[H][W], int posHead[2], int posFood[2], int length) {

    // TODO: Check if food has been 'eaten' by the snake. (~8 lines of code)
    if (false) {

        // TODO: If food is eaten, call the (completed) functions to extend snake and regenerate food

    }

    else {
        // Else, move the snake by extending snake and reducing snake. Call the (completed) functions that will cause it to move
        // If the below functions (and updateHeadPosition) are implemented correctly, you should be able to move the snake
        extendSnake(map, posHead, length);
        reduceSnake(map);
    }
}

/**
 * Initialize snake's position, printing leftwards from posHead.
 *
 * @param  map      - integer array containing information of empty squares, snake and food positions.
   @param  posHead  - coordinates of snake's head position
   @param  length   - current length of snake
 * @return void
 */
void initializeSnake(int map[H][W], int posHead[2], int length) {
    for (int i = 0; i < length; i++) {
        map[0][posHead[1] - i] = length - i;
    }
}

int main() {

    srand(time(0));              // Initialize a random seed
    double TIMESTEP = 150000;    // Initialize timestep

    int map[H][W] = {};          // Playable map. 0: Empty square. +ve: Snake position, -ve: Food position.
    int direction = 3;           // Command direction, obtained from user input. 0: UP, 1: DOWN, 2: LEFT, 3: RIGHT
    double prevTime = clock();   // Record of clock from previous cycle to ensure 
    
    int length = 3;              // Current length of snake
    int posHead[2] = { 0, 4 };   // Current position of snake's head
    int posFood[2] = { 0, 0 };   // Current position of food

    // Initialize snake and food position on map
    initializeSnake(map, posHead, length);
    generateFood(map, posFood);

    while (1) {

        // Refresh console display
        system("clear");
        render(map, posHead);
        std::cout << "Direction received = " << direction << "\n";

        // Hold program in this loop until timestep of loop passed or key pressed
        while (!isTimeElapsed(prevTime, TIMESTEP) && !isKeyPressed()); 

        // Get commanded direction
        if (isKeyPressed()) direction = getKeyDirection();

        // Update position of snake's head with commanded direction
        updateHeadPosition(posHead, direction); // TODO: Fill in this function!

        // TODO: Check for collisions with walls and body.
        // If collision has occured, print "Game Over" and exit while loop.  (~3 lines of code)
        if (true)
        {

        }

        // Update map
        update(map, posHead, posFood, length);

        // Update length of snake and previous cycle timestamp
        length = map[posHead[0]][posHead[1]];
        prevTime = clock();
    }

    return 1;
}
