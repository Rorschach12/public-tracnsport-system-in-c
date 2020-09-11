#include "common.h"
#include "login.h"

//因为需要返回page值，所以页面的函数需是int型
int login(USER *u)
{
	int page = 0;
	int accountS, passwardS;	//accountS标识账号是否为空，passwardS标识密码是否为空
	int num;	//用于恢复界面,和帮助减少运行

	accountS = passwardS = num = 0;

	//防止鼠标在跳转页面时留痕
	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();
	page2_screen();
	/*循环，不停地监测异动，当异动导致page值改变，跳转页面*/
	while(page == 0)
	{
		//获取鼠标的位置和状态
		newmouse(&MouseX,&MouseY,&press);
		
		
		//点击退出程序框
		if (mouse_press(200, 300, 250, 370) == 1)
		{
			return 4;
		}
		//判断账号栏
		if (mouse_press(180, 170, 180 + 280, 170 + 40) == 2)
		{
			MouseS = 2;
			if (num == 0 && accountS == 0)
			{
				login_light(1);
				num = 1;	//防止重复点亮
			}
			continue;

		}
		else if (mouse_press(180, 170, 180 + 280, 170 + 35) == 1)
		{
			MouseS = 0;
			login_light(1);
			//以下为输入函数
			u->id[0] = '\0';//当从满输入重新输入的解决方法
			input_id(u->id, 180, 170, 8, LIGHTGRAY);
			if (strlen(u->id) != 0)
			{
				accountS = 1;
			}
			else
			{
				accountS = 0;
			}
			continue;

		}
		//判断密码栏
		if (mouse_press(180, 235, 180 + 280, 270) == 2)
		{
			MouseS = 2;
			if (num == 0 && passwardS == 0)
			{
				login_light(2);
				num = 1;
			}
			continue;
		}
		else if (mouse_press(180, 235, 180 + 280, 270) == 1)
		{
			MouseS = 0;
			login_light(2);

			u->passward[0] = '\0';
			input_passward(u->passward, 180, 235, 8, LIGHTGRAY);
			if (strlen(u->passward) != 0)
			{
				passwardS = 1;
			}
			else
			{
				passwardS = 0;
			}
		}
		//判断登陆栏
		if (mouse_press(250, 300, 320, 330) == 2)
		{
			//光标放在登陆上
			//加亮函数
			if (num == 0)
			{
				login_light(3);
				num = 3;
			}
			continue;
		}
		else if (mouse_press(250, 300, 320, 330) == 1)
		{
			//点击了登陆按钮
			MouseS = 0;
			if (has_registered(u))
			{
				//如果匹配了数据，证明已经注册，进入主界面
				return 2;
			}
			else
			{
				setfillstyle(1, LIGHTGRAY);
				bar(180, 200, 350, 280);
				puthz(200, 220, "密码错误", 24, 20, RED);
				delay(3000);
				return 0;
			}
			

		}
		if (num != 0)
		{
			if (accountS  == 0)
			{
				login_recover(1);
			}
			if (passwardS == 0)
			{
				login_recover(2);
			}
			if (num == 3)
			{
				login_recover(3);
			}

			num = 0;
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}

	}
	delay(1000);
	return page;//返回2到主函数的页面跳转循环
}

//绘制页面2界面
void page2_screen(void)
{
	cleardevice();//把以前的页面清屏
	
	setbkcolor(BLACK);//背景色设置
	
	setcolor(RED);
	setfillstyle(SOLID_FILL, WHITE);//设置白色框
	bar(110, 170, 110 + 70, 170 + 35);//跳转页面
	puthz(120, 180, "账号", 24, 20, LIGHTRED);

	setfillstyle(SOLID_FILL, WHITE);//设定红色框
	bar(180, 170, 180 + 280, 170 + 35);//跳转页面
	setlinestyle(SOLID_LINE, 0, 3);
	line(180, 170, 180, 205);

	setfillstyle(SOLID_FILL, WHITE);//设定蓝色框
	bar(110, 210 + 25, 180 , 210 + 25+35);//退出程序
	puthz(120, 245, "密码", 24, 20, LIGHTRED);

	setfillstyle(SOLID_FILL, WHITE);//设定红色框
	bar(180, 210 + 25, 180 + 280, 170 + 40 + 25 + 35);//退出程序
	setlinestyle(SOLID_LINE, 0, 3);
	line(180, 235, 180, 270);
	
	line(0, 130, 640, 130);


	//按钮
	setfillstyle(SOLID_FILL, RED);
	bar(250, 300, 320, 330);
	puthz(260, 300, "登入", 24, 25, WHITE);

	bar(200, 340, 250, 370);
	puthz(200, 340, "退出", 24, 25, WHITE);

}

void login_light(int flag)
{
	clrmous(MouseX, MouseY);
	delay(100);


	switch (flag)
	{
	case 1:	//加亮账号栏
	{
		setcolor(LIGHTRED);
		setfillstyle(1, LIGHTGRAY);
		bar(180, 170, 180 + 280, 170 + 35);
		//rectangle(180, 170, 180 + 280, 170 + 40);
		break;
	}
	case 2:	//加亮密码栏
	{
		setcolor(LIGHTRED);
		setfillstyle(1, LIGHTGRAY);
		bar(180, 235, 180 + 280, 270);
		//rectangle(180, 230, 180 + 280, 270);
		break;
	}
	case 3://加亮登陆按钮
	{
		setfillstyle(1, LIGHTGRAY);
		bar(250, 300, 320, 330);
		puthz(260, 300, "登入", 24, 25, RED);
		break;
	}
	default:
		break;
	}
}

void login_recover(int flag)
{
	clrmous(MouseX, MouseY);
	delay(100);


	switch (flag)
	{
	case 1:	//恢复账号栏
	{
		setfillstyle(1, WHITE);
		bar(180, 170, 180 + 280, 170 + 35);
		//rectangle(180, 170, 180 + 280, 170 + 40);
		break;
	}
	case 2:	//恢复密码栏
	{
		setfillstyle(1, WHITE);
		bar(180, 235, 180 + 280, 270);
		break;
		//rectangle(180, 230, 180 + 280, 270);
	}
	case 3:
	{
		setfillstyle(1, RED);
		setcolor(WHITE);
		bar(250, 300, 320, 330);
		puthz(260, 300, "登入", 24, 25, WHITE);
		break;
	}
	default:
		break;
	}
}