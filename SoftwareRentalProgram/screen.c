#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
#include<string.h>
#include "struct.h"

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

void Cursor(int n)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = n;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void StartMenuScreen() {
	system("cls");
	gotoxy(35, 9);
	printf("����Ʈ���� �뿩/���� ���α׷�");
	gotoxy(45, 12);
	printf("�� �� ��");
	gotoxy(45, 14);
	printf("ȸ������");
	gotoxy(45, 16);
	printf("��   ��");
	gotoxy(42, 12);
	printf("��");
}

void LoginScreen() {
	system("cls");
	gotoxy(45, 9);
	printf("�� �� ��");
	gotoxy(39, 12);
	printf("ID : ");
	gotoxy(39, 14);
	printf("PW : ");
}

void FailLoginScreen() {
	system("cls");
	gotoxy(30, 9);
	printf("���̵� ��й�ȣ�� Ȯ�����ּ���");
	gotoxy(34, 11);
	printf("�ƹ�Ű�� ������ ���ư��ϴ�");
}

void JoinScreen() {
	system("cls");
	gotoxy(42, 9);
	printf("ȸ �� �� ��");
	gotoxy(37, 12);
	printf("ID : ");
	gotoxy(37, 14);
	printf("PW : ");
	gotoxy(37, 16);
	printf("PWȮ�� : ");
	gotoxy(37, 18);
	printf("�̸� : ");
}

void FailJoinScreen() {
	system("cls");
	gotoxy(35, 9);
	printf("��й�ȣ�� ���� �ʽ��ϴ�");
	gotoxy(34, 11);
	printf("�ƹ�Ű�� ������ ���ư��ϴ�");
}

void AdminMenuScreen() {
	system("cls");
	gotoxy(35, 9);
	printf("����Ʈ���� �뿩���� ���α׷�");
	gotoxy(45, 12);
	printf("�뿩����");
	gotoxy(45, 14);
	printf("�ݳ�Ȯ��");
	gotoxy(45, 16);
	printf("��ü��Ȳ");
	gotoxy(45, 18);
	printf("S/W ����");
	gotoxy(45, 20);
	printf("�α׾ƿ�");
	gotoxy(42, 12);
	printf("��");
}

void UserMenuScreen() {
	system("cls");
	gotoxy(37, 9);
	printf("����Ʈ���� �뿩 ���α׷�");
	gotoxy(45, 12);
	printf("�뿩��û");
	gotoxy(45, 14);
	printf("�ݳ���û");
	gotoxy(45, 16);
	printf("�� ��Ȳ");
	gotoxy(45, 18);
	printf("�α׾ƿ�");
	gotoxy(42, 12);
	printf("��");
}

void RentalAcceptScreen(rental *rentalInfo, int page, int size) {
	system("cls");
	gotoxy(1, 1);
	printf("[ �뿩 ���� ]");
	gotoxy(90, 1);
	printf("PAGE %d/%d", page, (size / 10) + 1);
	gotoxy(0, 2);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(2, 4);
	printf("%-5s%-40s%-15s%-10s%-40s", "����", "����Ʈ�����", "�뿩��", "��û��¥", "����");
	gotoxy(0, 6);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(0, 27);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");

	if (page > 0) {
		gotoxy(1, 28);
		printf("ENTER: �ش� �뿩��û ���� / ESC: �޴�ȭ��");
		gotoxy(2, 7);

		int pg = 0;
		int i = 0;
		while(pg < ((page - 1) * 10 + 10)){
			if (pg >= size)break;
			if (rentalInfo[i].status == '1'&& pg >= (page - 1) * 10) {
				gotoxy(2, 7 + ((pg % 10) * 2));
				printf("%-5s%-40s%-13s%-13s%-40s", "", rentalInfo[i].swName, rentalInfo[i].userName, rentalInfo[i].rentalDt, rentalInfo[i].use);
				pg += 1;
			}
			i++;
		}
	}
	else {
		gotoxy(1, 28);
		printf("ESC: �޴�ȭ��");
		gotoxy(2, 8);
		printf("���� ��ϵ� �뿩 ��û�� �����ϴ�.");
	}
}

