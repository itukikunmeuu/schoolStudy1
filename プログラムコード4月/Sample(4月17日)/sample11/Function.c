/**void transSeconds(int sec) {
	int aHor, aMin, aSec;

	//���ȏ��ʂ�A���ꂼ��̌v�Z��1�s�ŏ���
//	aHor = sec / (60 * 60); //���Ԃ����߂�
//	aMin = (sec % (60 * 60)) / 60; //�������߂�
//	aSec = sec % 60; //�b�����߂�

	int tempSec = sec;			//temp:temporary�̗��@�ꎞ�I�Ƀf�[�^��ۑ����Ă���
	aHor = tempSec / (60 * 60); //���Ԃ̌v�Z
	tempSec %= (60 * 60);       //���Ԃ̕�������菜��
	aMin = tempSec / 60;		//���̌v�Z
	tempSec %= 60;
	aSec = tempSec;             //�b�i���̂܂܁j

	printf("%d�b�́A%d����%d��%d�b�ł��B\n", sec, aHor, aMin, aSec);

	return;
}*/