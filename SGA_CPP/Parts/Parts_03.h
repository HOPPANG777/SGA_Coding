#pragma once

#define DEF_LEN 5

/*
public과 private는 접근 제어자라고 불린다.
클래스에선 기본 접근 제어자는 private이다.

public으로 선언된 Parts_03을 main에서 호출 -> 링크 단계에서 소스파일의 Parts_03
구현부와 합쳐져 정상 작동함.(함수와 비슷)

만약 private로 만들어져있다면 외부에서 접근이 불가능 하지만
public의 Parts_03안에서 호출을 통한다면 접근이 가능한것.

기본 생성자를 통한 위임 생성자가 가능하다.

*/

class Player
{
public:
	//기본 생성자 : 위임 생성자	//기본 생성자를 통해서 위임을 하여 초기화를 하는 경우가 많음.
	Player() : Player(1, 0, 0) { cout << "기본생성자 호출!\n"; } 
	Player(int id, int hp, int atk);

	//복사 생성자
	Player(const Player& other);
	//연산자 오버로딩
	Player& operator=(const Player& other);

	//소멸자
	~Player();
public:
	int GetID() { return id; }
	int GetHP() { return hp; }
	int GetATK() { return atk; }
	void SetHP(int hp) { (*this).hp = hp; }
	void SetATK(int atk) { this->atk = atk; }

public:
	void Attack(Player& otherPlayer) { otherPlayer.hp -= atk; }

private:
	int hp = 0;
	int atk = 0;

	int* ptr = nullptr;
	int* arr = nullptr;

	const int id;
};

/*===================================================================================================*/

class Parts_03
{
public:
	Parts_03(); //생성자 : 반환형이 없으며 클래스와 이름이 동일하다.

private:
	void Class();
};