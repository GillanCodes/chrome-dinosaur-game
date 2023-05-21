#include <ncurses.h>

voic dinosaur1(int y, int x)
{
	mvprintw(y-4, x, "          e-e");
	mvprintw(y-3, x, "        /(\\_/)");
	mvprintw(y-2, x, ",___.--` /'-` ");
	mvprintw(y-1, x, " '-._, )/'");
	mvprintw(y, x,   "      \\/");
}
