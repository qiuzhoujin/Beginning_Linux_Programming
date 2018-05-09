#include <unistd.h>
#include <stdlib.h>
#include <curses.h>

int main()
{
	initscr();

	move(5, 15);
	printw("%s", "Hello World");
	refresh();

	sleep(2);
	
	endwin();

	return 0;
}
