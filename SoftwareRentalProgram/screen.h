// Ŀ���� ��ġ �̵�
void gotoxy(int x, int y);

// ���󺯰�
void setcolor(int color, int bgcolor);

// Ŀ�� ����
void Cursor(int n);

// ���� ȭ��
void StartMenuScreen();

// �α��� ȭ��
void LoginScreen();

// �α��� ���� ȭ��
void FailLoginScreen();

// ȸ������ ȭ��
void JoinScreen();

// ȸ������ ���� ȭ��
void FailJoinScreen();

// ������ �޴� ȭ��
void AdminMenuScreen();

// ����� �޴� ȭ��
void UserMenuScreen();

// �뿩 ���� ȭ��
void RentalAcceptScreen(rental *retalInfo, int page, int size);

// �ݳ� Ȯ�� ȭ��
void ReturnAcceptScreen(rental *retalInfo, int page, int size);

// ��ü ��Ȳ ��ȸ ȭ��
void RentalStatusScreen(rental *rentalInfo, int page, int size);

// ����Ʈ���� �߰� ȭ��
void AddSoftwareInfoScreen();

// ����Ʈ���� ���̼��� �߰�ȭ��
void AddSoftwareScreen(char name[50]);

// ����Ʈ���� ���� ȭ��
void UpdateSoftwareScreen(swInfo *sw, int choice);

// ����Ʈ���� ��ȭ��
void DetailSoftWareInfoScreen(software *swStock, int page, int size);

// ����Ʈ���� ���� ȭ��
void SoftWareInfoListScreen(swInfo *sw, int page, int size);

// �뿩 ��û ȭ��(����Է�)
void RentalSoftwareInputScreen(rental tmpRt);

// �뿩 ��û ȭ��(����Ʈ���� ����)
void RentalRequestScreen(swInfo *sw, int page, int size);

// �ݳ� ��û ȭ��
void ReturnRequestScreen(rental *rentalInfo, member member, int page, int size);

// �� ��Ȳ��ȸ ȭ��
void MyRentalStatusScreen(rental *rentalInfo, int page, int size);