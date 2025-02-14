#include "stdafx.h"
#include "Parts_List.h"

void Parts_03()
{
	Operator();
}

void Operator()
{
	/*
	// 논리 AND -> 논리값 &&(앰퍼센트) 논리값
	둘다 참일 경우 -> 참 -> 아니라면 거짓
	
	// 논리 OR -> 논리값 || 논리값 
	둘다 거짓일 경우 -> 거짓 -> 아니라면 참
	A와 B, 둘중 하나라도 참일 경우 참

	// 논리 NOT -> !논리값
	논리값의 반대값 -> 참이 들어갔다면 거짓이 거짓이 들어갔다면 참이
	bool ValueControl = false;
	if (!ValueControl)	// 이렇게 되면 거짓이였던 벨류컨트롤이 참으로 들어간다
	{
	}
	// ==, !=, >=
	*/
	int num1 = 0, num2 = 0;
	
	printf("정수(2개) 입력 : ");
	scanf("%d %d", &num1, &num2);

	// 증감연산자
	// 증가연산자
	// 감소연산자
	// ++
	// --
	// 단항연산자
	// num++ 
	// 전위, 후위
	// ++num
	// num++
	// num++ -> num += 1 -> num = num + 1 

	printf("\n===== 증감 연산자 결과 =====\n");
	//
	printf("증가연산자 전위 num1 : %d\n", ++num1); // 전위 즉시
	printf("중간값 확인 num1 : %d\n", num1);
	printf("증가연산자 후위 num1 : %d\n", num1++); // 후위 다음에
	printf("최종값 확인 num1 : %d\n", num1);

	printf("\n===== 감소 연산자 결과 =====\n");
	//
	printf("\n감소연산자 전위 num2 : %d\n", --num2); // 전위 즉시
	printf("중간값 확인 num2 : %d\n", num2);
	printf("감소연산자 후위 num2 : %d\n", num2--); // 후위 다음에
	printf("최종값 확인 num2 : %d\n", num2);
	
	printf("\n===== 비트 연산자 결과 =====\n");
	//
	printf("%d & %d = %d\n", num1, num2, num1 & num2);
	printf("%d | %d = %d\n", num1, num2, num1 | num2);
	printf("%d ^ %d = %d\n", num1, num2, num1 ^ num2);
	printf("~%d = %d\n", num1, ~num1);
	// 비트 쉬프트 연산자
	printf("%d << 2 = %d\n", num1, num1 << 2);
	printf("%d >> 2 = %d\n", num1, num1 >> 2);
	/*
	0000 1010 << 2

	0010 1000 >> 2

	0000 1010 >> 2

    0000 0010 
	*/

	/*
	비트 연산자 -> 수를 비트 단위로 쪼개서 연산	
	//
	&(앰퍼센트)
	비트AND연산자

	1010
	& 
	1111 

	1010 -> 10
	//
	^()
	비트XOR연산자 -> 다르면 참

	1010 
	^
	1001

	0011 
	//
	~
	비트NOT연산자 -> 비트로 쪼개서 0은 1로 1은 0으로
	1010 <-
	-> 0101

	*/

	printf("\n===== 조건 연산자 결과 =====\n");
	printf("(%d < %d) ? : = %d\n", num1, num2, (num1 < num2) ? num1 : num2); 
	// (참 or 거짓) ? (참일 경우 결과값) : (거짓일 경우 결과값)

}
