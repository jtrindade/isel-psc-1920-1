#include <stdio.h>

int items[5] = { 10, 11, 12, 13, 14 };

int main() {
	/*
	int *p = &items[0];
	
	printf("the address of items[0] is: %p\n", &items[0]);
	printf("p contains the address: %p\n", p);
	
	items[0] = 3;
	printf("p is pointing at the value: %d\n", *p);
	
	*p = 5;
	printf("items[0] contains: %d\n", items[0]);
	
	int *p2 = items;  // p2 = &items[0]
	
	int *p3 = p + 1;  // p3 = &items[1]
	*/
	
	int *p = &items[0];

	printf("p contains: %p\n", p);
	printf("items is: %p\n", items);
	printf("&items[0] is: %p\n", &items[0]);
	
	printf("p - 2 : %p\n", p - 2);  // &items[-2]
	printf("p - 1 : %p\n", p - 1);  // &items[-1]
	printf("p + 0 : %p\n", p + 0);  // &items[0]
	printf("p + 1 : %p\n", p + 1);  // &items[1]
	printf("p + 2 : %p\n", p + 2);  // &items[2]
	printf("p + 3 : %p\n", p + 3);  // &items[3]
	printf("p + 4 : %p\n", p + 4);  // &items[4]
	printf("p + 5 : %p\n", p + 5);  // &items[5]
	printf("p + 6 : %p\n", p + 6);  // &items[6]
	
	printf("items[3]     is: %d\n", items[3]);
	printf("*(items + 3) is: %d\n", *(items + 3));
	printf("3[items]     is: %d\n", 3[items]);
	
	for (int i = 0; i < 5; ++i) {
		printf("items[%d] : %d\n", i, items[i]);
	}
	
	for (int * p = items; p < &items[5]; ++p) {
		printf("*p : %d\n", *p);
	}

	printf("items[-2] : %d\n", items[-2]);
	printf("items[6] : %d\n", items[6]);
	
	int *px = (int *)0xFF080456788;
	printf("*px : %d\n", *px);
	
	printf("Good bye!\n");
	
	return 0;
}














