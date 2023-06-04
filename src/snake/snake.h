#include <ncurses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

// These utility functions do not need to be modified

/**
 * Function to check if key is hit
 * 
 * @return true if key is pressed
 */
bool isKeyPressed()
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return true;
  }
 
  return false;
}

/**
 * Check if timestep has passed since the previous time stamp.
 *
 * @param  prevTime - Previous time stamp.
 * @return bool     - True if timestep has passed, if not, return False.
 */
bool isTimeElapsed(double prevTime, double timestep) {

    if (clock() - prevTime <= timestep) {
        return false;
    }

    else {
        return true;
    }
}

/**
 * Get commanded direction from console input using standard library functions.
 *
 * @param  void
 * @return dir    - 0: UP, 1: DOWN, 2: LEFT, 3: RIGHT
 */
int getKeyDirection() {

    int dir = 0;

    // Series of commands necessary to extract arrow keys
    getchar();
    getchar();
    int tmp = getchar(); 

    // (Linux) Map the default getchar() values to our preferred values
    if (tmp == 65) dir = 0;
    if (tmp == 66) dir = 1;
    if (tmp == 68) dir = 2;
    if (tmp == 67) dir = 3;

    return dir;
}