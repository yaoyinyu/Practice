#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

//静态
//初始化通讯录
//void Inintcontact(Contact* pc)
//{
//	assert(pc);
//	pc->count = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//动态
int Inintcontact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	pc->data = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		printf("Inintcontact::%s\n", strerror(errno));return 1;
	}
	pc->capacity = DEFAULT_SZ;
	return 0;
}

//销毁信息
void DestroyContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
	pc = NULL;
}

//静态
//添加信息
//void AddContact(Contact* pc)
//{
//	assert(pc);
//	if (pc->count == MAX)
//	{
//		printf("通讯录已满，无法添加");
//		return;
//	}
//	printf("请输入名字：");
//	scanf("%s", pc->data[pc->count].name);
//	printf("请输入年龄：");
//	scanf("%d", &(pc->data[pc->count].age));
//	printf("请输入性别：");
//	scanf("%s", pc->data[pc->count].sex);	
//	printf("请输入电话：");
//	scanf("%s", pc->data[pc->count].tele);
//	printf("请输入地址：");
//	scanf("%s", pc->data[pc->count].addr);
//
//	pc->count++;
//	printf("增加成功\n");
//}

//增容
void CheckCapacity(Contact* pc)
{
	if (pc->count == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			printf("AddContact::%s\n", strerror(errno));
		}
		else
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("增容成功\n");
		}
	}
}

//动态
void AddContact(Contact* pc)
{
	assert(pc);
	//增容
	CheckCapacity(pc);

	printf("请输入名字：");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄：");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入性别：");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话：");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址：");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("增加成功\n");
}

//显示信息
void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[i].name, 
													pc->data[i].age, 
													pc->data[i].sex, 
													pc->data[i].tele, 
													pc->data[i].addr);
	}
}

//查找
static int FindByName(Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
			return i;
	}
	return -1;
}

//删除信息
void DelContcat(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	if (pc->count == 0)
	{
		printf("通讯录为空，无需删除");
		return;
	}
	printf("输入要删除人的名字：");
	scanf("%s", name);

	//查找
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("不存才此人\n");
		return;
	}

	//删除
	int i = 0;
	for (i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除成功\n");
}

//查找信息
void SearchContcat(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("输入要查找人的名字");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("不存才此人\n");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr);
}

//修改信息
void ModifyContcat(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("输入要修改人的名字");
	scanf("%s", name);

	//修改
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("不存才此人\n");
		return;
	}

	//修改
	printf("请输入名字：");
	scanf("%s", pc->data[pos].name);
	printf("请输入年龄：");
	scanf("%d", &(pc->data[pos].age));
	printf("请输入性别：");
	scanf("%s", pc->data[pos].sex);
	printf("请输入电话：");
	scanf("%s", pc->data[pos].tele);
	printf("请输入地址：");
	scanf("%s", pc->data[pos].addr);
}

int cmp_peo_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

//排序信息（姓名）
void SostContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("排序成功\n");
}