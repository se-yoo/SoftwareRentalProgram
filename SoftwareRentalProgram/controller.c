#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
#include<string.h>
#include <conio.h>
#include "service.h"
#include "screen.h"

int startMenuController() {
	int choiceMenu = 0;

	StartMenuScreen();

	int y = 12;
	char input;

	do {
		input = _getch();
		gotoxy(42, y);
		printf(" ");
		if (input == 72 && y != 12) {
			y -= 2;
		}
		else if (input == 80 && y != 16) {
			y += 2;
		}
		gotoxy(42, y);
		printf("▶");
	} while (input != 13);

	switch (y) {
	case 12:
		choiceMenu = 1;
		break;
	case 14:
		choiceMenu = 2;
		break;
	default:
		choiceMenu = 0;
		break;
	}

	return choiceMenu;
}

void LoginController(int *loginYN, int *isAdmin, member *loginUser) {
	char id[20];
	char pw[20];

	LoginScreen();

	gotoxy(45, 12);
	Cursor(1);
	scanf_s("%s", id, 20);
	gotoxy(45, 14);
	Cursor(1);
	int i = 0;
	while (((pw[i] = _getch()) != '\r') && i < 20) {
		if (pw[i] == '\b') {
			if (i > 0)i--;
			gotoxy(45 + i, 14);
			printf(" ");
			gotoxy(45 + i, 14);
		}
		else {
			printf("*");
			i++;
		}
	}
	pw[i] = '\0';
	member user = searchMember(id, pw);

	if (strcmp(user.id, "") == 0) {
		*loginYN = 0;
		FailLoginScreen();
		_getch();
		LoginController(loginYN, isAdmin, loginUser);
	}
	else {
		*loginYN = 1;
		if (strcmp(user.id, "admin") == 0) *isAdmin = 1;
		*loginUser = user;
	}
}

void JoinController() {
	char id[20] = "";
	char pw[20] = "";
	char pw2[20] = "";
	char name[20] = "";

	JoinScreen();

	gotoxy(43, 12);
	Cursor(1);
	scanf_s("%s", id, 20);
	gotoxy(43, 14);
	Cursor(1);
	int i = 0;
	while (((pw[i] = _getch()) != '\r') && i < 20) {
		if (pw[i] == '\b') {
			if (i > 0)i--;
			gotoxy(43 + i, 14);
			printf(" ");
			gotoxy(43 + i, 14);
		}
		else {
			printf("*");
			i++;
		}
	}
	pw[i] = '\0';
	gotoxy(47, 16);
	Cursor(1);
	i = 0;
	while (((pw2[i] = _getch()) != '\r') && i < 20) {
		if (pw2[i] == '\b') {
			if (i > 0)i--;
			gotoxy(47 + i, 16);
			printf(" ");
			gotoxy(47 + i, 16);
		}
		else {
			printf("*");
			i++;
		}
	}
	pw2[i] = '\0';
	gotoxy(45, 18);
	Cursor(1);
	scanf_s("%s", name, 20);

	if (strcmp(pw, pw2) == 0) {
		gotoxy(45, 20);
		createMember(id, pw, name);
	}
	else {
		FailJoinScreen();
		_getch();
		JoinController();
	}
}

int AdminMenuController() {
	int choiceMenu = 0;

	AdminMenuScreen();

	int y = 12;
	char input;

	do {
		input = _getch();
		gotoxy(42, y);
		printf(" ");
		if (input == 72 && y != 12) {
			y -= 2;
		}
		else if (input == 80 && y != 20) {
			y += 2;
		}
		gotoxy(42, y);
		printf("▶");
	} while (input != 13);

	switch (y) {
	case 12:
		choiceMenu = 1;
		break;
	case 14:
		choiceMenu = 2;
		break;
	case 16:
		choiceMenu = 3;
		break;
	case 18:
		choiceMenu = 4;
		break;
	default:
		choiceMenu = 0;
		break;
	}

	return choiceMenu;
}

