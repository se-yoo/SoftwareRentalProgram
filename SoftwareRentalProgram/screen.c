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
	printf("模Щお錚橫 渠罹/婦葬 Щ煎斜極");
	gotoxy(45, 12);
	printf("煎 斜 檣");
	gotoxy(45, 14);
	printf("�蛾灠㊣�");
	gotoxy(45, 16);
	printf("謙   猿");
	gotoxy(42, 12);
	printf("Ⅱ");
}

void LoginScreen() {
	system("cls");
	gotoxy(45, 9);
	printf("煎 斜 檣");
	gotoxy(39, 12);
	printf("ID : ");
	gotoxy(39, 14);
	printf("PW : ");
}

void FailLoginScreen() {
	system("cls");
	gotoxy(30, 9);
	printf("嬴檜蛤釭 綠塵廓�ㄧ� �挫恉媮祤撚�");
	gotoxy(34, 11);
	printf("嬴鼠酈釭 援腦賊 給嬴骨棲棻");
}

void JoinScreen() {
	system("cls");
	gotoxy(42, 9);
	printf("�� 錳 陛 殮");
	gotoxy(37, 12);
	printf("ID : ");
	gotoxy(37, 14);
	printf("PW : ");
	gotoxy(37, 16);
	printf("PW�挫� : ");
	gotoxy(37, 18);
	printf("檜葷 : ");
}

void FailJoinScreen() {
	system("cls");
	gotoxy(35, 9);
	printf("綠塵廓�ㄟ� 蜃雖 彊蝗棲棻");
	gotoxy(34, 11);
	printf("嬴鼠酈釭 援腦賊 給嬴骨棲棻");
}

void AdminMenuScreen() {
	system("cls");
	gotoxy(35, 9);
	printf("模Щお錚橫 渠罹婦葬 Щ煎斜極");
	gotoxy(45, 12);
	printf("渠罹熱塊");
	gotoxy(45, 14);
	printf("奩陶�挫�");
	gotoxy(45, 16);
	printf("瞪羹⑷��");
	gotoxy(45, 18);
	printf("S/W 婦葬");
	gotoxy(45, 20);
	printf("煎斜嬴醒");
	gotoxy(42, 12);
	printf("Ⅱ");
}

void UserMenuScreen() {
	system("cls");
	gotoxy(37, 9);
	printf("模Щお錚橫 渠罹 Щ煎斜極");
	gotoxy(45, 12);
	printf("渠罹褐羶");
	gotoxy(45, 14);
	printf("奩陶褐羶");
	gotoxy(45, 16);
	printf("頂 ⑷��");
	gotoxy(45, 18);
	printf("煎斜嬴醒");
	gotoxy(42, 12);
	printf("Ⅱ");
}

void RentalAcceptScreen(rental *rentalInfo, int page, int size) {
	system("cls");
	gotoxy(1, 1);
	printf("[ 渠罹 熱塊 ]");
	gotoxy(90, 1);
	printf("PAGE %d/%d", page, (size / 10) + 1);
	gotoxy(0, 2);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(2, 4);
	printf("%-5s%-40s%-15s%-10s%-40s", "摹鷗", "模Щお錚橫貲", "渠罹濠", "褐羶陳瞼", "跡瞳");
	gotoxy(0, 6);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(0, 27);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");

	if (page > 0) {
		gotoxy(1, 28);
		printf("ENTER: п渡 渠罹褐羶 熱塊 / ESC: 詭景�飛�");
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
		printf("ESC: 詭景�飛�");
		gotoxy(2, 8);
		printf("億煎 蛔煙脹 渠罹 褐羶檜 橈蝗棲棻.");
	}
}

