#pragma once

/*
    템플릿의 특수화(Specialization)
    함수 템플릿 - 완전 특수화
    완전 특수화(Explicit(Full)Specialization)
    클래스 템플릿 -
    부분 특수화(Partial Specialization)
*/

namespace Parts_07_FuncTemplate
{
	struct Data
	{
		int a;
		float b;
	};

}

namespace Parts_07_LinkedListClassTemplate
{
	template <typename T>
	class LinkedList
	{
        struct Node
        {
            T val = T();
            Node* nextNode = nullptr;
        };

    public:
        LinkedList() = default;
        ~LinkedList() { Reset(); }
        LinkedList(const LinkedList& other) { *this = other; }
        LinkedList& operator=(const LinkedList& other)
        {
            Reset();

            Node* curNode = other.headNode;

            while (curNode != nullptr)
            {
                AddValue(curNode->val);
                curNode = curNode->nextNode;
            }

            return *this;
        }

    public:
        int GetNumValues() const { return numVals; }

    public:
        void Reset()
        {
            Node* curNode = headNode;

            while (curNode != nullptr)
            {
                Node* removeNode = curNode;
                curNode = curNode->nextNode;

                SAFE_DELETE(removeNode);
            }

            numVals = 0;
            headNode = nullptr;
            tailNode = nullptr;
        }

        void AddValue(T val)
        {
            Node* newNode = CreateNode(val);

            if (headNode == nullptr)
            {
                headNode = newNode;
                tailNode = headNode;
            }
            else
            {
                tailNode->nextNode = newNode;
                tailNode = newNode;
            }

            ++numVals;
        }

        T FindValue(int index)
        {
            return FindNode(index)->val;
        }

    private:
        Node* FindNode(int index)
        {
            Node* curNode = headNode;

            for (int i = 0; i < index; ++i)
                curNode = curNode->nextNode;

            return curNode;
        }

        Node* CreateNode(T val)
        {
            Node* node = new Node();
            node->val = val;

            return node;
        }

    private:
        int numVals = 0;
        Node* headNode = nullptr;
        Node* tailNode = nullptr;
	};
}

namespace Parts_07_SingletonClassTemplate
{
    template <typename T>
    class Singleton
    {
    public:
        static T* Get() 
        { 
            if (instance == nullptr)
                instance = new T();

            return instance;
        }

        static void Destroy()
        {
            SAFE_DELETE(instance);
        }

    protected:
        Singleton() { cout << "Singleton::Singleton() 생성자 호출!\n"; }
        virtual ~Singleton() { cout << "Singleton::~Singleton() 소멸자 호출!\n"; };
        Singleton(const Singleton& other) = delete;
        Singleton& operator=(const Singleton& other) = delete;

    private:
        static T* instance;
    };

    template <typename T>
    T* Singleton<T>::instance = nullptr;

    class Widget : public Singleton<Widget>
    {
        friend Singleton<Widget>;

    private:
        Widget() { cout << "Widget::Widget() 생성자 호출!\n"; }
        ~Widget() override { cout << "Widget::~Widget() 소멸자 호출!\n"; }

    public:
        void ShowInfo() { cout << "Widget::ShowInfo() 함수 호출!\n"; }
    };
}

namespace Parts_07_ClassTemplateSpecialization
{
    template <typename T1, typename T2>
    class Datas
    {
    public:
        Datas() { cout << "Datasint<T1, T2>::Datas() 생성자 호출!\n"; }

    private:
        T1 val1 = T1();
        T2 val2 = T2();
    };

    template <typename T>
    class Datas<int, T>
    {
    public:
        Datas() { cout << "Datasint<int, T>::Datas() 생성자 호출!\n"; }

    private:
        int val1 = 0;
        T val2 = T();
    };

    template <>
    class Datas<int, float>
    {
    public:
        Datas() { cout << "Datas<int, float>::Datas()생성자 호출!\n"; }

    private:
        int val1 = 0;
        float val2 = 0.0f;
    };
}

class Parts_07
{
public:
    Parts_07();
    template <typename T>
    void Swap(T& a, T& b);

    void FuncTemplate();
    void LinkedListClassTemplate();
    void SingletonClassTemplate();
    void ClassTemplateSpecialization();
};

template<typename T>
inline void Parts_07::Swap(T& a, T& b)
{
    T temp = b;
    b = a;
    a = temp;
}

template<>
inline void Parts_07::Swap(Parts_07_FuncTemplate::Data& data1, Parts_07_FuncTemplate::Data& data2)
{
    Swap<int>(data1.a, data2.a);
}

template <typename T, int SIZE = 10>
T* MakeArr(int size = SIZE)
{
    return new T[size];
}