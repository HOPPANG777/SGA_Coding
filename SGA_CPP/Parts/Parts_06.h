#pragma once

namespace Parts_06_StaticMember
{
	/*
	static멤버 함수는 static으로 선언된 자기 자신안에 멤버 변수만 접근이 가능함.
	정적이기에, this가 없음

	static 이기에, 데이터 영역에 존재하지만,
	클래스를 통해서만 접근이 가능하다.

	static멤버 함수는 클래스 외부에서 초기화를 해주어야 한다.
	그래야 그 값을 쓸 수 있음.
	*/

	class Widget
	{
	public:
		int GetValue() const { return this->value; }
		//정적함수는 정적변수를 접근할 수 있음.
		static int GetStaticMemValue() { return staticValue; }
		
		void SetValue(int value) { this->value = value; }
		//일반 함수에서 정적멤버 접근은 가능하다.
		void AddValue(int value) { staticValue += value; }

		static void ShowInfo() { cout << "Widget::ShowInfo() 호출!\n"; }
	private:
		int value;
		static int staticValue;
	};
}

namespace Parts_06_Singleton
{
	struct Data
	{
		string id = "";

		int value = 0;
		float fltVal = 0.0f;
	};

	class DataManager
	{
		//컴파일러가 기본적으로 생성하는 생성자와 소멸자를 명시적으로 적어줌.(의도를 위해)
		//어디까지나 명시적이기 때문에 = default를 안적어도 됨.
		DataManager() = default;
		~DataManager() = default;

		//이런식으로 필요없는 기본적으로 생성되는 함수를 지울 수 있음
		DataManager(const DataManager& other) = delete;
		DataManager& operator=(const DataManager& other) = delete;

	public:
		Data GetData(const string& id);
		void AddData(const Data& data);
		void RemoveData(const string& id);
		int FindData(const string& id);

		static DataManager* Get();
		static void Destroy();

	private:
		size_t numDatas = 0;
		Data datas[100];
		
		static DataManager* instance;
	};
}

namespace Parts_06_Singletons
{
	class SingletonA
	{
		DECLARE_SINGLETON(SingletonA);

	public:
		void ShowInfo() { cout << "SingletonA::ShowInfo() 호출!\n"; }
	};

	class SingletonB
	{
		DECLARE_SINGLETON(SingletonB);

	public:
		void ShowInfo() { cout << "SingletonB::ShowInfo() 호출!\n"; }
	};

	class SingletonC
	{
		DECLARE_SINGLETON(SingletonC);

	public:
		void ShowInfo() { cout << "SingletonC::ShowInfo() 호출!\n"; }
	};
}

class Parts_06
{
public:
	Parts_06();

private:
	void StaticMember();
	void Singleton();
	void Singletons();
};