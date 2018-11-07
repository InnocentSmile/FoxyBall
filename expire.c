#include<time.h>
#include<malloc.h>
#include"hashmap.h"
#include"expire.h"
#include"global.h"

long get_timestamp()
{
	time_t t;
	long ret;
	ret = time(&t);
	return ret;
}

int set_expire(Array *arr, Expires *expires_head, char *k, long time)
{
	Entry *dest_entry = exist_key(arr,k);
	//key������
	if (dest_entry == 0)
		return 0;
	while (1)
	{
		if (expires_head->next == 0)
		{
			Expires *expire = (Expires *)malloc(sizeof(Expires));
			expire->last = expires_head;
			expire->next = 0;
			expire->entry = dest_entry;
			expire->expire = get_timestamp() + time;
			expires_head->next = expire;
			return 1;
		}
		else
		{
			expires_head = expires_head->next;
		}
	}
	return 0;
}

int expire_if_needed(Entry *dest_entry, Expires *expires)
{
	if (expires == 0)
		return 0;

	do
	{
		//�ҵ�����Ҫɾ����entry
		if (dest_entry == expires->entry)
		{
			//�ж��Ƿ����
			if (expires->expire < get_timestamp())
			{
				//û����һ���ڵ�
				if (expires->next == 0)		
				{
					//��hash_table��ɾ��
					del_key(hash_table, dest_entry->k);
					//expires->last->next = 0;
					//free(expires);
					return 1;
				}
				//����һ���ڵ�
				else
				{
					//��hash_table��ɾ��
					del_key(hash_table, dest_entry->k);
					//expires->last->next = expires->next;
					//free(expires);
					return 1;
				}
			}
		}
	} while (expires = expires->next);
	return 0;
}

int del_key_before(Entry *dest_entry, Expires *expires)
{
	if (expires == 0)
		return 0;

	do
	{
		//�ҵ�����Ҫɾ����entry
		if (dest_entry == expires->entry)
		{
			//ɾ����ǰ�ڵ�
			if (expires->next == 0)		//û����һ���ڵ�
			{
				expires->last->next = 0;
				free(expires);
				return 1;
			}
			//����һ���ڵ�
			else
			{
				expires->last->next = expires->next;
				free(expires);
				return 1;
			}
		}
	} while (expires = expires->next);
	return 0;
}