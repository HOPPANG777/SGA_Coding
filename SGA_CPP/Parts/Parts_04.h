#pragma once

/*
//순수가상함수
함수의 정의가 존재하지 않는 함수
만약 클래스 내에 순수 가상함수가 하나라도 존재한다면,
그 함수는 추상클래스가 된다.
추상클래스를 통해선 객체를 생성할 수 없다.
순수가상함수로 이루어진 클래스 인터페이스라고 함.

추상클래스를 상속 받는 파생 클래스에선,
상속 받은(의무) 순수 가상 함수를 정의 해야한다. (그렇지 않으면 파생 클래스도 추상 클래스가 됨)
결론적으로 추상클래스에 순수가상함수는 틀이 되주기 위해 존재하며,
그 클래스를 상속 받은 파생클래스에선 자신의 클래스에 맞게
전달받은 순수가상함수를 정의해서 써야 한다.
*/

namespace Parts_04_Inheritance
{
	/*
	virtual 가상함수
	virtual ~Base(); 가상 소멸자
	파생 객체 또한 소멸자가 호출됨

	virtual을 붙이는 순간 버츄얼 펑션 포인터가 기반 객체에 추가가 된다.
	기반 객체에 추가가 됐다는건,
	파생 객체에도 버츄얼 펑션 포인터가 추가가 된다.
	힙영역에 vft table을 만든다. (가상함수테이블 -> 이중 포인터)
	이 가상함수 테이블은 함수 포인터들을 담고 있다. 이 가상함수테이블은
	함수 포인터의 주소 뿐 아닌 공간이 하나씩 더 잡히는데, 이것은 RTTI라고 부른다.
	RTTI는 실행 중에 실제 객체에 대한 자료형의 정보를 가지고 있다.

	아래 코드에선, ~Base()와 PrintInfo() 대한 함수의 주소(함수 포인터)를 가상함수 테이블은 가진다.
	그럼, 기반 객체에 테이블에서 파생 객체의 테이블로 깊은 복사를 통해 함수의 주소를 받게된다.
	그렇게 된다면, 파생 객체에 있는 동일한 함수를 만나게 되어 함수 재정의(오버라이드)가 일어나게 된다.

	오버라이드가 되는 조건
	1. 가상 함수여야 할 것.
	2. 함수의 원형이 완전히 동일해야 한다. (단, 소멸자의 특징에 의해 이름은 달라도 된다.)

	그런 후 기반 객체로 부터 받아온 가상함수의 정보를 파생객체의 정보로 오버라이드 일어난 부분을 덮어씌운다.
	이 과정이 일어난것을 알고싶다면 override를 붙여 확인하면 된다.
	*/

	class Base
	{
	public:
		//Base() : Base(0, 0.0f) {};
		Base(int num, float fltNum);
		virtual ~Base();

	public:
		virtual void PrintInfo();
		
	protected:
		int num = 0;
		float fltNum = 0.0f;
	};

	//상속 접근제어자. (public.. 등등)
	//자신이 상속 받은 상태를 그대로 유지한다면 public
	//현재 proteced로 되어있으니 protected로 유지함.
	//만약, protected면, public을 모두 protected로,
	//만약, private면, 모두 private로 바꿈.

	class Derived : public Base
	{
	public:
		Derived();
		Derived(int num, float fltNum, const char* string);

		~Derived();

	public:
		void PrintInfo();

	private:
		char string[100] = "";
	};
}

namespace Parts_04_Polymorphism
{
	class Base 
	{

	public:
		Base() { cout << "Base() 생성자 실행!\n"; }
		virtual ~Base() { cout << "~Base() 소멸자 실행!\n"; }

	public:
		virtual void ShowInfo();
	};


	//final
	//이 밑에 상속 받는 클래스에서 final이 붙게 된다면
	//더 이상 오버라이드 할 수 없게됨.
	//클래스 뒤에도 붙일 수 있으며,
	//더 이상 상속을 하지 말란 뜻이 된다.
	//class Derived final: public Base
	class Derived : public Base
	{
	public:
		Derived() { cout << "Derived() 생성자 실행!\n"; }
		~Derived() override { cout << "~Derived() 소멸자 실행!\n"; }
	
	public:
		//void ShowInfo() final override;
		void ShowInfo() override;

	protected:
		//순수 가상함수화 함 ( 순수 지정자 = 0을 붙임)
		virtual void DoShowInfo() = 0;
	};


	class SubDerived : public Derived
	{
	public:
		SubDerived() { cout << "SubDerived() 생성자 실행!\n"; }
		~SubDerived() override { cout << "~SubDerived() 소멸자 실행!\n"; }

	public:
		int GetValue() const //상수 멤버 함수가 됨. 
		//이 함수 안에서 this를 통한 객체를 상수화 시킴
		//또 이 안에선 비상수 함수를 호출 시킬수 없다.
		//이것도 네임 맹글링이 되기 때문에 오버로딩이 가능함.
		//상수 멤버 함수를 호출하는건 오버로딩 되어있는 상황에선 상수화된 객체만 호출이 가능하다.
		{ 
			//val = 10; 
			return val;
		}
		int GetValue() { return val; }
		void SetValue() const;

		int GetSumValue(const SubDerived& a, SubDerived& b);

	public:
		void DoShowInfo();
		void ShowInfo() override;

	private:
		int val = 0;
	};
}

class Parts_04
{
public:
	Parts_04();
	
private:
	void Inheritance();
	void Polymorphism();
};