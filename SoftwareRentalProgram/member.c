#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include "struct.h"

void createMember(char id[20],char pw[20], char name[20]) {
	FILE *fp;
	fp = fopen("member.txt", "r");
	char tmpId[20], tmpPw[20], tmpNm[20];

	while (fscanf_s(fp, "%[^/]/%[^/]/%[^/^\n]\n", tmpId, 20, tmpPw, 20, tmpNm, 20) != EOF) {
		if (strcmp(id, tmpId) == 0 || strcmp(id, "admin") == 0) {
			system("cls");
			gotoxy(37, 9);
			printf("존재하는 계정입니다.");
			gotoxy(34, 11);
			printf("아무키나 누르면 돌아갑니다");
			getch();
			fclose(fp);
			return;
		}
	}
	fclose(fp);

	fp = fopen("member.txt", "a");
	fprintf(fp, "%s/%s/%s\n", id, pw, name);
	fclose(fp);
}

member searchMember(char id[20], char pw[20]) {
	member user;
	//초기화
	strcpy(user.id, "");
	strcpy(user.pw, "");

	//admin계정
	if (strcmp(id, "admin") == 0 && strcmp(pw, "admin") == 0) {
		strcpy(user.id, "admin");
		strcpy(user.name, "관리자");
	}
	else {
		//파일 읽어서 회원 확인
		FILE *fp;
		fp = fopen("member.txt", "r");
		char tmpId[20], tmpPw[20], tmpNm[20];

		while (fscanf_s(fp, "%[^/]/%[^/]/%[^/^\n]\n", tmpId, 20, tmpPw, 20, tmpNm, 20)!=EOF) {
			if (strcmp(id, tmpId) == 0 && strcmp(pw, tmpPw) == 0) {
				strcpy(user.id, id);
				strcpy(user.name, tmpNm);
				break;
			}
		}
	}

	return user;
}