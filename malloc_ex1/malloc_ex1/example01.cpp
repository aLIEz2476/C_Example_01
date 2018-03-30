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
	
	GameObject sB = sGameObject; // sGameObject�� �����Ͱ� sB�� �Ѿ�� �Ǵ� memcpy �߻�

	free(pGameObject);
	// strcpy�� �����Ҵ��� ���ױ� ������ -> ȭ��ǥ �ݵ�� �ʿ�

}

void DynamicMain()
{
	int nSize = 0;
	scanf("%d", &nSize);
	int* pDynamic = new int[nSize]; //(int*)malloc(nSize * sizeof(int)) �� ��� ����
	

	for (int i = 0; i < 100; i++)
	{
		*(pDynamic + i) = i + 1;
		printf("%d\n", *(pDynamic + i));
	} // ���� �ο��� �����Ϳ� ������ �Է�
	printf("\n");
	delete[] pDynamic; // pDynamic�� �迭�� �������� ���, delete ���� �迭���� �˸��� ���� []�� ����
	pDynamic = new int();
	delete pDynamic; // pDyanmic�� ���Ϸ� �����ߴٸ�, delete �� ���� ��
	//free(pDynamic);  �ο��� ������ ��ȯ
}

int main()
{
	StructMain();
}

// ������� : �ڵ��ۼ� -> �����Ϸ�(���� �˻�) -> �������� ����
// �����Ҵ� : �Ϲ������� ������ �����ؼ� ����ϴ� ��. -> �ڵ� �ۼ��ÿ� ��� -> �����Ͻ� �޸� ���� ���� �� �̸� ����
// �����Ҵ� : ��Ÿ�� �߿� �޸𸮸� ����� ����ϴ� ��. -> ���α׷� ���� �߿� ��� -> ���� ���� �������� ���࿡ �ش�

