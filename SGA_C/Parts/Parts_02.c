#include "stdafx.h"
#include <limits.h>
#include <float.h>
#include "Parts_02.h"

void Parts_02()
{
	// DataSize();
	DataRange();
}

void DataSize()
{
	// 컴퓨터
	// 데이터를 연산하고, 저장하는 장치
	// CentralProcessUnit(중앙처리장치) -> 사람의 뇌(근데 이제 여러개 7950X3D -> 16명 팔 32
	// 똑똑한 애들 소수정예
	// GraphicsProcessUnit(그래픽처리장치)
	// 채굴 - 문제
	// 단순한 애들 다수(좀 아니 ㅈㄴ많은 -> 수학문제 피라미드 1000만층 한명당 10~100층씩 쌓아서 풀기)
	// 게임
	// 그래픽
	// 1920(가로)x1080(세로)
	// FramePerSecond(프레임 1초에 그림 몇장 띄울꺼냐)
	// 60
	// 120 144 240 360 540
	// 저장장치
	//
	// 보조기억장치
	// HDD, SSD, FDD, CD
	// 주기억장치
	// RAM, ROM(BIOS)
	// Cache Memory(CPU(장로)전용 창고 혹은 금고(Cache Memory)
	//
	// ROM
	// ReadOnlyMemory(BIOS)
	// 
	// RAM  
	// RandomAccessMemory
	// RandomAccess(임의접근)
	// 32bit, 64bit
	// 윈도우
	// 4GB
	// 0x00000000, 0xFFFFFFFF
	// 0x0000000000000000, 0xFFFFFFFFFFFFFFFF
	// 프로그램
	// OS
	// 가상메모리
	// 
	// 배열 -> O(1)
	// 램 기준에서 가장 최소 공간이 1bit
	// 1 Bit -> 0 or 1 (전기 신호가 통하면 0 통하지 않으면 1)
	// 1 Byte -> 8bit -> 0or1 0or1 0or1 0or1 0or1 0or1 0or1 0or1 -> 256 경우의 수
	// int -> 4byte -> 32bit -> 2^32 

	char ch = 'A';	// 65
	// 1byte
	// 문자 or 정수 1개
	// 'A' -> 정수

	short shortNum = 10;
	int integerNum = 20;
	long longNum = 30;
	long long longLongNum = 40;

	float floatingNum = 0.1f;
	double doubleNum = 10.2;

	long double longDoubleNum = 10.3;
	// vc++
	// gcc, g++
	// long double 16byte

	printf("===== 문자형 출력 =====\n");
	printf("Char (%llu) : %c\n\n", sizeof(ch), ch);

	// short <= int <= long 
	// 이게 원래 int가 short였는데 기술의 발달로 기본 int로는 그냥 물리적으로 숫자가 부족해지자,
	// long을 int로 바꾸고 short를 만들어 기본 int를 집어넣었다 그래서 그냥 long은 int와 같다 ㅇㅇ

	printf("===== 정수형 출력 =====\n");
	printf("Short (%llu) : %d\n\n", sizeof(shortNum), shortNum);
	printf("Int (%llu) : %d\n\n", sizeof(integerNum), integerNum);
	printf("Long (%llu) : %ld\n\n", sizeof(longNum), longNum);
	printf("Long Long (%llu) : %lld\n\n", sizeof(longLongNum), longLongNum);

	// 곱셈 9자리
	printf("===== 실수형 출력 =====\n");
	printf("Float (%llu) : %f\n\n", sizeof(floatingNum), floatingNum);
	printf("Double (%llu) : %lf\n\n", sizeof(doubleNum), doubleNum);
	printf("Long Double (%llu) : %lf\n\n", sizeof(longDoubleNum), longDoubleNum);
	/*
	 부동소수점
	 부동(floating 떠다닌다)
	 IEEE (겁나 똑똑이 엔지니어 모임)
	 IEEE754
	 컴퓨터 -> 실수를 어떻게 저장할거냐
	 고정소수점
	 32bit
	 16bit 정수부, 16bit 소수부
	 하지만 이건 정수와 소수 모두 줄여버리는 결과라 다른 방법을 쓴다

	 <limits.h> : 자료형들의 제한 범위를 메크로로 기록해둠
	 SCHAR : Signed Character Minimum

	 최상위비트 : 부호
	 부호(+-)[1] 지수(n)[8] 가수(m)[23] -> float
	 부호(+-)[1] 지수(n)[11] 가수(m)[52] -> double
	 (+-) m * 2^n
	 +- m * 2^n
	 22
	 22 / 2 = 11 ... 0
	 11 / 2 = 5 ... 1
	 5 / 2 = 2 ... 1
	 2 / 2 = 1 ... 0
	 1 / 2 = 0 ... 1
	 10110

	 0.22
	 0.22 * 2 = 0.44 -> 0
	 0.44 * 2 = 0.88 -> 0
	 0.88 * 2 = 1.76 -> 1
	 0.76 * 2 = 1.04 -> 1
	 0.04 * 2 = 0.07 -> 0
	 00110
			
	 0.1
	 0.1 * 2 = 0.2 -> 0
	 0.2 * 2 = 0.4 -> 0
	 0.4 * 2 = 0.8 -> 0
	 0.8 * 2 = 1.6 -> 1
	 0.6 * 2 = 1.2 -> 1
	그냥 이게 계속 반복된다

	+- 0.000110011001100
	1.10011001100110011001100

	IEEE
	Round-up
	0(부호) 10011001100110011001100(가수) * 2^-4(지수)

	지수
	bias
	(8bit)127
	중간값
	2의보수법

	우리가 일반적으로 활용하는 8bit를 활용을 해서 언사인 시켜야하는데 어려워서 bias값을 사용한다.
	1000 0000 -4
	0.1f <- 이걸
	0(부호) 01111011(지수) 10011001100110011001101(가수) <- 컴퓨터는 이러한 방식으로 기억을 한다
	1.10011001100110011001101 * 2^-4
	= 0.00011001100110011001101
	= 0.0625 + 0.03125 + 0.015625 + 0.00390625 + 0.001953125 + 암튼 1이 있는건 반띵 해서 더한다
	0000 0000 <- 여기서 1식 올라가면 2의 배수
	0000 0001 <- 1
	0000 0011 <- 2
	0000 0101 <- 5
	근데
	0000 0001.1 <- 이렇게 소수점 찍고 가면은 2분의 1배 즉 반띵



	가수하고 지수의 크기가 바뀔뿐이다 그냥 자리수를 더 많이 저장하는것
	정밀도는 올라간다 근데 그거 조차도 무한소수이기 때문에 동일한 값을 저장하는게 어렵다

	*/
	// %llu 64bit 부호가 없는 정수
	// long long unsigned
	// unsigned -> 부호가 없는 (음수를 표현하지 않음)
	// unsigned -> signed -> 부호가 있는 (음수를 표현함)
	// sizeof(ch) -> sizeof 연산자 () 안의 데이터(자료) 혹은 자료형의 크기를 나타낸다.
	//  
}

