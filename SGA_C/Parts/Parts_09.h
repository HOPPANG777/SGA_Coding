#pragma once

void Parts_09();

// 사용자 정의 자료형
//  struct, union, enum
// 구조체, 공용체, 열거형
/*
struct 구조체 이름
{
	멤버변수 1;
	멤버변수 2;
}

스트럭트 안에 들어가있는 변수를 멤버라 한다.
멤버 변수

이 구조체 라는 것을 멤버라는 것을 포함해서 우리가 임의로 만든 자료형이다

다른 자료형을 가진 변수를 조합해서 만든 것이라고 할수있다.

서로 연관성을 가진 자료형들을 묶어서 하나의 자료형으로 표현할수있는것을 구조체라고 할수있다.

struct Player
{
	int atk;
	int hp;
}

이렇게 연관성있는 데이터들을 묶어둘수있겠다.
이런걸 구조체라 한다.
*/

/*
구조체의 패딩
CPU가 편할려고 패딩을 한다.
정확히 레지스터가 편할려고.

CPU에서 데이터를읽어들여서 처리를한다.
이때 얼마만큼 읽어드릴지는 레지스터가 기준이된다.

int double int가 있었을땐
16이면 될꺼같은데 24를 썼다
왜 이러냐면

더블까지는 16이 나왔을것이다 이 이유는
컴퓨터는 제일 큰놈 기준으로 읽는다.

무조건 8바이트로 읽는다.

CPU입장에선 4바이트로 나누어서 합치느니 그냥 8바이트 째로 읽어버리는게 편하다
그래서 아무 의미없는 4바이트를 인트 뒤에 채워넣고 마치 패딩에 털 채워넣듯이
더블이 뒤에 있으면 인트 바로뒤엔 4바이트를 넣어서 8바이트씩 읽는다.

그래서 뒤에 인트가 나와도 가장 큰 더블이 기준이라 뒤에 인트로 8바이트로 된다.

근데 만약
int
int
double
이라면

16바이트가 나온다
왜냐하면
인트 2개를 합하면 8바이트니까
4바이트면 되니까
4바이트 4바이트 짜르고
더블은 그냥 8바이트로 읽고
패딩이 따로 안들어가고
바로 실행이된다.
진짜 극한의 최적화를 한다면,
유니온을 고려해보겠지만 이건 너무 극단적이고
이런 순서를 고려해보는것도 방법이다

구조체 순서를 바꿧을뿐인데 크기가 줄었지 않는가.

*/

struct Test
{
	int a;
	int c;
	double b;
};

/*
	C++의 스트럭트는 사실 스트럭트가 아니라 클래스다 그래서
	C에서의 스트럭트는 완전 다른것이다.
	구조체의 이름만 정해놓는것이아니라 별명같은걸 지정해주어야 한다.
	typedef은 다른곳에도 쓰이지만 일단 지금은 새롭게 이름을 지정해준다
	일종의 별명을 정해준다고 생가하면 된다.
*/

typedef struct Player
{
	int id;
	int level;
	int hp;
	int atk;
} Player;

void Structure();
void PrintPlayerInfo(Player player);
Player PlayerLevelUp(Player up);

typedef union Data
{
	int intNum;
	float fltNum;
	double dblNum;
} Data;
/*
크기를 보면
8바이트가 나온다.
왜 그러느냐
기존의 스트럭처는 공간은 늘리면 늘렸지 않은가 그렇다면 16은 있어야 하지 않을까?

공용체라는 녀석은
지금 8바이트는 더블에서 나온건데
그렇다면
공용체는
마지막으로 넣은 데이터에 따라서 이 공용체가 저장하는 값이 달라진다.
*/
void Union();

typedef enum Color
{
	COLOR_NONE = -1,	// 심볼릭 상수
	COLOR_RED,
	COLOR_GREEN,
	COLOR_BLUE,
	COLOR_MAX_VALUE
} Color;

typedef enum Status
{
	STATUS_NONE,
	STATUS_ALIVE,
	STATUS_DEAD,
	STATUS_MAX_VALUE
} Status;

/*
이렇게 지금 상태에서는 아무 문제가 없어보인다.

네임 스페이스라는 개념이 있다 이 이름이 하나의 공간을 가진다는 의미이다.

근데 우리가 사용하는 이넘은 이름 공간이 없다

이걸 unscoped enum
영역을 가지지 않는 이넘이라고 부르는데
C++ 의 이넘 클래스는 어떤 특징을 가지냐 네임 스페이스가 있다
이걸 scoped enum이라고 부른다
이걸 C++에 가서 배우게 된다.

이넘밖에 없어서 컬러처럼 접두를 붙히거나 접미를 붙힌다.
*/

typedef enum Motion
{
	MOTION_IDLE,
	MOTION_NONE,
	MOTION_WALKING,
	MOTION_RUNNING,
	MOTION_MAX_VALUE
} Motion;

/*
	엔진을 기준으로 설명을 해보자면
	스테이터스 그러니까 상태를 정할때도 쓸수있다.
	특정 상태일때 진행이 되도록
	예를 들어 죽었는지 살았는지

	그리고 유한 상태 머신 같이 상태를 이용해서 상태값을 계속 바꿔줌으로써
	컴퓨터가 하나의 상태만 가지고 작동을 하는거다
	애니메이션을 가지고 그때 그때 맞는 행동만 하도록

	스테이터스 와 모션을 나눠서
	지금 공중에 있는지 뛰어 다니는지 점프하는지를 정할수있다.
*/

/*
enum은 열거형이라고 흔히들 불린다.
이넘같은 경우엔
상수에다가 이름을 붙힌다
왜 이름을 붙히냐
결국은 가독성 때문일것이다.
0123이라고 그냥 숫자로 분류하는것이 아니라
이넘으로 이름을 붙혀서 분류하는것이다.
혼자할땐 숫자로 해도 되지만 결국 같이 코딩을 하니까 여러사람과 함께 하기 위해
*/

typedef enum ItemType
{
	ITEM_NONE = -1,
	ITEM_GOLD,
	ITEM_WEAPON,
	ITEM_ARMOR,
	ITEM_MAX_VALUE
} ItemType;

typedef enum WeaponType
{
	WEAPON_NONE = -1,
	WEAPON_SWORD,
	WEAPON_BOW,
	WEAPON_GUN,
	WEAPON_MAX_VALUE
} WeaponType;

void Enumeration();
