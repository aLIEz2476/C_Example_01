#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct GameObject {
	char name[100];
	char tag[100];
	bool ActiveSelf;
};

void StructMain()
{
	GameObject sGameObject;
	strcpy_s(sGameObject.name, "Cube");
	strcpy_s(sGameObject.tag, "Player");
	sGameObject.ActiveSelf = true;

	GameObject arrGameObject[10];

	for (int i = 0; i < 10; i++)
	{
		sprintf(arrGameObject[i].name, "Cube %d", i);
		strcpy_s(arrGameObject[i].name, "Player");
		arrGameObject[i].ActiveSelf = true;

		printf("GameObject[%d]:%s\n", i, arrGameObject[i].name);

	}

	GameObject* pGameObject = (GameObject*)malloc(sizeof(GameObject));
	strcpy_s(pGameObject->name, "Cube");
	strcpy_s(pGameObject->tag, "Player");
	pGameObject->ActiveSelf = true;
	
	GameObject sB = sGameObject; // sGameObject의 데이터가 sB로 넘어가게 되는 memcpy 발생

	free(pGameObject);
	// strcpy시 동적할당을 시켰기 때문에 -> 화살표 반드시 필요

}

void DynamicMain()
{
	int nSize = 0;
	scanf("%d", &nSize);
	int* pDynamic = new int[nSize]; //(int*)malloc(nSize * sizeof(int)) 과 기능 같음
	

	for (int i = 0; i < 100; i++)
	{
		*(pDynamic + i) = i + 1;
		printf("%d\n", *(pDynamic + i));
	} // 공간 부여된 포인터에 데이터 입력
	printf("\n");
	delete[] pDynamic; // pDynamic을 배열로 선언했을 경우, delete 사용시 배열임을 알리기 위해 []을 붙임
	pDynamic = new int();
	delete pDynamic; // pDyanmic을 단일로 선언했다면, delete 걍 쓰면 됨
	//free(pDynamic);  부여된 공간을 반환
}

int main()
{
	StructMain();
}

// 빌드순서 : 코드작성 -> 컴파일러(문법 검사) -> 실행파일 생성
// 정적할당 : 일반적으로 변수를 선언해서 사용하는 것. -> 코드 작성시에 사용 -> 컴파일시 메모리 변수 생성 및 이름 지정
// 동적할당 : 런타임 중에 메모리를 만들어 사용하는 것. -> 프로그램 실행 중에 사용 -> 빌드 순서 기준으로 실행에 해당

