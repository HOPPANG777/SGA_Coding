#pragma once

namespace Parts_08_SmartPointer
{
	class Widget
	{
	public:
		Widget() { cout << "Widget::Widget() 생성자 호출!\n"; }
		~Widget() { cout << "\nWidget::~Widget() 소멸자 호출!\n"; }
	};
}

namespace Parts_08_WeakPtr
{
	//전방선언
	class WidgetB;

	class WidgetA
	{
	public:
		~WidgetA() { cout << "WidgetA::WidgetA() 소멸자 호출!\n"; }

	public:
		void SetTarget(shared_ptr<WidgetB> targetPtr)
		{
			this->targetPtr = targetPtr;
		}

		void ShowInfo() { cout << "WidgetA::ShowInfo() 함수 호출!\n"; }

	private:
		shared_ptr<WidgetB> targetPtr;
	};

	class WidgetB
	{
	public:
		~WidgetB() { cout << "WidgetB::WidgetB() 소멸자 호출!\n"; }

	public:
		void SetTarget(shared_ptr<WidgetA> targetPtr)
		{
			this->targetPtr = targetPtr;

			//뎅글링 포인트
			//해제된 공간을 관리하려고 한다면 문제가 난다.
			//weakPtr은 기본적으로 뎅글링 포인터를 감수하는 포인터 이며,
			//그렇기 떄문에 관리하고 있는 공간을 바로 들어가려 하려는 행위가 막혀있다.
			//lock을 통해서 유효성을 검사해야 한다. (뎅글링 포인터라면 nullptr을 반환.)
			if (this->targetPtr.lock() != nullptr)
				this->targetPtr.lock()->ShowInfo();
		}

	private:
		//shared_ptr<WidgetA> targetPtr;
		//weak_ptr는 shared_ptr이 사용될 때 순환을 막고자 보조용으로 쓰이는 것.
		//기본적으로 weakPtr은 관리하는 공간에 대해서 약한참조를 하기때문에
		//레퍼런스 카운팅이 증가하지 않는다.
		weak_ptr<WidgetA> targetPtr;
	};
}

namespace Parts_08_MemFuncPtr
{
	class Data
	{
	public:
		Data(int val) : val(val) {}

	public:
		void ShowInfo() const { cout << "Data::ShowInfo() : " << val << '\n'; }

		int GetPowerVal(int val) { return val * val; }
		float GetAvrVal(int val1, int val2) { return (val1 + val2) / 2.0f; }
		float GetDivVal(int val1, int val2) { return val1 / (float)val2; }

	private:
		int val = 0;
	};
}

class Parts_08
{
public:
	Parts_08();

private:
	void Auto();
	void RangeBasedFor();
	void AutoPtr();
	void UniquePtr();
	void SharedPtr();
	void WeakPtr();
	void Lambda();
	void MemFuncPtr();

private:
	static void CloseFStream(FILE* stream);

private:
	auto GetLambda(int val)
	{
		return [=]() -> int
		{
			return val * val;
		};
	}

	template <typename T, int SIZE>
	void InitArr(array<T, SIZE>& arr, const function<T()>& func)
	{
		for (auto& elem : arr)
			elem = func();
	}

	template <typename T, int SIZE>
	void PrintArr(array<T, SIZE>& arr, const function<void(const T&)>& func)
	{
		for (const auto& elem : arr)
			func(elem);
	}
};