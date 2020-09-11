#ifndef _REGISTER_H_
#define _REGISTER_H_

#include "common.h"
#include "login.h"
#include "lgfunc.h"
//输入数据进入数据库
int input_success(USER *u);

//将input与数据库进行比较,存在相同则返回1，否则返回0
int has_registered(USER *input);

//登陆
int registered();

//绘制登陆界面
void register_screen();

//加亮界面
void light_register(int flag);

//恢复界面
void recover_register(int flag);

#endif // !_REGISTER_H_
