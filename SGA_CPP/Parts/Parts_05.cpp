#include "stdafx.h"
#include "Parts_05.h"

using namespace Parts_05_ArrayListClass;

Parts_05::Parts_05()
{
	//ArrayListClass();
	PaintingProgram();
}

void Parts_05::PrintArray(int* arr, size_t numElements)
{
	for (int i = 0; i < numElements - 1; ++i)
		cout << arr[i] << ", ";
	cout << arr[numElements - 1] << ", ";
	cout << '\n';
}

void Parts_05::ArrayListClass()
{
	//ArrayListClass
	//가변배열은 기존 원시배열의 유연성을 보완하고자 등장한 자료구조이다.

	ArrayList arr1;

	for (int i = 0; i < 10; ++i)
		arr1.push_back(i + 1);

	ArrayList arr2(arr1);
	ArrayList arr3;

	arr3 = arr1;

	
	cout << "===== 배열 리스트 1 원소 =====\n";
	//PrintArray(arr1.data(), arr1.size());
	arr1.Print();

	cout << "\n===== 배열 리스트 2 원소 =====\n";
	//PrintArray(arr2.data(), arr2.size());
	arr2.Print();

	cout << "\n===== 배열 리스트 2 원소 =====\n";
	//PrintArray(arr3.data(), arr3.size());
	arr3.Print();

	ArrayList arr;
	
	//효율을 위해 미리 넣을만큼 잡아둠
	arr.reserve(10);

	for (int i = 0; i < arr.capacity(); ++i)
		arr.push_back(i + 1);

	for (int i = 0; i < arr.size(); ++i)
		arr[i] *= 10;

	cout << "\n===== 배열 리스트 원소 =====\n";
	//arr.Print();
	cout << arr++;
	cout << "\n\n" << ++arr;
}


namespace Parts_05_ArrayListClass
{
	ArrayList& ArrayList::operator=(const ArrayList& other)
	{
		cap = other.cap;
		numElements = other.numElements;

		SAFE_DELETE_ARRAY(arr);

		arr = new int[cap];

		memcpy(arr, other.arr, sizeof(int) * cap);

		return *this;
	}

	ArrayList::ArrayList(size_t capacity)
		: cap(capacity)
	{
		if (0 == cap)
			return;

		arr = new int[cap];
		memset(arr, 0, sizeof(int) * cap);
	}

	ArrayList::ArrayList(const ArrayList& other)
	{
		*this = other;
	}

	ArrayList::~ArrayList()
	{
		SAFE_DELETE_ARRAY(arr);
	}

	void ArrayList::reserve(size_t capacity)
	{
		if (cap >= capacity) return;

		cap = capacity;

		int* newArr = (int*)realloc(arr, sizeof(int) * cap);
		if (newArr != nullptr)
		{
			arr = newArr;
			memset(arr + numElements, 0, sizeof(int) * (cap - numElements));
			newArr = nullptr;
		}
	}

	void ArrayList::push_back(int value)
	{
		if (numElements >= cap)
		{
			//최댓값을 구해주는 함수 max
			size_t newCap = max<size_t>(1, cap * 2);

			reserve(newCap);
		}
		arr[numElements++] = value;
	}

	void ArrayList::Print()
	{
		for (int i = 0; i < numElements - 1; ++i)
			cout << arr[i] << ", ";
		cout << arr[numElements - 1] << ", ";
		cout << '\n';
	}
}

ostream& operator<<(ostream& stream, const Parts_05_ArrayListClass::ArrayList& arr)
{
	for (size_t i = 0; i < arr.size() - 1; ++i)
		stream << arr[i] << ", ";

	stream << arr[arr.size() - 1];

	return stream;
}

void Parts_05::PaintingProgram()
{
	using namespace Parts_05_PaintingProgram;

	Menu menu = Menu::NONE;

	Canvas canvas;

	do
	{
		system("cls");
		cout << "===== 메뉴 =====\n";
		cout << "1. 선 추가\n";
		cout << "2. 삼각형 추가\n";
		cout << "3. 사각형 추가\n";
		cout << "4. 도형 그리기\n";
		cout << "5. 종료\n";

		cout << "\n메뉴 선택 : ";
		scanf("%d", &menu);

		switch (menu)
		{
		case Parts_05_PaintingProgram::Menu::ADD_LINE:
		case Parts_05_PaintingProgram::Menu::ADD_TRIANGLE:
		case Parts_05_PaintingProgram::Menu::ADD_RECTANGLE:
			canvas.AddObject(CreateObject(menu));
			cout << '\n';
			system("pause");
			break;
		case Parts_05_PaintingProgram::Menu::PRESENT:
			canvas.Present();
			system("pause");
			break;
		case Parts_05_PaintingProgram::Menu::EXIT:
			cout << "프로그램을 종료합니다.\n\n";
			break;
		default:
			cout << "잘못 입력하셨습니다. 1 ~ 5 사이의 정수 값을 입력하세요. \n\n";
			system("pause");
			break;
		}

	} while (menu != Menu::EXIT);
}

Parts_05_PaintingProgram::Object* Parts_05::CreateObject(Parts_05_PaintingProgram::Menu menu)
{
	using namespace Parts_05_PaintingProgram;

	//난수 생성기. 속도가 느림. 그래서 이걸로 뽑은걸로
	random_device random;
	//이 난수 생성기에 넣어서 시드 값으로 난수를 생성.
	mt19937 gen(random());
	//난수를 뽑을 때 형태를 정해줌. 여기선 1, 2, 3 중 균등한 확률 로 하나가 나오면 좋으니 균등분포로 뽑음.
	uniform_int_distribution<int> uniform(static_cast<int>(Color::RED), static_cast<int>(Color::BLUE));

	//균등분포로 뽑은 난수로 기본생성자 호출.
	Color color = Color(uniform(gen));

	switch (menu)
	{
	case Parts_05_PaintingProgram::Menu::ADD_LINE:
		return new Line(color);
		break;
	case Parts_05_PaintingProgram::Menu::ADD_TRIANGLE:
		return new Triangle(color);
		break;
	case Parts_05_PaintingProgram::Menu::ADD_RECTANGLE:
		return new Rrectangle(color);
		break;
	}
}

namespace Parts_05_PaintingProgram
{
	const char* Object::GetColorStr() const
	{
		static const char* colorStrs[] =
		{
			"빨간색",
			"녹색",
			"파란색"
		};

		//형변환으로 넣어줘야함
		return colorStrs[size_t(color)];
	}

	void Line::Render()
	{
		cout << GetColorStr() << " 선을 그린다\n\n";
	}

	void Triangle::Render() 
	{
		cout << GetColorStr() << " 삼각형을 그린다\n\n";
	}

	void Rrectangle::Render()
	{
		cout << GetColorStr() << " 사각형을을 그린다\n\n";
	}

	Canvas::~Canvas()
	{
		for (size_t i = 0; i < objectList.size(); ++i)
		{
			SAFE_DELETE(objectList[i]);
			cout << '\n';
		}
	}

	void Canvas::Present()
	{
		for (size_t i = 0; i < objectList.size(); ++i)
			objectList[i]->Render();
	}
}