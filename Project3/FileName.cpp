#include <stdio.h>
#include <string.h>
#define MAX 100
typedef int ElemType;
typedef struct {
	ElemType data[MAX];
	int length;
}list;

void initList(list* L) {
	L->length = 0;
}
int biaoman(list* L, ElemType e) {
	if (L->length >= MAX) return 0;
}