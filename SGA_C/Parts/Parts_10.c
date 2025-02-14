#include "stdafx.h"
#include "Parts_10.h"

void Parts_10()
{
	// Pointer();
	// InitializeArray();
	PointerToPointer();
}

void Pointer()
{
	int intNum = 0;
	float fltNum = 0.0f;
	double dblNum = 0.0;

	/*
	포인터 선언 방법
	자료형 (*)포인터연산자 포인터이름
	
	포인터 : 주소값을 저장하는 변수	// 어떤 주소값인지는 알수 없다.
	
	포인터(주소값)의 크기 
	x86(32bit) - 4바이트
	x64(64bit) - 8바이트
	
	int intNum;

	int* intPtr = &intNum;	// intPtr이 intNum의 주소값을 가지게 된다.

	*/

	// 사용하고자 하는 자료형에 *를 넣으면 된다.
	int* intPtr = &intNum;
	// 어떤 주소값을 저장하는 변수 주소값을 저장하고 싶다면 엠퍼센트를 붙히면 된다.
	// scanf쓸때 붙히는 & 이게 주소 연산자다.
	float* fltPtr = &fltNum;
	double* dblPtr = &dblNum;

	printf("\n===== 포인터 크기 =====\n");
	printf("int* : %zd\n", sizeof(intPtr));
	printf("float* : %zd\n", sizeof(fltPtr));
	printf("doubl* : %zd\n", sizeof(dblPtr));
	// 실행하면 8바이트가 나오는데 포인터는 4바이트 아닌가? 생각할수있다.
	// 포인터는 32비트 운영체제일 경우엔 4바이트가 나온다.
	// 64비트 운영체제에서는 8바이트가 나온다.
	/*
	x86(32bit 운영체제) -> 4GB

	0xFFFFFFFF
	요거에 의미를 보면 굉장히 간단히 이해되는 문제이다.
	이게 HAX값인데 
	저 F를 10진수로 바꿔보면 
	unsigned int 최대값이 나온다.
	4바이트 -> 32
	2^32
	32비트 운영체제는 기본적으로 가상 램의 공간을 저 F 8개 밖에 없을 것이다 라는 전제를 깔고간다,
	그래서 암튼 이걸 1024로 계속 나누면 결국 4기가가 나온다 그래서 32비트 운영체제는 4기가로 한정되게 되는것이다.
	메모리 주소값을 0xFFFFFFFF밖에 안들어가게 되는것이다.

	왜 이렇게 만들었냐? 
	당연하게도 예전에는 이걸 다쓸줄 몰랐던거지 "야... 이걸 어케 다쓰냐 ㅇㅈ?" 컴터 과학자들은 ㅇㅈㄹ하고 있었던거지
	근데 막 8기가 메모리도 나오고 하드웨어 발전 속도 보더니 어? 부족하네 하게 된거지

	2^64
	이말은 자릿수가 2배로 늘어난단 소리다

	그래서 포인터가 64비트 운영체제에서는 크기가 8바이트가 되는것이다.

	
	*/

	// 만약 최적화를 많이 하고싶다 하면
	// x86을 선택하는걸 고려할수있다.
	// 32비트 프로그램이라고 64비트 운영체제에서 안돌아간다는 소리는 아니다.
	// 포인터는 메모리 공간에서 주소를 저장하는 변수이다.
	// 
	// 포인터를 활용해서 주소값을 넘기는것에 대해 이점이 많다.
	
	/*
	intNum = 10; X
	intPtr = &intNum
	*intPtr = 10;	// intNum을 간접참조하라
	위의 직접 대입하는 대신 간접참조연산자를 사용하여 간접적으로 사용한다. 
	포인터 앞에 *표시 붙이면 간접참조연산자다 
	*/
	// 간접참조연산자
	*intPtr = 10;
	// intNum = 10; 이라는 뜻이다.
	*fltPtr = 3.14f;
	// 변수 선언할때 붙이는 별하고 
	// 이미 선언된 포인터에 붙이는 별은 완전 다른 의미다.
	// 그래서 간접참조연산자는 어디에 쓰이는 것이냐 
	// 포인터에 간접참조를 한다는 것은 주소를 통해서 값을 간접적으로 참조하라
	// 변수를 직접 참조하지 않고도 우리가 이 변수를 바꿀수있다.
	// %p는 주소값을 볼수있다.
	printf("\n===== 포인터 간접 참조 결과 =====\n");
	printf("Int : %d, %p, Int* : %p %d\n", intNum, &intNum, intPtr, *intPtr);
	printf("Float : %f, %p, Float* : %p %f\n", fltNum, &fltNum, fltPtr, *fltPtr);
	
	void* ptr = &intNum;
	
	*((int*)ptr) = 20;

	printf("\n===== 포인터 간접 참조 결과 =====\n");
	printf("Int : %d, %p, Void* : %p %d\n", intNum, &intNum, ptr, *((int*)ptr));
	
	/*
	함수 호출 -> Call By Value
	player->level += 1; // 간접참조를 해서 가져와라
	*/

	int num1 = 0;
	int num2 = 0;

	printf("\n정수 2개 입력 : ");
	scanf("%d %d", &num1, &num2);

	printf("\n===== 값 교환 전 =====\n");
	printf("지역 변수 num1(%p) : %d, 지역 변수 num2(%p) : %d\n", &num1, num1, &num2, num2);

	printf("\n===== 값 교환 중 =====\n");
	SwapByPtr(&num1, &num2);
	
	printf("\n===== 값 교환 후 =====\n");
	printf("지역 변수 num1(%p) : %d, 지역 변수 num2(%p) : %d\n", &num1, num1, &num2, num2);

	// 이건 인트와 가깝기 때문에 포인터를 통한 값의 조작이 상수화가 되는것이다 간접참조화를 통한 변경이 불가능해진다.
	const int* constPtr1 = &num1;

	// 포인터와 더 가깝기 때문에 값의 주소값의 변경을 할수가 없다.
	int* const constPtr2 = &num2;

	// 이건 두 개 다 붙였기 때문에 변경을 아예 할수 없도록 막아둔것
	const int* const constPtr3 = &num1;

	// *constPtr1 = 10; 불가능
	constPtr1 = &num2;

	*constPtr2 = 20;
	// constPtr2 = &num1; // 불가능

	// 둘 다 불가능
	// *constPtr3 = 10;
	// constPtr3 = &num1;



}

