typedef struct rental {
	int seq;
	char id[20];
	char userName[20];
	int swInfoSeq;
	char swName[80];
	int swSeq; //�뿩 ���������� �Ҵ�� ���̼����� �����Ƿ� 0
	char rentalDt[15];
	char returnDt[15];
	char status; // 1�� �뿩��û, 2�� �뿩��, 3�� �ݳ���û, 4�� �ݳ��Ϸ�
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
	char status; //1�� �뿩����, 2�� �뿩��
}software;