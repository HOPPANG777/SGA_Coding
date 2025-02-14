#include "stdafx.h"
#include "Parts/Parts_List.h"

struct TestData
{
	int num;
};

int main()
{
	//Parts_01 Parts_01;
	Parts_02 Parts_02;
	//Parts_03 Parts_03; //Parts_03 클래스를 통해서 p03 객체를 만든다.
					//Parts_03 클래스의 생성자가 호출이 된다.
	//Parts_04 Parts_04;
	//Parts_05 Parts_05;
	//Parts_06 Parts_06;
	//Parts_07 Parts_07;
	//Parts_08 Parts_08;
	//Parts_09 Parts_09;

	//형변환
	/*
	//C와 C++의 형변환 차이점 
	C의 경우 ()만을 이용하며, 형변환이 필요한 모든 상황이 다 ()로 대체된다.
	C++은 각 상황에 맞는 형변환이 존재하며, 형변환의 이름을 통해
	코드를 좀 더 가독성 있게 사용이 가능하다. (검색에서 사용하기 좋음)

	C
	(자료형)

	C++
	static_cast<자료형>(변수)		-> 일반적인 형변환, 컴파일 타임에 체크
	dynamic_cast<자료형>(변수)		-> 다운캐스팅, 런타임에 체크, 안전한 다운캐스팅
	const_cast<자료형>(상수화된객체)	-> 상수화된 객체의 상수성을 일시적으로 제거
	reinterpret_cast<자료형>(변수)	-> 저우 -> 주소갑스 포인터 -> 다른 형태 포인터, 첫 번째 멤버의 주소에 대한 포인터
	*/

	//static_cast
	/*
	short num = 10;
	
	//short형의 num을 int형의 포인터가 가지지 못하도록 컴파일 타임에 알려줌.
	int* ptr = (int*)(&num); //그냥 되어버림
	int* ptr = static_cast<int*>(&num); //막아줌
	
	int intNum = 10;
	ptr = &intNum;
	
	//int의 공간을 마치 float처럼 저장하고 읽어들이는 예시
	float* fltPtr = (float*)intNum;
	float* fltPtr = static_cast<float*>(intNum); //막아줌
	*fltPtr = 10.1f;
	
	cout << *fltPtr << endl;
	*/

	//const_cast
	/*
	//const case에서 <>부분에는 포인터나 참조(레퍼런스)만 들어갈 수 있다.
	//만약 변수를 const를 붙여 상수화 시킨다면 컴파일러 입장에선 변할 일이 없다고 생각하여
	//상수변수가 쓰인 곳을 그 값으로 모두 번역을 해버린다.
	//그렇기 때문에 상수성을 떼어내어 아무리 값을 넣어도 효과를 볼 수 없다.
	//그런 컴파일러의 최적화를 막는 키워드가 volatile이다.

	const_cast는 volatile를 붙이지 않아도 최적화를 막아버린다.
	const volatile int num = 10;
	const volatile int* ptr = &num;
	//이렇게 작성한다면 이 포인터 한정 언제든지 상수를 때고 접근 가능
	int* ptr = const_cast<int*>(&num);
	*const_cast<int*>(ptr) = 20;

	cout << "num : " << num << ", *ptr : " << *ptr << endl;
	*/

	//reinterpret_cast
	/*
	//특정 자료형 포인터가 다른 자료형 포인터를 받으려 할 때
	//C++에선 그걸 막아버려 하지 못하는 상황에서
	//reinterpret_cast를 사용한다면 해버릴 수 있음.
	unsigned long long address = 12345678;
	int* ptr1 = reinterpret_cast<int*>(address);

	cout << ptr1 << endl;

	int num = 128;
	int* ptr2 = &num;
	char* cp;
	//c에선 가능, static으론 불가능
	//cp = (char*)ptr2;
	cp = reinterpret_cast<char*>(ptr2);
	printf("\n%c, %d", *cp, *cp);

	TestData data = { 20 };
	//아래 상황에서도 c스타일 형변환은 문제 없지만
	int* ptr = (int*)&data;
	//C++에선 reinterpret_cast을 사용해서 가능하다.
	int* ptr = reinterpret_cast<int*>(&data);
	*ptr = 30;

	cout << *ptr << endl;
	*/

	std::cout << '\n';
	return 0;
}