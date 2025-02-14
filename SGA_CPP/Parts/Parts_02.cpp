#include "stdafx.h"
#include "Parts_02.h"

	//다형성이란 한 가지의 대상이 될 수 있는 여러가지 경우리며,
	//함수오버로딩은 정적다형성이다.
	//즉, 같은 이름의 함수가 서로 다른 역할을 할 수 있다는 것이다.
	//그 이유는 컴파일 단계(정적)에서 결정나는 같은 이름의 함수의
	//매개변수의 타입과 개수에 따라 같은 함수지만 다른 함수로 받아들일 수 있다. (네임맹글링)
	//그 이뉴는 컴파일 단계(정적)에서 결정나는 같은 이름의 함수의
	// 매개변수의 타입과 개수에 따라 같은 함수지만 다른 함수로 받아들일 수 있다.

Parts_02::Parts_02()
{
	Overloading();
	Reference();
	//RandomEngine();
}

void Parts_02::Overloading()
{
	int a = 10, b = 20, c = 30;

	cout << "===== 함수 오버로딩 결과 =====\n";
	cout << "숫자 2개 합계 : " << GetSumValue(a, b) << '\n';
	cout << "숫자 3개 합계 : " << GetSumValue(a, b, c) << '\n';
	cout << "숫자 2개 평균 : " << GetAvr(a, b) << '\n';
	cout << "숫자 3개 평균 : " << GetAvr(a, b, c) << '\n';

}

void Parts_02::Reference()
{
	//포인터의 경우 val라는 공간의 주소를 저장.
	//레퍼런스의 경우 val라는 공간의 별명으로 val과 ref 둘 다 접근 가능.
	//레퍼런스의 경우 단순한 값의 전달에서 좋음
	//주의사항 : 
	int val = 0;
	//int* ptr = &val; //주소연산자 &
	int& ref = val;  //레퍼런스 &
	//int& ref2 = NULL; //레퍼런스는 NULL로 초기화 불가능
	ref = 10;

	cout << "===== 레퍼런스 결과 =====\n";
	cout << "Value : " << val << ", " << &val << '\n';
	cout << "Ref Value : " << ref << ", " << &ref << "\n\n";

	int a = 10;
	int b = 20;
	cout << "===== 값 교환 전 =====\n";
	cout << a << ", " << b << "\n\n";
	
	SwapByRef(a, b);

	cout << "===== 값 교환 후 =====\n";
	cout << a << ", " << b << "\n\n";

}

void Parts_02::RandomEngine()
{
	random_device random;

	//rand에 비해 크기가 크며,
	//(알고리즘을 사용했음에도)수를 뽑는 속도가 굉장히 빠름.
	mt19937 generator(random());
	uniform_int_distribution<int> intDist(0, 99);
	uniform_real_distribution<float> realDist(0.0f, 10.0f);

	int arr[10] = { 0 };
	float fltArr[10] = { 0.0f };
	
	const int len = sizeof(arr) / sizeof(arr[0]);
	const int len2 = sizeof(fltArr) / sizeof(fltArr[0]);

	for (int i = 0; i < len; i++)
		arr[i] = intDist(generator);
	
	for (int i = 0; i < len2; i++)
		fltArr[i] = realDist(generator);

	cout << "===== 정수형 배열 원소 (균등) =====\n";
	for (int i = 0; i < len; i++)
		cout << arr[i] << ", ";
	cout << "\n\n===== 실수형 배열 원소 (균등) =====\n";
	for (int i = 0; i < len2; i++)
		cout << fltArr[i] << ", ";

	int sum = 0;
	float avr = 0.0f;

	//ODR
	GetSumAndAvr(arr, len, sum, avr);

	cout << "\n\n합계 : " << sum;
	cout << "\n평균 : " << avr << '\n';
	
	int uniformGraph[100] = { 0 };
	const int uniformLen = sizeof(uniformGraph) / sizeof(uniformGraph[0]);

	cout << "\n===== 균등 분포 그래프 =====\n";
	for (int i = 0; i < 1500; i++)
	{
		int index = intDist(generator);
		++uniformGraph[index];
	}

	for (int i = 0; i < uniformLen; i++)
	{
		cout << i << '\t';
		for (int j = 0; j < uniformGraph[i]; j++)
			cout << '*';
		cout << '\n';
	}

	normal_distribution<double> normalDist(50.0, 7.0);

	for (int i = 0; i < len; i++)
		arr[i] = normalDist(generator);

	cout << "\n===== 정수형 배열 원소 (정규) =====\n";
	for (int i = 0; i < len; i++)
		cout << arr[i] << ", ";

	int normalGraph[100] = { 0 };
	const int normalLen = sizeof(normalGraph) / sizeof(normalGraph[0]);

	cout << "\n===== 정규 분포 그래프 =====\n";
	for (int i = 0; i < 1500; i++)
	{
		int index = (int)normalDist(generator);
		++normalGraph[index];
	}

	for (int i = 0; i < normalLen; i++)
	{
		cout << i << '\t';
		for (int j = 0; j < normalGraph[i]; j++)
			cout << '*';
		cout << '\n';
	}

	bernoulli_distribution bernoulliDist(0.000002);

	int count = 0;

	cout << "\n===== 당첨 여부 (베르누이) =====\n";
	for (int i = 0; i < 100; i++)
	{
		if (bernoulliDist(generator))
		{
			++count;
			cout << "당첨 되셨습니다!\n";
		}
		else
			cout << "꽝!\n";
	}

	cout << "\n당첨 횟수 : " << count;
}

int Parts_02::GetSumValue(int a, int b)
{
	return a + b;
}

int Parts_02::GetSumValue(int a, int b, int c)
{
	return a + b + c;
}

void Parts_02::SwapByRef(int& ref1, int& ref2) //레퍼런스는 추가하는 위치가 중요
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}