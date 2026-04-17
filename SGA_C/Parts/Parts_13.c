#include "stdafx.h"   // Visual Studio의 컴파일 속도를 높이기 위한 미리 컴파일된 헤더
#include "Parts_13.h" // 현재 파일의 함수 선언이 담긴 헤더 파일

// [메인 진입점]
void Parts_13()
{
	// TextIO();     // 텍스트 기반 입출력 테스트 (현재 주석 처리됨)
	BinaryIO();      // 이진 데이터 기반 입출력 테스트 (현재 실행 대상)
}

// ==========================================================
// [섹션 1: 텍스트 모드 입출력 (Text I/O)]
// 사람이 읽을 수 있는 문자열 형태로 데이터를 저장하는 방식
// ==========================================================
void TextIO()
{
	/*
	  [기초 지식: 스트림 생성 모드]
	  w (Write): 쓰기 모드. 파일이 없으면 만들고, 있으면 내용을 다 지우고 새로 씀.
	  r (Read): 읽기 모드. 파일이 반드시 있어야 함.
	  a (Append): 추가 모드. 파일 끝에 내용을 덧붙임.

	  [기초 지식: 데이터 형식 모드]
	  t (Text): 텍스트 모드. 줄바꿈(\n) 등을 운영체제에 맞춰 자동 변환함.
	  b (Binary): 이진 모드. 메모리 값을 있는 그대로 저장 (변환 없음).
	*/

	// "wt" = Write + Text (텍스트 쓰기 모드)
	FILE* wStream = fopen("01.txt", "wt");

	if (wStream != NULL) // 파일 열기에 성공했다면 (NULL이 아니면 성공)
	{
		// 1. 파일에 문자열 쓰기
		for (int i = 0; i < 10; ++i)
			fputs("Hello, World!\n", wStream); // 10줄을 씀

		/*
		  [기초 지식: fseek 함수]
		  파일 내부에는 '파일 위치 포인터(FP)'라는 커서가 있습니다.
		  fseek(파일스트림, 이동거리, 기준점);
		  - SEEK_SET: 파일의 맨 처음 (0번지)
		  - SEEK_CUR: 현재 커서 위치
		  - SEEK_END: 파일의 맨 끝
		*/

		// 맨 앞으로 가서 "Olleh" 쓰기 (기존 "Hell" 부분 덮어쓰기)
		fseek(wStream, 0, SEEK_SET);
		fputs("Olleh", wStream);

		// 현재 위치에서 2칸 뒤로 이동해서 "w" 쓰기
		fseek(wStream, 2, SEEK_CUR);
		fputs("w", wStream);

		// 맨 끝에서 3칸 앞으로(마이너스) 이동해서 "s" 쓰기
		fseek(wStream, -3, SEEK_END);
		fputs("s", wStream);

		fclose(wStream); // 파일 사용이 끝나면 반드시 닫아야 저장됨 (메모리 해제)
	}
	else
	{
		printf("Write Stream Open Error!\n");
		return;
	}

	// "rt" = Read + Text (텍스트 읽기 모드)
	FILE* rStream = fopen("01.txt", "rt");

	if (rStream != NULL)
	{
		char string[100] = "";

		// fgets: 한 줄씩 읽어서 string 배열에 저장 (파일 끝이면 NULL 반환)
		while (fgets(string, sizeof(string), rStream) != NULL)
			printf("%s", string);

		// 마지막 읽은 내용을 확인용으로 한 번 더 출력
		printf("%s", string);

		fclose(rStream);
	}
	else
	{
		printf("Read Stream Open Error!\n");
		return;
	}

	printf("\n");

	// "r+t" = Read + Write + Text (읽기와 쓰기가 동시에 가능한 모드)
	FILE* wrStream = fopen("02.txt", "r+t");

	if (wrStream != NULL)
	{
		for (int i = 0; i < 10; ++i)
			fputs("Hello, World!\n", wrStream);

		// 쓰기를 마친 후 커서가 파일 끝에 가 있으므로, 다시 맨 앞으로 이동해야 읽을 수 있음
		fseek(wrStream, 0, SEEK_SET);

		char string[100] = "";
		while (fgets(string, sizeof(string), wrStream) != NULL)
			printf("%s", string);

		printf("%s", string);

		fclose(wrStream);
	}
	else
	{
		// "r+"는 파일이 없으면 자동으로 만들지 않기 때문에 에러가 날 가능성이 높음
		printf("Write Read Stream Open Error!\n");
		return;
	}
}

// ==========================================================
// [섹션 2: 이진 모드 입출력 (Binary I/O)]
// 메모리의 비트 데이터를 그대로 파일에 옮겨 담는 방식
// ==========================================================
void BinaryIO()
{
	// "wb" = Write + Binary (이진 쓰기 모드)
	FILE* wStream = fopen("01.bin", "wb");

	char buffer[20] = { "Hello, World!\n" };
	size_t elemCount = strlen(buffer); // 문자열의 길이 (약 14글자)
	size_t repeatCount = 10;           // 반복 횟수

	if (wStream != NULL)
	{
		/*
		  [기초 지식: fwrite 함수]
		  fwrite(데이터주소, 데이터단위크기, 데이터개수, 스트림);
		*/
		for (int i = 0; i < repeatCount; ++i)
			// buffer에 들어있는 char(1바이트)들을 elemCount만큼 파일에 씀
			fwrite(buffer, sizeof(buffer[0]), elemCount, wStream);

		// 정수형 배열 저장 (이진 모드의 진가: 배열 통째로 저장)
		int arr[20] = { 0 };
		const int len = sizeof(arr) / sizeof(arr[0]); // 배열 요소 개수(20개) 계산

		for (int i = 0; i < len; ++i)
			arr[i] = i + 1; // 1, 2, 3... 20까지 대입

		// int형 데이터 20개를 한 번에 파일에 저장
		fwrite(arr, sizeof(arr[0]), len, wStream);

		fclose(wStream);
	}
	else
	{
		printf("Write Stream Open Error!\n");
		return;
	}

	// "rb" = Read + Binary (이진 읽기 모드)
	FILE* rStream = fopen("01.bin", "rb");

	if (rStream != NULL)
	{
		/*
		  [기초 지식: fread 함수]
		  fread(저장할주소, 데이터단위크기, 읽어올개수, 스트림);
		*/
		char string[200] = "";
		// 아까 쓴 문자열들을 한 번에 읽어옴
		fread(string, sizeof(string[0]), elemCount * repeatCount, rStream);
		printf("%s\n", string);

		// 정수 데이터 읽기
		int arr[20] = { 0 };
		const int len = sizeof(arr) / sizeof(arr[0]);

		// 파일 포인터는 앞에서 문자열을 읽은 만큼 뒤로 밀려나 있으므로, 
		// 이어서 바로 숫자를 읽어오면 정수 데이터가 딱 맞게 읽힘.
		fread(arr, sizeof(arr[0]), len, rStream);

		// 읽어온 숫자 배열 출력
		for (int i = 0; i < len; ++i)
			printf("%d, ", arr[i]);

		printf("\n");

		fclose(rStream);
	}
	else
	{
		printf("Read Stream Open Error!\n");
		return;
	}
}