// ���� �޴� ����
int startMenuController();

// �α���
void LoginController(int *loginYN, int *isAdmin, member *loginUser);

// ȸ������
void JoinController();

// ������ �޴�
int AdminMenuController();

// ����� �޴�
int UserMenuController();

// �뿩 ���� ����
void RentalAcceptController();

// �ݳ� Ȯ�� ����
void ReturnAcceptController();

// ��ü ��Ȳ ����
void RentalStatusController();

// ����Ʈ���� �߰�
void AddSoftwareController(int swInfoSeq, int newSeq, char name[50], char version[30]);

// ����Ʈ���� ���̼��� �߰�
void AddSoftwareController(int swInfoSeq, int newSeq, char name[50], char version[30]);

// ����Ʈ���� ����
void UpdateSoftwareController(swInfo *sw, int choice);

// ����Ʈ���� ��
void DetailSoftWareInfoController(swInfo *sw, int choice);

// ����Ʈ���� ����
void SoftWareInfoListController();

// �뿩 ��û �Է�
void RentalSoftwareInputController(swInfo swInfo, member user);

// �뿩 ��û ����
void RentalRequestController(member member);

// �ݳ� ��û ����
void ReturnRequestController(member member);

// �� ��Ȳ��ȸ����
void MyRentalStatusController(member member);