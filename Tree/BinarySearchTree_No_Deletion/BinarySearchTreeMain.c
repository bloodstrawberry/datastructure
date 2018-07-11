#include <stdio.h>
#include "BinarySearchTree.h"

int main()
{
	BTreeNode *bstRoot;
	BTreeNode *sNode; //search Node

	BSTMakeAndInit(&bstRoot);

	BSTInset(&bstRoot, 9);
	BSTInset(&bstRoot, 1);
	BSTInset(&bstRoot, 6);
	BSTInset(&bstRoot, 2);
	BSTInset(&bstRoot, 8);
	BSTInset(&bstRoot, 3);
	BSTInset(&bstRoot, 5);

	sNode = BSTSearch(bstRoot, 1);
	if (sNode == NULL) printf("탐색 실패\n");
	else printf("탐색에 성공한 키의 값 : %d\n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 4);
	if (sNode == NULL) printf("탐색 실패\n");
	else printf("탐색에 성공한 키의 값 : %d\n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 6);
	if (sNode == NULL) printf("탐색 실패\n");
	else printf("탐색에 성공한 키의 값 : %d\n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 7);
	if (sNode == NULL) printf("탐색 실패\n");
	else printf("탐색에 성공한 키의 값 : %d\n", BSTGetNodeData(sNode));

	return 0;
}
