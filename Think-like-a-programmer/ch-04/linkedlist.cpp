#include <iostream>
using namespace std;

// 宣告節點結構
typedef struct ns
{
	int data;
	struct ns* next;
} node;

// 宣告相關函式
node* create_node(int);
void insert_node(node*, node*);
void remove_node(node*);
void print_lists(node*);
void delete_lists(node*);

int main(void)
{
	node* lists = create_node(0);
	node* a = create_node(1);
	node* b = create_node(2);
	node* c = create_node(3);
	node* d = create_node(4);
	node* e = create_node(5);


	insert_node(lists, e);//05
	insert_node(lists, a);//01
	insert_node(a, b);//12
	insert_node(b, c);//23
	insert_node(c, d);//34

	print_lists(lists);//012345

	delete_lists(lists);

	system("pause");

	return 0;
}

node* create_node(int data)
{
	//node* n = (node*)malloc(sizeof(node));
	node* n = new node;
	n->data = data;
	n->next = NULL;
	return n;
}

void insert_node(node* n1, node* n2)
{
	n2->next = n1->next;
	n1->next = n2;

}

void remove_node(node* n1)
{
	//tempNode 避免 memory leak
	//node *tempNode = (node*)malloc(sizeof(node));
	node* tempNode = new node;
	tempNode->data = n1->next->data;
	tempNode->next = n1->next;
	n1->next = n1->next->next;
	delete tempNode;
}

void print_lists(node* lists)
{
	node *n = lists;
	while (n != NULL)
	{
		cout << n->data;
		n = n->next;
	}
	cout << endl;
}

void delete_lists(node* lists)
{
	if (lists->next != NULL)
	{
		delete_lists(lists->next);
	}
	delete lists;
}