void ReturnAcceptScreen(rental *rentalInfo, int page, int size) {
	system("cls");
	gotoxy(1, 1);
	printf("[ �ݳ� Ȯ�� ]");
	gotoxy(90, 1);
	printf("PAGE %d/%d", page, (size / 10) + 1);
	gotoxy(0, 2);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(2, 4);
	printf("%-5s%-35s%-12s%-13s%-40s", "����", "����Ʈ�����", "�뿩��", "�뿩��¥", "���̼���");
	gotoxy(0, 6);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(0, 27);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");

	if (page > 0) {
		gotoxy(1, 28);
		printf("ENTER: �ش� �ݳ���û Ȯ�� / ESC: �޴�ȭ��");
		gotoxy(2, 7);

		int pg = 0;
		int i = 0;
		char license[50];

		while (pg < ((page - 1) * 10 + 10)) {
			if (pg >= size)break;
			if (rentalInfo[i].status == '3'&& pg >= (page - 1) * 10) {
				gotoxy(2, 7 + ((pg % 10) * 2));
				GetLicense(rentalInfo[i].swSeq, license);
				printf("%-5s%-35s%-12s%-13s%-40s", "", rentalInfo[i].swName, rentalInfo[i].userName, rentalInfo[i].rentalDt, license);
				pg += 1;
			}
			i++;
		}
	}
	else {
		gotoxy(1, 28);
		printf("ESC: �޴�ȭ��");
		gotoxy(2, 8);
		printf("���� ��ϵ� �ݳ� ��û�� �����ϴ�.");
	}
}

void RentalStatusScreen(rental *rentalInfo, int page, int size) {//, int sType, char search[30], int aType
	system("mode con:cols=150 lines=30");
	system("cls");
	gotoxy(1, 1);
	printf("[ �뿩 �ݳ� ��ü ��Ȳ ]");
	gotoxy(140, 1);
	printf("PAGE %d/%d", page, (size / 10) + 1);
	gotoxy(0, 2);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(0, 4);
	printf(" %-50s%-12s%-13s%-13s%-50s%-10s", "����Ʈ�����", "�뿩��", "�뿩��¥", "�ݳ���¥", "���̼���","����");
	gotoxy(0, 6);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(0, 27);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");

	if (size > 0) {
		gotoxy(1, 28);
		printf("S: �˻� / A: ���� / ESC: �޴�ȭ��");

		char license[50];

		gotoxy(0, 7);
		for (int i = ((page - 1) * 10); i < ((page - 1) * 10 + 10); i++) {
			if (i >= size)break;

			if(rentalInfo[i].status != '1'&&rentalInfo[i].status!='4')GetLicense(rentalInfo[i].swSeq, license);
			else strcpy(license, "-");

			printf(" %-50s%-12s%-13s%-13s%-50s", rentalInfo[i].swName, rentalInfo[i].userName, rentalInfo[i].rentalDt, rentalInfo[i].returnDt, license);
			switch (rentalInfo[i].status) {
			case '1':
				printf("%-10s\n\n", "�뿩��û"); break;
			case '2':
				printf("%-10s\n\n", "�뿩��"); break;
			case '3':
				printf("%-10s\n\n", "�ݳ���û"); break;
			case '4':
				printf("%-10s\n\n", "�ݳ��Ϸ�"); break;
			default:
				printf("%-10s\n\n", "����"); break;
			}
		}
	}
	else {
		gotoxy(1, 28);
		printf("ESC: �޴�ȭ��");
		gotoxy(2, 8);
		printf("�뿩/�ݳ� ��Ȳ�� �����ϴ�.");
	}
}

void AddSoftwareInfoScreen() {
	system("cls");
	gotoxy(1, 1);
	printf("[ ����Ʈ���� �߰� ]");
	gotoxy(0, 2);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(5, 4);
	printf("����Ʈ�����: ");
	gotoxy(5, 6);
	printf("����: ");
}

void AddSoftwareScreen(char name[50]) {
	system("cls");
	gotoxy(1, 1);
	printf("[ ���̼��� �߰� ] - %s", name);
	gotoxy(0, 2);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(5, 4);
	printf("���̼���: ");
}

