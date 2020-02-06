#ifndef _FINGER_ACCESS_STRUCT_H_
#define _FINGER_ACCESS_STRUCT_H_


//定义数据头文件
#define  STUDENT_NUM_MAX 10
#define  STUDENT_NAME_LENTH 10

typedef struct
{
	int math_mark;
	int english_mark;
	int chinese_mark;
	int physics_mark;
}SCORE_STRUCT;

typedef struct
{
	char *name;
	int  id;
	SCORE_STRUCT score;
}STUDENT_STRUCT;

int Student_Info_Init();
int Show_Student_Info();
int Edit_Student_Info();
int Insert_Student_Info();
int Exit_Student_Info();



#endif