#ifndef _PAGE2_H_
#define _PAGE2_H_

typedef struct user {
	char id[24];
	char passward[24];
	char identify[24];
}USER;


//�������ܣ�ҳ��2
int login(USER *u);

//��������
void login_light(int flag);

//�ָ�����
void login_recover(int flag);

//����ҳ���
void page2_screen(void);


#endif