#ifndef __BINARY_TREE3_H__
#define __BINARY_TREE3_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode *left;
	struct _bTreeNode *right;
}BTreeNode;

BTreeNode *MakeBTreeNode(void); //노드 생성
BTData GetData(BTreeNode* bt); // 저장 데이터 반환
void SetData(BTreeNode* bt, BTData data); // 데이터 저장

BTreeNode *GetLeftSubTree(BTreeNode *bt); //주소값 반환
BTreeNode *GetRightSubTree(BTreeNode *bt);

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub); //연결
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);

typedef void VisitFuncPtr(BTData data);

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);

//void DeleteTree(BTreeNode *bt);

//자식 노드 제거
BTreeNode *RemoveLeftSubTree(BTreeNode *bt);
BTreeNode *RemoveRightSubTree(BTreeNode *bt);

//메모리 소멸을 수반하지 않고, 자식 노드를 변경.
void ChangeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void ChangeRightSubTree(BTreeNode *main, BTreeNode *sub);


#endif
#pragma once
