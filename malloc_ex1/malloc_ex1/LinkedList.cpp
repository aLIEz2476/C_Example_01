/*
当コードはすべての機能を具現化したコードである。
バグっぽい部分があちこち有ったが現在時点で発見したバグはリストを逆に出力する部分以外ないと思う。
よってこのコードを完成版だと判断する。　以上。
*/

/*
逆出力部分の修正方法

関数の返還タイプを構造体関数で修正
修正した理由はポインターが始めるところがめちゃくちゃになる。
よってこれらの問題をメイン文の中で解決できるように修正した。
*/

/*##################################
단일연결리스트(수업용)
파일명: LinkedList_empty.cpp
작성자: 김홍규 (downkhg@gmail.com)
마지막수정날짜: 2018.02.09
버전: 1.04
###################################*/

#include <stdio.h>
#include <stdlib.h> //메모리 동적할당 헤더
#include <crtdbg.h> //메모리 누수 탐지 헤더

//#include  "linkedlistClass.h"

struct SNode {
	int nData;
	SNode* pNext;
};

SNode* CreateNode(SNode* pNode, int data); //노드를 생성하여 리턴한다.
SNode* FindNodeData(SNode* pStart, int data); //해당 데이터를 가진 노드를 찾는다.
SNode* InsertNodeData(SNode* pStart, int data, int insert); //해당 데이터를 가진 노드 뒤에 노드를 추가한다.
void DeleteNodeData(SNode* pStart, int del); //해당데이터를 가진 노드를 삭제한다.
void PrintLinkedList(SNode* pStart); //노드를 순회하며 끝날때까지 출력한다.
void DeleteLinkedList(SNode* pStart); //노드를 순회하며 모든데이터를 삭제한다.
SNode* ReverseLinkedList(SNode* pStart); //

									   //연결리스트 동적으로 입력받기.(동적할당 설명용)
void InputAdd();

//정상작동 테스트를 위해서, 다음과 같이 기본적인 절차로 오류를 확인한다.
//이 소스에 몇가지 버그가 존재한다.
//이 코드가 정상작동 된 후 발견해볼것!
//main()함수 내 코드는 절대 코드 변경하지말것.
int main()
{
	//_CrtSetBreakAlloc(71); //메모리 누수시 번호를 넣으면 할당하는 위치에 브레이크 포인트를 건다.
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //메모리 누수 검사 

	SNode* pBegin = NULL;
	SNode* pEnd = NULL;
	//pBegin : head, pEnd : tail

	//노드 추가 테스트
	pEnd = CreateNode(pEnd, 10);
	pBegin = pEnd; //마지막 노드를 알아야 검색이 가능하므로 저장해둔다.
	// 반환된 노드를 시작값에 저장

	pEnd = CreateNode(pEnd, 20);
	pEnd = CreateNode(pEnd, 30);
	pEnd = CreateNode(pEnd, 40);
	pEnd = CreateNode(pEnd, 50);

	PrintLinkedList(pBegin);

	SNode* pFind = FindNodeData(pBegin, 40);
	printf("Find:%d\n", pFind->nData);

	pEnd = InsertNodeData(pBegin, 30, 60);//노드 삽입

	
	PrintLinkedList(pBegin);

	pBegin=ReverseLinkedList(pBegin);
	pEnd = NULL;

	DeleteNodeData(pBegin, 60);//노드 삭제

	PrintLinkedList(pBegin);
	

	DeleteLinkedList(pBegin); //모든노드삭제 - 이 함수를 호출하지않을시 메모리가 누수됨.
}

//여기서 부터 기능을 구현한다.
//기존코드는 손대지말고, 현 프로그램 정상 작동하도록할것.
SNode* CreateNode(SNode* pNode, int data)
{
	SNode* pTemp;

	pTemp = new SNode(); // 임시 노드 동적할당으로 생성
	
	pTemp->nData = data;
	
	if (pNode != NULL)
	{
		pNode->pNext = pTemp;
	}
	// pNode가 NULL이 아닐 때, 즉 pNode 내부에 내용물이 있을 때
	// pNode(이전 노드의 주소)의 pNext(다음 노드 좌표)에게 pTemp(다음 노드의 주소)를 전달
		
	else
	{
		pTemp->pNext = pNode;
	}
	// pNode가 NULL일 때, 즉 pNode 내용물이 없을 때
	// pTemp의 pNext에게 자신의 주소를 전달
		
	
	return pTemp; // 노드 반환

}

