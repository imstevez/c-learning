#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
	list *l;
	int v;

	l = list_create();
	if (l == NULL) {
		exit(1);
	}

	for (int i = 0; i < 10; i++) {
		list_order_insert(l, &i);
	}
	
	list_delete_at(l, 6, &v);

	list_display(l);
	
	printf("deleted value: %d\n", v);
	
	list_destroy(l);

	list_display(l);
}