void ReturnAcceptScreen(rental *rentalInfo, int page, int size) {
	system("cls");
	gotoxy(1, 1);
	printf("[ 奩陶 �挫� ]");
	gotoxy(90, 1);
	printf("PAGE %d/%d", page, (size / 10) + 1);
	gotoxy(0, 2);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(2, 4);
	printf("%-5s%-35s%-12s%-13s%-40s", "摹鷗", "模Щお錚橫貲", "渠罹濠", "渠罹陳瞼", "塭檜摹蝶");
	gotoxy(0, 6);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(0, 27);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");

	if (page > 0) {
		gotoxy(1, 28);
		printf("ENTER: п渡 奩陶褐羶 �挫� / ESC: 詭景�飛�");
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
		printf("ESC: 詭景�飛�");
		gotoxy(2, 8);
		printf("億煎 蛔煙脹 奩陶 褐羶檜 橈蝗棲棻.");
	}
}

void RentalStatusScreen(rental *rentalInfo, int page, int size, int sType, char search[]) {
	system("mode con:cols=150 lines=30");
	system("cls");
	gotoxy(1, 1);
	printf("[ 渠罹 奩陶 瞪羹 ⑷�� ]");
	if (sType == 1)printf("- '%s' 匐儀唸婁", search);
	else if (sType == 2) {
		switch (search[0]) {
		case '1':
			printf("- '渠罹褐羶' 鼻鷓 匐儀唸婁"); break;
		case '2':
			printf("- '渠罹醞' 鼻鷓 匐儀唸婁"); break;
		case '3':
			printf("- '奩陶褐羶' 鼻鷓 匐儀唸婁"); break;
		case '4':
			printf("- '奩陶諫猿' 鼻鷓 匐儀唸婁"); break;
		default:
			printf("- 匐儀 螃盟"); break;
		}
	}
	else if (sType == 3) printf("- '%s' 餌辨濠 匐儀唸婁", search);
	gotoxy(140, 1);
	printf("PAGE %d/%d", page, (size / 10) + 1);
	gotoxy(0, 2);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(0, 4);
	printf(" %-50s%-12s%-13s%-13s%-50s%-10s", "模Щお錚橫貲", "渠罹濠", "渠罹陳瞼", "奩陶陳瞼", "塭檜摹蝶","鼻鷓");
	gotoxy(0, 6);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(0, 27);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");

	if (size > 0) {
		gotoxy(1, 28);
		printf("S: 匐儀 / A: 薑溺 / ESC: 詭景�飛�");

		int pg = 0;
		int i = 0;
		char license[50];

		gotoxy(0, 7);
		while (pg < ((page - 1) * 10 + 10)) {
			if (i >= size)break;
			gotoxy(0, 7 + ((pg % 10) * 2));

			if (sType != 0) {
				if (sType == 1 && strstr(rentalInfo[i].swName, search) == NULL) {
					i++;
					continue;
				}
				if (sType == 2 && rentalInfo[i].status != search[0]) {
					i++;
					continue;
				}
				if (sType == 3 && (strstr(rentalInfo[i].userName, search) == NULL) && (strstr(rentalInfo[i].id, search) == NULL)) {
					i++;
					continue;
				}
			}

			if (rentalInfo[i].status != '1'&&rentalInfo[i].status != '4')GetLicense(rentalInfo[i].swSeq, license);
			else strcpy(license, "-");

			printf(" %-50s%-12s%-13s%-13s%-50s", rentalInfo[i].swName, rentalInfo[i].userName, rentalInfo[i].rentalDt, rentalInfo[i].returnDt, license);
			switch (rentalInfo[i].status) {
			case '1':
				printf("%-10s\n\n", "渠罹褐羶"); break;
			case '2':
				printf("%-10s\n\n", "渠罹醞"); break;
			case '3':
				printf("%-10s\n\n", "奩陶褐羶"); break;
			case '4':
				printf("%-10s\n\n", "奩陶諫猿"); break;
			default:
				printf("%-10s\n\n", "螃盟"); break;
			}
			pg += 1;
			i++;
		}

		if (pg == 0) {
			gotoxy(2, 8);
			printf("匐儀 唸婁陛 橈蝗棲棻.");
		}
	}
	else {
		gotoxy(1, 28);
		printf("ESC: 詭景�飛�");
		gotoxy(2, 8);
		printf("渠罹/奩陶 ⑷�窕� 橈蝗棲棻.");
	}
}