void SwapByValue(int a, int b)
{
	printf("매개 변수 a(%p) : %d, 매개 변수 b(%p) : %d\n", &a, a, &b, b);

	//	a ^= b ^= a ^= b;
	int temp = a;
	a = b;
	b = temp;

	printf("매개 변수 a(%p) : %d, 매개 변수 b(%p) : %d\n", &a, a, &b, b);
}

void SwapByPtr(int* a, int* b)
{
	printf("매개 변수 a(&p) : %d, 매개 변수 b(%p) : %d\n", a, *a, b, *b);

	//	a ^= b ^= a ^= b;
	int temp = *a;
	*a = *b;
	*b = temp;

	printf("매개 변수 a(%p) : %d, 매개 변수 b(%p) : %d\n", a, *a, b, *b);
}

void InitializeArray()
{
	int arr1[5] = { 1,2,3,4,5 };
	int arr2[5] = { 1,2,3,4,5 };

	const int len1 = sizeof(arr1) / sizeof(arr1[0]);
	const int len2 = sizeof(arr2) / sizeof(arr2[0]);

	printf("===== 배열 1 원소 (%lld) =====\n", sizeof(arr1));
	for (int i = 0; i < len1; ++i)
		printf("%d, ", *(arr1 + i));

	int* const ptr1 = arr2;
	printf("\n\n===== 배열 2 원소 (%lld) =====\n", sizeof(ptr1));
	for (int i = 0; i < len2; ++i)
		printf("%d, ", ptr1[i]);
	/*
	포인터 연산

	*(ptr1 + 1)
	포인터 연산이 어떻게 작동을 하는가
	arr2의 시작점의 주소를 ptr1에 넣고
	+1을 하면
	포인터는 보이드 포인터 말고 다른 포인터들은 자료형의 크기를 알고 있다.
	보이드 포인터는 당연히 포인터 연산 안된다

	인트 값만큼 건너뛰어라 건너뛰어서 그 주소값이 되는것이다.
	ptr1 + 1 - 1은 다시 0x00으로 돌아온다 만약 +2를 하면 여기서 2만큼 건너뛰어라 하면
	0x08로 간다

	간접참조를 했다 그 주소값에 들어있는 인트 값을 간접참조가 된다 처음에 0번지에 있는 값 처음에 1이
	나온거고 i가 1일때 2가 나온거다

	ptr[i]
	대신에 인덱스 연산을 해도 된다.
	포인터 연산을 해서 인덱스 안에 들어있는 값만큼 포인터 더하기 연산을 해서
	그 값만큼 간접참조를 한거다

	우리가 여태까지 써오던 인덱스 연산은 포인터 연산으로 간접참조를 한것이다
	배열 이름으로도 포인터 연산이 가능하다.

	둘이 차이가 없어 보이지만
	사이즈 오브 배열이름 하면 1번째는 20나오는 배열의 크기
	포인터는 배열의 이름을 아무리 담아도 8바이트 포인터 크기가 나온다.

	이게 왜 중요하냐


	*/

	int arr3[5] = { 0 };

	const int len3 = sizeof(arr3) / sizeof(arr3[0]);

	InitArrayByPtr(arr3, len3);

	printf("\n\n===== 배열 3 원소 (%lld) =====\n", sizeof(arr3));
	for (int i = 0; i < len3; ++i)
		printf("%d, ", arr3[i]);

	printf("\n");
}

