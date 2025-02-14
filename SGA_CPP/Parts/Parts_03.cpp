#include "stdafx.h"
#include "Parts_03.h"

/*
	C - > 절차적(Procedural) 프로그래밍

	프로시저 (절차, 과정)-> 함수를 중심
	함수(Function) - >기능

	C++ -> 객체 지향 프로그래뮝
	대기업
	이윤창출
	분산시켜 아랫급 사람들에게 각 부서에 맞추어 일을 나눈다. -> 클래스

	속성(멤버변수)과 기능(멤버함수)
	c언어에서 함수가 기능이였다면, struct는 속성이다.
	struct -> 속성만 있음.
	class -> 속성, 기능이 모두 있음 (C++에서의 struct는 class와 거의 동일함)

	OOP 4가지 특징
	1. 추상화
	2. 캡슐화
	3.
	4. 다형성
*/

Parts_03::Parts_03()
{
	Class();
}

void Parts_03::Class()
{
	Player player1;
	player1.SetHP(100);
	player1.SetATK(15);

	Player player2(2, 50, 35);

	cout << "\n===== 공격 전 =====\n";
	cout << "player1 : " << player1.GetHP() << ", " << player1.GetATK() << '\n';
	cout << "player2 : " << player2.GetHP() << ", " << player2.GetATK();

	player1.Attack(player2);

	cout << "\n\n===== player1 -> player2 공격 결과 =====\n";
	cout << "player1 : " << player1.GetHP() << ", " << player1.GetATK() << '\n';
	cout << "player2 : " << player2.GetHP() << ", " << player2.GetATK();

	cout << "\n\n===== player3 생성 =====\n";
	//Player player3 = player2;
	Player player3;
	player3 = player2;

	cout << "player3 : " << player3.GetID() << ", " << player3.GetHP() << ", " << player3.GetATK();

	player2.Attack(player1);

	cout << "\n\n===== player2 -> player1 공격 결과 =====\n";
	cout << "player1 : " << player1.GetHP() << ", " << player1.GetATK() << '\n';
	cout << "player2 : " << player2.GetHP() << ", " << player2.GetATK();

	player1.Attack(player2);

	cout << "\n\n===== player1 -> player2 공격 결과 =====\n";
	cout << "player1 : " << player1.GetHP() << ", " << player1.GetATK() << '\n';
	cout << "player2 : " << player2.GetHP() << ", " << player2.GetATK() << '\n';
	cout << "player3 : " << player3.GetHP() << ", " << player3.GetATK();
}

/*===================================================================================================*/

Player::Player(int id, int hp, int atk)
	: id(id), hp(hp), atk(atk) //선언과 동시에 멤버 이니셜라이저를 초기화.
	//괄호 안에 적은 자료형에 따라서 맞춰서 적어주어야 한다.
{
	// this->id = id; 공간이 잡힌 후 대입하기 때문에 const에 의해 안됨.

	cout << "생성자(int, int, int) 실행!\n";

	//생성자 생성 시 동적할 당 방법.
	//new란 c에서의 동적할당에선 malloc, calloc, realloc이 있다면 new로 통일됨.
	//new의 경우 new 자료형(초기화 값) 또는 new 자료형[크기] { 초기화 값 } 형식으로 사용한다.
	ptr = new int(5);
	arr = new int[DEF_LEN] { 5 };

}

Player::Player(const Player& other)
	: id(other.id)
{
	*this = other;

	cout << "복사 생성자 실행!\n";
}

Player& Player::operator=(const Player& other)
{
	hp = other.hp;
	atk = other.atk;

	SAFE_DELETE(ptr);
	SAFE_DELETE_ARRAY(arr);

	ptr = new int(*other.ptr);
	arr = new int[DEF_LEN];
	memcpy(arr, other.arr, sizeof(arr[0]) * DEF_LEN);

	cout << "복사 할당 연산자 실행!\n";

	return *this;
}

Player::~Player()
{
	//delete[] arr; //배열 공간의 동적할당 해제.
	//delete ptr; //동적할당 해제

	SAFE_DELETE_ARRAY(arr);
	SAFE_DELETE(ptr);
}