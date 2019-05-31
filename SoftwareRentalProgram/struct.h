typedef struct rental {
	int seq;
	char id[20];
	char userName[20];
	int swInfoSeq;
	char swName[80];
	int swSeq; //대여 수락전까지 할당된 라이선스가 없으므로 0
	char rentalDt[15];
	char returnDt[15];
	char status; // 1은 대여신청, 2는 대여중, 3은 반납신청, 4는 반납완료
	char use[100];
}rental;

typedef struct member {
	char id[20];
	char pw[20];
	char name[20];
}member;

typedef struct swInfo {
	int seq;
	char name[50];
	char version[30];
}swInfo;

typedef struct software {
	int swInfoSeq;
	int seq;
	char name[50];
	char license[50];
	char status; //1은 대여가능, 2는 대여중
}software;