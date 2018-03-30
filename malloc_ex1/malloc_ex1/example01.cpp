#include<stdio.h>
#include<stdlib.h>
int main()
{
	int nSize = 0;
	scanf("%d", &nSize);
	int* pDynamic = (int*)malloc(nSize * sizeof(int)); // 100칸의 공간 부여
	
	for (int i = 0; i < 100; i++)
	{
		*(pDynamic + i) = i+1;
		printf("%d\n", *(pDynamic + i));
	} // 공간 부여된 포인터에 데이터 입력
	printf("\n");
	free(pDynamic); // 부여된 공간을 반환
}

// 빌드순서 : 코드작성 -> 컴파일러(문법 검사) -> 실행파일 생성
// 정적할당 : 일반적으로 변수를 선언해서 사용하는 것. -> 코드 작성시에 사용 -> 컴파일시 메모리 변수 생성 및 이름 지정
// 동적할당 : 런타임 중에 메모리를 만들어 사용하는 것. -> 프로그램 실행 중에 사용 -> 빌드 순서 기준으로 실행에 해당

