#include "stdafx.h"
#include "Parts_List.h"

void Parts_04()
{
	// If();
	Switch();
}

void If()
{
	// if
	/*
	if (조건식)
	{
		조건식이 참일 경우 실행할 명령문1
		조건식이 참일 경우 실행할 명령문2
		조건식이 참일 경우 실행할 명령문3
		조건식이 참일 경우 실행할 명령문4
	}
	else if (조건식)
	{
		바로 위의 if/else if의 조건식이 거짓이면서, 조건식이 참일 경우 실행할 명령문1
		바로 위의 if/else if의 조건식이 거짓이면서, 조건식이 참일 경우 실행할 명령문2
		바로 위의 if/else if의 조건식이 거짓이면서, 조건식이 참일 경우 실행할 명령문3
		바로 위의 if/else if의 조건식이 거짓이면서, 조건식이 참일 경우 실행할 명령문4
	}
	else if (조건식)
	{
		바로 위의 if/else if의 조건식이 거짓이면서, 조건식이 참일 경우 실행할 명령문1
		바로 위의 if/else if의 조건식이 거짓이면서, 조건식이 참일 경우 실행할 명령문2
		바로 위의 if/else if의 조건식이 거짓이면서, 조건식이 참일 경우 실행할 명령문3
		바로 위의 if/else if의 조건식이 거짓이면서, 조건식이 참일 경우 실행할 명령문4
	}
	else
	{
		위에 있는 모든 if/else if의 조건식이 거짓일 경우 실행할 명령문1
		위에 있는 모든 if/else if의 조건식이 거짓일 경우 실행할 명령문2
		위에 있는 모든 if/else if의 조건식이 거짓일 경우 실행할 명령문3
		위에 있는 모든 if/else if의 조건식이 거짓일 경우 실행할 명령문4
	}
	조건문/반복문
	제어문 -> 프로그램의 흐름을 제어
	*/
	// 조건문
	// if문/switch문
	int num1 = 0, num2 = 0;

	// 아스키코드 0번(정수 0)
	char oper = '\0';

	printf("수식 입력 (+, -, *, /) : ");
	scanf("%d %c %d", &num1, &oper, &num2);

	if (oper == '+')
	{
		printf("%d + %d = %d\n", num1, num2, num1 + num2);
	}
	else if (oper == '-')
	{
		printf("%d - %d = %d\n", num1, num2, num1 - num2);
	}
	else if (oper == '*')
	{
		printf("%d * %d = %d\n", num1, num2, num1 * num2);
	}
	else if (oper == '/')
	{
		printf("%d / %d = %f\n", num1, num2, num1 / (float)num2);
	}
	else
	{
		printf("잘못된 수식을 입력했습니다.");
	}
}

void Switch()
{
	// switch
	/*
	switch(정수)
	{
	case 1:
		정수값이 1일 경우 실행할 명령문1;
		정수값이 1일 경우 실행할 명령문2;
		정수값이 1일 경우 실행할 명령문3;
		정수값이 1일 경우 실행할 명령문4;
		break;
	case 2:
		정수값이 1일 경우 실행할 명령문1;
		정수값이 1일 경우 실행할 명령문2;
		정수값이 1일 경우 실행할 명령문3;
		정수값이 1일 경우 실행할 명령문4;
		break;
	case 3:
		정수값이 1일 경우 실행할 명령문1;
		정수값이 1일 경우 실행할 명령문2;
		정수값이 1일 경우 실행할 명령문3;
		정수값이 1일 경우 실행할 명령문4;
		break;
	default:
		정수값이 위의 어떤 case에도 해당하지 않을 경우 실행할 명령문1;
		정수값이 위의 어떤 case에도 해당하지 않을 경우 실행할 명령문2;
		정수값이 위의 어떤 case에도 해당하지 않을 경우 실행할 명령문3;
		정수값이 위의 어떤 case에도 해당하지 않을 경우 실행할 명령문4;
		break;
	}
	// 만약 case에 포함되어있지 않은 정수 가령 위를 예시로 들면 4를 누르면 디폴트로 간다
	*/

	int num1 = 0, num2 = 0;

	// 아스키코드 0번(정수 0)
	char oper = '\0';

	printf("수식과 숫자를 입력해주세요 입력 (+, -, *, /) : ");
	scanf("%d %c %d", &num1, &oper, &num2);

	switch (oper)
	{
	case '+':
	{
		printf("%d + %d = %d\n", num1, num2, num1 + num2);
	}break;
	case '-':
	{
		printf("%d - %d = %d\n", num1, num2, num1 - num2);
	}break;
	case '*':
	{
		printf("%d * %d = %d\n", num1, num2, num1 * num2);
	}break;
	case '/':
	{
		printf("%d / %d = %f\n", num1, num2, num1 / (float)num2);
	}break;
	default:
	{
		printf("잘못된 수식을 입력했습니다.");
	}break;
	}
}
