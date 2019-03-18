#ifndef RFSoo
#define RFSoo
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>
#include <stdarg.h>

#define UP 72
#define DOW 80
#define LEF 75
#define RIG 77
#define ESC 27
#define RET 13
#define UPLRIGD 187
#define UPRLEFD 201
#define DOWLRUP 188
#define DOWRLUP 200
#define HOR 205
#define VER 186
#define FOOD 42

/* SIZE OF FIELD - 120X28  - CLEAR GAMEFIELD - 118X24
TOP L POS CGF-X = 1			TOP L POS CGF-Y = 2
LOW R POS CGF-X = 120		LOW R POS CGF-Y = 28	*/

FILE*records;

typedef struct node {
	int x;
	int y;
	struct node * nextframe;
	//struct node * prevframe;
} bodyframe;
bodyframe*general;
typedef struct food {
	int x;
	int y;
} foodpos;

typedef struct records {
	char name1[5];
	char name2[5];
	char name3[5];
	int rec1;
	int rec2;
	int rec3;
} reclist;

void pause_menu();
void clearCnsl(int x, int y, int clear_x, int clear_y);
void setCnslPos(int x, int y);
char direction_engine(const char direction);
void pause_menu();
void borders();
void main_menu();
void snake_menu_logo();
void clear_field();
void snake_engine(bodyframe**general);
char print_body(bodyframe * head, char direction, char prevdir);
int generatefood(foodpos* coords);
void eatfood(bodyframe* head);
int checkbody(bodyframe*head, int xheadpos, int yheadpos);
void youlose();
void recordslist(FILE*records);
void callrecord(int pos, int score);
void checkrecord(int score);
void afterpause(bodyframe*head);
void printcredits();
void freemem(bodyframe *general);
#endif