int UserMenuController() {
	int choiceMenu = 0;

	UserMenuScreen();

	int y = 12;
	char input;

	do {
		input = _getch();
		gotoxy(42, y);
		printf(" ");
		if (input == 72 && y != 12) {
			y -= 2;
		}
		else if (input == 80 && y != 20) {
			y += 2;
		}
		gotoxy(42, y);
		printf("▶");
	} while (input != 13);

	switch (y) {
	case 12:
		choiceMenu = 1;
		break;
	case 14:
		choiceMenu = 2;
		break;
	case 16:
		choiceMenu = 3;
		break;
	default:
		choiceMenu = 0;
		break;
	}

	return choiceMenu;
}

void RentalAcceptController() {
	int size = getRentalCnt();
	int realSize = getRentalStatusCnt('1');
	int choice = 0;
	int page = 1;
	char input;

	if (realSize > 0) {
		rental *rentalInfo = (rental *)malloc((size) * sizeof(rental));
		GetRentalInfoList(rentalInfo, size);
		RentalAcceptScreen(rentalInfo, page, realSize);

		int *rentalRequest= (int *)malloc((realSize) * sizeof(int));
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (rentalInfo[i].status == '1') {
				if (j >= realSize)break;
				rentalRequest[j++] = i;
			}
		}

		gotoxy(2, 7);
		printf("▶");

		do {
			input = _getch();
			gotoxy(2, 7 + (choice % 10 * 2));
			printf(" ");
			if (input == 13) {
				int cnt = 0;
				software *rentalSw = GetPossibleRentalSwList(rentalInfo[rentalRequest[choice]].swInfoSeq, &cnt);
				if (cnt < 1) {
					system("cls");
					gotoxy(34, 9);
					printf("[%s]", rentalInfo[rentalRequest[choice]].swName);
					gotoxy(27, 11);
					printf("현재 대여가능한 상태의 라이선스가 없습니다");
					gotoxy(34, 13);
					printf("아무키나 누르면 돌아갑니다");
					_getch();
				}
				else {
					rentalInfo[rentalRequest[choice]].status = '2';
					rentalInfo[rentalRequest[choice]].swSeq = rentalSw[0].seq;
					RentalSoftwareAccept(rentalInfo, rentalRequest[choice]);
				}
				RentalAcceptController();
				return;
			}
			else if (input == 72 && (choice % 10) > 0) { // 방향키 위
				choice -= 1;
			}
			else if (input == 80 && (choice % 10) < 9 && choice < realSize - 1) { //방향키 아래
				choice += 1;
			}
			else if (input == 72 && choice % 10 == 0 && page != 1) { // 맨 위 항목에서 방향키 위
				page -= 1;
				RentalAcceptScreen(rentalInfo, page, realSize);
				choice -= 1;
			}
			else if (input == 80 && choice % 10 == 9 && page != realSize) { // 맨 아래 항목에서 방향키 아래
				page += 1;
				RentalAcceptScreen(rentalInfo, page, realSize);
				choice += 1;
			}
			gotoxy(2, 7 + (choice % 10 * 2));
			printf("▶");
		} while (input != 27);
	}
	else {
		rental rt;
		RentalAcceptScreen(&rt, 0, realSize);
		do {
			input = _getch();
		} while (input != 27);
	}
}

void ReturnAcceptController() {
	int size = getRentalCnt();
	int realSize = getRentalStatusCnt('3');
	int choice = 0;
	int page = 1;
	char input;

	if (realSize > 0) {
		rental *rentalInfo = (rental *)malloc((size) * sizeof(rental));
		GetRentalInfoList(rentalInfo, size);
		ReturnAcceptScreen(rentalInfo, page, realSize);

		int *returnRequest = (int *)malloc((realSize) * sizeof(int));
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (rentalInfo[i].status == '3') {
				if (j >= realSize)break;
				returnRequest[j++] = i;
			}
		}

		gotoxy(2, 7);
		printf("▶");

		do {
			input = _getch();
			gotoxy(2, 7 + (choice % 10 * 2));
			printf(" ");
			if (input == 13) {
				rentalInfo[returnRequest[choice]].status = '4';
				ReturnSoftwareAccept(rentalInfo, returnRequest[choice]);
				ReturnAcceptController();
				return;
			}
			else if (input == 72 && (choice % 10) > 0) { // 방향키 위
				choice -= 1;
			}
			else if (input == 80 && (choice % 10) < 9 && choice < realSize - 1) { //방향키 아래
				choice += 1;
			}
			else if (input == 72 && choice % 10 == 0 && page != 1) { // 맨 위 항목에서 방향키 위
				page -= 1;
				ReturnAcceptScreen(rentalInfo, page, realSize);
				choice -= 1;
			}
			else if (input == 80 && choice % 10 == 9 && page != realSize) { // 맨 아래 항목에서 방향키 아래
				page += 1;
				ReturnAcceptScreen(rentalInfo, page, realSize);
				choice += 1;
			}
			gotoxy(2, 7 + (choice % 10 * 2));
			printf("▶");
		} while (input != 27);
	}
	else {
		rental rt;
		ReturnAcceptScreen(&rt, 0, realSize);
		do {
			input = _getch();
		} while (input != 27);
	}
}

