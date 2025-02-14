#pragma once

void Parts_10();

/*
	포인터란 무엇이냐 
	매우 단순하게 정의를 하자면 
	어떤 주소값을 저장하는 변수

*/

void Pointer();
void SwapByValue(int a, int b);
void SwapByPtr(int* a, int* b);

void InitializeArray();
// void InitArray(int a[]);
void InitArrayByPtr(int* arr, int len);

void PointerToPointer();
void SwapByP(int* ptr1, int* ptr2);
void SwapByPP(int** pp1, int** pp2);
