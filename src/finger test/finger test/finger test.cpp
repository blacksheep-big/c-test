// finger test.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <stdlib.h>
#include "finger test.h"
#include <finger access struct.h>
COMMAN_STRUCT command[COMMAND_MAX_ITEM] =
{
	{"show_info",Show_Student_Info},
	{"change_info",Edit_Student_Info},
	{"insert_info",Insert_Student_Info},
	{"exit",Exit_Student_Info}
};

int main()
{
	char contnue;
	int i;
	int match = FALSE;
	bool exit = FALSE;
	char command_buffer[COMMAND_MAX_SIZE];
	int iReturncode = OK;
	/*
	command_buffer = NULL;
	command_buffer = (char *)malloc(COMMAND_MAX_SIZE);
	if (command_buffer == NULL)
	{ 
		printf("gg");
		return 0;
	}
	*/
	printf("欢迎登陆xxx学校学生信息系统\n");

	iReturncode = Student_Info_Init(); //初始化学生信息数据
	if (iReturncode == OK)
	{
		printf("初始化信息系统成功\n");
	}
	else
	{
		printf("初始化信息系统失败\n");
		return 0;
	}
	
	while (1)
	{
		memset(command_buffer,0,sizeof(char)*COMMAND_MAX_SIZE);
		match = FALSE;

		printf("   命令     |     功能    \n");
		printf(" show_info  | 显示学生信息\n");
		printf("change_info | 更改学生信息\n");
		printf("insert_info | 添加学生信息\n");
		printf("   exit     |      退出   \n");

		scanf_s("%s",command_buffer, COMMAND_MAX_SIZE);
		for (i = 0; i < COMMAND_MAX_ITEM; i++)
		{
			if (strcmp(command_buffer, command[i].command) == OK)
			{
				if (strcmp(command_buffer, "exit") == OK)
				{
					exit = TRUE;
					match = TRUE;
					printf("\n\n");
					break;
				}	
				else
				{
					iReturncode = (*command[i].command_reply_handle)();
					if (iReturncode == OK)
						printf("命令执行成功!\n");
					else
					{
						printf("信息系统功能异常，退出!");
						exit = TRUE;
					}
				}
				match = TRUE;
				printf("\n\n");
				break;
			}
		}
		if(match != TRUE)
			printf("no such command,please input again:\n\n");

		if (exit == TRUE)
			break;
	}
	return 0;
}

