#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>
#include <time.h>
#include "struct.h"

int getSoftwareCnt() {
	//파일 읽어서 소프트웨어 개수 구하기
	FILE *fp;
	fp = fopen("swInfo.txt", "r");
	char tmp;
	int cnt = 0;

	if (fp == NULL) {
		return 0;
	}
	while (fscanf(fp, "%c", &tmp) != EOF) {
		if (tmp == '\n')
			cnt++;
	}

	fclose(fp);

	return cnt;
}

int getSWStatusCnt(int seq) {
	//파일 읽어서 소프트웨어 재고 개수 구하기
	FILE *fp;
	fp = fopen("swStatus.txt", "r");
	char tmp[1000];
	int tmpSeq=0;
	int cnt = 0;

	if (fp == NULL) {
		return 0;
	}
	while (fscanf_s(fp, "%d/%[^\n]\n", &tmpSeq, tmp, 1000) != EOF) {
		if (tmpSeq==seq)
			cnt++;
	}

	fclose(fp);

	return cnt;
}

int getSWStockCnt() {
	FILE *fp;
	fp = fopen("swStatus.txt", "r");
	char tmp;
	int cnt = 0;

	if (fp == NULL) {
		return 0;
	}
	while (fscanf(fp, "%c", &tmp) != EOF) {
		if (tmp == '\n')
			cnt++;
	}

	fclose(fp);

	return cnt;
}

int getRentalCnt() {
	FILE *fp;
	fp = fopen("rental.txt", "r");
	char tmp;
	int cnt = 0;

	if (fp == NULL) {
		return 0;
	}
	while (fscanf(fp, "%c", &tmp) != EOF) {
		if (tmp == '\n')
			cnt++;
	}

	fclose(fp);

	return cnt;
}

int getUserRentalCnt(char id[20]) {
	FILE *fp;
	fp = fopen("rental.txt", "r");
	char tmp[1000];
	int tmpSeq = 0;
	char tmpStatus;

	char tmpId[20];
	int cnt = 0;

	if (fp == NULL) {
		return 0;
	}
	while (fscanf_s(fp, "%d/%[^/]/%[^/]/%d/%[^/]/%d/%[^/]/%[^/]/%[^/]/%c\n", &tmpSeq, tmpId, 20, tmp, 20, &tmpSeq, tmp, 80, &tmpSeq, tmp, 15, tmp, 15, tmp, 90, &tmpStatus, 1) != EOF) {
		if (strcmp(tmpId,id) == 0)
			cnt++;
	}

	fclose(fp);

	return cnt;
}

int getRentalStatusCnt(char status){
	FILE *fp;
	fp = fopen("rental.txt", "r");
	char tmp[1000];
	int tmpSeq = 0;
	char tmpStatus;
	int cnt = 0;

	if (fp == NULL) {
		return 0;
	}
	while (fscanf_s(fp, "%d/%[^/]/%[^/]/%d/%[^/]/%d/%[^/]/%[^/]/%[^/]/%c\n", &tmpSeq, tmp, 20, tmp, 20, &tmpSeq, tmp, 80, &tmpSeq, tmp, 15, tmp, 15, tmp, 90, &tmpStatus, 1) != EOF) {
		if (tmpStatus == status)
			cnt++;
	}

	fclose(fp);

	return cnt;
}

int getNowRentalCntByID(char id[20]) {
	FILE *fp;
	fp = fopen("rental.txt", "r");
	char tmp[1000];
	int tmpNum = 0;
	char tmpChar;
	char tmpId[20];
	int cnt = 0;

	if (fp == NULL) {
		return 0;
	}
	while (fscanf_s(fp, "%d/%[^/]/%[^/]/%d/%[^/]/%d/%[^/]/%[^/]/%[^/]/%c\n", &tmpNum, tmpId, 20, tmp, 20, &tmpNum, tmp, 80, &tmpNum, tmp, 15, tmp, 15, tmp, 90, &tmpChar, 1) != EOF) {
		if (strcmp(tmpId,id)==0 && tmpChar=='2')
			cnt++;
	}

	fclose(fp);

	return cnt;
}