// void InitArray(int a[])
//{
//	const int len = sizeof(a) / sizeof(a[0]);
//	/*
//	배열을 전한게 아니라 시작점의 주소를 나타내는 포인터를 넣은거다
//	그러면 어째서 첫번째랑 2번째만 되느냐
//	포인터는 8바이트 2개로 나누면 4바이트 2개만 들어간거다.
//	포인터는 사이즈오브로 배열을 제대로 체크할수 없다.
//	*/
//	for (int i = 0; i < len; ++i)
//		a[i] = i + 1;	
//}

void InitArrayByPtr(int* arr, int len)
{
	for (int i = 0; i < len; ++i)
		arr[i] = i + 1;
}

void PointerToPointer()
{
	/*
	이중 포인터 
	영어로 PointerToPointer

	이중 포인터는 뭐하는거냐
	어떤 변수의 주소값을 저장한 포인터의 주소값을 저장한 포인터
	프레임워크 설계단에서 자주 쓰인다.
	고오급 프로그래머가 되고 싶다면 이중 포인터를 쓰는 방법을 알아두어야한다.
	프로그래머의 프로그래머
	엔진 프로그래머라든지, 

	DX배워보면 많다 MS에서 만든 윈도우 그래픽 제작 API
	*/

	int num1 = 0;
	int num2 = 0;

	int* ptr = &num1;
	int** ptrToPtr = &ptr;

	**ptrToPtr = 10;

	*ptrToPtr = &num2;		// 간접참조2번
	**ptrToPtr = 20;	

	printf("===== 이중 포인터 간접 참조 결과 =====\n");
	printf("num1 : %d, %p\n", num1, &num1);
	printf("num2 : %d, %p\n", num2, &num2);
	printf("int* : %p, %p int** : %p, %p\n", ptr, &ptr, ptrToPtr, &ptrToPtr);
	// 함수를 통해서 전달되는 포인터의 주소값을 변경하고 싶을때

	int* ptr1 = &num1;
	int* ptr2 = &num2;

	printf("\n===== 포인터 교환 전 =====\n");
	printf("%p : %d, %p : %d\n", ptr1, *ptr1, ptr2, *ptr2);
	
	// SwapByP(ptr1, ptr2);
	SwapByPP(&ptr1, &ptr2);

	printf("\n===== 포인터 교환 후 =====\n");
	printf("%p : %d, %p : %d\n", ptr1, *ptr1, ptr2, *ptr2);

}

void SwapByP(int* ptr1, int* ptr2)
{
	int* temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}

void SwapByPP(int** pp1, int** pp2)
{
	int* temp = *pp1;
	*pp1 = *pp2;
	*pp2 = temp;
}





