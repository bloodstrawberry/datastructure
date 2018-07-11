#include <stdio.h>
#include "BinaryTree2.h"
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode *bst)
{
	return GetData(bst);
}

void BSTInset(BTreeNode **pRoot, BSTData data)
{
	BTreeNode *pNode = NULL; //parent
	BTreeNode *cNode = *pRoot; //current
	BTreeNode *nNode = NULL; //new

	//새로운 노드가 추가될 위치를 찾는다.
	while (cNode != NULL)
	{
		if (data == GetData(cNode)) return; //중복 방지

		pNode = cNode;

		if (GetData(cNode) > data) cNode = GetLeftSubTree(cNode);
		else cNode = GetRightSubTree(cNode);
	}

	//parent에 자식 노드로 추가할 새 노드 생성
	nNode = MakeBtreeNode();
	SetData(nNode, data);

	if (pNode != NULL) // 루트 노드가 아니라면
	{
		if (data < GetData(pNode)) MakeLeftSubTree(pNode, nNode);
		else MakeRightSubTree(pNode, nNode);
	}
	else *pRoot = nNode;
}

BTreeNode *BSTSearch(BTreeNode *bst, BSTData target)
{
	BTreeNode *cNode = bst; //current
	BSTData cd; //current data

	while (cNode != NULL)
	{
		cd = GetData(cNode);

		if (target == cd) return cNode;
		else if (target < cd) cNode = GetLeftSubTree(cNode);
		else cNode = GetRightSubTree(cNode);
	}

	return NULL;
}
