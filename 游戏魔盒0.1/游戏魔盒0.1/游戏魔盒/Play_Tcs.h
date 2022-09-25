#define SNAKESIZE 100
#define MAPWIDTH 58
#define MAPHEIGHT 18



struct {
	int x;
	int y;
}food;

struct {
	int speed;
	int len;
	int x[SNAKESIZE];
	int y[SNAKESIZE];

}snake;

void Tcs_guize();

void drawMap();

void createFood();

void keyDown();

int snakeStatus();

void gotoxy(int x, int y);

int Play_Tcs();