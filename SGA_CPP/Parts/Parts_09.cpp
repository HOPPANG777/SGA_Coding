#include "stdafx.h"
#include "Parts_09.h"

Parts_09::Parts_09()
{
	//Array();
	//Vector();
	//List();
	//Map();
	//Set();
	//Iterator();
	Algorithm();
}

void Parts_09::Array()
{
	array<int, 10> valList1 = { 0 };
	array<string, 10> valList2 = { "" };

	for (size_t i = 0; i < valList1.size(); ++i)
		valList1[i] = int(i) + 1;
	
	for (size_t i = 0; i < valList2.size(); ++i)
		valList2[i] = to_string(valList2.size() - i);

	cout << "===== array<int> 원소 출력 =====\n";
	for (size_t i = 0; i < valList1.size(); i++)
		cout << valList1[i] << ", ";
	
	cout << "\n\n===== array<string> 원소 출력 =====\n";
	for (size_t i = 0; i < valList2.size(); i++)
		cout << valList2[i] << ", ";
}

void Parts_09::Vector()
{
	//vector는 기본으로 0 초기화를 해줌
	vector<int> valList1;
	vector<string> valList2;

	valList1.reserve(10);
	valList2.resize(10, "");

	for (size_t i = 0; i < valList1.capacity(); ++i)
		valList1.emplace_back(int(i) + 1);

	for (size_t i = 0; i < valList2.size(); ++i)
		valList2[i] = to_string(valList2.size() - i);

	cout << "===== vector<int> 원소 출력 =====\n";
	for (size_t i = 0; i < valList1.size(); i++)
		cout << valList1[i] << ", ";

	cout << "\n\n===== vector<string> 원소 출력 =====\n";
	for (size_t i = 0; i < valList2.size(); i++)
		cout << valList2[i] << ", ";
}

void Parts_09::List()
{
	list<int> valList1;
	list<string> valList2;

	for (int i = 0; i < 10; ++i)
	{
		valList1.push_back(i + 1);
		valList2.insert(valList2.begin(), to_string(i + 1));
	}

	cout << "===== list<int> 원소 출력 =====\n";
	for (auto val : valList1)
		cout << val << ", ";

	cout << "\n\n===== list<string> 원소 출력 =====\n";
	for (auto str : valList2)
		cout << str << ", ";
}

void Parts_09::Map()
{
	//삽입, 탐색 속도 O(logN)
	map<string, int> valList1;
	unordered_map<string, string> valList2;

	for (int i = 0; i < 15; ++i)
	{
		string key = to_string(i);

		//valList1.insert(make_pair(key, i + 1));
		//valList2.insert(decltype(valList2)::value_type(key, to_string(i + 1)));
		valList1.emplace(key, i + 1);
		valList2.emplace(key, to_string(i + 1));
	}

	cout << "===== map 원소 출력 =====\n";
	for (auto node : valList1)
		cout << "[" << node.first << "] " << node.second << ", ";

	cout << "\n\n===== unorderd map 원소 출력 =====\n";
	for (auto node : valList2)
		cout << "[" << node.first << "] " << node.second << ", ";

	valList1.erase("5");
	valList2.erase("10");

	cout << "\n\n===== 5번 키 삭제 후 map 원소 출력 =====\n";
	for (auto node : valList1)
		cout << "[" << node.first << "] " << node.second << ", ";

	cout << "\n\n===== 10번 키 삭제 후 unorderd map 원소 출력 =====\n";
	for (auto node : valList2)
		cout << "[" << node.first << "] " << node.second << ", ";
}

void Parts_09::Set()
{
	srand((unsigned int)time(nullptr));

	// 내림차순으로 하도록 함수자 사용 (기본값은 less함수자)
	set<int, greater<int>> valList;

	for (int i = 0; i < 10; ++i)
		valList.insert(rand() % 10);

	cout << "===== set 원소 출력 =====\n";
	for (const int& val : valList)
		cout << val << ", ";

	string str;

	cout << "\n\n문자열 입력 : ";
	cin >> str;

	if (str.back() == '\n')
		str.back() = '\0';

	cout << "중복 없는 문자열 여부 : " << (IsUniqueStr(str) ? "중복 없음" : "중복 있음");
}

