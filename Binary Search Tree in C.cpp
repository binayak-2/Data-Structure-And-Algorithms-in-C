#include <stdio.h>
#include <stdlib.h>
struct Node {
	struct Node *leftChild;
	int data;
	struct Node *rightChild;
}*root = NULL;

void Insert(int key)
{
	Node *t = root;
	Node *tail = NULL, *newNode;
	if(root == NULL){
		newNode = (struct Node *)malloc(sizeof(struct Node));
		newNode->data = key;
		newNode->leftChild = newNode->rightChild = NULL;
		root = newNode;
		return;
	}
	while(t != NULL)
	{
		tail = t;
		if(key == t->data)
			return;
		else if(key < t->data)
			t = t->leftChild;
		else 
			t = t->rightChild;
	}
	newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = key;
	newNode->leftChild = newNode->rightChild = NULL;
	
	if(newNode->data < tail->data)
		tail->leftChild = newNode;
	else 
		tail->rightChild = newNode;
}

void Inorder(struct Node *p)
{
	if(p)
	{
		Inorder(p->leftChild);
		printf("%d	", p->data);
		Inorder(p->rightChild);
	}
}


struct Node *Search(int key){
	struct Node *t = root;
	while(t != NULL){
		if(key == t->data)
			return t;
		else if(key < t->data)
			t = t->leftChild;
		else 
			t = t->rightChild;
	}
	return NULL; //out of loop without key found !
}
struct Node *delete_node(struct Node *root, int val)
{
    if (root == NULL)
        return NULL;
    if (val < root->data)
        root->leftChild = delete_node (root->leftChild, val);
    else if (val > root->data)
        root->rightChild = delete_node(root->rightChild, val);
    else
    {
        // no child
        if (root->leftChild == NULL && root->rightChild == NULL)
        {
            delete(root);
            return NULL;
        }
        // 1 child
        else if (root->leftChild == NULL || root->rightChild == NULL)
        {
            struct Node *temp = root->leftChild ? root->leftChild : root->rightChild;
            free(root);
            return temp;
        }
        // 2child
        else if (root->leftChild != NULL && root->rightChild != NULL)
        {
            struct Node *temp = root->rightChild;
            while (temp->leftChild != NULL)
                temp = temp->leftChild;
            root->data = temp->data;
            root->rightChild = delete_node(root->rightChild, root->data);
        }
    }
    return root;
}
int main()
{
	Insert(10);Insert(5);Insert(20); Insert(8); Insert(30);
	Inorder(root);
	delete_node(root, 5);
	printf("\n");
	Inorder(root);
	printf("\n");
	struct Node *temp = Search(100);
	if(temp != NULL)
	{
		printf("Element %d is found \n", temp->data);	
	}
	else 
		printf("Element is not found ");
	
	
}