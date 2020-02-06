#ifndef _FINGER_TEST_H_
#define _FINGER_TEST_H_

#include <finger access struct.h>
#define COMMAND_MAX_SIZE 20
#define COMMAND_MAX_ITEM 4
//项目定义数据定义头文件

#define IN 
#define OUT
#define INOUT

#define OK 0
#define TRUE 1
#define FALSE 0

typedef int student_info_manage(void);

typedef struct
{
	char command[COMMAND_MAX_SIZE];
	student_info_manage *command_reply_handle;
}COMMAN_STRUCT;



#endif 