void RentalStatusController() {
	int size = getRentalCnt();
	int page = 1;
	char input;

	if (size > 0) {
		rental *rentalInfo = (rental *)malloc((size) * sizeof(rental));
		GetRentalInfoList(rentalInfo, size);
		RentalStatusScreen(rentalInfo, page, size);

		do {
			input = _getch();
			if (input == 'S' || input == 's') { // 검색
				
			}
			else if (input == 'A' || input == 'a') { // 정렬
				
			}
			else if (input == 75) { // 왼쪽
				if (page > 1) {
					page--;
					RentalStatusScreen(rentalInfo, page, size);
				}
			}
			else if (input == 77) { // 오른쪽
				if (page < ((size / 10) + 1)) {
					page++;
					RentalStatusScreen(rentalInfo, page, size);
				}
			}
		} while (input != 27);
		system("mode con:cols=100 lines=30");
	}
	else {
		rental rt;
		RentalStatusScreen(&rt, 0, size);
		do {
			input = _getch();
		} while (input != 27);
		system("mode con:cols=100 lines=30");
	}
}

void AddSoftwareInfoController(int seq) {
	char name[50];
	char version[30];

	AddSoftwareInfoScreen();

	gotoxy(20, 4);
	Cursor(1);
	scanf(" %[^\n]s", name);
	gotoxy(11, 6);
	scanf_s(" %[^\n]s", version, 30);
	Cursor(0);

	AddSoftwareInfo(seq, name, version);
}

void AddSoftwareController(int swInfoSeq, int newSeq, char name[50], char version[30]) {
	software tmpSw;

	tmpSw.swInfoSeq = swInfoSeq;
	strcpy(tmpSw.name, name);
	strcat(strcat(tmpSw.name, " "), version);
	tmpSw.seq = newSeq;

	AddSoftwareScreen(name);

	gotoxy(15, 4);
	Cursor(1);
	scanf_s(" %[^\n]s", tmpSw.license, 50);
	Cursor(0);

	AddSoftware(tmpSw);
}

void UpdateSoftwareController(swInfo *sw, int choice) {
	UpdateSoftwareScreen(sw, choice);

	gotoxy(25, 10);
	Cursor(1);
	scanf_s(" %[^\n]s", sw[choice].name, 50);
	gotoxy(16, 12);
	scanf_s(" %[^\n]s", sw[choice].version, 30);
	Cursor(0);

	UpdateSoftware(sw, sw[choice].seq);
}

void DetailSoftWareInfoController(swInfo *sw, int choice) {
	char input;
	int size = getSWStatusCnt(sw[choice].seq);
	int newSeq = GetSoftwareNewSeq();
	int page = 1;

	software *swStock = (software *)malloc((size) * sizeof(software));
	GetSoftwareList(swStock, sw[choice].seq);

	DetailSoftWareInfoScreen(swStock, page, size);
	gotoxy(1, 1);
	printf("[ %s ]", sw[choice].name);

	do {
		input = _getch();
		if (input == 'C' || input == 'c') { // 추가
			AddSoftwareController(sw[choice].seq, newSeq, sw[choice].name, sw[choice].version);
			DetailSoftWareInfoController(sw, choice);
			return;
		}
		else if (input == 'U' || input == 'u') { // 수정
			UpdateSoftwareController(sw, choice);
			DetailSoftWareInfoController(sw, choice);
			return;
		}
		else if (input == 'D' || input == 'd') { // 삭제
			DelSoftwareInfo(sw, sw[choice].seq);
			return;
		}
		else if (input == 75) { // 왼쪽
			if (page > 1) {
				page--;
				DetailSoftWareInfoScreen(swStock, page, size);
				gotoxy(1, 1);
				printf("[ %s ]", sw[choice].name);
			}
		}
		else if (input == 77) { // 오른쪽
			if (page < ((size / 10) + 1)) {
				page++;
				DetailSoftWareInfoScreen(swStock, page, size);
				gotoxy(1, 1);
				printf("[ %s ]", sw[choice].name);
			}
		}
	} while (input != 27);
}

