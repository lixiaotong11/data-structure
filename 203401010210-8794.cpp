#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
struct workers
{
	int num;        //ְ���ţ�
	char name[15];	   //������
	int clunum[31];	   //��������	 
	int time[31];      //ʱ�䣻   
	int day;           //��¼�ڵ㣻
	int sum;           //����������
};
typedef struct node
{
	struct workers data;
	struct node* next;
}Node;
//����ְ����Ϣ"'β�巨��
void Add(Node *workers)
{
	Node* p, * q, * z;
	double n;
	q = workers;
	while (q->next != NULL)
	{
		q = q->next;
	}
	while (1)
	{
	close: cout << "��ʾ�������0�����ּ������У�����0�������˵���\n";
		cin >> n;
		if (!n)
			break;
		cout << "������ְ����:";
		cin >> n;
		for (z = workers; z != NULL; z = z->next)//����д��ְ���ظ���д��������
		{
			if (n == z->data.num)
			{
				cout << "������������ӵĲ�Ʒ����:";
				cin >> z->data.clunum[z->data.day];//���󣺽�z������д��p
				z->data.sum += z->data.clunum[z->data.day];
				cout << "������ò�Ʒ���ʱ�䣺";
				cin >> z->data.time[z->data.day++];
				goto close;
			}
		}

		p = (Node*)malloc(sizeof(Node));
		p->data.num = n;
		printf("����������:");
		cin >> p->data.name;
		
		p->data.sum = p->data.day = 0;//����������ʱ��ڵ��ʼ����

		int clunum, time;//���ڸ���Ʒ������ʱ�丳ֵ��
		while (1)
		{
		//	
			/*if (!n) {
				p->data.clunum[p->data.day] = p->data.time[p->data.day] = 0;
				break;
			}*/
			cout << "��ʾ�������Ʒ��������0�����Ǽǣ�\n";
			cout << "�������Ʒ����:";
			cin >> clunum;//�����˳������Ʒ�����Ͷ�Ӧʱ���ѭ����
			if (clunum == 0)
				break;
			p->data.clunum[p->data.day] = clunum;
			p->data.sum += p->data.clunum[p->data.day];
			cout << "���������ʱ��:";
			cin >> time;
			p->data.time[p->data.day++] = time;
		}
		cout << "��ʾ���Ѿ����һ����¼���!";
		p->next = NULL;
		q->next = p;
		q = p;
	}
}
//�޸�ְ����Ϣ
int change(Node *workers)
{
	Node* p;
	int f;
	p = workers->next;
	if (p == NULL)//������û�ڵ�ʱ�˳���
	{
		cout << "\n��ʾ����û�����Ͽ��Բ�ѯ��\n";
		return 0;
	}
	cout << "������Ҫ�޸ĵ�ְ���ţ�";
	cin >> f;
	while (p)
	{
		if (f == p->data.num)
		{
			break;
		}
		p = p->next;
	}
	if (p != NULL)
	{
		int x;
		while (1)
		{
			cout << "����޸�������0�����������0���ֽ����޸ģ�";
			cin >> x;
			if (x == 0) {
				break;
			}
			cout << "�������µ�ְ���ţ�";
			cin >> p->data.num;
			cout << "��������ְ��������";
			cin >> p->data.name;
			int clunum, time;//���ڸ���Ʒ������ʱ�丳ֵ��
			while (1)
			{
				cout << "��ʾ�������Ʒ��������0�����Ǽǣ�\n";

				cout << "�������Ʒ����:";
				cin >> clunum;//�����˳������Ʒ�����Ͷ�Ӧʱ���ѭ����
				if (clunum == 0)
					break;
				p->data.clunum[p->data.day] = clunum;
				p->data.sum += p->data.clunum[p->data.day];
				cout << "���������ʱ��:";
				cin >> time;
				p->data.time[p->data.day++] = time;
			}
		}
	}
	else
		cout << "\n��ʾ��û����Ҫ�޸ĵ����ϣ�\n";
}
//�Ը�ְ����������
void coll(Node *workers)
{

	Node *p1, * p2, * p3,*temp;
	int i = 1;
	for (p2 = NULL; p2 != workers->next; p2 = p1)
		for (p1 = (p3 = workers)->next; p1->next != p2; p1 = (p3 = p1)->next)
			if (p1->data.sum < p1->next->data.sum)//�����ɴ�С����
			{
				p3->next = p1->next;
				temp = p3->next->next;
				p1->next = temp;
				p3->next->next = p1;
				p1 = p3->next;
			}
	for (p1 = workers->next; p1; p1 = p1->next) {//���������β�ڵ�
		cout << i++ << "	"<<p1->data.num	<<"		"<<p1->data.sum << endl;
	}
}
//��ѯְ����Ϣ
int find(Node *workers)
{
	Node* p;
	int sel;
	double  find;
	char find_[30];
	p = workers->next;
	int i;
	if (p == NULL)
	{
		printf(" \n��ʾ��û�����Ͽ��Բ�ѯ��\n ");
		return 0;
	}
	cout << "\n��ʾ��\n ���� 0---- �˳�\t ���� 1----��ְ���Ų�ѯ\t ���� 2-----��ְ��������ѯ\n";
	cout << "��ѡ��";
	cin >> sel;
	if (sel == 1)
	{
		i = 0;
		cout << "\n��������Ҫ��ѯ�����ְ���ţ�";
		cin >> find;
		while (p != NULL)
		{
			if (find == p->data.num)
			{
				cout << "ְ���ţ�"<<p->data.num;
				cout << "\n������" << p->data.name;
				for ( ;i<p->data.day; i++)
				{
					cout << "\n����ʱ�䣺" << p->data.time[i] << "���ڸù�����������ɵļ�����" << p->data.clunum[i];
				}
				break;
			}
			p = p->next;
		}
		if (i == 0)
			cout << "��ʾ��û�д�Ա��";
	}
	else 
		if (sel == 2)
		{
			cout << "\n��������Ҫ��ѯ�����������";
			cin >> find_;
			while (p != NULL)
			{
				i = 0;
				if (strcmp(find_,p->data.name)==0)
				{
					cout << "ְ���ţ�" << p->data.num;
					cout << "\n������" << p->data.name;
					for (;i<p->data.day; i++)
					{
						cout << "\n����ʱ�䣺" << p->data.time[i] << "���ڸù�����������ɵļ�����" << p->data.clunum[i];
					}
					break;
				}
				p = p->next;
			}
			if (i == 0)
				cout << "��ʾ��û�и�Ա��";
		}
		else if (sel == 0)
		{
			return 0;
		}
}
//��ְ����Ϣ���浽�ļ�
void save(Node *workers)
{
	int n;
	Node* p = NULL;
	FILE* fp;
	int i;
	printf("�Ƿ񱣴浽�ļ���( 1-----���棡��0-----�����棡 )");
	cin >> n;

	if (n == 1)
	{
		if (workers->next == NULL)
		{
			printf(" û�м�¼��");
		}

		else
		{
			p = workers->next;
		}

		if ((fp = fopen("C:/Users/LXT/Desktop/zhigong.txt", " w ")) == NULL)
		{
			printf(" �ļ����ܴ򿪣�\n");
		}

		while (p)
		{
			fprintf(fp, "%d\t%s\t%d", p->data.num, p->data.name, p->data.sum);
			for(i=0;i< p->data.day;i++)
			fprintf(fp, "\t%d\t%d", p->data.clunum[i], p->data.time[i]);//���ļ���д�룻
			p = p->next;
			fprintf(fp, "\n");
		}
		fprintf(fp, "-1");
		fclose(fp);

	}

}

