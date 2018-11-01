#ifndef _FUNC_
#define _FUNC_
#include"ArrayLib.h"

//kv�ṹ
typedef struct kv
{
	struct kv *next;
    char *k;
    char *v;
} Entry;

//����hashtable
Array *new_hash_table(int length);

//��ʼ��Entry
void init_entry(Entry *entry);

//����Entry
Entry *new_entry();

//hash�����±�
int hash(char *k,int length);

//DJB Hash Function
unsigned int times33(char *key);

//��hash�����������
int add_data(Array *arr,char *k,char *v);

//���ٲ�������
char *get_data(Array *arr,char *k);

#endif