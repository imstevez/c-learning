#include <stdlib.h>
#include <stdio.h>
#include "list.h"


// 创建带头链表
list *list_create()
{
	list *me;
	me = malloc(sizeof(*me));
	if (me == NULL) {
		return NULL;
	}
	
	me->next = NULL;
	return me;
};

// 打印带头链表
void list_display(list *l)
{
	struct node_st* cur;
	for(cur = l->next; cur != NULL; cur = cur->next) {
		printf("%d ", cur->data);
	}
	printf("\n");
}

// 向带头链表指定插入节点
// 返回值：0 成功 -1 内存申请失败 -2 指定位置不存在
int list_insert_at(list *l, int n, datatype *data)
{
	struct node_st *cur = l, *new;
	int i;

	for (i = 1; cur != NULL && i < n; i++) {
		cur = cur->next;
	}
	if (cur == NULL) {
		return -2;
	}

	new = malloc(sizeof(*new));
	if (new == NULL) {
		return -1;
	}

	new->data = *data;
	new->next = cur->next;
	cur->next = new;

	return 0;
}

// 删除带头链表指定位置的节点
// 返回值：0 成功 -2 指定位置不存在
int list_delete_at(list *l, int n, datatype *data)
{
	struct node_st *cur = l, *nod;
	int i;
	for (i = 1; i < n && cur->next != NULL; i++) {
		cur = cur->next;
	}
	if (cur->next == NULL) {
		return -2;
	}

	nod = cur->next;
	*data = nod->data;
	cur->next = nod->next;
	free(nod);

	return 0;
}

// 按值递增顺序向带头链表中插入节点
// 返回值：0 成功 -1 内存申请失败
int list_order_insert(list *l, datatype *data)
{
	struct node_st *cur = l, *new;
	while(cur->next != NULL && *data > cur->next->data) {
		cur = cur->next;
	}
	
	new = malloc(sizeof(*new));
	if (new == NULL) {
		return -1;
	}
	new->data = *data;
	new->next = cur->next;
	cur->next = new;
	return 0;
}

// 销毁带头链表
// 返回值：0 成功
int list_destroy(list *l)
{
	struct node_st *cur = l, *nod;
	while(cur != NULL) {
		nod = cur;
		cur = cur->next;
		nod->next = NULL;
		free(nod);
		
	}
	return 0;
}
