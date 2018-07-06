#include <stdio.h>
#include "BinaryTree2.h"

void ShowIntData(int data)
{
	printf("%d ", data);
}

int main(void)
{

	BTreeNode* bt1 = MakeBtreeNode();
	BTreeNode* bt2 = MakeBtreeNode();
	BTreeNode* bt3 = MakeBtreeNode();
	BTreeNode* bt4 = MakeBtreeNode();
	BTreeNode* bt5 = MakeBtreeNode();
	BTreeNode* bt6 = MakeBtreeNode();
	BTreeNode* bt7 = MakeBtreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);
	SetData(bt7, 7);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeLeftSubTree(bt3, bt6);
	MakeRightSubTree(bt3, bt7);


	PreorderTraverse(bt1, ShowIntData);
	printf("\n");
	InorderTraverse(bt1, ShowIntData);
	printf("\n");
	PostorderTraverse(bt1, ShowIntData);
	printf("\n");

	DeleteTree(bt1);

	
	return 0;
}
