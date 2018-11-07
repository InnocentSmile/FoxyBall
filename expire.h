#ifndef  _EXPIRE_H_
#define  _EXPIRE_H_
#include"arraylib.h"
#include"hashmap.h"

//ʹ�øýṹʱ����Ҫͷ��㣬ͷ��㲻��������
typedef struct expires
{
	struct expires *next;	//��һ��
	struct expires *last;	//��һ��
	Entry *entry;			//�й���ʱ���kv
	long expire;			//����ʱ��
}Expires;

//���ù���ʱ��
int set_expire(Array *arr, Expires *expires_head, char *k, long time);

//��ȡ��ǰʱ���
long get_timestamp();

//ɾ�����ڼ� ������ɾ����
int expire_if_needed(Entry *dest_entry, Expires *expires);

//ɾ����֮ǰ����expires��
int del_key_before(Entry *dest_entry, Expires *expires);
#endif