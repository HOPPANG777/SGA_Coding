
#include "stdafx.h"
#include "Parts_08.h"

Parts_08::Parts_08()
{
	//Auto();
	//RangeBasedFor();
	//AutoPtr();
	//UniquePtr();
	//SharedPtr();
	//WeakPtr();
	//Lambda();
	MemFuncPtr();
}

void Parts_08::Auto()
{
	//auto 키워드는 컴파일러에게 타입을 추론 시키는 것이다.
	//초기화를 해주지 않는다면 형식을 추론할 수 없다.
	auto val1 = 10;
	auto val2 = 3.14f;
	auto str = "Hello, World!";
	
	cout << val1 << ", " << val2 << ", " << str << endl;
}

void Parts_08::RangeBasedFor()
{
	array<int, 5> arr = { 1, 2, 3, 4, 5 };

	cout << "===== Index 기반 for문 결과 =====\n";
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << ", ";

	//레퍼런스로 복사를 해온다면 원본으로 접근이 가능함.
	for (int& val : arr)
		val *= 2;

	cout << "\n\n===== 범위 기반 for문 결과 =====\n";
	for (const int& val : arr)
		cout << val << ", ";

	int matrix[5][5] = { 0 };
	cout << "\n\n===== 2차원 배열 범위 기반 for문 결과(원시 배열) =====\n";
	for (int(&row)[5] : matrix)
	{
		for (int elem : row)
			cout << elem << ", ";

		cout << endl;
	}

	array<array<int, 5>, 5> matrix2 = { 0 };
	cout << "\n\n===== 2차원 배열 범위 기반 for문 결과(array) =====\n";
	for (const auto& row : matrix2)
	{
		for (const auto& elem : row)
			cout << elem << ", ";

		cout << endl;
	}

	cout << endl;
}

void Parts_08::AutoPtr()
{
	using namespace Parts_08_SmartPointer;

	//smart pointer의 장점은 힙에서 관리되는 데이터를
	//스택에 책임을 옮김으로써, 자동으로 데이터 해제가 가능하게 해주는 것이다.

	auto_ptr<int> autoPtr(new int(10));
	*autoPtr = 20;

	cout << "autoPtr : " << autoPtr.get() << ", " << *autoPtr << "\n\n";

	int* otherPtr = new int;
	autoPtr.reset(otherPtr);
	*autoPtr = 30;
	cout << "otherPtr : " << autoPtr.get() << ", " << *otherPtr << "\n\n";

	int* otherPtr2 = autoPtr.release();
	cout << "otherPtr2 : " << otherPtr2 << ", " << *otherPtr2 << "\n\n";
	SAFE_DELETE(otherPtr2);

	//deprected 버려짐
	auto_ptr<Widget> ptr1(new Widget());
	auto_ptr<Widget> ptr2;

	cout << "\n===== auto_ptr 권한 위임 전 =====\n";
	if (ptr1.get() != nullptr)
		cout << "ptr1 객체가 권한을 가지고 있습니다!\n";
	if (ptr2.get() != nullptr)
		cout << "ptr2 객체가 권한을 가지고 있습니다!\n";

	ptr2 = ptr1;

	cout << "\n===== auto_ptr 권한 위임 후 =====\n";
	if (ptr1.get() != nullptr)
		cout << "ptr1 객체가 권한을 가지고 있습니다!\n";
	if (ptr2.get() != nullptr)
		cout << "ptr2 객체가 권한을 가지고 있습니다!\n";

	//이건 쓰면 안되는 형태이다.
	auto_ptr<Widget>* ptr = new auto_ptr<Widget>(new Widget());
}

void Parts_08::UniquePtr()
{
	using namespace Parts_08_SmartPointer;

	//unique_ptr<Widget> ptr1(new Widget());
	//auto를 Smart Pointer와 같이 쓸 수 있게 해주기 위한 형태
	//특정 자료형을 unique Pointer로 만들어서 반환해주는 형태.
	auto ptr1 = make_unique<Widget>();
	unique_ptr<Widget> ptr2;

	cout << "\n===== unique_ptr 권한 위임 전 =====\n";
	if (ptr1.get() != nullptr)
		cout << "ptr1 객체가 권한을 가지고 있습니다!\n";

	if (ptr2.get() != nullptr)
		cout << "ptr2 객체가 권한을 가지고 있습니다!\n";

	//복사 할당 연산자를 막아놨기 때문에,
	//명확히 move라는 키워드를 통해 이동 연산자를 사용하도록 함.
	ptr2 = move(ptr1);

	cout << "\n===== unique_ptr 권한 위임 후 =====\n";
	/*if (ptr1.get() != nullptr)
		cout << "ptr1 객체가 권한을 가지고 있습니다!\n";*/

	if (ptr2.get() != nullptr)
		cout << "ptr2 객체가 권한을 가지고 있습니다!\n";

	//unique_ptr<FILE, int(*)(FILE*)> wStreamPtr(fopen("Parts_08.txt", "wt"), &fclose);
	unique_ptr<FILE, decltype(&CloseFStream)> wStreamPtr(fopen("Parts_08.txt", "wt"), &CloseFStream);

	if (wStreamPtr.get() != nullptr)
		fprintf(wStreamPtr.get(), "Hello, World!\n");
}

