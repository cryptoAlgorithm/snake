
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "snake.h"
#include "map.h"
#include "Configuration.h"

// Terminal control characters
#define ESC "\033"
#define CLR ESC "[2J" // Escape char for clearing screen and moving to (0, 0)
#define RESET ESC "[0m"

typedef struct {
    uint8_t x;
    uint8_t y;
} Coordinate;

Coordinate snakeHistory[H*W] = { 0 }; // Pieces of snake body

uint8_t direction = 3;           // Command direction, obtained from user input. 0: UP, 1: DOWN, 2: LEFT, 3: RIGHT
uint16_t len = 3;
uint16_t highScore = 0;

Coordinate headPos = { W/2, H/2 };

static void restoreHighScore() {
    FILE* fp = fopen(HIGHSCORE_FILE, "r");
    if (!fp) return; // No high score yet
    fscanf(fp, "%hd", &highScore);
    fclose(fp);
}
static void saveHighScore() {
    FILE* fp = fopen(HIGHSCORE_FILE, "w+");
    if (!fp) {
        printf("High score file open fail!\n");
        return;
    }
    fprintf(fp, "%d", highScore);
    fclose(fp);
}


static void exit_handler() {
    endwin();
    printf("Thank you for playing snake!\n");
}


void init() {
    // Clear the screen
    initscr();
    curs_set(0);

    restoreHighScore(); // Attempt to read last high score from file
    map_Init();
    // Write initial snake body
    for (uint8_t i = 0; i < len; i++) {
        snakeHistory[i] = (Coordinate){ headPos.x-i-1, headPos.y };
    }
}

static void spawnFood() {
    Coordinate newFoodPos;
    do {
        newFoodPos = (Coordinate){ rand()%W, rand()%H };
    } while (map[newFoodPos.y][newFoodPos.x] != TILE_EMPTY);
    map[newFoodPos.y][newFoodPos.x] = TILE_FOOD;
}


static void bodyEnqueue() {
    // Start by moving all body elemens one step backward
    for (uint16_t i = len; i > 0; i--) snakeHistory[i] = (Coordinate){ snakeHistory[i-1].x, snakeHistory[i-1].y };
    // Then, append the new head pos to the start of the history
    snakeHistory[0] = headPos;
}

static void updateHeadPos() {
    // Move body
    bodyEnqueue();
    // Dumbly move head pos, we don't care if we have moved out of bounds because we will check for it later
    switch (direction) { // 0: UP, 1: DOWN, 2: LEFT, 3: RIGHT
        case 0:
            headPos.y -= 1;
            break;
        case 1:
            headPos.y += 1;
            break;
        case 2:
            headPos.x -= 1;
            break;
        case 3:
            headPos.x += 1;
            break;
    }
}

static void die() {
    printf(CLR
        "#########################\n"
        "#  Oops! Game Over ;(  ##\n"
        "#########################\n");
    if (len > highScore) {
        highScore = len;
        printf("New high score: %hd!\n", highScore);
        saveHighScore();
    }
    exit(0);
}


static uint8_t posIsBody(uint8_t x, uint8_t y) {
    for (uint16_t i = 0; i < len; i++) {
        if (x == snakeHistory[i].x && y == snakeHistory[i].y) return 1;
    }
    return 0;
}

static void handleHeadHitbox() {
    if (posIsBody(headPos.x, headPos.y)) {
        die();
        return;
    }
    // Find the square that the head is now on and carry out an action
    switch (map[headPos.y][headPos.x]) {
        case TILE_FOOD:
            len += 1;
            map[headPos.y][headPos.x] = TILE_EMPTY;
            spawnFood();
            bodyEnqueue();
            break;
        case TILE_OBSTACLE:
            die();
    }
}

void render() {
    for (size_t y = 0; y < H; y++) {
        // Move cursor to desired row
        printf("\033[%ld;1H", y+1);
        for (size_t x = 0; x < W; x++) {
            if (x == headPos.x && y == headPos.y) {
                // Print out different chars depending on direction snake is moving
                switch (direction) {
                    case 0:
                    case 1:
                        printf("xx");
                        break;
                    case 2:
                        printf("x-");
                        break;
                    case 3:
                        printf("-x");
                }
                continue;
            }
            if (posIsBody(x, y)) {
                printf("--");
                continue;
            }
            switch (map[y][x]) {
                case TILE_FOOD:
                    printf("$$");
                    break;
                case TILE_OBSTACLE:
                    printf("##");
                    break;
                default:
                    printf("  ");
            }
        }
        printf("\n");
    }
    printf("High Score: %d\n", highScore);
    printf("\n------ DEBUG ------\n");
    printf("Head pos: (%d, %d)\n", headPos.x, headPos.y);
}


int main() {
    // Register exit handler
    atexit(exit_handler);

    srand(time(0));              // Initialize a random seed
    double TIMESTEP = 150000;    // Initialize timestep

    double prevTime = clock();   // Record of clock from previous cycle to ensure 

    // Initialize snake and food position on map
    init();
    spawnFood();

    while (1) {
        // Refresh console display
        render();

        // Hold program in this loop until timestep of loop passed or key pressed
        while (!isTimeElapsed(prevTime, TIMESTEP) && !isKeyPressed()); 

        // Get commanded direction
        if (isKeyPressed()) direction = getKeyDirection();

        // Update position of snake's head with commanded direction
        updateHeadPos();
        handleHeadHitbox();

        // Update previous cycle timestamp
        prevTime = clock();
    }

    return 1;
}
