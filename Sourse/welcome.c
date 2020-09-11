#include "common.h"
#include "welcome.h"

//因为需要返回page值，所以页面的函数需是int型
int welcome(void)
{
	int page = 0;
	
	//防止鼠标在跳转页面时留痕
	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();

	page1_screen();
	
	/*循环，不停地监测异动，当异动导致page值改变，跳转页面*/
	while(1)
	{
		//获取鼠标的位置和状态
		newmouse(&MouseX,&MouseY,&press);
		
		//点击跳转页面框，跳转到login界面
		if(mouse_press(180, 170, 180+280, 170+60) == 1)
		{
			page = 1;//返回1到主函数的页面跳转循环
			break;
		}
		
		//点击退出程序框
		else if(mouse_press(180, 170+60+40, 180+280, 170+60+40+60) == 1)
		{
			page = 4;//返回2到主函数的页面跳转循环
			break;
		}
		//如果点击注册按钮
		if (mouse_press(300, 350, 400, 450)==1)
		{
			page = 3;
			break;
		}
	}
	delay(1000);
	return page;
}

//绘制页面1界面
void page1_screen(void)
{
	cleardevice();//把以前的页面清屏
	
	setbkcolor(BLACK);//背景色设置
	
	setfillstyle(SOLID_FILL, BLUE);//设定蓝色框
	bar(180, 170, 180+280, 170+60);//跳转页面
	puthz(240, 180, "登录", 24, 100, WHITE);
	setfillstyle(SOLID_FILL, RED);//设定红色框
	bar(180, 170 + 60 + 40, 180 + 280, 170 + 60 + 40 + 60);//退出程序
	puthz(240, 280, "退出", 24, 100, WHITE);

	setfillstyle(SOLID_FILL, BLUE);//设定蓝色框
	bar(300, 350, 400, 450);
	puthz(320, 370, "注册", 24, 20, RED);
	
}
	