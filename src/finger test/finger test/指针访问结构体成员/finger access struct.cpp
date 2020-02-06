#include "C:\Users\杨金良\Documents\GitHub\c-test\src\finger test\finger test\stdafx.h"
#include "finger access struct.h"
#include "C:\Users\杨金良\Documents\GitHub\c-test\src\finger test\finger test\finger test.h"
#include <stdlib.h>
#include <string.h>
STUDENT_STRUCT STUDENT_INFO[STUDENT_NUM_MAX];

int Student_Info_Init()
{
	int iReturncode = OK;
	int i;

	for(i = 0;i < STUDENT_NUM_MAX;i++)
	{
		STUDENT_INFO[i].name = (char *)malloc(STUDENT_NAME_LENTH);
		memset(STUDENT_INFO[i].name,0, STUDENT_NAME_LENTH);
		if (STUDENT_INFO[i].name == NULL)
		{ 
			printf("malloc student %d name faild\n",i);
			iReturncode = FALSE;
			break;
		}	
		memcpy(STUDENT_INFO[i].name, "NULL",sizeof("NULL"));
		STUDENT_INFO[i].id = 0;
		STUDENT_INFO[i].score = { 0,0,0,0 };
	}
	return iReturncode;
}

int Show_Student_Info()
{
	int iReturncode = OK;
	int i = 0;
	printf("      姓名        学号      数学成绩      英语成绩      语文成绩      物理成绩\n");// 间隔4  ：10 8 10 10 10 10
	for (i = 0; i < STUDENT_NUM_MAX; i++)
	{
		if (strcmp(STUDENT_INFO[i].name,"NULL") != OK) 
		{
			printf("%10s    %8d    %10d    %10d    %10d    %10d  \n", STUDENT_INFO[i].name, STUDENT_INFO[i].id, STUDENT_INFO[i].score.math_mark, STUDENT_INFO[i].score.english_mark, STUDENT_INFO[i].score.chinese_mark, STUDENT_INFO[i].score.physics_mark);
		}
	}

	return iReturncode;
}
int Edit_Student_Info()
{
	int i;
	char c;
	for (i = 0; i < STUDENT_NUM_MAX; i++)
	{
		while(1)
		{
			if (strcmp(STUDENT_INFO[i].name, "NULL") != OK)
			{
				printf("是否修改%s成绩信息？：Y/N:", STUDENT_INFO[i].name);
				scanf_s("%c", &c);
				if (c == 'Y')
				{
					printf("请输入数学成绩：");
					scanf_s("%d", &STUDENT_INFO[i].score.math_mark);
					printf("请输入英语成绩：");
					scanf_s("%d", &STUDENT_INFO[i].score.english_mark);
					printf("请输入语文成绩：");
					scanf_s("%d", &STUDENT_INFO[i].score.chinese_mark);
					printf("请输入物理成绩：");
					scanf_s("%d", &STUDENT_INFO[i].score.physics_mark);
					break;
				}
				else if (c == 'N')
				{
					break;
				}
				else
					continue;
			}
		}
		
	}
	return 0;
}
int Insert_Student_Info()
{
	int i;
	char c;
	for (i = 0; i < STUDENT_NUM_MAX; i++)
	{
		if (strcmp(STUDENT_INFO[i].name, "NULL") == OK)
		{
			memset(STUDENT_INFO[i].name, 0, STUDENT_NAME_LENTH);
			printf("请输入姓名？：");
			scanf_s("%s", STUDENT_INFO[i].name, STUDENT_NAME_LENTH);
			printf("请输入学号：");
			scanf_s("%d", &STUDENT_INFO[i].id);
			printf("请输入数学成绩：");
			scanf_s("%d", &STUDENT_INFO[i].score.math_mark);
			printf("请输入英语成绩：");
			scanf_s("%d", &STUDENT_INFO[i].score.english_mark);
			printf("请输入语文成绩：");
			scanf_s("%d", &STUDENT_INFO[i].score.chinese_mark);
			printf("请输入物理成绩：");
			scanf_s("%d", &STUDENT_INFO[i].score.physics_mark);
			printf("是否继续插入学生信息？：Y/N：");
			scanf_s("%c",&c,1); // 跳过回车符
			scanf_s("%c", &c, 1);
			if (c == 'Y')
				continue;
			else
				break;
		}
	}
	return 0;
}
int Exit_Student_Info()
{
	int iReturncode = OK;
	int i = 0;
	//退出销毁内存
	for (i = 0; i < STUDENT_NUM_MAX; i++)
	{
		if (STUDENT_INFO[i].name != 0)
		{
			free(STUDENT_INFO[i].name);
		}
	}

	return iReturncode;
}