#include "struct.h"

// 소프트웨어 개수 가져오기(구조체 크기 동적할당)
int getSoftwareCnt();

// 특정 소프트웨어 라이선스 개수 가져오기
int getSWStatusCnt(int seq);

// 모든 소프트웨어 라이선스 개수 가져오기
int getSWStockCnt();

// 대여/반납 개수 가져오기(구조체 크기 동적할당)
int getRentalCnt();

// 특정 사용자의 대여/반납 개수 가져오기
int getUserRentalCnt(char id[20]);

// 상태에 따른 대여/반납 개수 가져오기
int getRentalStatusCnt(char status);

// 회원의 반납 개수 가져오기
int getNowRentalCntByID(char id[20]);

// 소프트웨어 라이선스 seq
int GetSoftwareNewSeq();

// 대여/반납 seq
int GetRentalNewSeq();

// 대여신청 수락
void RentalSoftwareAccept(rental *rentalSw,int seq);

// 반납신청 확인
void ReturnSoftwareAccept(rental *rentalSw, int seq);

// 대여/반납 리스트
void GetRentalInfoList(rental *rentalInfo, int size);

// 특정 사용자의 대여/반납 리스트
void GetUserRentalInfoList(rental *rentalInfo, int size, char id[20]);

// 소프트웨어 추가
void AddSoftwareInfo(int seq, char name[50], char version[30]);

// 소프트웨어 재고(라이선스)추가
void AddSoftware(software swStock);

// 소프트웨어 수정
void UpdateSoftware(swInfo *sw, int seq);

// 소프트웨어 삭제
void DelSoftwareInfo(swInfo *sw, int seq);

// 소프트웨어 리스트
void GetSoftwareInfoList(swInfo *sw, int size);

// 모든 소프트웨어 재고 리스트
void GetSoftwareAllList(software *swStock, int size);

// 특정 소프트웨어 재고 리스트
void GetSoftwareList(software *swStock, int seq);

// 특정 소프트웨어 대여가능 재고
software * GetPossibleRentalSwList(int seq, int *cnt);

// 대여신청
void RentalSoftware(rental rentalSw);

// 반납신청
void ReturnSoftware(rental *rentalSw);

// 라이선스 가져오기
void GetLicense(int seq, char license[50]);

// 정렬-대여날짜 최근
void sortRentByDateAsc(rental *rt, int n);

// 정렬-대여날짜 오래된순
void sortRentByDateDesc(rental *rt, int n);

// 정렬-상태
void sortRentByStatus(rental *rt, int n);

// 회원추가
void createMember(char id[20], char pw[20], char name[20]);

// 회원검색(로그인)
member searchMember(char id[20], char pw[20]);