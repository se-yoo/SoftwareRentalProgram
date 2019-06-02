// 시작 메뉴 조작
int startMenuController();

// 로그인
void LoginController(int *loginYN, int *isAdmin, member *loginUser);

// 회원가입
void JoinController();

// 관리자 메뉴
int AdminMenuController();

// 사용자 메뉴
int UserMenuController();

// 현황조회 검색 항목 선택
void SearchItemController(int *sType, char search[30], int isAdmin);

// 현황조회 정렬 항목 선택
void SortItemController(int *aType);

// 대여 수락 조작
void RentalAcceptController();

// 반납 확인 조작
void ReturnAcceptController();

// 전체 현황 조작
void RentalStatusController(int sType, char search[30], int aType);

// 소프트웨어 추가
void AddSoftwareController(int swInfoSeq, int newSeq, char name[50], char version[30]);

// 소프트웨어 라이선스 추가
void AddSoftwareController(int swInfoSeq, int newSeq, char name[50], char version[30]);

// 소프트웨어 수정
void UpdateSoftwareController(swInfo *sw, int choice);

// 소프트웨어 상세
void DetailSoftWareInfoController(swInfo *sw, int choice);

// 소프트웨어 관리
void SoftWareInfoListController();

// 대여 신청 입력
void RentalSoftwareInputController(swInfo swInfo, member user);

// 대여 신청 조작
void RentalRequestController(member member);

// 반납 신청 조작
void ReturnRequestController(member member);

// 내 현황조회조작 sType: 검색 항목, aType: 정렬 조건
void MyRentalStatusController(member member,int sType, char search[30], int aType);