void Parts_08::SharedPtr()
{
	using namespace Parts_08_SmartPointer;

	//shared_ptr<Widget> sharedPtr1(new Widget());
	auto sharedPtr1 = make_shared<Widget>();
	shared_ptr<Widget> sharedPtr2;

	cout << "\n===== sharedPtr2 할당 전 =====\n";
	cout << "Ref Count : " << sharedPtr1.use_count() << "\n";

	sharedPtr2 = sharedPtr1;

	cout << "\n===== sharedPtr2 할당 후 =====\n";
	cout << "Ref Count : " << sharedPtr1.use_count() << "\n";

	sharedPtr1.reset();

	cout << "\n===== sharedPtr1 참조 해제 후 =====\n";
	cout << "Ref Count : " << sharedPtr2.use_count() << "\n";

	shared_ptr<FILE> rStreamPtr(fopen("Parts_08.txt", "rt"), &Parts_08::CloseFStream);

	if (rStreamPtr.get() != nullptr)
	{
		char buffer[20] = { 0 };
		fgets(buffer, sizeof(buffer), rStreamPtr.get());
		cout << "\n===== Parts_08.txt 출력 =====\n";
		cout << buffer;
	}
}

void Parts_08::WeakPtr()
{
	using namespace Parts_08_WeakPtr;

	auto widgetPtr1 = make_shared<WidgetA>();
	auto widgetPtr2 = make_shared<WidgetB>();

	cout << "===== 초기 상태 =====\n";
	cout << "Ptr1 Ref Count : " << widgetPtr1.use_count() << '\n';
	cout << "Ptr2 Ref Count : " << widgetPtr2.use_count() << '\n';

	widgetPtr1->SetTarget(widgetPtr2);
	cout << "\n===== widgetPtr1 target widgetPtr2 =====\n";
	cout << "Ptr1 Ref Count : " << widgetPtr1.use_count() << '\n';
	cout << "Ptr2 Ref Count : " << widgetPtr2.use_count() << '\n';

	widgetPtr2->SetTarget(widgetPtr1);
	cout << "\n===== widgetPtr2 target widgetPtr1 =====\n";
	cout << "Ptr1 Ref Count : " << widgetPtr1.use_count() << '\n';
	cout << "Ptr2 Ref Count : " << widgetPtr2.use_count() << '\n';
}

