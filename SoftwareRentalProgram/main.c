#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include "struct.h"
#include "controller.h"

int e = 1; //끝나는지 아닌지
int control;
int loginYN = 0;
int isAdmin = 0;
member loginUser;

void main() {
	while (e) {
		system("mode con:cols=100 lines=30"); // 콘솔 창크기
		Cursor(0);

		if (loginYN == 0) {
			control = startMenuController();

			switch (control) {
			case 1:
				LoginController(&loginYN, &isAdmin, &loginUser);
				break;
			case 2:
				JoinController();
				break;
			default:
				e = 0;
				strcpy(loginUser.id, "");
				strcpy(loginUser.name, "");
				system("cls");
				return;
			}
		}
		else {
			if (isAdmin) {
				control = AdminMenuController();

				switch (control) {
				case 1: // 대여수락
					RentalAcceptController();
					break;
				case 2: // 반납확인
					ReturnAcceptController();
					break;
				case 3: // 전체현황 조회
					RentalStatusController();
					break;
				case 4: // 소프트웨어관리
					SoftWareInfoListController();
					break;
				default: // 로그아웃
					loginYN = 0;
					isAdmin = 0;
					strcpy(loginUser.id, "");
					strcpy(loginUser.name, "");
				}
			}
			else {
				control = UserMenuController();

				switch (control) {
				case 1: // 대여신청
					RentalRequestController(loginUser);
					break;
				case 2: // 반납신청
					ReturnRequestController(loginUser);
					break; 
				case 3: // 내 현황조회
					MyRentalStatusController(loginUser);
					break;
				default:
					loginYN = 0;
					strcpy(loginUser.id, "");
					strcpy(loginUser.name, "");
				}
			}
		}
	}
}