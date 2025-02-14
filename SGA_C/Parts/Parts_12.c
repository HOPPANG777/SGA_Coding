#include "stdafx.h"
#include "Parts_12.h"

void Parts_12()
{
	// MemoryAllocation();

	// TwoDimensionalArrayMemoryAllocation();

	// ClearAllocation();

	ReAllocation();
}

void MemoryAllocation()
{
	/*
		동적할당

		정적이냐 동적이냐를 이야기할때
		동적이란건 런타임이란걸 의미를 한다 즉
		프로그램이 실행중일때를 의미한다.

		정적은 무엇이냐
		컴파일 타임이란걸로 기준을 잡는다
		컴파일러가 번역하는 시간대

		컴파일할때 결정되는 것을 정적
		런타임일때 결정할수 있는것을 동적

		동적할당이란
		프로그램 실행 중에 사용자가 필요한 만큼 메모리를 할당하거나
		해제할 수 있는 기능

		메모리 누수(Memory Leak)
		새로운 메모리를 잡고 사용후 다시 운영체제에게 돌려줘야하는데 이걸 안하면 일어나는것이다

		게임 같은 실시간 프로그램은 특히 더 메모리 누수를 주의해야한다.
		ㅈ같은 베데스다 새끼들 이새끼들은 20년째 만드는 게임마다 똑같이 메모리누수가 한결같이 일어나 시발련들
		5분만 지나기 시작하면 메모리 누수가 시작되요!! 이걸 회사가 안고치고 유저가 고쳐요!! 시발 병신

		x86이냐 x64냐에 따라서 해당 운영체제가 사용할수있는 메모리의 최대치를 땡겨놓고 생각한다가
		가상메모리다 우리가 하는 이야기들은 모두 가상 메모리에서 일어난다.

		비주얼스튜디오는 기본 최소 스택을 1MB로 잡아논다

		동적할당을 한다


	*/

	/*
	괄호 안의 크기 만큼 동적할당 malloc(동적할당할크기) -> MemoryAllocation
	calloc -> ClearAllocation
	realloc -> ReAllocation

	*/

	int* intPtr = (int*)malloc(sizeof(int));
	assert(intPtr != NULL);	// 어썰트가 작동하는 조건은 거짓일때 어썰션을 불러와서 작동한다.	//
	float* fltPtr = (float*)malloc(sizeof(float));
	assert(fltPtr != NULL);

	*intPtr = 10;
	*fltPtr = 3.14;

	printf("===== 동적 할당 결과 =====\n");
	printf("int*(%p) : %d\n", intPtr, *intPtr);
	printf("float*(%p) : %f\n", fltPtr, *fltPtr);

	SAFE_FREE(fltPtr);	
	SAFE_FREE(intPtr);

	if (intPtr != NULL)
		*intPtr = 10;

	//printf("\n===== 해제 결과 =====\n");
	//printf("int*(%p) : %d\n", intPtr, *intPtr);
	//printf("float*(%p) : %f\n", fltPtr, *fltPtr);

	int len = 0;

	printf("\n초기 배열 크기 입력 : ");
	scanf("%d", &len);
	
	int* arr = (int*)malloc(sizeof(int) * len);
	assert(arr != NULL);

	// 서수
	int ordinal = 0;
	int input = 0;

	printf("\n");

	while (true)
	{
		printf("%d번째 정수 입력 : ", ordinal + 1);
		scanf("%d", &input);

		if (input == 0)
			break;

		if (ordinal >= len)
		{
			len *= 2;
			int* newArr = (int*)malloc(sizeof(int) * len);
			assert(newArr != NULL);

			for (int i = 0; i < ordinal; ++i)
				newArr[i] = arr[i];
			
			SAFE_FREE(arr);
			arr = newArr;
			printf("배열 재할당 완료! 현재 배열 주소 : %p\n", arr);
		}

		arr[ordinal++] = input;

	}
	
	printf("\n===== 동적 할당 배열 원소 =====\n");
	for (int i = 0; i < ordinal; ++i)
		printf("%d, ", arr[i]);
	
	printf("\n");

	SAFE_FREE(arr);
}

void TwoDimensionalArrayMemoryAllocation()
{
	int row = 0;
	int col = 0;

	printf("행렬 크기 입력 : ");
	scanf("%d %d", &row, &col);

	// 2차원 배열 matrix를 동적 할당
	int** matrix = (int**)malloc(sizeof(int*) * row);
	assert(matrix != NULL);
	//for (int i = 0; i < row; ++i)
	//{ 
	//	matrix[i] = (int*)malloc(sizeof(int) * col);
	//	assert(matrix[i] != NULL);
	//}

	matrix[0] = (int*)malloc(sizeof(int) * row * col);
	assert(matrix[0] != NULL);
	for (int i = 1; i < row; ++i)
		matrix[i] = matrix[i - 1] + col;

	int num = 0;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			matrix[i][j] = ++num;

	printf("===== 행렬 원소 =====\n");
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			printf("%03d, ", matrix[i][j]);

		printf("\n");
	}

	//for (int i = 0; i < row; ++i)
	//	SAFE_FREE(matrix[i]);
	SAFE_FREE(matrix[0]);

	SAFE_FREE(matrix);
}

void ClearAllocation()
{
	int len = 0;

	printf("배열 크기 입력 : ");
	scanf("%d", &len);
	
	int* arr1 = (int*)malloc(sizeof(int) * len);
	int* arr2 = (int*)calloc(len, sizeof(int));
	int* arr3 = (int*)ClearAlloc(len, sizeof(int));

	printf("\n===== 배열 1 원소 =====\n");
	for (int i = 0; i < len; ++i)
		printf("%d, ", arr1[i]);

	printf("\n===== 배열 2 원소 =====\n");
	for (int i = 0; i < len; ++i)
		printf("%d, ", arr2[i]);

	printf("\n===== 배열 3 원소 =====\n");
	for (int i = 0; i < len; ++i)
		printf("%d, ", arr3[i]);

	printf("\n");

	SAFE_FREE(arr1);
	SAFE_FREE(arr2);
	SAFE_FREE(arr3);
}

void* ClearAlloc(int count, int size)
{
	int totalSize = count * size;
	void* buffer = malloc(totalSize);
	assert(buffer != NULL);

	// for (int i = 0; i < totalSize; ++i)
	//  	*((char*)buffer + i) = 0;

	memset(buffer, 0, totalSize);

	return buffer;
}

void ReAllocation()
{
	int len = 0;

	printf("\n초기 배열 크기 입력 : ");
	scanf("%d", &len);

	int* arr = (int*)malloc(sizeof(int) * len);
	assert(arr != NULL);

	// 서수
	int ordinal = 0;
	int input = 0;

	printf("\n");

	while (true)
	{
		printf("%d번째 정수 입력 : ", ordinal + 1);
		scanf("%d", &input);

		if (input == 0)
			break;

		if (ordinal >= len)
		{
			len *= 2;
			int* temp = (int*)realloc(arr, sizeof(int) * len);
			assert(temp != NULL);
			arr = temp;
			temp = NULL;
			
			printf("배열 재할당 완료! 현재 배열 주소 : %p\n", arr);
		}

		arr[ordinal++] = input;

	}

	printf("\n===== 동적 할당 배열 원소 =====\n");
	for (int i = 0; i < ordinal; ++i)
		printf("%d, ", arr[i]);

	printf("\n");

	SAFE_FREE(arr);
}
