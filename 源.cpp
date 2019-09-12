#include<iostream>
using namespace std;

//����һ������ڵ�
struct ListNode
{
	int value;
	ListNode* next;
};

//����һ���½ڵ㵽������(��������ͷ��)
void CreateList(ListNode*& head, int data)
{
	//�����½ڵ�
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->value = data;
	p->next = NULL;

	if (head == NULL)
	{
		head = p;
		return;
	}
	p->next = head;
	head = p;
}

void  printList(ListNode* head)
{
	ListNode* p = head;
	while (p != NULL)
	{
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
}


//�ݹ鷽ʽ��ʵ�ֵ�����ת
ListNode* ReverseList(ListNode* head)
{
	//�ݹ���ֹ�������ҵ��������һ�����
	if (head == NULL || head->next == NULL)
		return head;
	else
	{
		ListNode* newhead = ReverseList(head->next);//�ȷ�ת�����������������������㿪ʼ��ת��������ǰ
		head->next->next = head;//����һ��������ָ��ǰһ�����
		head->next = NULL;//��ԭ������ǰһ�����ָ���һ������ָ���ϵ�Ͽ�
		return newhead;
	}
}

//�ǵݹ鷽ʽ��ʵ�ֵ�����ת
ListNode* reverseList2(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* prev = head;
	ListNode* cur = head->next;
	ListNode* temp = head->next->next;

	while (cur) {
		temp = cur->next; //temp��Ϊ�м�ڵ㣬��¼��ǰ������һ���ڵ��λ��
		cur->next = prev;  //��ǰ���ָ��ǰһ���ڵ�
		prev = cur;     //ָ�����
		cur = temp;  //ָ����ƣ�������һ���ڵ�
	}

	head->next = NULL; //while�����󣬽���ת������һ���ڵ㣨����תǰ�ĵ�һ�����head����������ΪNULL
	return prev;
}


int main()
{
	ListNode* head = NULL;
	for (int i = 0; i < 9; i++)
		CreateList(head, i);
	printList(head);
	head = ReverseList(head);
	printList(head);
	system("pause");
	return 0;
}
