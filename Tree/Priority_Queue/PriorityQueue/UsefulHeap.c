#include "UsefulHeap.h"

void HeapInit(Heap *ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
}

int HIsEmpty(Heap *ph)
{
	if (ph->numOfData == 0) return TRUE;
	return FALSE;
}

int GetParentIDX(int idx)
{
	return idx / 2;
}

int GetLChildIDX(int idx)
{
	return idx * 2;
}

int GetRChildIDX(int idx)
{
	return GetLChildIDX(idx) + 1;
}

// 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환
int GetHiPriChildIDX(Heap *ph, int idx)
{
	int L, R;

	L = GetLChildIDX(idx);
	R = GetRChildIDX(idx);

	if (L > ph->numOfData) return 0; // 자식 노드가 없다면,
	else if (L == ph->numOfData) return L; //자식 노드가 왼쪽 자식 노드 하나만 존재한다면,
	else // 자식 노드가 둘 다 존재한다면,
	{
		//오른쪽 자식 노드의 우선순위가 높다면
		//if (ph->heapArr[L].pr > ph->heapArr[R].pr) return R;
		if (ph->comp(ph->heapArr[L], ph->heapArr[R]) < 0) return R;
		else return L;
	}
}


void HInsert(Heap *ph, HData data)
{
	int idx = ph->numOfData + 1; //새 노드가 저장될 인덱스
	//HeapElem nelem = { pr, data }; // 새 노드 생성 및 초기화

	while (idx != 1)
	{
		// 새 노드와 부모 노드의 우선 순위 비교.
		//if (pr < (ph->heapArr[GetParentIDX(idx)].pr))
		if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
		{
			// 부모 노드를 한 레벨 내림, 실제로 내린다.
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx); // 새 노드를 한 레벨 올림, 실제로 올리지는 않는다.
		}
		else break;
	}

	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}


HData HDelete(Heap *ph)
{
	HData retData = ph->heapArr[1]; //삭제할 데이터
	HData lastElem = ph->heapArr[ph->numOfData]; //힙의 마지막 노드

	int parentIdx = 1;
	int childIdx;

	//parent에서 우선순위가 높은 자식을 선택.
	while (childIdx = GetHiPriChildIDX(ph, parentIdx))
	{

		//if (lastElem.pr <= ph->heapArr[childIdx].pr) break;
		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0) break;

		//마지막 노드보다 우선순위가 높으니 부모 노드의 위치로 올림, 실제로 올린다.
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx; // 자식 노드의 위치로 내림, 실제로 내리진 않는다.
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;

	return retData;
}
