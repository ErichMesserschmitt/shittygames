#include "SnakeRF.h"

void fillfile() {
	FILE*records = fopen("records.txt", "w");
	char record1[5] = "----";
	char record2[5] = "----";
	char record3[5] = "----";
	int rec1 = 0;
	int rec2 = 0;
	int rec3 = 0;
	fprintf(records, "%s %d", record1, rec1);
	fprintf(records, "%s %d", record2, rec2);
	fprintf(records, "%s %d", record3, rec3);
	fclose(records);
}

void checkrecord(int score) {
	reclist tmp;
	records = fopen("records.txt", "r");
	fscanf(records, "%s %d", tmp.name1, &tmp.rec1);
	fscanf(records, "%s %d", tmp.name2, &tmp.rec2);
	fscanf(records, "%s %d", tmp.name3, &tmp.rec3);
	if (score > tmp.rec1) {
		callrecord(1, score);
		return;
	}
	if (score > tmp.rec2) {
		callrecord(2, score);
		return;
	}
	if (score > tmp.rec3) {
		callrecord(3, score);
		return;
	}
}
void callrecord(int pos, int score) {
	reclist tmp;
	reclist tmpmove;
	records = fopen("records.txt", "r");
	fscanf(records, "%s %d", tmp.name1, &tmp.rec1);
	fscanf(records, "%s %d", tmp.name2, &tmp.rec2);
	fscanf(records, "%s %d", tmp.name3, &tmp.rec3);
	fclose(records);
	char name[5];
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (1) {
		setCnslPos(0, 0);
		clear_field();
		borders();
		setCnslPos(0, 0);
		setCnslPos(45, 7);
		printf("%c", 201);
		for (int i = 0; i < 28; ++i) {
			printf("%c", 205);
		}
		printf("%c", 187);
		setCnslPos(45, 8);
		printf("%c   ENTER YOUR NAME '4 sym'  %c", 186, 186);
		setCnslPos(45, 9);
		printf("%c           [    ]           %c", 186, 186);
		setCnslPos(45, 10);
		printf("%c        press 'return'      %c", 186, 186);
		setCnslPos(45, 11);
		printf("%c", 200);
		for (int i = 0; i < 28; ++i) {
			printf("%c", 205);
		}
		printf("%c", 188);
		setCnslPos(58, 9);
		fgets(name, 5, stdin);
		if (strlen(name) > 4)
			continue;
		else break;
	}
	for (int i = 0; i < 4; ++i) {
		name[i] = toupper(name[i]);
	}
	if (pos == 1) {
		tmpmove = tmp;
		strcpy(tmp.name1, name);
		tmp.rec1 = score;
		strcpy(tmp.name2, tmpmove.name1);
		strcpy(tmp.name3, tmpmove.name2);
		tmp.rec2 = tmpmove.rec1;
		tmp.rec3 = tmpmove.rec2;
	}
	if (pos == 2) {
		strcpy(tmp.name2, name);
		tmp.rec2 = score;
		strcpy(tmp.name3, tmpmove.name2);
		tmp.rec3 = tmpmove.rec2;
	}
	if (pos == 3) {
		strcpy(tmp.name3, name);
		tmp.rec3 = score;
	}
	records = fopen("records.txt", "w");
	fprintf(records, "%s %d", tmp.name1, tmp.rec1);
	fprintf(records, "%s %d", tmp.name2, tmp.rec2);
	fprintf(records, "%s %d", tmp.name3, tmp.rec3);
	fclose(records);
	getchar();
	setCnslPos(0, 0);
	clear_field();
	borders();
	setCnslPos(0, 0);
}

void afterpause(bodyframe*head) {
	bodyframe*tmp = head;
	while (tmp != NULL) {
		setCnslPos(tmp->x, tmp->y);
		printf("%c", 248);
		setCnslPos(0, 0);
		tmp = tmp->nextframe;
	}
}

void printcredits() {
	setCnslPos(4, 4);
	printf("Developers: 'W.J. Ehrmantraut & E. Messerschmitt'");
	setCnslPos(4, 6);
	printf("Test: andrik59047, vatasik 'kit' ");
	setCnslPos(4, 8);
	printf("SPECIAL THANKS");
	setCnslPos(4, 9);
	printf("PZ-Zwolf, lexakogut, redfire");
	setCnslPos(0, 0);
	getchar();
	setCnslPos(0, 0);
	clear_field();
	borders();
	setCnslPos(0, 0);
}

void freemem(bodyframe *general){
	bodyframe*run = general;
	bodyframe*tmp;
	while (run != NULL) {
		tmp = run->nextframe;
		free(run);
		run = tmp;
	}
}