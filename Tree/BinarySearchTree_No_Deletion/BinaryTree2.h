#ifndef __BINARY_TREE2_H__
#define __BINARY_TREE2_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode *left;
	struct _bTreeNode *right;
}BTreeNode;

BTreeNode *MakeBtreeNode(void); //노드 생성
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

void DeleteTree(BTreeNode *bt);


#endif