void Parts_09::Iterator()
{
	vector<int> valList1;
	unordered_map<string, int> valList2;

	for (int i = 0; i < 10; ++i)
	{
		string key = to_string(i);

		valList1.push_back(i + 1);
		valList2.emplace(key, i + 1);
	}

	cout << "===== 반복자를 통한 vector 원소 출력 =====\n";
	for (vector<int>::iterator iter = valList1.begin(); iter != valList1.end(); ++iter)
		cout << *iter << ", ";

	cout << "\n\n===== 반복자를 통한 unordered_map 원소 출력 =====\n";
	for (auto iter = valList2.begin(); iter != valList2.end(); ++iter)
		cout << "[" << iter->first << "] " << iter->second << ", ";

	int* arr = new int[10];
	string* strs = new string[10];

	IteratorWrapper<int> intWrapper(arr, 10);
	IteratorWrapper<string> strWrapper(strs, 10);

	for (int& refVal : intWrapper)
		refVal = rand() % 10;
	
	for (string& refStr : strWrapper)
		refStr = to_string(rand() % 10);

	cout << "\n\n===== 커스텀 range base for문 결과 (정수) =====\n";
	for (const int& val : intWrapper)
		cout << val << ", ";

	cout << "\n\n===== 커스텀 range base for문 결과 (문자열) =====\n";
	for (const string& str : strWrapper)
		cout << str << ", ";

	SAFE_DELETE_ARRAY(arr);
	SAFE_DELETE_ARRAY(strs);
}

void Parts_09::Algorithm()
{
	vector<int> valList;

	valList.resize(10);

	int i = 0;

	for (int& val : valList)
		val = ++i;

	auto lambda = [](int val) -> void { cout << val << ", ";  };

	cout << "===== for_each 함수를 통한 vector 함수 출력 =====\n";

	// iterator를 통한 원하는 범위 순회
	for_each(valList.begin(), valList.end(), lambda);

	valList.erase(valList.begin() + 2);

	cout << "\n\n===== 3번 째 원소 제거 후 vector 원소 출력 =====\n";
	for_each(valList.begin(), valList.end(), lambda);

	auto iteratorA = find(valList.begin(), valList.end(), 5);

	if (iteratorA != valList.end())
		valList.erase(iteratorA);

	cout << "\n\n===== 5 제거 후 vector 원소 출력 =====\n";
	for_each(valList.begin(), valList.end(), lambda);

	auto iteratorB = find_if(valList.begin(), valList.end(), [](int val) -> bool { return val <= 2;});

	while (iteratorB != valList.end())
	{
		valList.erase(iteratorB);
		iteratorB = find_if(valList.begin(), valList.end(), [](int val) -> bool { return val <= 2; });
	}

	cout << "\n\n===== 2 이하 제거 후 vector 원소 출력 =====\n";
	for_each(valList.begin(), valList.end(), lambda);

	// 퀵 정렬을 사용하는 sort와 다르게 stable_sort는 병합 정렬을 한다.
	// stable 안정 정렬을 지원, 퀵 소트는 불안정 정렬
	// 기존 상태를 보장하고 싶다면 안정 정렬을 사용해야 한다.
	sort(valList.begin(), valList.end(), [](int lhs, int rhs) -> bool { return lhs > rhs; });
	
	cout << "\n\n===== 내림차순 정렬 후 vector 원소 출력 =====\n";
	for_each(valList.begin(), valList.end(), lambda);
}

bool Parts_09::IsUniqueStr(const string& str)
{
	set<char> letterList;

	for (const auto& ch : str)
		letterList.insert(ch);

	return str.length() == letterList.size();
}
