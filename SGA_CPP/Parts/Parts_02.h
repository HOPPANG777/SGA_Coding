#pragma once

extern "C" //C의 번역규칙을 따르게 할 수 있음.
{
	//float GetAvr(int a, int b) { return (a + b) / 2.0f; }
	//float GetAvr(int a, int b, int c) { return (a + b + c) / 3.0f; }
}

class Parts_02
{
public:
	Parts_02();

private:
	void Overloading();
	void Reference();
	void RandomEngine();

private:
	int GetSumValue(int a, int b);
	int GetSumValue(int a, int b, int c);
	float GetAvr(int a, int b) { return (a + b) / 2.0f; }
	//int GetAvr(int a, int b) { return (a + b) / 2; } //반환형이 아닌 매개변수를 달리해야함.
	float GetAvr(int a, int b, int c) { return (a + b + c) / 3.0f; }

private:
	void SwapByRef(int& ref1, int& ref2);
};

/*
inline

'컴파일러한테 인라이닝해' 라고 명령을 내림

함수 호출시 필연적으로 함수 오버헤드는 발생함.

인라이닝의 역할은. 코드 실행 전,
함수를 호출하는 모든 부분을 함수가 구현된 함수의 코드를 붙여넣기 해넣은것.
단, 현재의 컴파일러의 경우 굉장히 똑똑해 졌기 때문에,
인라인을 붙이지 않아도 컴파일러 스스로 인라인이 필요하거나 적합하다면 자동으로
인라인 기능을 사용하기 때문에 우리가 스스로 컴파일러에게 인라이닝 하라고 명령을 내리는 것은
굉장히 퇴색된 방법이다.

그렇기 때문에 우리가 인라인을 사용하는 핵심적인 의미는
두 번째로
여러 번역 단위에서 중복 정의 되었어도 다 똑같은 애로 치부하여금 쓸 수 있게끔 아무나 가져다 쓸 수 있게 해준는 키워드.
*/

inline void GetSumAndAvr(int* arr, int len, int& outSum, float& outAvr)
{
	for (int i = 0; i < len; i++)
		outSum += arr[i];
	outAvr = outSum / (float)len;
}