void Parts_08::Lambda()
{
	/*
	//람다
	람다는 간단한 일회성 함수이며, 지역 함수이다.
	함수이면서 지역변수처럼 사용이 가능함.
	람다는 기본적으로 반환형을 적어주지 않는다면 void이다.
	람다는 자료형을 정해줄 수 없어, auto를 쓰는것이 맞다.

	람다의 형태는 [](){}이다.
	[]는 캡처절,
	()는 매개변수,
	{}는 본문
	반환형을 적어주고 싶다면, []()->반환형{} 이다.

	람다의 캡처절은 크게 두 가지가 있다.
	[] - 
	[=] - 값 형식의 캡처. 기본적으로 외부에 변수들을 사본으로 가져옴
	[a, b] - 적어준 변수만 캡처해옴
	[&] - 외부에 변수를 원본으로 캡처해옴
	[&, a] - 외부에 변수를 원본으로 가져오되, a만 사본으로 캡처해봄

	람다는 기본적으로 상수 사본으로 캡처를 해오며,
	만약 이 사본을 값을 변경하며 사용하려면, mutable 키워드를 사용해야한다.


	//함수자
	함수자란 간단한 함수를 구현해놓은 것이며,
	예를 들어 less 함수자의 경우,
	left가 right보다 작은 경우를 리턴하는 함수이다.
	greater 함수자의 경우
	right가 left보다 작은 경우를 리턴하는 함수이다.
	*/

	//RValue - 식이 끝나고 남아있지 않음.
	//LValue - 식이 끝나고 남아있음.

	cout << "===== 람다 선언&호출 결과 =====\n";
	[](int a, int b)
	{
		cout << a << " + " << b << " = " << a + b << '\n';
	}(10, 20);
	
	auto lambda1 = [](int a, int b)
	{
		cout << a << " + " << b << " = " << a + b << '\n';
	};

	cout << "\n===== 람다 선언 후 할당 및 재사용 결과 =====\n";
	lambda1(10, 20);
	lambda1(30, 40);

	int a = 0, b = 0;

	cout << "\n정수 (2개) 입력 : ";
	cin >> a >> b;
	
	auto lambda2 = [=]()
	{
		cout << a << " + " << b << " = " << a + b << '\n';
	};

	lambda2();

	auto lambda3 = [&a, &b]() // 레퍼런스를 이용하여 원본으로 가져옴
	{
		a *= 2;
		b *= 2;
	};

	lambda3();

	auto lambda4= [a, b]() mutable //현재 사본으로 가져온 a, b를 수정가능하게 함
	{
		a *= 2;
		b *= 2;
		cout << "\n===== 값 형식 캡처 결과 (mutable) =====\n";
		cout << "a : " << a << ", b : " << b << '\n';
	};

	lambda4();

	cout << "\n===== 값 형식 캡처 결과 =====\n";
	cout << "a : " << a << ", b : " << b << '\n';

	auto lambda5 = [a, b]() -> int
	{
		return a + b;
	};

	cout << "\n===== 람다 함수 반환 결과 =====\n";
	cout << a << " + " << b << " = " << lambda5() << '\n';

	auto lambda6 = GetLambda(10);
	
	cout << "\n===== 람다 반환 함수 반환 결과 =====\n";
	cout << 10 << " * " << 10 << " = " << lambda6() << '\n';

	srand((unsigned int)time(nullptr));

	array<int, 10> arr = { 0 };
	//typename - 반환형 매개변수
	function<int()> func = []() -> int { return rand() % 100; };
	InitArr(arr, func);

	function<void(const int&)> printLambda = [](const int& val) { cout << val << ", "; };

	cout << "\n===== 배열 정렬 전 =====\n";
	PrintArr(arr, printLambda);

	sort(arr.begin(), arr.end(), [](int a, int b) -> bool { return a < b; });
	sort(arr.begin(), arr.end(), less<int>());
	//sort(arr.begin(), arr.end());
	cout << "\n\n===== 배열 오름차순 정렬 후 =====\n";
	PrintArr(arr, printLambda);

	sort(arr.begin(), arr.end(), greater<int>());
	cout << "\n\n===== 배열 내림차순 정렬 후 =====\n";
	PrintArr(arr, printLambda);
}

void Parts_08::MemFuncPtr()
{
	using namespace Parts_08_MemFuncPtr;

	/*
	정적멤버함수의 경우 객체에 종속적이지 않기 때문에 일반함수와 비슷함.
	즉, 함수포인터를 사용하는데 어려움이 없음.
	*/

	Data data1(10);
	Data data2(20);

	cout << "===== 멤버 함수 직접 호출 결과 =====\n";
	data1.ShowInfo();
	data2.ShowInfo();

	auto memFuncA = &Data::ShowInfo;
	auto memFuncB = &Data::ShowInfo;

	cout << "\n===== 멤버 함수 포인터 호출 결과 =====\n";
	(data1.*memFuncA)();
	(data2.*memFuncB)();

	function<void(void)> FuncA = bind(&Data::ShowInfo, &data1);
	auto FuncB = bind(&Data::ShowInfo, &data2);

	auto FuncC = bind(&Data::GetPowerVal, &data1, 10);
	auto FuncD = bind(&Data::GetPowerVal, &data2, placeholders::_1);

	auto FuncE = bind(&Data::GetAvrVal, &data1, placeholders::_1, 30);
	auto FuncF = bind(&Data::GetAvrVal, &data1, 20, placeholders::_1);
	auto FuncG = bind(&Data::GetDivVal, &data1, placeholders::_1, placeholders::_2);

	cout << "\n===== function 객체를 통한 함수 호출 결과 =====\n";
	FuncA = bind(&Data::ShowInfo, &data2);
	FuncA();
	FuncB();

	cout << "\n10 ^ 2 : " << FuncC() << '\n';
	cout << "30 ^ 2 : " << FuncC(30) << '\n';

	cout << "\nFuncE 평균 : " << FuncE(10) << '\n';
	cout << "FuncF 평균 : " << FuncF(30) << '\n';
	cout << "FuncG 평균 : " << FuncG(1, 4) << '\n';
}

void Parts_08::CloseFStream(FILE* stream)
{
	cout << "\nCloseFStream() 호출!\n";
	fclose(stream);
}
