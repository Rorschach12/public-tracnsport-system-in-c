#include "lgfunc.h"

int ifnormal(char t)
{
	return (t != '\n'
		&& t != '\r'
		&& t != ' '
		&& t != 033);
}
void input_id(char *id, int x1, int y1, int num, int color)
{
	char ch;
	int i = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	//�����ı���ɫ
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, color);

	//�����ַ������ʽ
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);//2�����������ʻ�ˮƽ���
	settextjustify(LEFT_TEXT, TOP_TEXT);//���ϽǸ�ʽ���

	line(x1 + 5, y1 + 10, x1 + 5, y1 + 24);
	
	while (1)
	{
		ch = bioskey(0);
		//��С������i����ʱ��
		if (i < num)
		{
			//�����Ϊɾ�������У��ո��˳��ַ�
			if (ifnormal(ch))
			{
				//�����Ϊɾ���ַ�
				if (ch != '\b')
				{
					*(id + i) = ch;//��ֵ
					*(id + i + 1) = '\0';
					bar(x1 + 5 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26); //�ڸǹ��
					outtextxy(x1 + 5 + i * 18, y1 + 3, id + i);//���t�ַ�(16)
					i++;
					line(x1 + 5 + i * 18, y1 + 10, x1 + 5 + i * 18, y1 + 24);
				}
				//�����ɾ���ַ�
				else if (ch == '\b'&&i > 0)
				{
					bar(x1 + 5 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26);//�ڸǹ��
					bar(x1 - 12 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//�ڸ�����
					i--;//����һ������
					line(x1 + 5 + i * 18, y1 + 10, x1 + 5 + i * 18, y1 + 24);//���ƹ��
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else 
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 5 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26);
				break;
			}
			
		}
		else if (i >= num)
		{
			if (ifnormal(ch))
			{
				if (ch == '\b'&&i > 0)
				{
					bar(x1 + 5 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26);//�ڸǹ��
					bar(x1 - 12 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//�ڸ�����
					i--;//����һ������
					line(x1 + 5 + i * 18, y1 + 10, x1 + 5 + i * 18, y1 + 24);//���ƹ��
					*(id + i) = '\0';
				}
				
				
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 5 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26);//�ڸǹ��
				break;
			}
		}
	}
}


void input_passward(char *passward, int x1, int y1, int num, int color)
{
	char ch;
	int i = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	//�����ı���ɫ
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, color);

	//�����ַ������ʽ
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);//2�����������ʻ�ˮƽ���
	settextjustify(LEFT_TEXT, TOP_TEXT);//���ϽǸ�ʽ���

	line(x1 + 5, y1 + 10, x1 + 5, y1 + 24);
	
	while (1)
	{
		ch = bioskey(0);
		//��С������i����ʱ��
		if (i < num)
		{
			//�����Ϊɾ�������У��ո��˳��ַ�
			if (ifnormal(ch))
			{
				//�����Ϊɾ���ַ�
				if (ch != '\b')
				{
					*(passward + i) = ch;//��ֵ
					*(passward + i + 1) = '\0';
					bar(x1 + 5 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26); //�ڸǹ��
					outtextxy(x1 + 5 + i * 18, y1 + 3, passward + i);//���t�ַ�(16)
					i++;
					line(x1 + 5 + i * 18, y1 + 10, x1 + 5 + i * 18, y1 + 24);
				}
				//�����ɾ���ַ�
				else if (ch == '\b'&&i > 0)
				{
					bar(x1 + 5 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26);//�ڸǹ��
					bar(x1 - 12 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//�ڸ�����
					i--;//����һ������
					line(x1 + 5 + i * 18, y1 + 10, x1 + 5 + i * 18, y1 + 24);//���ƹ��
					*(passward + i) = '\0';
					*(passward + i + 1) = '\0';
				}
			}
			else if (!ifnormal(ch))
			{
				break;
			}
			
		}
		else if (i >= num  )
		{
			if (ifnormal(ch))
			{
				if (ch == '\b'&&i > 0)
				{
					bar(x1 + 5 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26);//�ڸǹ��
					bar(x1 - 12 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//�ڸ�����
					i--;//����һ������
					line(x1 + 5 + i * 18, y1 + 10, x1 + 5 + i * 18, y1 + 24);//���ƹ��
					*(passward + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 5 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26);//�ڸǹ��
				break;
			}
		}
	}
}


void input_identify(char *passward, int x1, int y1, int num, int color)
{
	input_passward(passward, x1, y1, num, color);
}

int same_passward(char *a, char *b);