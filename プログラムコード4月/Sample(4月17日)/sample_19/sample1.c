int main(void)
{
    Student stu[3];



    stu[0].no = 1;
    stu[0].height = 160.0f;
    stu[0].weight = 55.5f;



    stu[1].no = 2;
    stu[1].height = 170.0f;
    stu[1].weight = 65.5f;



    stu[2].no = 3;
    stu[2].height = 150.0f;
    stu[2].weight = 45.5f;



    for (int i = 0; i < 3; i++)
    {
        printf("%d: �g��%fcm�@�̏d%fkg\n", stu[i].no, stu[i].height, stu[i].weight);
    }



    return 0;
}









/*
//�\���̂̕��K



typedef struct TestScore
{
    int kokugo;
    int sansu;
    int rika;
    int syakai;
}TestScore;



//�\���̂̐錾
typedef struct StudentDate
{
    int no;
    float height;
    float weight;



    TestScore score;
}StudentDate;



//���k�̃f�[�^��\������֐�
void disaStudentDate(StudentDate date)
{
    printf("�o�Ȕԍ�%d\n", date.no);
    printf("�g��%f\n", date.height);
    printf("�Z���̓_��%d\n", date.score.sansu);
}



//���k�̏o�Ȕԍ���ύX����֐�
//date: �o�Ȕԍ���ύX���������k�̃f�[�^
//nextNo: �ǂ̏o�Ȕԍ��ɕύX��������
void changeStudentNo(StudentDate* pDate, int nextNo)
{
//    date.no = nextNo;     //�^����ꂽ���k�̃f�[�^�̏o�Ȕԍ��������̒l�ɕύX����
    pDate->no = nextNo;
}



int main(void)
{
    StudentDate student1 = { 10,155.5f,45.8f,{50,60,70,80} };
     //�\���̂̃����o�ɃA�N�Z�X����
     student1.no = 7;
     student1.height = 160.5f;
     student1.weight = 55.5f;
     student1.score.kokugo = 50;
     student1.score.sansu = 60;
     student1.score.rika = 70;
     student1.score.syakai = 80;



     StudentDate student2;



     student2 = student1;

     disaStudentDate(student2);
     changeStudentNo(&student2, 99);   //���k�̏o�Ȕԍ���ύX
     disaStudentDate(student2);       //�������ύX�ł��������m�F




    return 0;
}
*/