void AddSoftwareInfoScreen() {
	system("cls");
	gotoxy(1, 1);
	printf("[ 模Щお錚橫 蹺陛 ]");
	gotoxy(0, 2);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(5, 4);
	printf("模Щお錚橫貲: ");
	gotoxy(5, 6);
	printf("幗瞪: ");
}

void AddSoftwareScreen(char name[50]) {
	system("cls");
	gotoxy(1, 1);
	printf("[ 塭檜摹蝶 蹺陛 ] - %s", name);
	gotoxy(0, 2);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(5, 4);
	printf("塭檜摹蝶: ");
}

void UpdateSoftwareScreen(swInfo *sw, int choice) {
	system("cls");
	gotoxy(1, 1);
	printf("[ 模Щお錚橫 熱薑 ]");
	gotoxy(0, 2);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(5, 4);
	printf("晦襄 模Щお錚橫貲: %s", sw[choice].name);
	gotoxy(5, 6);
	printf("晦襄 幗瞪: %s", sw[choice].version);

	gotoxy(5, 10);
	printf("滲唳 模Щお錚橫貲: ");
	gotoxy(5, 12);
	printf("滲唳 幗瞪: ");
}

void DetailSoftWareInfoScreen(software *swStock, int page, int size) {

	system("cls");
	gotoxy(90, 1);
	printf("PAGE %d/%d", page, (size / 10) + 1);
	gotoxy(0, 2);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(2, 4);
	printf("%-40s%-40s%-10s", "模Щお錚橫貲", "塭檜摹蝶", "鼻鷓");
	gotoxy(0, 6);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(0, 27);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(1, 28);
	printf("C: 酈 蹺陛 / U: 模Щお錚橫 熱薑 / D: 模Щお錚橫 餉薯 / ∠,⊥ む檜雖檜翕 / ESC: 檜瞪");

	if (size > 0) {
		gotoxy(0, 7);
		for (int i = ((page - 1) * 10); i < ((page - 1) * 10 + 10); i++) {
			if (i >= size)break;
			printf("  %-40s%-40s", swStock[i].name, swStock[i].license);
			switch (swStock[i].status) {
			case '1':
				printf("%-10s\n\n", "渠罹陛棟"); break;
			case '2':
				printf("%-10s\n\n", "渠罹醞"); break;
			case '3':
				printf("%-10s\n\n", "渠罹碳陛"); break;
			default:
				printf("%-10s\n\n", "螃盟"); break;
			}
		}
	}
	else {
		gotoxy(2, 8);
		printf("蛔煙脹 塭檜摹蝶陛 橈蝗棲棻. 蹺陛п輿撮蹂");
	}
}

void SoftWareInfoListScreen(swInfo *sw, int page, int size) {
	system("cls");
	gotoxy(1, 1);
	printf("[ 模Щお錚橫 婦葬 ]");
	gotoxy(90, 1);
	printf("PAGE %d/%d",page,(size/10)+1);
	gotoxy(0, 2);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(2, 4);
	printf("%-5s%-50s%-30s", "摹鷗", "模Щお錚橫貲", "幗瞪");
	gotoxy(0, 6);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(0, 27);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");

	if (page > 0) {
		gotoxy(1, 28);
		printf("C: о跡 蹺陛 / ENTER: о跡 酈 蹺陛,熱薑,餉薯 / ESC: 詭景�飛�");
		gotoxy(2, 7);

		for (int i = ((page-1) * 10); i < ((page - 1) * 10 + 10); i++) {
			if (i >= size)break;
			gotoxy(2, 7+((i%10)*2));
			printf("%-5s%-50s%-30s", "", sw[i].name, sw[i].version);
		}
	}
	else {
		gotoxy(1, 28);
		printf("C: о跡 蹺陛 / ESC: 詭景�飛�");
		gotoxy(2, 8);
		printf("蛔煙脹 模Щお錚橫陛 橈蝗棲棻. 蹺陛п輿撮蹂");
	}
}

