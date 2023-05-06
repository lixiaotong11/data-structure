#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
struct workers
{
	int num;        //职工号；
	char name[15];	   //姓名；
	int clunum[31];	   //工作量；	 
	int time[31];      //时间；   
	int day;           //记录节点；
	int sum;           //工作总量；
};
typedef struct node
{
	struct workers data;
	struct node* next;
}Node;
//输入职工信息"'尾插法‘
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
	close: cout << "提示：输入非0的数字继续进行，输入0返回主菜单！\n";
		cin >> n;
		if (!n)
			break;
		cout << "请输入职工号:";
		cin >> n;
		for (z = workers; z != NULL; z = z->next)//已填写的职工重复填写工作量；
		{
			if (n == z->data.num)
			{
				cout << "请输入您想添加的产品数量:";
				cin >> z->data.clunum[z->data.day];//错误：将z的链表写成p
				z->data.sum += z->data.clunum[z->data.day];
				cout << "请输入该产品完成时间：";
				cin >> z->data.time[z->data.day++];
				goto close;
			}
		}

		p = (Node*)malloc(sizeof(Node));
		p->data.num = n;
		printf("请输入名字:");
		cin >> p->data.name;
		
		p->data.sum = p->data.day = 0;//定义总量和时间节点初始量；

		int clunum, time;//用于给产品数量和时间赋值；
		while (1)
		{
		//	
			/*if (!n) {
				p->data.clunum[p->data.day] = p->data.time[p->data.day] = 0;
				break;
			}*/
			cout << "提示：如果产品数量输入0结束登记！\n";
			cout << "请输入产品数量:";
			cin >> clunum;//用于退出输入产品数量和对应时间的循环；
			if (clunum == 0)
				break;
			p->data.clunum[p->data.day] = clunum;
			p->data.sum += p->data.clunum[p->data.day];
			cout << "请输入完成时间:";
			cin >> time;
			p->data.time[p->data.day++] = time;
		}
		cout << "提示：已经完成一条记录添加!";
		p->next = NULL;
		q->next = p;
		q = p;
	}
}
//修改职工信息
int change(Node *workers)
{
	Node* p;
	int f;
	p = workers->next;
	if (p == NULL)//链表中没节点时退出；
	{
		cout << "\n提示：您没有资料可以查询！\n";
		return 0;
	}
	cout << "请输入要修改的职工号：";
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
			cout << "完成修改请输入0，否则输入非0数字进行修改！";
			cin >> x;
			if (x == 0) {
				break;
			}
			cout << "请输入新的职工号：";
			cin >> p->data.num;
			cout << "请输入新职工姓名：";
			cin >> p->data.name;
			int clunum, time;//用于给产品数量和时间赋值；
			while (1)
			{
				cout << "提示：如果产品数量输入0结束登记！\n";

				cout << "请输入产品数量:";
				cin >> clunum;//用于退出输入产品数量和对应时间的循环；
				if (clunum == 0)
					break;
				p->data.clunum[p->data.day] = clunum;
				p->data.sum += p->data.clunum[p->data.day];
				cout << "请输入完成时间:";
				cin >> time;
				p->data.time[p->data.day++] = time;
			}
		}
	}
	else
		cout << "\n提示：没有你要修改的资料：\n";
}
//对各职工进行排序
void coll(Node *workers)
{

	Node *p1, * p2, * p3,*temp;
	int i = 1;
	for (p2 = NULL; p2 != workers->next; p2 = p1)
		for (p1 = (p3 = workers)->next; p1->next != p2; p1 = (p3 = p1)->next)
			if (p1->data.sum < p1->next->data.sum)//进行由大到小排序；
			{
				p3->next = p1->next;
				temp = p3->next->next;
				p1->next = temp;
				p3->next->next = p1;
				p1 = p3->next;
			}
	for (p1 = workers->next; p1; p1 = p1->next) {//不输出含零尾节点
		cout << i++ << "	"<<p1->data.num	<<"		"<<p1->data.sum << endl;
	}
}
//查询职工信息
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
		printf(" \n提示：没有资料可以查询！\n ");
		return 0;
	}
	cout << "\n提示：\n 输入 0---- 退出\t 输入 1----按职工号查询\t 输入 2-----按职工姓名查询\n";
	cout << "请选择：";
	cin >> sel;
	if (sel == 1)
	{
		i = 0;
		cout << "\n请输入你要查询分类的职工号：";
		cin >> find;
		while (p != NULL)
		{
			if (find == p->data.num)
			{
				cout << "职工号："<<p->data.num;
				cout << "\n姓名：" << p->data.name;
				for ( ;i<p->data.day; i++)
				{
					cout << "\n工作时间：" << p->data.time[i] << "；在该工作周期内完成的件数：" << p->data.clunum[i];
				}
				break;
			}
			p = p->next;
		}
		if (i == 0)
			cout << "提示：没有此员工";
	}
	else 
		if (sel == 2)
		{
			cout << "\n请输入你要查询分类的姓名：";
			cin >> find_;
			while (p != NULL)
			{
				i = 0;
				if (strcmp(find_,p->data.name)==0)
				{
					cout << "职工号：" << p->data.num;
					cout << "\n姓名：" << p->data.name;
					for (;i<p->data.day; i++)
					{
						cout << "\n工作时间：" << p->data.time[i] << "；在该工作周期内完成的件数：" << p->data.clunum[i];
					}
					break;
				}
				p = p->next;
			}
			if (i == 0)
				cout << "提示：没有该员工";
		}
		else if (sel == 0)
		{
			return 0;
		}
}
//将职工信息保存到文件
void save(Node *workers)
{
	int n;
	Node* p = NULL;
	FILE* fp;
	int i;
	printf("是否保存到文件？( 1-----保存！，0-----不保存！ )");
	cin >> n;

	if (n == 1)
	{
		if (workers->next == NULL)
		{
			printf(" 没有记录！");
		}

		else
		{
			p = workers->next;
		}

		if ((fp = fopen("C:/Users/LXT/Desktop/zhigong.txt", " w ")) == NULL)
		{
			printf(" 文件不能打开！\n");
		}

		while (p)
		{
			fprintf(fp, "%d\t%s\t%d", p->data.num, p->data.name, p->data.sum);
			for(i=0;i< p->data.day;i++)
			fprintf(fp, "\t%d\t%d", p->data.clunum[i], p->data.time[i]);//往文件中写入；
			p = p->next;
			fprintf(fp, "\n");
		}
		fprintf(fp, "-1");
		fclose(fp);

	}

}

//读取职工信息
Node* du()
{
	Node* p,*q, *head;
	int n, i;
	FILE* fp;

	if ((fp = fopen("C:/Users/LXT/Desktop/zhigong.txt", "r")) == NULL)
	{
		printf("文件不能打开!\n ");
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
		printf("\n职工工作量统计系统\n");
		printf("==================菜 单==================\n");
		printf("1.输入职工工作信息\n");
		printf("2.修改职工信息\n");
		printf("3.对职工进行排序并输出名次\n");
		printf("4.查询职工信息\n");
		printf("5.读取职工信息\n");
		printf("0.退出\n");

		printf("输入您选择的序号进行操作\n");
		cin >> n;
		switch (n)
		{
		case 0:printf("\n提示：退出系统！\n"); return 0;
		case 1:Add(workers); save(workers); break;//添加,保存文件；
		case 2:change(workers); break;//修改
		case 3:coll(workers); break;//排序
		case 4:find(workers); break;//查找
		case 5:workers = du(); break;//读取
		default:printf("输入错误");
			break;
		}
		
	}
}