#ifndef  _ARRAY_LIB_H_
#define  _ARRAY_LIB_H_

typedef struct 
{
	int  n;     // ��̬�����Ԫ�ظ���
	//int  size;	// ��̬�����Ԫ�ؿռ��С
	void **data; // ��̬�����������ʼ��ַ
} Array;

/*
	���ܣ���ʼ����̬����
	������
		int n:���鳤��
		void(*init_obj)(void*):��ʼ��Ԫ�صĻص�����
	����ֵ��
		Arrayָ���0
*/
Array *init_array(int n);

#endif  /* _ARRAY_LIB_H_ */