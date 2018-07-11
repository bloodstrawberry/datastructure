#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int PriorityComp(HData d1, HData d2);

//우선순위를 저장하는 멤버는 더이상 필요가 없음.
//typedef struct _heapElem
//{
//	Priority pr; // 값이 작으면 높은 우선 순위
//	HData data;
//} HeapElem;

typedef struct _heap
{
	PriorityComp *comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph, PriorityComp pc);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data);
HData HDelete(Heap *ph);

#endif
