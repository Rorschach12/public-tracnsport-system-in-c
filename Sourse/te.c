#include "common.h"

typedef struct user {
	char id[24];
	char passward[24];
	char identify[24];
}USER;

void input_success(USER *u)
{
	FILE* fp;
	char n;
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
	fwrite(u, sizeof(USER), 1, fp);//把用户信息写入文件 余额默认为0
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
}

//将input与数据进行比较
int read_success(USER *input)
{
	int i;
	int len;
	FILE* fp;
	USER* u = NULL;
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
			&& strcmp(input->passward, u->passward) == 0
			&& strcmp(input->identify, u->identify) == 0)
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
int main()
{
	USER u;
	memset(&u,'\0', sizeof(USER));
	strcpy(u.id, "1234");
	strcpy(u.passward, "123");
	strcpy(u.identify, "1234");
	//input_success(&u);
	if (read_success(&u))
	{
		printf("\nhas finded\n");
	}
	else
	{
		printf("\nhas not be finded!");
	}
	getchar();
}


