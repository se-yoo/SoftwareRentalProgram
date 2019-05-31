// 커서의 위치 이동
void gotoxy(int x, int y);

// 색상변경
void setcolor(int color, int bgcolor);

// 커서 숨김
void Cursor(int n);

// 시작 화면
void StartMenuScreen();

// 로그인 화면
void LoginScreen();

// 로그인 실패 화면
void FailLoginScreen();

// 회원가입 화면
void JoinScreen();

// 회원가입 실패 화면
void FailJoinScreen();

// 관리자 메뉴 화면
void AdminMenuScreen();

// 사용자 메뉴 화면
void UserMenuScreen();

// 대여 수락 화면
void RentalAcceptScreen(rental *retalInfo, int page, int size);

// 반납 확인 화면
void ReturnAcceptScreen(rental *retalInfo, int page, int size);

// 전체 현황 조회 화면
void RentalStatusScreen(rental *rentalInfo, int page, int size);

// 소프트웨어 추가 화면
void AddSoftwareInfoScreen();

// 소프트웨어 라이선스 추가화면
void AddSoftwareScreen(char name[50]);

// 소프트웨어 수정 화면
void UpdateSoftwareScreen(swInfo *sw, int choice);

// 소프트웨어 상세화면
void DetailSoftWareInfoScreen(software *swStock, int page, int size);

// 소프트웨어 관리 화면
void SoftWareInfoListScreen(swInfo *sw, int page, int size);

// 대여 신청 화면(양식입력)
void RentalSoftwareInputScreen(rental tmpRt);

// 대여 신청 화면(소프트웨어 선택)
void RentalRequestScreen(swInfo *sw, int page, int size);

// 반납 신청 화면
void ReturnRequestScreen(rental *rentalInfo, member member, int page, int size);

// 내 현황조회 화면
void MyRentalStatusScreen(rental *rentalInfo, int page, int size);