void UpdateSoftwareScreen(swInfo *sw, int choice) {
	system("cls");
	gotoxy(1, 1);
	printf("[ ����Ʈ���� ���� ]");
	gotoxy(0, 2);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(5, 4);
	printf("���� ����Ʈ�����: %s", sw[choice].name);
	gotoxy(5, 6);
	printf("���� ����: %s", sw[choice].version);

	gotoxy(5, 10);
	printf("���� ����Ʈ�����: ");
	gotoxy(5, 12);
	printf("���� ����: ");
}

void DetailSoftWareInfoScreen(software *swStock, int page, int size) {

	system("cls");
	gotoxy(90, 1);
	printf("PAGE %d/%d", page, (size / 10) + 1);
	gotoxy(0, 2);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(2, 4);
	printf("%-40s%-40s%-10s", "����Ʈ�����", "���̼���", "����");
	gotoxy(0, 6);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(0, 27);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(1, 28);
	printf("C: Ű �߰� / U: ����Ʈ���� ���� / D: ����Ʈ���� ���� / ��,�� �������̵� / ESC: ����");

	if (size > 0) {
		gotoxy(0, 7);
		for (int i = ((page - 1) * 10); i < ((page - 1) * 10 + 10); i++) {
			if (i >= size)break;
			printf("  %-40s%-40s", swStock[i].name, swStock[i].license);
			switch (swStock[i].status) {
			case '1':
				printf("%-10s\n\n", "�뿩����"); break;
			case '2':
				printf("%-10s\n\n", "�뿩��"); break;
			case '3':
				printf("%-10s\n\n", "�뿩�Ұ�"); break;
			default:
				printf("%-10s\n\n", "����"); break;
			}
		}
	}
	else {
		gotoxy(2, 8);
		printf("��ϵ� ���̼����� �����ϴ�. �߰����ּ���");
	}
}

void SoftWareInfoListScreen(swInfo *sw, int page, int size) {
	system("cls");
	gotoxy(1, 1);
	printf("[ ����Ʈ���� ���� ]");
	gotoxy(90, 1);
	printf("PAGE %d/%d",page,(size/10)+1);
	gotoxy(0, 2);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(2, 4);
	printf("%-5s%-50s%-30s", "����", "����Ʈ�����", "����");
	gotoxy(0, 6);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(0, 27);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");

	if (page > 0) {
		gotoxy(1, 28);
		printf("C: �׸� �߰� / ENTER: �׸� Ű �߰�,����,���� / ESC: �޴�ȭ��");
		gotoxy(2, 7);

		for (int i = ((page-1) * 10); i < ((page - 1) * 10 + 10); i++) {
			if (i >= size)break;
			gotoxy(2, 7+((i%10)*2));
			printf("%-5s%-50s%-30s", "", sw[i].name, sw[i].version);
		}
	}
	else {
		gotoxy(1, 28);
		printf("C: �׸� �߰� / ESC: �޴�ȭ��");
		gotoxy(2, 8);
		printf("��ϵ� ����Ʈ��� �����ϴ�. �߰����ּ���");
	}
}

void RentalSoftwareInputScreen(rental tmpRt) {
	system("cls");
	gotoxy(1, 1);
	printf("[ ����Ʈ���� �뿩 ]");
	gotoxy(0, 2);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(5, 4);
	printf("�뿩 ����Ʈ�����: %s", tmpRt.swName);
	gotoxy(5, 6);
	printf("�뿩��: %s", tmpRt.userName);
	gotoxy(0, 27);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(2, 28);
	printf("* ��û������ ���� ���������� ó���ϹǷ� ����� ������ ������ ������ �� �ֽ��ϴ�.");

	gotoxy(5, 10);
	printf("�̿����: ");
}

