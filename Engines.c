#include "SnakeRF.h"

char direction_engine(const char direction){
HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);
char catched;
while(13) {
	if (_kbhit()) {
		catched = _getch();
		switch(catched){
		case UP:
			if (direction == DOW)
			return(direction);
			else return(catched);
			break;
		case DOW:
			if (direction == UP)
			return(direction);
			else return(catched);
			break;
		case RIG:
			if (direction == LEF)
			return(direction);
			else return(catched);
			break;
		case LEF:
			if (direction == RIG)
			return(direction);
			else return(catched);
			break;
		}
		if (catched == ESC) {
			return(catched);
		}
		FlushConsoleInputBuffer(hStdIn);
	}
	else return 0;
}
}

void snake_engine(bodyframe**general) {
	int score = 1;
	int time = 150;
	int timecounter = 0;
	int speedcounter = 1;
	bodyframe* head;
	bodyframe* nframe;
	bodyframe* tmp;
	foodpos coords;
	coords.x = 0; coords.y = 0;
	int iseaten = 1;
	head = (bodyframe*)malloc(sizeof(bodyframe));
	*general = head;
	head->nextframe = NULL;
	head->x = 7;
	head->y = 7;
	setCnslPos(7, 7);
	printf("%c", HOR);
	nframe = (bodyframe*)malloc(sizeof(bodyframe));
	head->nextframe = nframe;
	nframe->x = 6;
	nframe->y = 7;
	setCnslPos(6, 7);
	printf("%c", HOR);
	nframe->nextframe = NULL;
	tmp = (bodyframe*)malloc(sizeof(bodyframe));
	tmp->x = 5;
	tmp->y = 7;
	setCnslPos(5, 7);
	printf("%c", HOR);
	nframe->nextframe = tmp;
	tmp->nextframe = NULL;
	char tdirection;
	char direction = UP;
	char prevdir = RIG;
	while (13) {
		tdirection = direction_engine(direction);
		if (tdirection == ESC) {
			pause_menu();
			tdirection = prevdir;
			setCnslPos(coords.x, coords.y);
			printf("%c", FOOD);
			setCnslPos(0, 0);
		}
		if (tdirection)
			direction = tdirection;
		if (coords.x == head->x&&coords.y == head->y) {
			eatfood(head);
			score += 12 + speedcounter;
			setCnslPos(90, 0);
			printf("Speed: %-3d Score: %-5d",speedcounter, score);
			setCnslPos(0, 0);
			++timecounter;
			if (timecounter == 5) {
				timecounter = 0;
				time -= 10;
				++speedcounter;
			}
			iseaten = 1;
		}
		if (iseaten) {
			iseaten = generatefood(&coords);
			setCnslPos(coords.x, coords.y);
			printf("%c", FOOD);
			setCnslPos(0, 0);
		}
		prevdir = print_body(head, direction, prevdir);
		if (checkbody(head, head->x, head->y)) {
			youlose();
			freemem(*general);
			checkrecord(score);
			return;
		}
		
		Sleep(time);
	}
}
char print_body(bodyframe * head, char direction, char prevdir) {
	bodyframe* nframe;
	bodyframe tempcoord;
	bodyframe tmp;
	char symb;
	nframe = head;
	switch(direction){
	case UP: {
			switch (prevdir) {
			case RIG: {
				symb = DOWLRUP;
				break;
			}
			case LEF: {
				symb = DOWRLUP;
				break;
			}
			case UP:
			case DOW:
				
				symb = VER;
				break;
			}
			break;
		}
	case DOW:
	{
		switch (prevdir) {
		case RIG: {
			symb = UPLRIGD;
			break;
		}
		case LEF: {
			symb = UPRLEFD;
			break;
		}
		case DOW:
		case UP:
			
			symb = VER;
			break;
		}
		break;
	}
	case RIG:
	{
		switch (prevdir) {
		case UP: {
			symb = UPRLEFD;
			break;
		}
		case DOW: {
			symb = DOWRLUP;
			break;
		}
		case RIG:
		case LEF:
			
			symb = HOR;
			break;
		}
		break;
	}
	case LEF:
	{
		switch (prevdir) {
		case UP: {
			symb = UPLRIGD;
			break;
		}
		case DOW: {
			symb = DOWLRUP;
			break;
		}
		case RIG:
		case LEF:
			
			symb = HOR;
			break;
		}
		break;
	}
	}
	while (nframe->nextframe != NULL) {
		if (nframe == head) {
			tempcoord.x = nframe->x;
			tempcoord.y = nframe->y;
			switch (prevdir) {
			case RIG:
				nframe->x += 1;
				break;
			case LEF:
				nframe->x -= 1;
				break;
			case UP:
				nframe->y -= 1;
				break;
			case DOW:
				nframe->y += 1;
				break;
			}

			switch (nframe->x) {
			case 0:
				nframe->x = 118;
				break;
			case 119:
				nframe->x = 1;
				break;
			}

			switch (nframe->y) {
			case 1:
				nframe->y = 27;
				break;
			case 28:
				nframe->y = 2;
				break;
			}
			setCnslPos(nframe->x, nframe->y);
			printf("%c", symb);
			setCnslPos(0, 0);
			prevdir = direction;
			nframe = nframe->nextframe;
		}
		else {
			tmp.x = nframe->x;
			tmp.y = nframe->y;
			nframe->x = tempcoord.x;
			nframe->y = tempcoord.y;
			tempcoord.x = tmp.x;
			tempcoord.y = tmp.y;
			nframe = nframe->nextframe;
		}
	}
	setCnslPos(nframe->x, nframe->y);
	if (nframe->x == head->x && nframe->y == head->y) {
		setCnslPos(0, 0);
		nframe->x = tempcoord.x;
		nframe->y = tempcoord.y;
		return prevdir;
	}
	printf(" ");
	setCnslPos(0, 0);
	nframe->x = tempcoord.x;
	nframe->y = tempcoord.y;
	return prevdir;
}

void eatfood(bodyframe* head) {
	bodyframe*nframe = head;
	bodyframe*newframe = (bodyframe*)malloc(sizeof(bodyframe));
	while (nframe->nextframe != NULL) {
		nframe = nframe->nextframe;
	}
	nframe->nextframe = newframe;
	newframe->nextframe = NULL;
}

int generatefood(foodpos* coords) {
	int x, y;
	x = rand()%118;
	if (!x)
		x = 3;
	y = rand() % 27;
	if (y < 2)
		y = 3;
	coords->x = x;
	coords->y = y;
	return 0;
}
int checkbody(bodyframe*head, int xheadpos, int yheadpos) {
	bodyframe*nframe = head;
	nframe = nframe->nextframe;
	while (nframe != NULL) {
		if (xheadpos == nframe->x&&yheadpos == nframe->y)
			return 1;
		nframe = nframe->nextframe;
	}
	return 0;
}

