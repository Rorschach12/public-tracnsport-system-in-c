#include "common.h"
#include "welcome.h"

//��Ϊ��Ҫ����pageֵ������ҳ��ĺ�������int��
int welcome(void)
{
	int page = 0;
	
	//��ֹ�������תҳ��ʱ����
	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();

	page1_screen();
	
	/*ѭ������ͣ�ؼ���춯�����춯����pageֵ�ı䣬��תҳ��*/
	while(1)
	{
		//��ȡ����λ�ú�״̬
		newmouse(&MouseX,&MouseY,&press);
		
		//�����תҳ�����ת��login����
		if(mouse_press(180, 170, 180+280, 170+60) == 1)
		{
			page = 1;//����1����������ҳ����תѭ��
			break;
		}
		
		//����˳������
		else if(mouse_press(180, 170+60+40, 180+280, 170+60+40+60) == 1)
		{
			page = 4;//����2����������ҳ����תѭ��
			break;
		}
		//������ע�ᰴť
		if (mouse_press(300, 350, 400, 450)==1)
		{
			page = 3;
			break;
		}
	}
	delay(1000);
	return page;
}

//����ҳ��1����
void page1_screen(void)
{
	cleardevice();//����ǰ��ҳ������
	
	setbkcolor(BLACK);//����ɫ����
	
	setfillstyle(SOLID_FILL, BLUE);//�趨��ɫ��
	bar(180, 170, 180+280, 170+60);//��תҳ��
	puthz(240, 180, "��¼", 24, 100, WHITE);
	setfillstyle(SOLID_FILL, RED);//�趨��ɫ��
	bar(180, 170 + 60 + 40, 180 + 280, 170 + 60 + 40 + 60);//�˳�����
	puthz(240, 280, "�˳�", 24, 100, WHITE);

	setfillstyle(SOLID_FILL, BLUE);//�趨��ɫ��
	bar(300, 350, 400, 450);
	puthz(320, 370, "ע��", 24, 20, RED);
	
}
	