void SoftWareInfoListController() {
	int size = getSoftwareCnt();
	int choice = 0;
	char input;
	int page = 1;

	if (size > 0) {
		swInfo *sw = (swInfo *)malloc((size) * sizeof(swInfo));
		GetSoftwareInfoList(sw, size);
		SoftWareInfoListScreen(sw, page, size);

		gotoxy(2, 7);
		printf("▶");

		do {
			input = _getch();
			gotoxy(2, 7 + (choice % 10 * 2));
			printf(" ");
			if (input == 'C' || input == 'c') { // 추가
				int seq = sw[size - 1].seq + 1;
				AddSoftwareInfoController(seq);
				SoftWareInfoListController();
				return;
			}
			else if (input == 13) {
				DetailSoftWareInfoController(sw, choice);
				SoftWareInfoListController();
				return;
			}
			else if (input == 72 && (choice % 10) > 0) { // 방향키 위
				choice -= 1;
			}
			else if (input == 80 && (choice % 10) < 9 && choice < size - 1) { //방향키 아래
				choice += 1;
			}
			else if (input == 72 && choice % 10 == 0 && page != 1) { // 맨 위 항목에서 방향키 위
				page -= 1;
				SoftWareInfoListScreen(sw, page, size);
				choice -= 1;
			}
			else if (input == 80 && choice % 10 == 9 && page != size) { // 맨 아래 항목에서 방향키 아래
				page += 1;
				SoftWareInfoListScreen(sw, page, size);
				choice += 1;
			}
			gotoxy(2, 7 + (choice % 10 * 2));
			printf("▶");
		} while (input != 27);
	}
	else {
		swInfo sw;
		SoftWareInfoListScreen(&sw, 0, size);
		do {
			input = _getch();
			if (input == 'C' || input == 'c') {
				AddSoftwareInfoController(1);
				SoftWareInfoListController();
				return;
			}
		} while (input != 27);
	}
}

void RentalSoftwareInputController(swInfo swInfo, member user) {
	rental tmpRt;
	sprintf(tmpRt.swName, "%s %s", swInfo.name, swInfo.version);
	tmpRt.swInfoSeq = swInfo.seq;
	tmpRt.swSeq = 0;//대여 수락전까지 할당된 라이선스가 없으므로 0
	strcpy(tmpRt.id, user.id);
	strcpy(tmpRt.userName, user.name);
	tmpRt.seq = GetRentalNewSeq();

	RentalSoftwareInputScreen(tmpRt);

	gotoxy(15, 10);
	Cursor(1);
	scanf_s(" %[^\n]s", tmpRt.use, 100);
	Cursor(0);

	RentalSoftware(tmpRt);
}

