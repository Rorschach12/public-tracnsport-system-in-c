#include "putbmp_vga.h"

int putbmp(int x, int y, char *path)
{
    FILE *fp;
    long width, height;
    long begin;          //存储图像的长和宽
    unsigned char index; //用于读取序号
    int bit;
    int i, j;
    unsigned char color[256], Red, Green, Blue; //256的bmp图片的调色板和三原色
    //判定图片是否可以打开
    if ((fp = fopen(path, "rb")) == NULL)
    {
        printf("can't open the bmp!!");
        getchar();
        exit(1);
    }
    fseek(fp, 10l, SEEK_SET); //定位到图片的第10个字节处读取文件描述区长度
    fread(&begin, 4, 1, fp);
    fseek(fp, 18l, SEEK_SET); //定位到18个字节处读取图像长和宽
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);
    fseek(fp, 28l, SEEK_SET); //定位到28个字节处读取每个像素的二进制位数
    fread(&bit, 2, 1, fp);

    if (bit != 8)
    {
        printf("bit not 8!!");
        getchar();
        exit(1);
    }

    fseek(fp, 54l, SEEK_SET); //定位到图像信息区
    for (i = 0; i < 256; i++) //256张调色板的读取和映射
    {
        //读取三原色
        fread(&Blue, 1, 1, fp);
        fread(&Green, 1, 1, fp);
        fread(&Red, 1, 1, fp);
        //256色的映射
        if (Red < 42)
        {
            color[i] = (Blue > 84) + 2 * (Green > 84);
        }
        else if (Red < 126)
        {
            color[i] = 8 + (Blue > 168) + 2 * (Green > 168);
        }
        else if (Red < 210)
        {
            color[i] = 4 + (Blue > 84) + 2 * (Green > 60);
        }
        else
        {
            color[i] = 12 + (Blue > 168) + 2 * (Green > 168);
        }
        fseek(fp, 1, SEEK_CUR); //迁移一个字节来跳过灰度
    }

    //由于bmp格式问题采用屏幕倒写法
    for (i = 0; i < height; i++)
    {
        fseek(fp, begin + (width + 3) * i  , 0); 
        for (j = 0; j < width; j++)
        {
            fread(&index, 1, 1, fp);
            putpixel(x + j, y + height - i - 1, color[index]);
        }
    }
    fclose(fp);
    return 1;
}
