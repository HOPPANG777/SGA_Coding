#pragma once

namespace Parts_05_ArrayListClass
{
	class ArrayList
	{
	public:
		int& operator[](const size_t& index) const { return arr[index];  }

		ArrayList& operator=(const ArrayList& other);

	public:
		//전위
		ArrayList& operator++(void) 
		{ 
			for (size_t i = 0; i < numElements; ++i)
				++arr[i];

			return *this;
		}

		//후위
		ArrayList operator++(int) 
		{ 
			ArrayList temp = *this;

			for (size_t i = 0; i < numElements; ++i)
				++arr[i];

			return temp;
		}

	public:
		//amartized O(1) 거의 1의 시간이 나온다는 뜻
		int* data() const { return arr; }
		size_t capacity() const { return cap; }
		size_t size() const { return numElements; }

	public:
		//안적을시 호출이 되며 0으로 취급함
		ArrayList(size_t capacity = 0);
		ArrayList(const ArrayList& other);
		~ArrayList();
	
	public:
		void reserve(size_t capacity);
		void push_back(int value);
		void Print();

	private:
		size_t cap = 0;
		size_t numElements = 0;

		int* arr = nullptr;
	};
}

//이미 완성되어 제공되는 클래스에 경우 전역으로 오버로딩이 가능함
ostream& operator<<(ostream& stream, const Parts_05_ArrayListClass::ArrayList& arr);

namespace Parts_05_PaintingProgram
{
	//enum은 unscoped 별도의 공간 구분이 안됨
	//enum class는 공간 구분이 가능
	enum class Menu
	{
		NONE = 0,
		ADD_LINE,
		ADD_TRIANGLE,
		ADD_RECTANGLE,
		PRESENT,
		EXIT,
		MAX_VALUE
	};

	enum class Color
	{
		NONE = -1,
		RED,
		GREEN,
		BLUE,
		MAX_VALUE
	};
	
	class Object
	{
	public:
		virtual ~Object() { cout << "~Object 소멸자 호출!\n"; }

	public:
		const char* GetColorStr() const;
		virtual void Render() = 0;

	//protected에 생성자가 있으므로써, 파생 클래스를 통해서만 사용 가능한 클래스가 됨.
	//추상 클래스와 비슷한 역할 이긴함.
	protected:
		Object(const Color& color) : color(color) { cout << "Object 생성자 호출!\n"; }

	protected:
		Color color = Color::NONE;
	};

	class Line : public Object
	{
	public:
		Line(const Color& color) : Object(color) { cout << "LineColor 생성자 호출!\n"; }
		~Line() override { cout << "~Line 소멸자 호출!\n"; }

	public:
		void Render() override;
	};
	
	class Triangle : public Object
	{
	public:
		Triangle(const Color& color) : Object(color) { cout << "TriangleColor 생성자 호출!\n"; }
		~Triangle() override { cout << "~Triangle 소멸자 호출!\n"; }

	public:
		void Render() override;
	};
	
	class Rrectangle : public Object
	{
	public:
		Rrectangle(const Color& color) : Object(color) { cout << "RrectangleColor 생성자 호출!\n"; }
		~Rrectangle() override { cout << "~Rrectangle 소멸자 호출!\n"; }

	public:
		void Render() override;
	};

	class Canvas
	{
	public:
		~Canvas();

	public:
		void AddObject(Object* objPtr) { objectList.push_back(objPtr); }
		void Present();

	private:
		vector<Object*> objectList;
	};
}

inline istream& operator>>(istream& stream, Parts_05_PaintingProgram::Menu& menu)
{
	int temp;
	
	//이렇게 기본 자료형도 기본 생성자 처럼 사용이 가능하다.
	//float f = float(temp);

	if (stream >> temp)
		menu = Parts_05_PaintingProgram::Menu(temp);
	else
	{
		stream.clear();
		while (stream.get() != '\n');
	}
	
	return stream;
}

class Parts_05
{
public:
	Parts_05();

private:
	void PrintArray(int* arr, size_t numElements);

public:
	void ArrayListClass();
	void PaintingProgram();

public:
	Parts_05_PaintingProgram::Object* CreateObject(Parts_05_PaintingProgram::Menu menu);
};