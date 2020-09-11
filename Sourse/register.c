#include "register.h"

int input_success(USER *u)
{
	FILE* fp;
	char n;
	int flag = 0;
	/*检查是否正确创建文件夹
	if (mkdir(way))
	{
		printf("mkdir wrong!");
	}
	else
	{
		printf("mkdir right");
	}*/
	/*if((fp=fopen("c")))*/
	if ((fp = fopen("c:\\dage\\userInfo\\UserData.dat", "rb+")) == NULL)//建立数据库
	{
		printf("cannot open file UserData.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//跳转至文件末尾
	if (fwrite(u, sizeof(USER), 1, fp))//把用户信息写入文件 余额默认为0
	{
		flag = 1;
	}
	else {
		flag = 0;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
	return flag;
}

//将input与数据进行比较
int has_registered(USER *input)
{
	int i;
	int len;
	FILE* fp;
	USER* u = NULL;//用于读取数据
	if ((fp = fopen("c:\\dage\\userInfo\\UserData.dat", "rb+")) == NULL)
	{
		printf("cannot open file UserDat.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//文件指针定位到最后一位
	len = ftell(fp) / sizeof(USER);//计算用户个数
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);//每次往后移一个用户
		fread(u, sizeof(USER), 1, fp);		  //将信息读入u
		if (strcmp(input->id, u->id) == 0
			&& strcmp(input->passward, u->passward) == 0)
		{
			//匹配正确
			return 1;
		}
		else
		{
			if (u != NULL)
			{
				free(u);
				u = NULL;
			}

		}
	}
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database");
		exit(1);
	}
	//没有对应得匹配
	return 0;
}

int same_passward(char *a, char *b)
{
	return (!strcmp(a, b));
}

int registered()
{
	USER u;
	int num, accountR, passwardR, passwardRS, identifyR;
	char dou_passward[24] = { '\0' };
	cleardevice();
	clrmous(MouseX,MouseY);

	memset(&u, sizeof(USER), '\0');
	num = accountR = passwardR = passwardRS = identifyR = 0;

	register_screen();
	//进入主循环
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(180, 70, 180 + 280, 105) == 2)
		{
			MouseS = 2;
			//未点击账号栏
			if (num == 0 && accountR == 0) 
			{
				light_register(1);
				num = 1;
			}
			continue;
		}
		else if (mouse_press(180, 70, 180 + 280, 105) == 1)
		{
			//点击了账号栏
			MouseS = 0;
			light_register(1);
			
			u.id[0] = '\0';
			input_id(u.id, 180, 70, 8, LIGHTGRAY);
			if (strlen(u.id) != 0)
			{
				accountR = 1;
			}
			else
				accountR = 0;
			continue;

		}

		if (mouse_press(180, 125, 180 + 280, 160) == 2)
		{
			//未点击密码
			MouseS = 2;
			if (num == 0 && passwardR == 0)
			{
				light_register(2);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(180, 125, 180 + 280, 160) == 1)
		{
			//点击了密码栏
			MouseS = 0;
			light_register(2);

			u.passward[0] = '\0';
			input_passward(u.passward, 180, 125, 8, LIGHTGRAY);
			if (strlen(u.passward) != 0) {
				passwardR = 1;
			}
			else {
				passwardR = 0;
			}
		}

		if (mouse_press(180, 160 + 20, 180 + 280, 215) == 2)
		{
			//未点击确定密码栏
			MouseS = 2;
			if (num == 0 && passwardRS == 0)
			{
				light_register(3);
				num = 3;
			}
			continue;
		}
		else if (mouse_press(180, 160 + 20, 180 + 280, 215) == 1)
		{
			//点击了确定密码栏
			MouseS = 0;
			light_register(3);

			memset(dou_passward, sizeof(char) * 24, '\0');
			input_passward(dou_passward, 180, 180, 8, LIGHTGRAY);
			if (strlen(dou_passward) != 0) {
				passwardRS = 1;
			}
			else {
				passwardRS = 0;
			}

		}

		if (mouse_press(180, 215 + 20, 180 + 280, 235 + 35) == 2)
		{
			//未点击身份证栏
			MouseS = 2;
			if (num == 0 && identifyR == 0)
			{
				light_register(4);
				num = 4;
			}
			continue;
		}
		else if (mouse_press(180, 215 + 20, 180 + 280, 235 + 35) == 1)
		{
			//点击了身份证栏
			MouseS = 0;
			light_register(4);

			u.identify[0] = '\0';
			input_identify(u.identify, 180, 215 + 20, 8, LIGHTGRAY);
			if (strlen(u.identify) != 0) {
				identifyR = 1;
			}
			else {
				identifyR = 0;
			}
		}

		if (mouse_press(180, 320, 250, 350) == 2)
		{
			//未点击注册
			MouseS = 0;
			if (num == 0)
			{
				light_register(5);
				num = 5;
			}
			continue;
		}
		else if (mouse_press(180, 320, 250, 350) == 1)
		{
			//点击了注册按钮
			if (same_passward(dou_passward, u.passward))
			{
				//如果密码一致，则将密码写入文件
				if (input_success(&u))
				{
					setfillstyle(1, LIGHTGRAY);
					bar(180, 200, 350, 280);
					puthz(200, 220, "注册成功，进入登陆界面", 24, 20, RED);
					delay(3000);
					return 1;
				}
				else
				{
					setfillstyle(1, LIGHTGRAY);
					bar(180, 200, 350, 280);
					puthz(200, 220, "注册失败", 24, 20, RED);
					delay(3000);
					return 4;
				}

			}
			else
			{
				setfillstyle(1, LIGHTGRAY);
				bar(180, 200, 350, 280);
				puthz(200, 220, "密码不一致!", 24, 20, RED);
				delay(3000);
				return 3;
			}
		}
		
		if (mouse_press(310, 320, 380, 350) == 2)
		{
			MouseS = 0;
			if (num == 0)
			{
				light_register(6);
				num = 6;
			}
			continue;
		}
		else if (mouse_press(310, 320, 380, 350) == 1)
		{
			//点击了返回按钮
			return 0;
		}

		//恢复机制
		if (num != 0)
		{
			if (num==1&&accountR == 0)
			{
				recover_register(1);
				
			}
			if (num==2&&passwardR == 0)
			{
				recover_register(2);
				
			}
			if (num==3&&passwardRS == 0)
			{
				recover_register(3);
			
			}
			if (num==4&&identifyR == 0)
			{
				recover_register(4);
				
			}
			if (num == 5)
			{
				recover_register(5);
				
			}
			if (num == 6)
			{
				recover_register(6);
			}
			num = 0;
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
	return 0;
	
}

void register_screen()
{
	cleardevice();
	setbkcolor(LIGHTBLUE);
	//绘制主要对话框
	
	setcolor(RED);
	setfillstyle(1, WHITE);
	setlinestyle(SOLID_LINE, 0, 3);
	bar(110, 70, 180 + 280, 70 + 35);
	puthz(120, 80, "账号", 24, 20, RED);
	line(180, 70, 180, 70 + 35);

	bar(110, 105 + 20, 180 + 280, 105 + 20 + 35);
	puthz(120, 135, "密码", 24, 20, RED);
	line(180, 125, 180 , 105 + 20 + 35);

	bar(110, 160 + 20, 180 + 280, 215);
	puthz(105, 190, "确认密码", 24, 17, RED);
	line(180, 160 + 20, 180, 215);
	
	bar(110, 215 + 20, 180 + 280, 235 + 35);
	puthz(118, 215 + 20 + 10, "身份证", 24, 18, RED);
	line(180, 215 + 20, 180, 235 + 35);

	//设置按钮
	setfillstyle(1,RED);
	bar(180, 320, 250, 350);
	puthz(190, 325, "注册", 24, 25, WHITE);

	bar(310, 320, 380, 350);
	puthz(320, 325, "返回", 24, 25, WHITE);
}

void light_register(int flag)
{
	clrmous(MouseX, MouseY);
	delay(100);

	switch (flag)
	{
	case 1:
	{
		//加亮账号栏
		setfillstyle(1, LIGHTGRAY);
		bar(180, 70, 180 + 280, 105);
		line(180, 70, 180, 70 + 35);
		break;
	}
	case 2:
	{
		//加亮密码栏
		setfillstyle(1, LIGHTGRAY);
		bar(180, 125, 180 + 280, 160);
		line(180, 125, 180, 160);
		break;
	}
	case 3:
	{
		//加亮确定密码栏
		setfillstyle(1, LIGHTGRAY);
		bar(180, 160 + 20, 180 + 280, 215);
		line(180, 160 + 20, 180, 215);
		break;
	}
	case 4:
	{
		//加亮身份证栏
		setfillstyle(1, LIGHTGRAY);
		bar(180, 215 + 20, 180 + 280, 235 + 35);
		line(180, 215 + 20, 180, 235 + 35);
		break;
	}
	case 5:
	{
		//加亮注册按钮
		setcolor(LIGHTRED);
		setfillstyle(1, LIGHTGRAY);
		bar(180, 320, 250, 350);
		puthz(190, 325, "注册", 24, 25, RED);
		break;
	}
	case 6:
	{
		//加亮返回按钮
		setcolor(LIGHTRED);
		setfillstyle(1, LIGHTGRAY);
		bar(310, 320, 380, 350);
		puthz(320, 325, "返回", 24, 25, RED);
		break;
	}
	default:
		break;
	}
}

void recover_register(int flag)
{
	clrmous(MouseX, MouseY);
	delay(100);

	switch (flag)
	{
	case 1:	//恢复账号栏
	{
		setfillstyle(1, WHITE);
		bar(180, 70, 180 + 280, 105);
		//rectangle(180, 170, 180 + 280, 170 + 40);
		break;
	}
	case 2:	//恢复密码栏
	{
		setfillstyle(1, WHITE);
		bar(180, 125, 180 + 280, 160);
		break;
		//rectangle(180, 230, 180 + 280, 270);
	}
	case 3://恢复确定密码栏
	{
		setfillstyle(1, WHITE);
		bar(180, 160 + 20, 180 + 280, 215);
		break;
	}
	case 4://恢复身份证栏
	{
		setfillstyle(1, WHITE);
		bar(180, 215 + 20, 180 + 280, 235 + 35);
		break;
	}
	case 5://恢复注册按钮
	{
		setfillstyle(1, RED);
		setcolor(WHITE);
		bar(180, 320, 250, 350);
		puthz(190, 325, "注册", 24, 25, WHITE);
	}
	case 6:
	{
		setfillstyle(1, RED);
		setcolor(WHITE);
		bar(310, 320, 380, 350);
		puthz(320, 325, "返回", 24, 25, WHITE);
	}
	default:
		break;
	}
}