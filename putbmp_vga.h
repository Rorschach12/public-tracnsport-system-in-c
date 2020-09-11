#ifndef _PUTBMP_VGA_H_
#define _PUTBMP_VGA_H_

#include <stdio.h>
#include <graphics.h>
//读取bmp格式到(x,y)处
int putbmp(int x, int y, char *path);

#endif