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
	//设置文本颜色
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, color);

	//设置字符输出格式
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);//2号字体三倍笔画水平输出
	settextjustify(LEFT_TEXT, TOP_TEXT);//左上角格式输出

	line(x1 + 5, y1 + 10, x1 + 5, y1 + 24);
	
	while (1)
	{
		ch = bioskey(0);
		//当小于输入i限制时候
		if (i < num)
		{
			//如果不为删除，换行，空格，退出字符
			if (ifnormal(ch))
			{
				//如果不为删除字符
				if (ch != '\b')
				{
					*(id + i) = ch;//赋值
					*(id + i + 1) = '\0';
					bar(x1 + 5 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26); //遮盖光标
					outtextxy(x1 + 5 + i * 18, y1 + 3, id + i);//输出t字符(16)
					i++;
					line(x1 + 5 + i * 18, y1 + 10, x1 + 5 + i * 18, y1 + 24);
				}
				//如果是删除字符
				else if (ch == '\b'&&i > 0)
				{
					bar(x1 + 5 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26);//遮盖光标
					bar(x1 - 12 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//遮盖文字
					i--;//减少一个字数
					line(x1 + 5 + i * 18, y1 + 10, x1 + 5 + i * 18, y1 + 24);//绘制光标
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
					bar(x1 + 5 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26);//遮盖光标
					bar(x1 - 12 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//遮盖文字
					i--;//减少一个字数
					line(x1 + 5 + i * 18, y1 + 10, x1 + 5 + i * 18, y1 + 24);//绘制光标
					*(id + i) = '\0';
				}
				
				
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 5 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26);//遮盖光标
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
	//设置文本颜色
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, color);

	//设置字符输出格式
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);//2号字体三倍笔画水平输出
	settextjustify(LEFT_TEXT, TOP_TEXT);//左上角格式输出

	line(x1 + 5, y1 + 10, x1 + 5, y1 + 24);
	
	while (1)
	{
		ch = bioskey(0);
		//当小于输入i限制时候
		if (i < num)
		{
			//如果不为删除，换行，空格，退出字符
			if (ifnormal(ch))
			{
				//如果不为删除字符
				if (ch != '\b')
				{
					*(passward + i) = ch;//赋值
					*(passward + i + 1) = '\0';
					bar(x1 + 5 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26); //遮盖光标
					outtextxy(x1 + 5 + i * 18, y1 + 3, passward + i);//输出t字符(16)
					i++;
					line(x1 + 5 + i * 18, y1 + 10, x1 + 5 + i * 18, y1 + 24);
				}
				//如果是删除字符
				else if (ch == '\b'&&i > 0)
				{
					bar(x1 + 5 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26);//遮盖光标
					bar(x1 - 12 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//遮盖文字
					i--;//减少一个字数
					line(x1 + 5 + i * 18, y1 + 10, x1 + 5 + i * 18, y1 + 24);//绘制光标
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
					bar(x1 + 5 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26);//遮盖光标
					bar(x1 - 12 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//遮盖文字
					i--;//减少一个字数
					line(x1 + 5 + i * 18, y1 + 10, x1 + 5 + i * 18, y1 + 24);//绘制光标
					*(passward + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 5 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26);//遮盖光标
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