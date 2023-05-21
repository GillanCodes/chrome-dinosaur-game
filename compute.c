#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

struct user
{
	char name[20];
	char lastName[20];
	char age[3];
};

void startEngine(int highScore, struct user firstUser);
int computePrize(int score, int usedPrice);
void endGame(int score, int highScore, int diY, int diX, struct firstUser);
void show Dinosaur(int diY, int diX);
void startMenu();
int computeTime(int delayTimer);
int CheckGame(int y, int x, int diY, int diX);

int checkGame(int y, int x, int diY, int dix)
{
	if (diY == y)
	{
		if (abs((diX+14)-x) <= 4)
		{
			return 0;		
		};
	};
	return 1;
};

int computeTime(int delayTime)
{
	if (delayTime >= 250000)
	{
		delayTime -= 900;
	}
	else if (delayTime >= 200000)
	{
		delayTime -= 600;
	}
	else
	{
		delayTime -= 200;
	}
	return delayTime;
};

void startMenu()
{
	struct user firstUser;
	int highScore;
	FILE *highScoreFile;
	highScoreFile = fopen("./highScore.txt", "r");
	fscanf(highScoreFile, "%d", &highScore);
	fclose(highScoreFile);
	int maxX = getmaxx(stdscr)/2;
	int maxY = getmaxy(stdscr)/2;
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(3));
	showTrex(maxY, maxX);
	attroff(COLOR_PAIR(3));
	mvprintw(maxY+1, maxX-28, "Write inputs and press Enter to start Game.");
	mvprintw(maxY+2, maxX-26, "When you had prize, fire it with 'k' key!");
	mvprintw(maxY+3, maxX-21, "You can jump with space key!");
	mvprintw(maxY+4, maxX-15, "Name: ");
	getstr(firstUser.name);
	mvprintw(maxY+5, maxX-15, "Last name: ");
	getstr(firstUser.lastName);
	mvprintw(maxY+6, maxX-15, "Age: ");
	getstr(firstUser.age);
	noecho();
	startEngine(highScore, firstUser);
}

void showDinosaur(int diY, int diX)
{
	static int counter = 0;
	if (counter == 0)
	{
		dinosaur1(diY, diX);
		counter++;
	}
	else
	{
		dinosaur2(diY, diX);
		counter--;
	}
}

void endGame(int Score, int highScore, int diY, int diX, struct user firstUser)
{
	nodelay(stdscr, false);
	init_pair(2, COLOR_RED,COLOR_BLACK);

	if (score > highScore)
	{
		highScore = score;
		FILE *highScoreFile;
		highScoreFile = fopen("./highScore.txt", "w");
		fprintf(highScoreFile, "%d", highScore);
		fclose(highScoreFile);
	}
	int maxX = getmaxx(stdscr)/2;
	int maxY = getmaxy(stdscr)/2;
	attron(COLOR_PAIR(2));
	showLoss(maxY, maxX);
	mvprintw(diY-4, diX, "          X-X ");
	mvprintw(diY, diX, "      ||");
	char toExitKey = getCh();

	if (keyToExit == "r")
	{
		attroff(COLOR_PAIR(2));
		startEngine(highScore, firstUser);
	}
	else if (keyToExit == "q")
	{
		return;
	}
	else 
	{
		endGame(score, highScore, diY, diX, firstUser);
	}
}
