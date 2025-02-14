#include "stdafx.h"
#include "Parts_07.h"

Parts_07::Parts_07()
{
	//FuncTemplate();
	//LinkedListClassTemplate();
	//SingletonClassTemplate();
	ClassTemplateSpecialization();
}

void Parts_07::FuncTemplate()
{
	using namespace Parts_07_FuncTemplate;
	int val1 = 10;
	int val2 = 20;

	cout << "===== 정수 교환전=====\n" << val1 << ", " << val2 << '\n';
	Swap(val1, val2);
	cout << "\n===== 정수 교환후=====\n" << val1 << ", " << val2 << '\n';

	float fltVal1 = 10.1f;
	float fltVal2 = 20.5f;

	cout << "\n===== 실수 교환전=====\n" << fltVal1 << ", " << fltVal2 << '\n';
	Swap<float>(fltVal1, fltVal2);
	cout << "\n===== 실수 교환후=====\n" << fltVal1 << ", " << fltVal2 << '\n';

	string str1 = "AB";
	string str2 = "CD";

	cout << "\n===== 문자열 교환전=====\n" << str1 << ", " << str2 << '\n';
	Swap<string>(str1, str2);
	cout << "\n===== 문자열 교환후=====\n" << str1 << ", " << str2 << '\n';

	Data data1 = { 1, 10.1f };
	Data data2 = { 2, 20.2f };

	cout << "\n===== 데이터 교환전=====\n" << "Int : " << data1.a << ", " << "Float : " << data1.b << ", " << "Int : " << data2.a << ", " << "Float : " << data2.b << '\n';
	Swap(data1, data2);
	cout << "\n===== 데이터 교환후=====\n" << "Int : " << data1.a << ", " << "Float : " << data1.b << ", " << "Int : " << data2.a << ", " << "Float : " << data2.b << '\n';

	int* intArr = MakeArr<int>();
	float* fltArr = MakeArr<float>();

	for (int i = 0; i < 10; i++)
	{
		intArr[i] = i + 1;
		fltArr[i] = i + 1.5f;
	}

	cout << "\n===== 동적할당 결과 =====\n";
	cout << "Int : ";
	for (int i = 0; i < 10; i++)
	{
		cout << intArr[i] << ", ";

	}
	cout << "\nFlt : ";
	for (int i = 0; i < 10; i++)
	{
		cout << fltArr[i] << ", ";
	}
	cout << "\n\n";

	SAFE_DELETE_ARRAY(intArr);
	SAFE_DELETE_ARRAY(fltArr);
}

void Parts_07::LinkedListClassTemplate()
{
	using namespace Parts_07_LinkedListClassTemplate;

	LinkedList<int> valList1;
	LinkedList<string> valList2;

	for (int i = 0; i < 10; i++)
	{
		valList1.AddValue(i + 1);
		valList2.AddValue(to_string(i + 1.5f));
	}

	cout << "===== 연결 리스트 1 원소 =====\n";
	for (int i = 0; i < valList1.GetNumValues(); i++)
		cout << valList1.FindValue(i) << ", ";

	cout << "\n===== 연결 리스트 2 원소 =====\n";
	for (int i = 0; i < valList2.GetNumValues(); i++)
		cout << valList2.FindValue(i) << ", ";

	cout << '\n';

	list<int> intList;
	list<string> strList;

	for (int i = 0; i < 10; i++)
	{
		intList.push_back(i + 1);
		strList.push_back(to_string(i + 1.5f));
	}

	cout << "\n===== intList<int> 원소 =====\n";
	for (list<int>::iterator iter = intList.begin(); iter != intList.end(); ++iter)
		cout << *iter << ", ";

	cout << "\n\n===== strList<string> 원소 =====\n";
	for (auto str : strList)
		cout << str << ", ";
}

void Parts_07::SingletonClassTemplate()
{
	using namespace Parts_07_SingletonClassTemplate;

	Widget::Get()->ShowInfo();
	Widget::Get()->ShowInfo();
	Widget::Destroy();
}

void Parts_07::ClassTemplateSpecialization()
{
	using namespace Parts_07_ClassTemplateSpecialization;

	Datas<string, string> Data1;
	Datas<int, string> Data2;
	Datas<int, float> Data3;
}
