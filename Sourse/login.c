#include "common.h"
#include "login.h"

//��Ϊ��Ҫ����pageֵ������ҳ��ĺ�������int��
int login(USER *u)
{
	int page = 0;
	int accountS, passwardS;	//accountS��ʶ�˺��Ƿ�Ϊ�գ�passwardS��ʶ�����Ƿ�Ϊ��
	int num;	//���ڻָ�����,�Ͱ�����������

	accountS = passwardS = num = 0;

	//��ֹ�������תҳ��ʱ����
	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();
	page2_screen();
	/*ѭ������ͣ�ؼ���춯�����춯����pageֵ�ı䣬��תҳ��*/
	while(page == 0)
	{
		//��ȡ����λ�ú�״̬
		newmouse(&MouseX,&MouseY,&press);
		
		
		//����˳������
		if (mouse_press(200, 300, 250, 370) == 1)
		{
			return 4;
		}
		//�ж��˺���
		if (mouse_press(180, 170, 180 + 280, 170 + 40) == 2)
		{
			MouseS = 2;
			if (num == 0 && accountS == 0)
			{
				login_light(1);
				num = 1;	//��ֹ�ظ�����
			}
			continue;

		}
		else if (mouse_press(180, 170, 180 + 280, 170 + 35) == 1)
		{
			MouseS = 0;
			login_light(1);
			//����Ϊ���뺯��
			u->id[0] = '\0';//������������������Ľ������
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
		//�ж�������
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
		//�жϵ�½��
		if (mouse_press(250, 300, 320, 330) == 2)
		{
			//�����ڵ�½��
			//��������
			if (num == 0)
			{
				login_light(3);
				num = 3;
			}
			continue;
		}
		else if (mouse_press(250, 300, 320, 330) == 1)
		{
			//����˵�½��ť
			MouseS = 0;
			if (has_registered(u))
			{
				//���ƥ�������ݣ�֤���Ѿ�ע�ᣬ����������
				return 2;
			}
			else
			{
				setfillstyle(1, LIGHTGRAY);
				bar(180, 200, 350, 280);
				puthz(200, 220, "�������", 24, 20, RED);
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
	return page;//����2����������ҳ����תѭ��
}

//����ҳ��2����
void page2_screen(void)
{
	cleardevice();//����ǰ��ҳ������
	
	setbkcolor(BLACK);//����ɫ����
	
	setcolor(RED);
	setfillstyle(SOLID_FILL, WHITE);//���ð�ɫ��
	bar(110, 170, 110 + 70, 170 + 35);//��תҳ��
	puthz(120, 180, "�˺�", 24, 20, LIGHTRED);

	setfillstyle(SOLID_FILL, WHITE);//�趨��ɫ��
	bar(180, 170, 180 + 280, 170 + 35);//��תҳ��
	setlinestyle(SOLID_LINE, 0, 3);
	line(180, 170, 180, 205);

	setfillstyle(SOLID_FILL, WHITE);//�趨��ɫ��
	bar(110, 210 + 25, 180 , 210 + 25+35);//�˳�����
	puthz(120, 245, "����", 24, 20, LIGHTRED);

	setfillstyle(SOLID_FILL, WHITE);//�趨��ɫ��
	bar(180, 210 + 25, 180 + 280, 170 + 40 + 25 + 35);//�˳�����
	setlinestyle(SOLID_LINE, 0, 3);
	line(180, 235, 180, 270);
	
	line(0, 130, 640, 130);


	//��ť
	setfillstyle(SOLID_FILL, RED);
	bar(250, 300, 320, 330);
	puthz(260, 300, "����", 24, 25, WHITE);

	bar(200, 340, 250, 370);
	puthz(200, 340, "�˳�", 24, 25, WHITE);

}

void login_light(int flag)
{
	clrmous(MouseX, MouseY);
	delay(100);


	switch (flag)
	{
	case 1:	//�����˺���
	{
		setcolor(LIGHTRED);
		setfillstyle(1, LIGHTGRAY);
		bar(180, 170, 180 + 280, 170 + 35);
		//rectangle(180, 170, 180 + 280, 170 + 40);
		break;
	}
	case 2:	//����������
	{
		setcolor(LIGHTRED);
		setfillstyle(1, LIGHTGRAY);
		bar(180, 235, 180 + 280, 270);
		//rectangle(180, 230, 180 + 280, 270);
		break;
	}
	case 3://������½��ť
	{
		setfillstyle(1, LIGHTGRAY);
		bar(250, 300, 320, 330);
		puthz(260, 300, "����", 24, 25, RED);
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
	case 1:	//�ָ��˺���
	{
		setfillstyle(1, WHITE);
		bar(180, 170, 180 + 280, 170 + 35);
		//rectangle(180, 170, 180 + 280, 170 + 40);
		break;
	}
	case 2:	//�ָ�������
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
		puthz(260, 300, "����", 24, 25, WHITE);
		break;
	}
	default:
		break;
	}
}