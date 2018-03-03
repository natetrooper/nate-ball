#include <ncurses.h>
#include <unistd.h>

#define DELAY 35000

int main(int argc, char *argv[]) {
  int x = 0,
      y = 0;
	bool isusecolors=has_colors();
	

	int key=0;
	int score=0;

  int max_x = 0,
      max_y = 0;

  int next_x = 0;
  int next_y = 0;

  int xdirection = 1;
  int ydirection = 1;

  initscr();
  noecho();
  curs_set(FALSE);
	if (isusecolors)
{
start_color();
init_pair(2, COLOR_BLUE, COLOR_BLACK);
init_pair(1, COLOR_WHITE, COLOR_BLACK);
}

  getmaxyx(stdscr, max_y, max_x);

keypad(stdscr, TRUE);

  x = max_x / 2;
  y = max_y / 2;
	int hx = max_x / 2;
	int hy = max_y /2 ;

  while (1) {
    getmaxyx(stdscr, max_y, max_x);

//    y = max_y / 2;

    clear();

	mvprintw(0,15,"NATE'S BALL:  Score=%d  [ up/down/left/right q=quit ]",score);
	if (isusecolors)
		attron(COLOR_PAIR(2));
    mvprintw(y, x, "o");
	if (isusecolors)
		attron(COLOR_PAIR(2));
    refresh();

    usleep(DELAY);
	timeout(1);
	key = getch();
	bool exit = false;
	bool change=false;
	switch (key)
	{
		case KEY_UP:
			ydirection=-1;
			change=true;
			break;
		case KEY_DOWN:
			ydirection=1;
			change=true;
			break;
		case KEY_LEFT:
			xdirection=-1;
			change=true;
			break;
		case KEY_RIGHT:
			xdirection=1;
			change=true;
			break;
		case 'q':
		case 'Q':
			exit=true;
			break;
	}
	if (exit)
		break;

    next_x = x + xdirection;
    next_y = y + ydirection;

    if (next_x >= max_x || next_x < 0) {
      xdirection*= -1;
	score++;
    } else {
      x+= xdirection;
    }
    if (next_y >= max_y || next_y < 0) {
	ydirection*=-1;
	score++;
    } else {
	y+= ydirection;
    }

  }

  endwin();

  return 0;
}
