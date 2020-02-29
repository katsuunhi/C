#include <stdio.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

int main ()
{
	struct node nd1,nd2,nd3;
	struct node *head,*tail;
	head=&nd1;
	tail=NULL;
	head->left=&nd2;
	head->right=&nd3;
	head->right->data=10;
	head->left->data=20;
	printf("%d\n%d",nd2.data,nd3.data);

	return 0;
}