void RentalSoftwareInputScreen(rental tmpRt) {
	system("cls");
	gotoxy(1, 1);
	printf("[ 模Щお錚橫 渠罹 ]");
	gotoxy(0, 2);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(5, 4);
	printf("渠罹 模Щお錚橫貲: %s", tmpRt.swName);
	gotoxy(5, 6);
	printf("渠罹濠: %s", tmpRt.userName);
	gotoxy(0, 27);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(2, 28);
	printf("* 蹂羶牖憮縑 評塭 牖離瞳戲煎 籀葬ж嘎煎 營堅陛 睡褶п 熱塊檜 雖翱腆 熱 氈蝗棲棻.");

	gotoxy(5, 10);
	printf("檜辨跡瞳: ");
}

void RentalRequestScreen(swInfo *sw, int page, int size) {
	system("cls");
	gotoxy(1, 1);
	printf("[ 模Щお錚橫 渠罹 ]");
	gotoxy(90, 1);
	printf("PAGE %d/%d", page, (size / 10) + 1);
	gotoxy(0, 2);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(2, 4);
	printf("%-5s%-50s%-30s", "摹鷗", "模Щお錚橫貲", "幗瞪");
	gotoxy(0, 6);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(0, 27);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");

	if (page > 0) {
		gotoxy(1, 28);
		printf("ENTER: п渡 模Щお錚橫 渠罹褐羶 / ESC: 詭景�飛�");
		gotoxy(2, 7);

		for (int i = ((page - 1) * 10); i < ((page - 1) * 10 + 10); i++) {
			if (i >= size)break;
			gotoxy(2, 7 + ((i % 10) * 2));
			printf("%-5s%-50s%-30s", "", sw[i].name, sw[i].version);
		}
	}
	else {
		gotoxy(1, 28);
		printf("ESC: 詭景�飛�");
		gotoxy(2, 8);
		printf("蛔煙脹 模Щお錚橫陛 橈蝗棲棻. 婦葬濠縑啪 僥曖ж撮蹂.");
	}
}

void ReturnRequestScreen(rental *rentalInfo, member member, int page, int size) {
	system("cls");
	gotoxy(1, 1);
	printf("[ 模Щお錚橫 奩陶 ]");
	gotoxy(90, 1);
	printf("PAGE %d/%d", page, (size / 10) + 1);
	gotoxy(0, 2);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(2, 4);
	printf("%-5s%-40s%-15s%-40s", "摹鷗", "模Щお錚橫貲", "渠罹陳瞼", "塭檜摹蝶");
	gotoxy(0, 6);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(0, 27);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");

	if (page > 0) {
		gotoxy(1, 28);
		printf("ENTER: п渡 模Щお錚橫 奩陶 / ESC: 詭景�飛�");
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
		printf("ESC: 詭景�飛�");
		gotoxy(2, 8);
		printf("渠罹醞檣 模Щお錚橫陛 橈蝗棲棻.");
	}
}

void SearchItemScreen(int isAdmin) {
	system("cls");
	gotoxy(63, 9);
	printf("匐儀 о跡 摹鷗");
	gotoxy(65, 12);
	printf("模Щお錚橫貲");
	gotoxy(65, 14);
	printf("渠 罹 ⑷ ��");
	if (isAdmin) {
		gotoxy(65, 16);
		printf("餌 辨 濠 貲");
		gotoxy(65, 18);
		printf("菴 煎 陛 晦");
	}
	else {
		gotoxy(65, 16);
		printf("菴 煎 陛 晦");
	}
	gotoxy(62, 12);
	printf("Ⅱ");
}

void SearchInputScreen() {
	system("cls");
	gotoxy(55, 15);
	printf("匐儀橫 : ");
	Cursor(1);
}

