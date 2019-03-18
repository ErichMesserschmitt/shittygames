#include "SnakeRF.h"

void clearCnsl(int x, int y, int clear_x, int clear_y) {
	setCnslPos(x, y);
	for (int j = 0; j < clear_x; ++j) {
		for (int i = 0; i < clear_y; ++i) {
			printf(" ");
		}
		printf("\n");
	}
}
void setCnslPos(int x, int y) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(hConsole, position);
}

void pause_menu() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//system("color F0");
	setCnslPos(45, 7); //19
	printf("%c", 201);
	for (int i = 0; i < 28; ++i) {
		printf("%c", 205);
	}
	printf("%c", 187);
	setCnslPos(45, 8);
	printf("%c         PAUSE MENU         %c", 186, 186);
	setCnslPos(45, 9);
	printf("%c                            %c", 186, 186);
	setCnslPos(45, 10);
	printf("%c           resume           %c", 186, 186);
	setCnslPos(45, 11);
	printf("%c      go to main menu       %c", 186, 186);
	setCnslPos(45, 12);
	printf("%c                            %c", 186, 186);
	setCnslPos(45, 13);
	printf("%c", 200);
	for (int i = 0; i < 28; ++i) {
		printf("%c", 205);
	}
	printf("%c", 188);

	char catched;
	int choice = 0;
	while (13) {
		if (_kbhit()) {
			catched = _getch();
			if (catched == UP) {
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));
				setCnslPos(57, 10);
				printf("RESUME");
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
				setCnslPos(52, 11);
				printf("go to main menu");
				choice = 0;

			}
			if (catched == DOW) {
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
				setCnslPos(52, 11);
				printf("GO TO MAIN MENU");
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
				setCnslPos(57, 10);
				printf("resume");
				choice = 1;
			}

			if (catched == RET) {
				if (!choice) {
					clear_field();
					afterpause(general);
					return 0;
				}
				else {
					clear_field();
					freemem(general);
					main_menu();
				}
			}
		}
		setCnslPos(0, 0);
	}
}
void borders() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	setCnslPos(1, 0);
	printf("snakefarm %c0.13  Ehrmantraut&Messerschmitt", 251);
	setCnslPos(0, 1);
	SetConsoleTextAttribute(hConsole, (WORD)((4 << 4) | 15));
	for (int ix = 0; ix < 120; ++ix) {
		printf(" ");
	}
	for (int i = 0; i < 27; ++i) {
		setCnslPos(0, i + 2);
		printf(" ");
		setCnslPos(119, i + 2);
		printf(" ");
	}
	setCnslPos(0, 28);
	for (int ix = 0; ix < 120; ++ix) {
		printf(" ");
	}
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
}

