#ifndef _IGFUNC_H_
#define _IGFUNC_H_

#include "common.h"

//�û������뺯��(colorΪ�����ɫ,numΪ������������)
void input_id(char *id, int x1, int y1, int num, int color);

//�������뺯��
void input_passward(char *passward, int x1, int y1, int num, int color);

void input_identify(char *passward, int x1, int y1, int num, int color);

//�������ط�0�����򷵻�1
int ifnormal(char t);




#endif // !_IGFUNC_H_
