#include <termios.h>
#include <stdio.h>

//Thanks to niko on stackoverflow

static struct termios old, _new;

/* Initialize _new terminal i/o settings */
void initTermios() 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  _new = old; /* make _new settings same as old settings */
  _new.c_lflag &= ~ICANON; /* disable buffered i/o */
  _new.c_lflag &= ~ECHO; /* set no echo mode */
  tcsetattr(0, TCSANOW, &_new); /* use these _new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character without echo */
char getch() 
{
  char ch;
  initTermios();
  ch = getchar();
  resetTermios();
  return ch;
}