void SearchStatusScreen() {
	system("cls");
	gotoxy(55, 8);
	printf("匐儀й 鼻鷓曖 廓�ㄧ� 殮溘п輿撮蹂");
	gotoxy(63, 11);
	printf("1. 渠 罹 褐 羶");
	gotoxy(63, 13);
	printf("2. 渠 罹 醞");
	gotoxy(63, 15);
	printf("3. 奩 陶 褐 羶");
	gotoxy(63, 17);
	printf("4. 奩 陶 諫 猿");
}

void SortItemScreen() {
	system("cls");
	gotoxy(63, 9);
	printf("薑溺 о跡 摹鷗");
	gotoxy(50, 12);
	printf("渠罹陳瞼 譆斬牖");
	gotoxy(50, 14);
	printf("渠罹陳瞼 螃楚脹牖");
	gotoxy(50, 16);
	printf("鼻鷓(奩陶褐羶,渠罹褐羶,渠罹醞,奩陶諫猿 牖)");
	gotoxy(47, 12);
	printf("Ⅱ");
}

void MyRentalStatusScreen(rental *rentalInfo, int page, int size, int sType, char search[]) {//int aType
	system("mode con:cols=140 lines=30");
	system("cls");
	gotoxy(1, 1);
	printf("[ 釭曖 渠罹 奩陶 ⑷�� ]");
	if (sType == 1)printf("- '%s' 匐儀唸婁", search);
	else if (sType == 2) {
		switch (search[0]) {
		case '1':
			printf("- '渠罹褐羶' 鼻鷓 匐儀唸婁"); break;
		case '2':
			printf("- '渠罹醞' 鼻鷓 匐儀唸婁"); break;
		case '3':
			printf("- '奩陶褐羶' 鼻鷓 匐儀唸婁"); break;
		case '4':
			printf("- '奩陶諫猿' 鼻鷓 匐儀唸婁"); break;
		default:
			printf("- 匐儀 螃盟"); break;
		}
	}
	gotoxy(130, 1);
	printf("PAGE %d/%d", page, (size / 10) + 1);
	gotoxy(0, 2);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(0, 4);
	printf(" %-55s%-13s%-13s%-40s%-10s", "模Щお錚橫貲", "渠罹陳瞼", "奩陶陳瞼", "塭檜摹蝶", "鼻鷓");
	gotoxy(0, 6);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");
	gotoxy(0, 27);
	printf("天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天");

	if (size > 0) {
		gotoxy(1, 28);
		printf("S: 匐儀 / A: 薑溺 / ESC: 詭景�飛�");

		int pg = 0;
		int i = 0;
		char license[50];

		gotoxy(0, 7);
		while (pg < ((page - 1) * 10 + 10)) {
			if (i >= size)break;
			gotoxy(0, 7 + ((pg % 10) * 2));

			if (sType != 0) {
				if (sType == 1 && strstr(rentalInfo[i].swName,search)==NULL) {
					i++;
					continue;
				}
				if (sType == 2 && rentalInfo[i].status != search[0]) {
					i++;
					continue;
				}
			}

			if (rentalInfo[i].status != '1'&&rentalInfo[i].status != '4')GetLicense(rentalInfo[i].swSeq, license);
			else strcpy(license, "-");

			printf(" %-55s%-13s%-13s%-40s", rentalInfo[i].swName, rentalInfo[i].rentalDt, rentalInfo[i].returnDt, license);
			switch (rentalInfo[i].status) {
			case '1':
				printf("%-10s\n\n", "渠罹褐羶"); break;
			case '2':
				printf("%-10s\n\n", "渠罹醞"); break;
			case '3':
				printf("%-10s\n\n", "奩陶褐羶"); break;
			case '4':
				printf("%-10s\n\n", "奩陶諫猿"); break;
			default:
				printf("%-10s\n\n", "螃盟"); break;
			}
			pg += 1;
			i++;
		}

		if (pg == 0) {
			gotoxy(2, 8);
			printf("匐儀 唸婁陛 橈蝗棲棻.");
		}
	}
	else {
		gotoxy(1, 28);
		printf("ESC: 詭景�飛�");
		gotoxy(2, 8);
		printf("渠罹/奩陶 ⑷�窕� 橈蝗棲棻.");
	}
}