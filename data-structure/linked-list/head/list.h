#ifndef LIST_H__
#define LIST_H__

// 节点数据类型
typedef int datatype;

// 节点结构，链表类型
typedef struct node_st
{
	datatype data;
	struct node_st *next;
}list;

// 创建链表
list *list_create(); 

// 打印链表
void list_display();

// 列表是否为空
int list_is_empty(list *);

// 指定位置插入节点
int list_insert_at(list *, int, datatype *);

// 删除指定位置节点
int list_delete_at(list *, int n, datatype *);

// 升序插入节点
int list_order_insert(list *, datatype *);

// 销毁链表
int list_destroy(list *);

#endif
