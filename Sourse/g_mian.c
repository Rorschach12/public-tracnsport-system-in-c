#include "g_main.h"

int g_main(USER u)
{

	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(1, LIGHTGRAY);
	bar(180, 200, 350, 280);
	puthz(200, 220, "ÃÜÂëÕıÈ·", 24, 20, RED);
	//delay(3000);
	return 1;
}