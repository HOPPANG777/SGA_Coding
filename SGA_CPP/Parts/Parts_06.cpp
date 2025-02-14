#include "stdafx.h"
#include "Parts_06.h"

int Parts_06_StaticMember::Widget::staticValue = 0;

Parts_06_Singleton::DataManager* Parts_06_Singleton::DataManager::instance = nullptr;

Parts_06::Parts_06()
{
	//StaticMember();
	//Singleton();
	Singletons();
}

void Parts_06::StaticMember()
{
	using namespace Parts_06_StaticMember;

	Widget widget1;
	Widget widget2;

	widget1.ShowInfo();
	Widget::ShowInfo();

	widget1.SetValue(10);
	widget2.SetValue(20);
	
	widget1.AddValue(10);
	widget2.AddValue(20);

	cout << "\n===== 클래스 변수 조작 결과 =====\n";
	cout << "widget1 : " << widget1.GetValue() << ", " << widget1.GetStaticMemValue() << '\n';
	cout << "widget2 : " << widget2.GetValue() << ", " << widget2.GetStaticMemValue();
}

void Parts_06::Singleton()
{
	using namespace Parts_06_Singleton;

	for (int i = 0; i < 10; ++i)
	{
		Data data = { to_string(i), i + 1, i + 1.5f };

		DataManager::Get()->AddData(data);
	}

	cout << "===== 데이터 추가 결과 =====\n";

	for (int i = 0; i < 10; ++i)
	{
		const string& id = to_string(i);
		const Data& data = DataManager::Get()->GetData(id);

		cout << data.value << ", " << data.fltVal << '\n';
	}

	DataManager::Destroy();
}

void Parts_06::Singletons()
{
	using namespace Parts_06_Singletons;

	SingletonA::Get()->ShowInfo();
	cout << '\n';
	SingletonB::Get()->ShowInfo();
	cout << '\n';
	SingletonC::Get()->ShowInfo();
	cout << '\n';
}

namespace Parts_06_Singleton
{
	Data DataManager::GetData(const string& id)
	{
		int index = FindData(id);

		assert(index >= 0);

		return datas[index];
	}

	void DataManager::AddData(const Data& data)
	{
		int index = FindData(data.id);

		if (index <= -1)
			datas[numDatas++] = data;
	}

	void DataManager::RemoveData(const string& id)
	{
		int index = FindData(id);

		if (index >= 0)
		{
			for (int i = index; i < numDatas - 1; ++i)
				datas[i] = datas[i + 1];

			--numDatas;
		}
	}

	int DataManager::FindData(const string& id)
	{
		for (int i = 0; i < numDatas; i++)
			if (datas[i].id == id)
				return i;
			

		//데이터를 찾을 수 없는 경우
		return -1;
	}

	DataManager* Parts_06_Singleton::DataManager::Get()
	{
		//게으른 초기화
		//처음 이 DataManager를 필요로 했을 때 만들어줌.
		//휴먼에러 방지가 가능하다는 이점이 있다.
		if (instance == nullptr)
			instance = new DataManager();

		return instance;
	}

	void DataManager::Destroy()
	{
		SAFE_DELETE(instance);
	}
}

namespace Parts_06_Singletons
{
	SingletonA::SingletonA()
	{
		cout << "SingletonA() 생성자 호출!\n";
	}
	
	SingletonA::~SingletonA()
	{
		cout << "~SingletonA() 소멸자 호출!\n";
	}
	
	SingletonB::SingletonB()
	{
		cout << "SingletonB() 생성자 호출!\n";
	}
	
	SingletonB::~SingletonB()
	{
		cout << "~SingletonB() 소멸자 호출!\n";
	}
	
	SingletonC::SingletonC()
	{
		cout << "SingletonC() 생성자 호출!\n";
	}
	
	SingletonC::~SingletonC()
	{
		cout << "~SingletonC() 소멸자 호출!\n";
	}
}