class CManiac {
public:
    // �P�� + ���Z�q���`����B
    int operator+() {
        return 2;
    }
};

int main() {
    CManiac maniac;          // �N���X�I�u�W�F�N�g maniac ���쐬����B
    int iValue = +maniac;   // �P����+ ���Z�q�� maniac �ɓK�p����B
    printf("iValue = %d\n", iValue);    // ������ 2 �ɂȂ�܂��B
    return 0;
}