void main_menu() {
	while (13) {
		borders();
		snake_menu_logo();
	}
}
void snake_menu_logo() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	records = fopen("records.txt", "r");
	setCnslPos(55, 3);
	printf("SNAKE");
	setCnslPos(52, 5);
	printf("start  game");
	setCnslPos(54, 6);
	printf("records");
	setCnslPos(54, 7);
	printf("credits");
	setCnslPos(55, 9);
	printf("exit");

	char catched;
	int button_num = 0;
	while (13) {
		if (_kbhit()) {
			catched = _getch();
			if (catched == UP) {
				--button_num;
				if (button_num == -1) {
					button_num = 3;
				}
				switch (button_num) {
				case 0: {
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));
					setCnslPos(52, 5);
					printf("START  GAME");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(54, 6);
					printf("records");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(54, 7);
					printf("credits");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(55, 9);
					printf("exit");
					break; }
				case 1: {
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(52, 5);
					printf("start  game");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));
					setCnslPos(54, 6);
					printf("RECORDS");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(54, 7);
					printf("credits");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(55, 9);
					printf("exit");
					break; }
				case 2: {
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(52, 5);
					printf("start  game");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(54, 6);
					printf("records");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));
					setCnslPos(54, 7);
					printf("CREDITS");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(55, 9);
					printf("exit");
					break; }
				case 3: {
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(52, 5);
					printf("start  game");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(54, 6);
					printf("records");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
					setCnslPos(55, 9);
					printf("EXIT");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(54, 7);
					printf("credits");
					break; }
				}
			}
			if (catched == DOW) {
				if (button_num == 3) {
					button_num = 0;
				}
				else {
					++button_num;
				}
				switch (button_num) {
				case 0: {
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));
					setCnslPos(52, 5);
					printf("START  GAME");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(54, 6);
					printf("records");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(54, 7);
					printf("credits");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(55, 9);
					printf("exit");
					break; }
				case 1: {
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(52, 5);
					printf("start  game");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));
					setCnslPos(54, 6);
					printf("RECORDS");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(54, 7);
					printf("credits");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(55, 9);
					printf("exit");
					break; }
				case 2: {
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(52, 5);
					printf("start  game");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(54, 6);
					printf("records");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));
					setCnslPos(54, 7);
					printf("CREDITS");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(55, 9);
					printf("exit");
					break; }
				case 3: {
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(52, 5);
					printf("start  game");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(54, 6);
					printf("records");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
					setCnslPos(55, 9);
					printf("EXIT");
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					setCnslPos(54, 7);
					printf("credits");
					break; }
				}
			}

			if (catched == RET) {
				switch (button_num) {
				case 0: {
					clear_field();
					snake_engine(&general);
					return;
				}
				case 1: {
					clear_field();
					setCnslPos(55, 9);
					recordslist(records);
					return;
				}
				case 2: {
					clear_field();
					setCnslPos(45, 9);
					printcredits();
					return;
				}
				case 3: {
					exit(0);
					break;
				}
				}
			}
		}
		setCnslPos(0, 0);
	}
}
void clear_field() {
	clearCnsl(0, 0, 30, 119);
	setCnslPos(0, 0);
	borders();
}
void youlose() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//system("color F0");
	setCnslPos(45, 7); //19
	printf("%c", 201);
	for (int i = 0; i < 28; ++i) {
		printf("%c", 205);
	}
	printf("%c", 187);
	setCnslPos(45, 8);
	printf("%c          YOU LOSE          %c", 186, 186);
	setCnslPos(45, 9);
	printf("%c        press 'return'      %c", 186, 186);
	setCnslPos(45, 10);
	printf("%c", 200);
	for (int i = 0; i < 28; ++i) {
		printf("%c", 205);
	}
	printf("%c", 188);
	getchar();
	setCnslPos(0, 0);
	clear_field();
	borders();
	setCnslPos(0, 0);
}

void recordslist(FILE*records) {
	records = fopen("records.txt", "r");
	char record1[5];
	char record2[5];
	char record3[5];
	int rec1;
	int rec2;
	int rec3;
	fscanf(records, "%s %d", record1, &rec1);
	fscanf(records, "%s %d", record2, &rec2);
	fscanf(records, "%s %d", record3, &rec3);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	setCnslPos(45, 7);
	printf("%c", 201);
	for (int i = 0; i < 28; ++i) {
		printf("%c", 205);
	}
	printf("%c", 187);
	setCnslPos(45, 8);
	printf("%c          RECORDS           %c", 186, 186);
	setCnslPos(45, 9);
	printf("%c %5s    -     %5d       %c", 186, record1, rec1, 186);
	setCnslPos(45, 10);
	printf("%c %5s    -     %5d       %c", 186, record2, rec2, 186);
	setCnslPos(45, 11);
	printf("%c %5s    -     %5d       %c", 186, record3, rec3, 186);
	setCnslPos(45, 12);
	printf("%c          press 'ESC'       %c", 186, 186);
	setCnslPos(45, 13);
	printf("%c", 200);
	for (int i = 0; i < 28; ++i) {
		printf("%c", 205);
	}
	printf("%c", 188);
	char exit = 0;
	while (13) {
		exit = _getch();
		
			if (exit == ESC)
				break;
		
	}
	setCnslPos(0, 0);
	clear_field();
	borders();
	fclose(records);
	setCnslPos(0, 0);
}