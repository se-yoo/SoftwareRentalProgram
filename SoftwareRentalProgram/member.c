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
			printf("�����ϴ� �����Դϴ�.");
			gotoxy(34, 11);
			printf("�ƹ�Ű�� ������ ���ư��ϴ�");
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
	//�ʱ�ȭ
	strcpy(user.id, "");
	strcpy(user.pw, "");

	//admin����
	if (strcmp(id, "admin") == 0 && strcmp(pw, "admin") == 0) {
		strcpy(user.id, "admin");
		strcpy(user.name, "������");
	}
	else {
		//���� �о ȸ�� Ȯ��
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