void AddSoftwareInfo(int seq, char name[50], char version[30]) {
	FILE *fp;

	fp = fopen("swInfo.txt", "a");
	fprintf(fp, "%d/%s/%s\n", seq, name, version);
	fclose(fp);
}

void AddSoftware(software swStock) {
	FILE *fp;

	fp = fopen("swStatus.txt", "a");
	fprintf(fp, "%d/%d/%s/%s/%c\n", swStock.swInfoSeq,swStock.seq,swStock.name,swStock.license,'1');
	fclose(fp);
}

void GetSoftwareInfoList(swInfo *sw, int size) {
	FILE *fp;
	
	fp = fopen("swInfo.txt", "r");

	if (fp == NULL) {
		return;
	}
	for (int i = 0; i < size; i++) {
		fscanf_s(fp, "%d/%[^/]/%[^/^\n]\n", &sw[i].seq, sw[i].name, 50, sw[i].version, 30);
		//[^/]은 /을 제외한 모든 문자열을 받는다는 의미(공백포함하기 위해)
	}
	fclose(fp);
}

void GetRentalInfoList(rental *rentalInfo, int size) {
	FILE *fp;
	
	fp = fopen("rental.txt", "r");

	if (fp == NULL) {
		return;
	}
	for (int i = 0; i < size; i++) {
		fscanf_s(fp, "%d/%[^/]/%[^/]/%d/%[^/]/%d/%[^/]/%[^/]/%[^/]/%c\n", &rentalInfo[i].seq, rentalInfo[i].id, 20, rentalInfo[i].userName, 20, &rentalInfo[i].swInfoSeq, rentalInfo[i].swName, 80, &rentalInfo[i].swSeq, rentalInfo[i].rentalDt, 15, rentalInfo[i].returnDt, 15, rentalInfo[i].use, 90, &rentalInfo[i].status, 1);
	}
	fclose(fp);
}

void GetUserRentalInfoList(rental *rentalInfo, int size, char id[20]) {
	FILE *fp;

	rental tmp;
	int i = 0;

	fp = fopen("rental.txt", "r");

	if (fp == NULL) {
		return;
	}
	while (fscanf_s(fp, "%d/%[^/]/%[^/]/%d/%[^/]/%d/%[^/]/%[^/]/%[^/]/%c\n", &tmp.seq, tmp.id, 20, tmp.userName, 20, &tmp.swInfoSeq, tmp.swName, 80, &tmp.swSeq, tmp.rentalDt, 15, tmp.returnDt, 15, tmp.use, 90, &tmp.status,1 ) != EOF) {
		if (strcmp(tmp.id,id)==0) {
			rentalInfo[i].seq=tmp.seq;
			strcpy(rentalInfo[i].id, tmp.id);
			strcpy(rentalInfo[i].userName, tmp.userName);
			rentalInfo[i].swInfoSeq = tmp.swInfoSeq;
			strcpy(rentalInfo[i].swName, tmp.swName);
			rentalInfo[i].swSeq = tmp.swSeq;
			strcpy(rentalInfo[i].rentalDt, tmp.rentalDt);
			strcpy(rentalInfo[i].returnDt, tmp.returnDt);
			strcpy(rentalInfo[i].use, tmp.use);
			rentalInfo[i].status = tmp.status;
			i++;
		}
	}
	fclose(fp);
}

void GetSoftwareList(software *swStock, int seq) {
	FILE *fp;
	char tmp[50];
	char tmp2[50];
	char tmp3;
	int tmpSeq = 0;
	int tmpSeq2 = 0;

	int i = 0;

	fp = fopen("swStatus.txt", "r");

	if (fp == NULL) {
		return;
	}

	while (fscanf_s(fp, "%d/%d/%[^/]/%[^/]/%c\n", &tmpSeq, &tmpSeq2, tmp, 50, tmp2, 50, &tmp3, 1) != EOF) {
		if (tmpSeq == seq) {
			swStock[i].swInfoSeq = tmpSeq;
			swStock[i].seq = tmpSeq2;
			strcpy(swStock[i].name, tmp);
			strcpy(swStock[i].license, tmp2);
			swStock[i].status = tmp3;
			i++;
		}
	}
	fclose(fp);
}