void RentalRequestScreen(swInfo *sw, int page, int size) {
	system("cls");
	gotoxy(1, 1);
	printf("[ ����Ʈ���� �뿩 ]");
	gotoxy(90, 1);
	printf("PAGE %d/%d", page, (size / 10) + 1);
	gotoxy(0, 2);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(2, 4);
	printf("%-5s%-50s%-30s", "����", "����Ʈ�����", "����");
	gotoxy(0, 6);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(0, 27);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");

	if (page > 0) {
		gotoxy(1, 28);
		printf("ENTER: �ش� ����Ʈ���� �뿩��û / ESC: �޴�ȭ��");
		gotoxy(2, 7);

		for (int i = ((page - 1) * 10); i < ((page - 1) * 10 + 10); i++) {
			if (i >= size)break;
			gotoxy(2, 7 + ((i % 10) * 2));
			printf("%-5s%-50s%-30s", "", sw[i].name, sw[i].version);
		}
	}
	else {
		gotoxy(1, 28);
		printf("ESC: �޴�ȭ��");
		gotoxy(2, 8);
		printf("��ϵ� ����Ʈ��� �����ϴ�. �����ڿ��� �����ϼ���.");
	}
}

void ReturnRequestScreen(rental *rentalInfo, member member, int page, int size) {
	system("cls");
	gotoxy(1, 1);
	printf("[ ����Ʈ���� �ݳ� ]");
	gotoxy(90, 1);
	printf("PAGE %d/%d", page, (size / 10) + 1);
	gotoxy(0, 2);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(2, 4);
	printf("%-5s%-40s%-15s%-40s", "����", "����Ʈ�����", "�뿩��¥", "���̼���");
	gotoxy(0, 6);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(0, 27);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");

	if (page > 0) {
		gotoxy(1, 28);
		printf("ENTER: �ش� ����Ʈ���� �ݳ� / ESC: �޴�ȭ��");
		gotoxy(2, 7);

		int pg = 0;
		int i = 0;
		char license[50];

		while (pg < ((page - 1) * 10 + 10)) {
			if (pg >= size)break;
			if (rentalInfo[i].status == '2'&& strcmp(rentalInfo[i].id, member.id)==0 && pg >= (page - 1) * 10) {
				gotoxy(2, 7 + ((pg % 10) * 2));
				GetLicense(rentalInfo[i].swSeq, license);
				printf("%-5s%-40s%-15s%-40s", "", rentalInfo[i].swName, rentalInfo[i].rentalDt, license);
				pg += 1;
			}
			i++;
		}
	}
	else {
		gotoxy(1, 28);
		printf("ESC: �޴�ȭ��");
		gotoxy(2, 8);
		printf("�뿩���� ����Ʈ��� �����ϴ�.");
	}
}

void MyRentalStatusScreen(rental *rentalInfo, int page, int size) {//, int sType, char search[30], int aType
	system("mode con:cols=140 lines=30");
	system("cls");
	gotoxy(1, 1);
	printf("[ ���� �뿩 �ݳ� ��Ȳ ]");
	gotoxy(130, 1);
	printf("PAGE %d/%d", page, (size / 10) + 1);
	gotoxy(0, 2);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(0, 4);
	printf(" %-55s%-13s%-13s%-40s%-10s", "����Ʈ�����", "�뿩��¥", "�ݳ���¥", "���̼���", "����");
	gotoxy(0, 6);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
	gotoxy(0, 27);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");

	if (size > 0) {
		gotoxy(1, 28);
		printf("S: �˻� / A: ���� / ESC: �޴�ȭ��");

		char license[50];

		gotoxy(0, 7);
		for (int i = ((page - 1) * 10); i < ((page - 1) * 10 + 10); i++) {
			if (i >= size)break;

			if (rentalInfo[i].status != '1'&&rentalInfo[i].status != '4')GetLicense(rentalInfo[i].swSeq, license);
			else strcpy(license, "-");

			printf(" %-55s%-13s%-13s%-40s", rentalInfo[i].swName, rentalInfo[i].rentalDt, rentalInfo[i].returnDt, license);
			switch (rentalInfo[i].status) {
			case '1':
				printf("%-10s\n\n", "�뿩��û"); break;
			case '2':
				printf("%-10s\n\n", "�뿩��"); break;
			case '3':
				printf("%-10s\n\n", "�ݳ���û"); break;
			case '4':
				printf("%-10s\n\n", "�ݳ��Ϸ�"); break;
			default:
				printf("%-10s\n\n", "����"); break;
			}
		}
	}
	else {
		gotoxy(1, 28);
		printf("ESC: �޴�ȭ��");
		gotoxy(2, 8);
		printf("�뿩/�ݳ� ��Ȳ�� �����ϴ�.");
	}
}