#include "stdafx.h"
#include "Parts_11.h"

void Parts_11()
{
	// FunctionPointer();
	FunctionPointerExample();
}

void FunctionPointer()
{
	// 함수는 코드의 위치가 저장이 된다.
	// 함수의 주소를 저장하는 것이다.
	/*
	반환형 (*함수포인터이름)(매개변수)
	*/

	int num1 = 0, num2 = 0;

	printf("정수 2개 입력 : ");
	scanf("%d %d", &num1, &num2);

	float (*fltFuncPtr)(int, int) = &GetAvr;
	printf("\n평균 : %f\n\n", fltFuncPtr(num1, num2));

	void (*funcPtr)() = &FuncA;
	funcPtr();

	funcPtr = &FuncB;
	funcPtr();

	int funcType = -1;

	printf("\n함수 타입 0 또는 1 입력 : ");
	scanf("%d", &funcType);

	funcPtr = FuncC(funcType);
	funcPtr();

	
}

float GetAvr(int a, int b)
{
	return (a + b) / 2.0f;
}

void FuncA()
{
	printf("FuncA 호출!\n");
}

void FuncB()
{
	printf("FuncB 호출!\n");
}

//void(*FuncC(int funcType))()
//{
//	printf("FuncC => ");
//	return funcType <= 0 ? &FuncA : &FuncB;
//}

FuncPtr_void_void FuncC(int funcType)
{
	printf("FuncC => ");
	return funcType <= 0 ? &FuncA : &FuncB;
}

void FunctionPointerExample()
{
	srand((unsigned)time(NULL));

	int arr[10] = { 0 };
	const int len = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < len; ++i)
		arr[i] = rand() % 100 + 1;

	printf("===== 정렬 전=====\n");
	for (int i = 0; i < len; ++i)
		printf("%d, ", arr[i]);

	SortArray(arr, len, &CompareByAscending);
	printf("\n\n===== 오름차순 정렬 후 =====\n");
	for (int i = 0; i < len; ++i)
		printf("%d, ", arr[i]);

	SortArray(arr, len, &CompareByDescending);
	printf("\n\n===== 내림차순 정렬 후 =====\n");
	for (int i = 0; i < len; ++i)
		printf("%d, ", arr[i]);

	printf("\n");
}

void SortArray(int* arr, int len, bool(*compareFunc)(int, int))
{
	for (int i = 0; i < len - 1; ++i)
	{
		int compareIndex = i;

		for (int j = i + 1; j < len; ++j)
		{
			if (compareFunc(arr[compareIndex], arr[j]) == true)
				compareIndex = j;
		}

		if (compareIndex != i)
		{
			int temp = arr[i];
			arr[i] = arr[compareIndex];
			arr[compareIndex] = temp;
		}
	}
}

bool CompareByAscending(int a, int b)
{
	return a > b;
}

bool CompareByDescending(int a, int b)
{
	return a < b;
}