void GetSoftwareAllList(software *swStock, int size) {
	FILE *fp;

	fp = fopen("swStatus.txt", "r");

	if (fp == NULL) {
		return;
	}
	for (int i = 0; i < size; i++) {
		fscanf_s(fp, "%d/%d/%[^/]/%[^/]/%c\n", &swStock[i].swInfoSeq, &swStock[i].seq, swStock[i].name, 50, swStock[i].license, 50, &swStock[i].status, 1);
	}
	fclose(fp);
}

int GetSoftwareNewSeq() {
	FILE *fp;
	int tmp1;
	char tmp[120];
	int whileCnt = 0;
	int seq=0;

	fp = fopen("swStatus.txt", "r");

	if (fp == NULL) {
		return 0;
	}
	while(fscanf_s(fp, "%d/%d/%[^\n]\n", &tmp1, &seq, tmp, 120) != EOF) { whileCnt++; }
	if (whileCnt == 0)seq = 0;
	
	seq += 1;

	fclose(fp);

	return seq;
}

int GetRentalNewSeq() {
	FILE *fp;
	char tmp[250];
	int whileCnt = 0;
	int seq = 0;

	fp = fopen("rental.txt", "r");

	if (fp == NULL) {
		return 0;
	}
	while (fscanf_s(fp, "%d/%[^\n]\n", &seq, tmp, 250) != EOF) { whileCnt++; }
	if (whileCnt == 0)seq = 0;
	
	seq += 1;

	fclose(fp);
	return seq;
}

void RentalSoftwareAccept(rental *rentalSw,int seq) {
	FILE *fp; 

	int size = getRentalCnt();

	fp = fopen("rental.txt", "w");
	fprintf(fp, "");
	fclose(fp);

	fp = fopen("rental.txt", "a");
	for (int i = 0; i < size; i++) {
		fprintf(fp, "%d/%s/%s/%d/%s/%d/%s/%s/%s/%c\n", rentalSw[i].seq, rentalSw[i].id, rentalSw[i].userName, rentalSw[i].swInfoSeq, rentalSw[i].swName, rentalSw[i].swSeq, rentalSw[i].rentalDt, rentalSw[i].returnDt, rentalSw[i].use, rentalSw[i].status);
	}

	fclose(fp);

	int size2 = getSWStockCnt();

	software *tmp = (software *)malloc((size2) * sizeof(software));
	GetSoftwareAllList(tmp, size2);

	fp = fopen("swStatus.txt", "w");
	fprintf(fp, "");
	fclose(fp);

	fp = fopen("swStatus.txt", "a");
	for (int i = 0; i < size2; i++) {
		if (tmp[i].seq != rentalSw[seq].swSeq)
			fprintf(fp, "%d/%d/%s/%s/%c\n", tmp[i].swInfoSeq, tmp[i].seq, tmp[i].name, tmp[i].license, tmp[i].status);
		else
			fprintf(fp, "%d/%d/%s/%s/%c\n", tmp[i].swInfoSeq, tmp[i].seq, tmp[i].name, tmp[i].license, '2');
	}
	fclose(fp);
}

void ReturnSoftwareAccept(rental *rentalSw, int seq) {
	struct tm *t;
	time_t timer;

	timer = time(NULL);
	t = localtime(&timer);
	sprintf(rentalSw[seq].returnDt, "%04d-%02d-%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);

	FILE *fp;

	int size = getRentalCnt();

	fp = fopen("rental.txt", "w");
	fprintf(fp, "");
	fclose(fp);

	fp = fopen("rental.txt", "a");
	for (int i = 0; i < size; i++) {
		fprintf(fp, "%d/%s/%s/%d/%s/%d/%s/%s/%s/%c\n", rentalSw[i].seq, rentalSw[i].id, rentalSw[i].userName, rentalSw[i].swInfoSeq, rentalSw[i].swName, rentalSw[i].swSeq, rentalSw[i].rentalDt, rentalSw[i].returnDt, rentalSw[i].use, rentalSw[i].status);
	}

	fclose(fp);

	int size2 = getSWStockCnt();

	software *tmp = (software *)malloc((size2) * sizeof(software));
	GetSoftwareAllList(tmp, size2);

	fp = fopen("swStatus.txt", "w");
	fprintf(fp, "");
	fclose(fp);

	fp = fopen("swStatus.txt", "a");
	for (int i = 0; i < size2; i++) {
		if (tmp[i].seq != rentalSw[seq].swSeq)
			fprintf(fp, "%d/%d/%s/%s/%c\n", tmp[i].swInfoSeq, tmp[i].seq, tmp[i].name, tmp[i].license, tmp[i].status);
		else
			fprintf(fp, "%d/%d/%s/%s/%c\n", tmp[i].swInfoSeq, tmp[i].seq, tmp[i].name, tmp[i].license, '1');
	}
	fclose(fp);
}

void UpdateSoftware(swInfo *sw, int seq) {
	FILE *fp;
	int idx = 0;//수정한 소프트웨어 인덱스
	int sum = 0;

	int size = getSoftwareCnt();

	fp = fopen("swInfo.txt", "w");
	fprintf(fp, "");
	fclose(fp);

	fp = fopen("swInfo.txt", "a");
	for (int i = 0; i < size; i++) {
		fprintf(fp, "%d/%s/%s\n", sw[i].seq, sw[i].name, sw[i].version);
		if (sw[i].seq == seq)idx = i;
		sum += getSWStatusCnt(sw[i].seq);
	}

	fclose(fp);

	char newName[50];
	strcpy(newName, sw[idx].name);
	strcat(strcat(newName, " "), sw[idx].version);

	software *tmp = (software *)malloc((sum) * sizeof(software));
	GetSoftwareAllList(tmp, sum);

	fp = fopen("swStatus.txt", "w");
	fprintf(fp, "");
	fclose(fp);

	fp = fopen("swStatus.txt", "a");
	for (int i = 0; i < sum; i++) {
		if (tmp[i].swInfoSeq != seq)
			fprintf(fp, "%d/%d/%s/%s/%c\n", tmp[i].swInfoSeq, tmp[i].seq, tmp[i].name, tmp[i].license, tmp[i].status);
		else
			fprintf(fp, "%d/%d/%s/%s/%c\n", tmp[i].swInfoSeq, tmp[i].seq, newName, tmp[i].license, tmp[i].status);
	}
	fclose(fp);
}

void DelSoftwareInfo(swInfo *sw, int seq) {
	FILE *fp;
	int idx = 0;//삭제한 소프트웨어 인덱스
	int sum = 0;

	int size = getSoftwareCnt();

	fp = fopen("swInfo.txt", "w");
	fprintf(fp, "");
	fclose(fp);

	fp = fopen("swInfo.txt", "a");
	for (int i = 0; i < size; i++) {
		if (sw[i].seq == seq)idx = i;
		else fprintf(fp, "%d/%s/%s\n", sw[i].seq, sw[i].name, sw[i].version);
		sum += getSWStatusCnt(sw[i].seq);
	}

	fclose(fp);
	
	software *tmp = (software *)malloc((sum) * sizeof(software));
	GetSoftwareAllList(tmp, sum);

	fp = fopen("swStatus.txt", "w");
	fprintf(fp, "");
	fclose(fp);

	fp = fopen("swStatus.txt", "a");
	for (int i = 0; i < sum; i++) {
		if (tmp[i].swInfoSeq != seq)
			fprintf(fp, "%d/%d/%s/%s/%c\n", tmp[i].swInfoSeq, tmp[i].seq, tmp[i].name, tmp[i].license, tmp[i].status);
	}
	fclose(fp);
}

software * GetPossibleRentalSwList(int seq, int *cnt) {
	FILE *fp;
	fp = fopen("swStatus.txt", "r");
	char tmp[50];
	char tmp2[50];
	char tmp3;
	int tmpSeq = 0;
	int tmpSeq2 = 0;

	if (fp == NULL) {
		return 0;
	}
	while (fscanf_s(fp, "%d/%d/%[^/]/%[^/]/%c\n", &tmpSeq, &tmpSeq2, tmp, 50, tmp2, 50, &tmp3, 1) != EOF) {
		if (tmpSeq == seq && tmp3 == '1')
			(*cnt)++;
	}

	fclose(fp);

	software *sw = (software *)malloc((*cnt) * sizeof(software));

	int i = 0;

	fp = fopen("swStatus.txt", "r");

	if (fp == NULL) {
		return 0;
	}

	while (fscanf_s(fp, "%d/%d/%[^/]/%[^/]/%c\n", &tmpSeq, &tmpSeq2, tmp, 50, tmp2, 50, &tmp3, 1) != EOF) {
		if (tmpSeq == seq && tmp3 == '1') {
			sw[i].swInfoSeq = tmpSeq;
			sw[i].seq = tmpSeq2;
			strcpy(sw[i].name, tmp);
			strcpy(sw[i].license, tmp2);
			sw[i].status = tmp3;
			i++;
		}
	}
	fclose(fp);

	return sw;
}

void RentalSoftware(rental rentalSw) {
	struct tm *t;
	time_t timer;

	timer = time(NULL);
	t = localtime(&timer);
	sprintf(rentalSw.rentalDt, "%04d-%02d-%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);

	FILE *fp;
	fp = fopen("rental.txt", "a");
	fprintf(fp, "%d/%s/%s/%d/%s/%d/%s/%s/%s/%c\n", rentalSw.seq, rentalSw.id, rentalSw.userName, rentalSw.swInfoSeq, rentalSw.swName, 0, rentalSw.rentalDt,"-",rentalSw.use, '1');

	fclose(fp);
}

void ReturnSoftware(rental *rentalSw) {
	FILE *fp;

	int size = getRentalCnt();

	fp = fopen("rental.txt", "w");
	fprintf(fp, "");
	fclose(fp);

	fp = fopen("rental.txt", "a");
	for (int i = 0; i < size; i++) {
		fprintf(fp, "%d/%s/%s/%d/%s/%d/%s/%s/%s/%c\n", rentalSw[i].seq, rentalSw[i].id, rentalSw[i].userName, rentalSw[i].swInfoSeq, rentalSw[i].swName, rentalSw[i].swSeq, rentalSw[i].rentalDt, rentalSw[i].returnDt, rentalSw[i].use, rentalSw[i].status);
	}

	fclose(fp);
}

void GetLicense(int seq, char license[50]) {
	int tmp;
	char tmpChar;
	char tmpString[50];

	int tmpSeq;
	char tmpLicense[50];

	FILE *fp;

	fp = fopen("swStatus.txt", "r");

	if (fp == NULL) {
		return;
	}

	while (fscanf_s(fp, "%d/%d/%[^/]/%[^/]/%c\n", &tmp, &tmpSeq, tmpString, 50, tmpLicense, 50, &tmpChar, 1) != EOF) {
		if (tmpSeq == seq && tmpChar == '2') {
			strcpy(license, tmpLicense);
		}
	}
	fclose(fp);
}

void sortRentByStatus(software *sw, int n) {
	int index;
	char tmpName[50], tmpLicense[50], min;

	for (int i = 0; i < n - 1; i++) {
		min = sw[i].status;
		strcpy(tmpName, sw[i].name);
		strcpy(tmpLicense, sw[i].license);
		index = i;
		for (int j = i + 1; j < n; j++) {
			if (min > sw[j].status) {
				strcpy(tmpName, sw[j].name);
				strcpy(tmpLicense, sw[j].license);
				min = sw[j].status;
				index = j;
			}
		}

		strcpy(sw[index].name, sw[i].name);
		strcpy(sw[index].license, sw[i].license);
		sw[index].status = sw[i].status;

		strcpy(sw[i].name, tmpName);
		strcpy(sw[i].license, tmpLicense);
		sw[i].status = min;
	}
}

void serachName(software *sw, int n, char search[]) {
	int result = 0;

	for (int i = 0; i < n; i++) {
		if (strstr(sw[i].name, search) != NULL) {
			printf("%-40s%-40s\t", sw[i].name, sw[i].license);
			if (sw[i].status == '1') printf("%s\n", "대여가능");
			else printf("%s\n", "대여중");

			result++;
		}
	}

	if (result == 0)printf("검색결과가 0건입니다.\n");
}