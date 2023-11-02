#include<stdio.h>
#include<conio.h>\

#define MAXLEN 100
typedef int DataType;
typedef struct
{
	DataType data[MAXLEN];
	int Length;
}SeqList;

SeqList L;
void InitList(SeqList* L)
{
	L->Length = 0;     //顺序表的初始化
}

void CreateList(SeqList* L, int n)
{
	int i;
	printf("请输入%d个整数：", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &L->data[i]);
		getchar();//顺序表的建立
	}
	L->Length = n;
}

int GetElem(SeqList* L, int i, DataType* x)
{
	if (i < 1 || i >L->Length)
		return 0;
	else                           //按位置查找
	{
		*x = L->data[i - 1];
		return 1;
	}
}

int Locate(SeqList* L, DataType x)
{
	int i = 0;
	while (i < L->Length && L->data[i] != x)
		i++;
	if (i >= L->Length)         //按值查找
		return 0;
	else
		return i + 1;
}

int InsElem(SeqList* L, int i, DataType x)
{
	int j;
	if (i<0 || i>L->Length+1)
		return 0;
	for (j = L->Length - 1; j >= i - 1; j--)
		L->data[j + 1] = L->data[j];                //插入元素
	L->data[i - 1] = x;
	L->Length++;
	return 1;
}

int DelElem(SeqList* L, int i, DataType* x)
{
	int j;
	if (L->Length == 0)
	{
		printf("顺序表为空");
		return 0;
	}
	if (i<1 || i>L->Length)
	{
		printf("不存在第%d个元素",i);        //删除操作
		return 0;
	}
	*x = L->data[i - 1];
	for (j = i; j < L->Length; j++)
		L->data[j - 1] = L->data[j];
	L->Length--;
	return 1;
}

void DispList(SeqList* L)
{
	int i;
	for (i = 0; i < L->Length; i++)     //输出表中元素
		printf("%5d", L->data[i]);
}

void Menu() {
	printf("\n               顺序表各种操作");
	printf("\n=================================================");
	printf("\n|           1--建立顺序表                        |");
	printf("\n|           2--插入元素                          |");
	printf("\n|           3--删除元素                          |");
	printf("\n|           4--按位置查找元素                    |");
	printf("\n|           5--按元素值查找在表中位置            |");
	printf("\n|           6--求顺序表的长度                    |");
	printf("\n|请输入菜单号（0-6）:");
}

int main()
{
	SeqList L;
	DataType x;
	int n, i, loc;
	char ch1, ch2, a;
	ch1 = 'y';
	while (ch1 == 'y' || ch1 == 'Y')
	{
		Menu();
		scanf("%c",&ch2);
		getchar();
		switch (ch2)
		{
		case '1':
			InitList(&L);
			printf("请输入建立线性表的个数：");
			scanf("%d", &n);
			getchar();
			CreateList(&L, n);
			printf("建立的线性表：");
			DispList(&L);
			break;
		case '2':
			printf("请输入要插入的位置：");
			scanf("%d", &i);
			getchar();
			printf("请输入要插入的值：");
			scanf("%d",&x);
			getchar();
			if (InsElem(&L, i, x))
			{
				printf("以成功在第%d的位置上插入%d，插入后的线性表为：\n", i, x);
				DispList(&L);
			}
			else
				printf("输入插入的参数错误！");
			break;
		case '3':
			printf("请输入要删除元素的位置：");
			scanf("%d", &i);
			getchar();
			if (DelElem(&L, i, &x))
			{
				printf("已成功在第%d的位置上删除%d，删除后的线性表为：\n", i, x);
				DispList(&L);
			}
			else
				printf("\n输入删除的参数错误！");
			break;
		case '4':
			printf("\n请输入要查看表中元素的位置（从1开始）：");
			scanf("%d", &i);
			getchar();
			if (GetElem(&L, i, &x)) {
				printf("当前线性表第%d个元素的值为：%d\n", i, x);
				DispList(&L);
			}
			else
				printf("输入位置错误！");
			break;
		case '5':
			printf("请输入要查找的元素值为：");
			scanf("%d", &x);
			getchar();
			loc = Locate(&L, x);
			;
			if (loc) {
				printf("查找元素值为%d的位置为:%d\n", x, loc);
			}
			else
				printf("该此表中无此元素");
			break;
		case '6':
			printf("(当前线性表的长度为:%d)",L.Length);
			break;
		case  '0':
			ch1 = 'n';
			break;
		default:
			printf("输出有误，请输入0-6进行选择！");

			if (ch2 != '0') {
				printf("\n按回车键继续，按任意键返回主菜单！\n");
				a = getchar();
				if (a != '\xA') 
                {
					getchar();
					ch1 = 'n';
				}
			}
		}
	}
}