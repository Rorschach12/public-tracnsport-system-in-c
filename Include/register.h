#ifndef _REGISTER_H_
#define _REGISTER_H_

#include "common.h"
#include "login.h"
#include "lgfunc.h"
//�������ݽ������ݿ�
int input_success(USER *u);

//��input�����ݿ���бȽ�,������ͬ�򷵻�1�����򷵻�0
int has_registered(USER *input);

//��½
int registered();

//���Ƶ�½����
void register_screen();

//��������
void light_register(int flag);

//�ָ�����
void recover_register(int flag);

#endif // !_REGISTER_H_
