#include "stdafx.h"
#include "Parts_04.h"

/*
OOP 4가지 특징
	1. 추상화
	2. 캡슐화
	3. 상속자
	4. 다형성
*/

Parts_04::Parts_04()
{
	//Inheritance();
	Polymorphism();
}

void Parts_04::Inheritance()
{
	using namespace Parts_04_Inheritance;

	Base base(10, 3.14f);
	cout << '\n';
	base.PrintInfo();
	cout << '\n';

	Derived derived;
	cout << '\n';

	derived.PrintInfo();
	cout << '\n';

	//업캐스팅
	//파생 클래스를 기반 클래스에 맞춰 형변환 하는것 //묵시적 형변환
	//이렇게 쓰는 이유는, (기반 객체로 파생객체의 동적할당 주소를 받음) 다형성의 의해서다.
	Base* basePtr = (Base*)new Derived(10, 3.14f, "Hello, World!\n");
	cout << '\n';
	basePtr->PrintInfo();
	cout << '\n';

	SAFE_DELETE(basePtr);

	cout << '\n';
}

void Parts_04::Polymorphism()
{
	using namespace Parts_04_Polymorphism;

	Base* base1 = new Base();
	cout << '\n';
	Base* base2 = new SubDerived(); //업캐스팅
	cout << '\n';

	Derived* derived1 = new SubDerived();
	cout << '\n';
	//이미 업캐스팅이 되어 있는 상황에서 다운 캐스팅이 가능함.
	//base2는 현재 SubDerived를 동적할당 하게 되며,
	//SubDerived를 Drevied로 받기 때문에 문제가 없어 보이지만,
	//이건 런타임 중에 결정이 나기 때문에 컴파일러 입장에선,
	//base를 Derived를 받는다고 보기 때문에 형 변환을 해주어야 한다.
	Derived* derived2 = dynamic_cast<Derived*>(base2); //다운 캐스팅
	assert(derived2 != nullptr);

	//dynamic_cast
	/*
	RTTI : 실행시간에서의 타입 정보
	dynamic_cast는 이 RTTI를 체크를하여 걸러준다.
	걸러주는 과정을 거치기 때문에 그만큼 과부화가 걸릴 수 있다.

	dynamic_cast를 사용하면,
	유효하지 않는 다운캐스팅일 경우 NULL을 반환해버림.

	dynamic_cast의 선제조건은 기본적으로 가상함수 테이블이 존재해야한다.
	즉, 한개 이상의 가상함수가 존재해야 한다.
	*/
	
	cout << typeid(*base1).name() << endl;
	cout << typeid(*base2).name() << endl << endl;

	base1->ShowInfo();
	cout << endl;
	base2->ShowInfo();
	cout << endl;
	derived1->ShowInfo();
	cout << endl;
	derived2->ShowInfo();
	cout << endl;

	cout << "===== 상수 멤버 함수 호출 결과 =====\n";
	//다운캐스팅을 했기 때문에 SubDerived에 있는 SetValue함수를 호출 가능함.
	//이런 명확한 상황에선 Static_cast를 사용해도 무관함.
	dynamic_cast<SubDerived*>(derived1)->SetValue();
	cout << "Value : " << dynamic_cast<SubDerived*>(derived1)->GetValue() << endl <<endl;

	SAFE_DELETE(derived1);
	cout << '\n';
	SAFE_DELETE(base2);
	cout << '\n';
	SAFE_DELETE(base1);
	cout << '\n';
}

namespace Parts_04_Inheritance 
{
	Base::Base(int num, float fltNum)
		: num(num), fltNum(fltNum)
	{
		cout << "Base(int, float) 생성자 호출!\n";
	}

	Base::~Base()
	{
		cout << "~Base() 소멸자 호출!\n";
	}

	void Base::PrintInfo()
	{
		cout << "===== 기반 객체 정보 =====\n";
		cout << "Int : " << num << '\n';
		cout << "Float : " << fltNum << '\n';
	}

	Derived::Derived() //상속을 위해 기본생성자 : Base();를 호출하기 때문에 기본 생성자가 없다면 에러가 남.
		: Derived(0, 0.0f, "") //Base의 생성자가 호출 할 수 있도록 정확히 명시해줌.
	{
		cout << "Derived() 생성자 실행!\n";
	}

	Derived::Derived(int num, float fltNum, const char* string)
		: Base(num, fltNum)
	{
		strcpy(this->string, string);
		cout << "Derived(int, float, const char*) 생성자 실행!\n";
	}

	Derived::~Derived()
	{
		cout << "~Derived() 소멸자 실행!\n";
	}

	void Derived::PrintInfo()
	{
		Base::PrintInfo();

		cout << "===== 파생 객체 정보 =====\n";
		cout << "String : " << string << '\n';
	}
}

namespace Parts_04_Polymorphism
{
	void Base::ShowInfo()
	{
		cout << "Base::ShowInfo() 실행!\n";
	}
	
	void Derived::ShowInfo()
	{
		//DoShowInfo의 호출이 가능하다는 것은
		//this에 객체가 할당된 것이고,
		//오버라이드 되었기 때문에 보장할 수 있어 문법적 오류가 아님
		this->DoShowInfo();
		cout << "Derived::ShowInfo() 실행!\n";
	}

	void SubDerived::SetValue() const
	{
		const_cast<SubDerived*>(this)->val = 10;
	}

	int SubDerived::GetSumValue(const SubDerived& a, SubDerived& b)
	{
		return a.GetValue() + b.GetValue();
	}

	void SubDerived::ShowInfo()
	{
		cout << "SubDerived::ShowInfo() 실행!\n";
	}
	
	void SubDerived::DoShowInfo()
	{
		cout << "SubDerived::ShowInfo() 실행!\n";
	}
}