#ifndef _GLOBAL_H
#define _GLOBAL_H
#include"arraylib.h"
#include"expire.h"

extern Array *hash_table;		//���ݿ���Ľṹ
extern Expires *expires_head;	//���ڱ�

//��ʼ�����ݿ�
int init_foxy_ball();
#endif