void DataRange()
{
	// 정수 오버플로우
	// signed <-> unsigned
	// 최상위 비트를 부호 비트로 사용하느냐 아니냐
	printf("===== 부호의 범위 출력 =====\n");

	printf("char의 범위 : %d ~ %d\n\n", SCHAR_MIN, SCHAR_MAX);
	printf("unsigned char의 범위 : %u ~ %u\n\n", 0U, UCHAR_MAX);

	printf("short의 범위 : %d ~ %d\n\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short의 범위 : %u ~ %u\n\n", 0U, USHRT_MAX);

	printf("int의 범위 : %d ~ %d\n\n", INT_MIN, INT_MAX);
	printf("unsigned int의 범위 : %u ~ %u\n\n", 0u, UINT_MAX);

	printf("long의 범위 : %d ~ %d\n\n", LONG_MIN, LONG_MAX);
	printf("unsigned long의 범위 : %u ~ %u\n\n", 0u, ULONG_MAX);

	printf("long long의 범위 : -%llu ~ %llu\n\n", LLONG_MIN, LLONG_MAX);
	printf("unsigned long long의 범위 : %u ~ %llu\n\n", 0u, ULLONG_MAX);

	printf("float의 범위 : %f ~ %f ~ %f\n\n", -FLT_MAX, FLT_MIN, FLT_MAX);
	printf("double의 범위 : %lf ~ %lf ~ %lf\n\n", -DBL_MAX, DBL_MIN, DBL_MAX);

}
