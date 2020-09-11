#ifndef _PAGE2_H_
#define _PAGE2_H_

typedef struct user {
	char id[24];
	char passward[24];
	char identify[24];
}USER;


//函数功能：页面2
int login(USER *u);

//加亮函数
void login_light(int flag);

//恢复函数
void login_recover(int flag);

//绘制页面二
void page2_screen(void);


#endif