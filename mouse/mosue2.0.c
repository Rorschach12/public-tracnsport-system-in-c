//#include <conio.h>
//#include <graphics.h>
//#include <dos.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//void mouseinit(void)
//{
//	regs.x.ax = 0x00;
//	int86(MOUSE_INT, &regs.&regs);
//}
//
//void clrmous(int x, int y)
//{
//	regs.x.ax = 0x02;
//	init(MOUSE_INT, &regs, &regs);
//}
//
//void drawmous(int x, int y)
//{
//	regs.x.ax = 0x01;
//	init(MOUSE_INT, &regs, &regs);
//
//}
//
//void mread(int *nx, int *ny, int *nbuttons)
//{
//	regs.x.ax = 0x03;
//	init(MOUSE_INT, &regs.&regs);
//	*nx = regs.x.cx;
//	*ny = regs.x.dx;
//	*nbuttons = regs.x.bx;
//
//}
//
//void newmouse(int *nx, int *ny, int *nbuttons)
//{
//	int xn, yn, buttonsn;
//	int x0 = *nx, y0 = *ny, buttons0 = *nbuttons;
//	mread(&xn, &yn, &buttonsn);
//
//	*nx = xn;
//	*ny = yn;
//	if (buttons0 == *nbuttons)
//		*nbuttons = 0;    //使得能连续按键
//	if (xn == x0 && yn == y0 && buttonsn == buttons0)
//		return;
//	drawmous();
//	
//}
//void setMouseS(mscurstype mask)
//{
//
//}

include "mouse2.0.h"

int Squeeze_Mouse(int command, int *x, int *y, int *buttons)
{
	union REGS inregs, outregs;

	switch (command)
	{
	case MOUSE_RESET:
	{
		inregs.x.ax = 0x00;
		int86(MOUSE_INT, &inregs, &outregs);
		*buttons = outregs.x.bx;
		return(outregs.x.ax);
	}break;



	case MOUSE_SHOW:
	{
		inregs.x.ax = 0x01;
		int86(MOUSE_INT, &inregs, &outregs);
		return(1);
	}break;


	case MOUSE_HIDE:
	{
		inregs.x.ax = 0x02;
		int86(MOUSE_INT, &inregs, &outregs);
		return(1);
	}break;


	case MOUSE_BUTT_POS:
	{
		inregs.x.ax = 0x03;
		int86(MOUSE_INT, &inregs, &outregs);
		*x = outregs.x.cx;
		*y = outregs.x.dx;
		*buttons = outregs.x.bx;
		return(1);
	}break;


	case MOUSE_MOTION_REL:
	{
		inregs.x.ax = 0x03;
		int86(MOUSE_INT, &inregs, &outregs);
		*x = outregs.x.cx;
		*y = outregs.x.dx;
		return(1);
	}break;

	case MOUSE_SET_SENSITIVITY:
	{
		inregs.x.ax = 0x04;

		inregs.x.bx = *buttons;
		inregs.x.cx = *x;
		inregs.x.dx = *y;

		int86(MOUSE_INT, &inregs, &outregs);
		return(1);
	}break;


	default:break;
	}
}

void setcurshape(mscurstype mask)
{
	union REGS r;
	struct SREGS s;
	r.x.ax = 9;
	r.x.bx = mask.hor;
	r.x.cx = mask.ver;
	r.x.dx = FP_OFF(&mask);
	s.es = FP_SEG(&mask);
	int86x(0x33, &r, &r, &s);
}

void mscurson(mscurstype shape)
{
	union REGS r;
	struct SREGS s;
	setcurshape(shape);
	r.x.ax = 1;
	int86x(0x33, &r, &r, &s);
}

void Set_Video_Mode(int mode)
{
	union REGS inregs, outregs;
	inregs.h.ah = 0;
	inregs.h.al = (unsigned char)mode;
	int86(0x10, &inregs, &outregs);
}