SNode* FindNodeData(SNode* pStart, int data)
{
	SNode* pNode = pStart;
	while (pNode->pNext != NULL)
	{
		if (pNode->nData == data) return pNode; // 맞는 데이터를 찾으면 반환
		else pNode = pNode->pNext; // 맞는 게 아니면 다음 노드로 ㄱㄱ
	}
	return pNode;
}

SNode* InsertNodeData(SNode* pStart, int data, int insert)
{
	SNode* pNode = pStart;
	SNode* pTemp=FindNodeData(pNode, data);
	SNode* new_node = new SNode();
	new_node = CreateNode(NULL, insert);//넣을 노드 생성
	if (FindNodeData(pNode, data))
	{
		new_node->pNext = pTemp->pNext;
		pTemp->pNext = new_node;
	}// 데이터 찾아낸 경우
	else
	{
		printf("잘못된 입력입니다.\n\n");
		system("Pause");
	}// 아닌 경우
	
	
	
	return new_node;
}

void DeleteNodeData(SNode* pStart, int del)
{
	SNode* pNode = pStart;
	SNode* pDel = pStart->pNext; // pDel은 pNode대비 한발짝 더 나가있음
	while (pDel != NULL)
	{
		if (pDel->nData == del)
		{
			pNode->pNext = pDel->pNext; // 맞는 데이터를 찾았을 경우, 주소 변경
			free(pDel); // 대상 위치 박살
			printf("\n\n%d이(가) 들어간 노드 삭제 완료\n\n", del);
			break; // 탈출
		}
		else
		{
			pNode = pDel; // 한발 먼저 온 위치를 저장시킴
			pDel = pDel->pNext; // pDel을 한발짝 더 내보냄
		}
	}
}

void PrintLinkedList(SNode* pStart)
{
	SNode* pNode = pStart;
	printf("data:");
	while (pNode)
	{
		printf("%d", pNode->nData);
		pNode = pNode->pNext;

		if (pNode != NULL)
			printf(",");
	}
	printf("\n");
}

void DeleteLinkedList(SNode* pStart)
{
	SNode* pNode = pStart;
	SNode* pDel = pStart->pNext;

	while (1)
	{
		if (pDel->pNext==NULL)
		{
			free(pDel);
			break;
		}
		else
		{
			free(pNode);
			pNode = pDel;
			pDel = pDel->pNext;
		}
	}
	printf("\n\n모든 노드가 제거되었습니다.\n종료합니다.\n\n");
	
}

SNode* ReverseLinkedList(SNode* pStart)
{
	SNode *p, *q, *r;
	p = pStart; // 미처리 노드
	q = NULL; // 역순으로 만들어질 노드
	while (p != NULL)
	{
		r = q; // r은 역순으로 된 노드
		q = p; // r은 q를, ,q는 p를 따라감
		p = p->pNext; 
		q->pNext = r; // q의 링크방향 변경
	}
	// 역순 과정
	printf("\n\n역순으로 출력합니다.\n\n");
	PrintLinkedList(q); // q를 출력
	return q;
}

void InputAdd()
{
	SNode* pStart = NULL;
	SNode* pNode = NULL;
	int nData = 0;

	//동적할당을 하면 프로그램이 사용자에 의해서 사용되는 메모리가 결정된다.
	//쉽게말해서, 컴파일단계에서 100개를 만들고 쓴다면, 
	//사용하지않더라도 100개의 메모리를 사용할수밖에없다.
	//그리고, 100개 이상의 메모리도 사용할수없다.
	//그러나, 동적할당을 하면 사용자가 추가한 메모리만큼만 메모리가 사용되고 
	//메모리용량이 허용하는 한 추가가 된다.
	while (nData != -1)
	{
		scanf("%d", &nData);
		pNode = CreateNode(pNode, nData);

		if (pNode == NULL)
		{
			printf("더 이상 사용할수 있는 메모리가 없습니다!");
		}

		if (pStart == NULL)
			pStart = pNode;

		PrintLinkedList(pStart);
	}

	DeleteLinkedList(pStart); //모든노드삭제 - 이 함수를 호출하지않을시 메모리가 누수됨.
}

