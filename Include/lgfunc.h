#ifndef _IGFUNC_H_
#define _IGFUNC_H_

#include "common.h"

//用户名输入函数(color为填充颜色,num为限制输入数字)
void input_id(char *id, int x1, int y1, int num, int color);

//密码输入函数
void input_passward(char *passward, int x1, int y1, int num, int color);

void input_identify(char *passward, int x1, int y1, int num, int color);

//正常返回非0，否则返回1
int ifnormal(char t);




#endif // !_IGFUNC_H_