//��ȡְ����Ϣ
Node* du()
{
	Node* p,*q, *head;
	int n, i;
	FILE* fp;

	if ((fp = fopen("C:/Users/LXT/Desktop/zhigong.txt", "r")) == NULL)
	{
		printf("�ļ����ܴ�!\n ");
	}
	head = q = (Node*)malloc(sizeof(Node));
	fscanf(fp, "%d", &n);
	while (n>=0)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data.num = n;
		fscanf(fp, "%s%d%d", p->data.name, &(p->data.sum), &(p->data.day));
		for(i=0;i < p->data.day;i++)
			fscanf(fp, "%d%d", p->data.clunum + i, p->data.time + i);
		q->next = p;
		q = p;
		fscanf(fp, "%d", &n);
	}
	p->next = NULL;
	fclose(fp);
	return head;

}

int main()
{
	Node* workers;
	int n;
	workers = (Node*)malloc(sizeof(Node));
	workers->next = NULL;
	while (1)
	{
		printf("\nְ��������ͳ��ϵͳ\n");
		printf("==================�� ��==================\n");
		printf("1.����ְ��������Ϣ\n");
		printf("2.�޸�ְ����Ϣ\n");
		printf("3.��ְ�����������������\n");
		printf("4.��ѯְ����Ϣ\n");
		printf("5.��ȡְ����Ϣ\n");
		printf("0.�˳�\n");

		printf("������ѡ�����Ž��в���\n");
		cin >> n;
		switch (n)
		{
		case 0:printf("\n��ʾ���˳�ϵͳ��\n"); return 0;
		case 1:Add(workers); save(workers); break;//���,�����ļ���
		case 2:change(workers); break;//�޸�
		case 3:coll(workers); break;//����
		case 4:find(workers); break;//����
		case 5:workers = du(); break;//��ȡ
		default:printf("�������");
			break;
		}
		
	}
}