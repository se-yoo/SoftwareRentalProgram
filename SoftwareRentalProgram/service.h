#include "struct.h"

// ����Ʈ���� ���� ��������(����ü ũ�� �����Ҵ�)
int getSoftwareCnt();

// Ư�� ����Ʈ���� ���̼��� ���� ��������
int getSWStatusCnt(int seq);

// ��� ����Ʈ���� ���̼��� ���� ��������
int getSWStockCnt();

// �뿩/�ݳ� ���� ��������(����ü ũ�� �����Ҵ�)
int getRentalCnt();

// Ư�� ������� �뿩/�ݳ� ���� ��������
int getUserRentalCnt(char id[20]);

// ���¿� ���� �뿩/�ݳ� ���� ��������
int getRentalStatusCnt(char status);

// ȸ���� �ݳ� ���� ��������
int getNowRentalCntByID(char id[20]);

// ����Ʈ���� ���̼��� seq
int GetSoftwareNewSeq();

// �뿩/�ݳ� seq
int GetRentalNewSeq();

// �뿩��û ����
void RentalSoftwareAccept(rental *rentalSw,int seq);

// �ݳ���û Ȯ��
void ReturnSoftwareAccept(rental *rentalSw, int seq);

// �뿩/�ݳ� ����Ʈ
void GetRentalInfoList(rental *rentalInfo, int size);

// Ư�� ������� �뿩/�ݳ� ����Ʈ
void GetUserRentalInfoList(rental *rentalInfo, int size, char id[20]);

// ����Ʈ���� �߰�
void AddSoftwareInfo(int seq, char name[50], char version[30]);

// ����Ʈ���� ���(���̼���)�߰�
void AddSoftware(software swStock);

// ����Ʈ���� ����
void UpdateSoftware(swInfo *sw, int seq);

// ����Ʈ���� ����
void DelSoftwareInfo(swInfo *sw, int seq);

// ����Ʈ���� ����Ʈ
void GetSoftwareInfoList(swInfo *sw, int size);

// ��� ����Ʈ���� ��� ����Ʈ
void GetSoftwareAllList(software *swStock, int size);

// Ư�� ����Ʈ���� ��� ����Ʈ
void GetSoftwareList(software *swStock, int seq);

// Ư�� ����Ʈ���� �뿩���� ���
software * GetPossibleRentalSwList(int seq, int *cnt);

// �뿩��û
void RentalSoftware(rental rentalSw);

// �ݳ���û
void ReturnSoftware(rental *rentalSw);

// ���̼��� ��������
void GetLicense(int seq, char license[50]);

// ����-�뿩��¥ �ֱ�
void sortRentByDateAsc(rental *rt, int n);

// ����-�뿩��¥ �����ȼ�
void sortRentByDateDesc(rental *rt, int n);

// ����-����
void sortRentByStatus(rental *rt, int n);

// ȸ���߰�
void createMember(char id[20], char pw[20], char name[20]);

// ȸ���˻�(�α���)
member searchMember(char id[20], char pw[20]);