void RentalRequestController(member member) {
	int size = getSoftwareCnt();
	int choice = 0;
	int page = 1;
	char input;

	if (size > 0) {
		swInfo *sw = (swInfo *)malloc((size) * sizeof(swInfo));
		GetSoftwareInfoList(sw, size);
		RentalRequestScreen(sw, page, size);

		gotoxy(2, 7);
		printf("▶");

		do {
			input = _getch();
			gotoxy(2, 7 + (choice % 10 * 2));
			printf(" ");
			if (input == 13) {
				int cnt = 0;
				software *retalSw = GetPossibleRentalSwList(sw[choice].seq, &cnt);
				if (cnt < 1) {
					system("cls");
					gotoxy(34, 9);
					printf("[%s %s]", sw[choice].name, sw[choice].version);
					gotoxy(27, 11);
					printf("현재 대여가능한 상태의 라이선스가 없습니다");
					gotoxy(34, 13);
					printf("아무키나 누르면 돌아갑니다");
					_getch();
				}
				else {
					RentalSoftwareInputController(sw[choice], member);
				}
				RentalRequestController(member);//이후에 현황조회 화면으로 수정하기!!
				return;
			}
			else if (input == 72 && (choice % 10) > 0) { // 방향키 위
				choice -= 1;
			}
			else if (input == 80 && (choice % 10) < 9 && choice < size - 1) { //방향키 아래
				choice += 1;
			}
			else if (input == 72 && choice % 10 == 0 && page != 1) { // 맨 위 항목에서 방향키 위
				page -= 1;
				RentalRequestScreen(sw, page, size);
				choice -= 1;
			}
			else if (input == 80 && choice % 10 == 9 && page != size) { // 맨 아래 항목에서 방향키 아래
				page += 1;
				RentalRequestScreen(sw, page, size);
				choice += 1;
			}
			gotoxy(2, 7 + (choice % 10 * 2));
			printf("▶");
		} while (input != 27);
	}
	else {
		swInfo sw;
		RentalRequestScreen(&sw, 0, size);
		do {
			input = _getch();
		} while (input != 27);
	}
}

void ReturnRequestController(member member) {
	int size = getRentalCnt();
	int realSize = getNowRentalCntByID(member.id);
	int choice = 0;
	int page = 1;
	char input;

	if (size > 0) {
		rental *rentalInfo = (rental *)malloc((size) * sizeof(rental));
		GetRentalInfoList(rentalInfo, size);
		ReturnRequestScreen(rentalInfo, member, page, realSize);

		int *retalList = (int *)malloc((realSize) * sizeof(int));
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (rentalInfo[i].status == '2'&& strcmp(rentalInfo[i].id, member.id) == 0) {
				if (j >= realSize)break;
				retalList[j++] = i;
			}
		}

		gotoxy(2, 7);
		printf("▶");

		do {
			input = _getch();
			gotoxy(2, 7 + (choice % 10 * 2));
			printf(" ");
			if (input == 13) {
				rentalInfo[retalList[choice]].status = '3';
				ReturnSoftware(rentalInfo);
				ReturnRequestController(member);//이후에 현황조회 화면으로 수정하기!!
				return;
			}
			else if (input == 72 && (choice % 10) > 0) { // 방향키 위
				choice -= 1;
			}
			else if (input == 80 && (choice % 10) < 9 && choice < realSize - 1) { //방향키 아래
				choice += 1;
			}
			else if (input == 72 && choice % 10 == 0 && page != 1) { // 맨 위 항목에서 방향키 위
				page -= 1;
				ReturnRequestScreen(rentalInfo, member, page, realSize);
				choice -= 1;
			}
			else if (input == 80 && choice % 10 == 9 && page != realSize) { // 맨 아래 항목에서 방향키 아래
				page += 1;
				ReturnRequestScreen(rentalInfo, member, page, realSize);
				choice += 1;
			}
			gotoxy(2, 7 + (choice % 10 * 2));
			printf("▶");
		} while (input != 27);
	}
	else {
		rental rt;
		ReturnRequestScreen(&rt, member, page, realSize);
		do {
			input = _getch();
		} while (input != 27);
	}
}

void MyRentalStatusController(member member) {
	int size = getUserRentalCnt(member.id);
	int page = 1;
	char input;

	if (size > 0) {
		rental *rentalInfo = (rental *)malloc((size) * sizeof(rental));
		GetUserRentalInfoList(rentalInfo, size, member.id);
		MyRentalStatusScreen(rentalInfo, page, size);

		do {
			input = _getch();
			if (input == 'S' || input == 's') { // 검색

			}
			else if (input == 'A' || input == 'a') { // 정렬

			}
			else if (input == 75) { // 왼쪽
				if (page > 1) {
					page--;
					MyRentalStatusScreen(rentalInfo, page, size);
				}
			}
			else if (input == 77) { // 오른쪽
				if (page < ((size / 10) + 1)) {
					page++;
					MyRentalStatusScreen(rentalInfo, page, size);
				}
			}
		} while (input != 27);
		system("mode con:cols=100 lines=30");
	}
	else {
		rental rt;
		MyRentalStatusScreen(&rt, 0, size);
		do {
			input = _getch();
		} while (input != 27);
		system("mode con:cols=100 lines=30");
	}
}