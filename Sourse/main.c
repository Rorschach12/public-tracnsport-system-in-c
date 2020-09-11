#include "common.h"
#include "main.h"

void main(void)
{
	/***********各种初始化*****************/
	/*设定初始页面
	调试的时候可以改变page的初始设定，直接跳转到需要调试的页面
	*/
	int page = 0;
	//VGA画图的初始化
    int graphdriver = VGA;
    int	graphmode = VGAHI;
	USER u;
	memset(&u, '\0', sizeof(USER));
    initgraph(&graphdriver, &graphmode, "C:\\BORLANDC\\BGI");
	//鼠标的初始化
	mouseinit();
	
	/*
	*********页面跳转循环***********
	每一个页面对应一个page值，
	在各个页面的程序中，每一次有需要跳转页面的时候，就改变page值，且回到主程序
	在主程序的循环中，通过page值的改变，跳转到相应页面
	*/
	while(1)
	{
		switch(page)
		{
			case 0://欢迎界面
				page = welcome();
				break;
				
			case 1://登陆界面
			    page = login(&u);
				memset(&u, '\0', sizeof(USER));	//恢复初始化
				break;
				
			case 2://主要界面
				page = g_main();
				memset(&u, '\0', sizeof(USER));	//恢复初始化
				break;
			case 3://注册界面
				page = registered();
				break;
			case 4://退出程序
				closegraph();//关闭画图
				return;
		}
	}
}
		
				
