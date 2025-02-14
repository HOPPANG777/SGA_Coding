#include "stdafx.h"
#include "Parts_01.h"

Parts_01::Parts_01()
{
	IOStream();
	//OutputStream();
	//InputStream();
}

void Parts_01::IOStream()
{
	/*
	std는 네임스페이스이며, 하나의 지역 이름인 셈이다.
	::란 범위 확인 연산자.

	<<와 >> 비트쉬프트로 사용되지만, cout 뒤에 붙으면, 오버로딩되어 다르게 사용됨.
	// << put-to 스트림 삽입 연산자
	// >> get-from 스트림 추출 연산자
	*/
	std::cout << "Hello, World!\n\n";

	std::cout << "Int : " << num << ", Float : " << fltNum << '\n';

	std::cout << "\n데이터 입력 (정수) : ";
	std::cin >> num;

	std::cout << '\n' << num << " * " << num << " = " << num * num;
}

void Parts_01::OutputStream()
{
	cout.width(18); //출력칸 설정 (출력칸은 1byte씩)
	cout.fill('='); //빈 공간을 뭘로 채울지 설정
	cout << " 자릿수 ";
	cout.width(11);
	cout << '\n';

	//정수부를 포함한 소수부가 나오는 범위 설정. (기본값 : 6)
	//단 정수부가 5자리를 넘어간다면 정수부는 영향을 끼치지 않음.
	cout.precision(5); //5로 변경

	std::cout << "Int : " << num << ", Float : " << fltNum << '\n';

	//precision에 의해 표함되지 않는 수는 반올림된다.
	cout << "RoundOff1 : " << 1.23454 << '\n';
	cout << "RoundOff2 : " << 1.23455 << '\n';

	cout.precision(10); //10으로 변경
	cout << "\nBasic : " << 3.141592 << '\n';
	//ShowPoint는 precision로 설정한 소수점의 범위가 남을 경우,
	//그 자리를 0으로 채워준다.
	cout << "ShowPoint : " << showpoint << 3.141592 << '\n';
	//fixed는 정수부를 포함하지 않고 소수부을 출력.
	cout << noshowpoint << "Fixed : " << fixed << 3.141592 << '\n'; //noshowpoint를 이용하여 showpoint해제 가능.
	cout << defaultfloat << "DefaultFloat : " << 3.141592 << '\n'; //defaultfloat를 이용하여 모두 해제 가능.
	//cout.unsetf(ios::showpoint); //이런식으로도 ShowPoint를 해제 가능.
	//cout.unset(ios::fixed); //이런식으로도 fixed를 해제 가능.
}

void Parts_01::InputStream()
{
	cout << "정수 입력 : ";
	cin >> num;
	cout << "결과 : " << num << '\n';

	cout << "\n실수 입력 : ";
	cin >> fltNum;
	cout << "결과 : " << fltNum << '\n';
	cin.get(); //실수 입력에서 생기는 개행의 문자를 버퍼에서 비워줌.

	char string[100] = "";
	cout << "\n문자열 입력 : ";
	//cin >> string;
	cin.getline(string, sizeof(string)); //띄어쓰기를 포함한 문자를 입력하기 위해 사용.
	cout << "결과 : " << string << '\n';
}

