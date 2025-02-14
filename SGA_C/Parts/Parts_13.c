#include "stdafx.h"
#include "Parts_13.h"

void Parts_13()
{
	// TextIO();
	BinaryIO();
}

void TextIO()
{
	/*
	스트림 생성 모드
	w - write 쓰기가 가능한 모드
	r - 
	a

	데이터 입출력 모드
	t - 메모장 같은 텍스트 
	b - 이진 형태로 하겠다
	*/

	FILE* wStream = fopen("01.txt", "wt");

	if (wStream != NULL)
	{
		// fprintf(wStream, "Hello, World!\n");
		for (int i = 0; i < 10; ++i)
			fputs("Hello, World!\n", wStream);

		fseek(wStream, 0, SEEK_SET);
		fputs("Olleh", wStream);

		fseek(wStream, 2, SEEK_CUR);
		fputs("w", wStream);

		fseek(wStream, -3, SEEK_END);
		fputs("s", wStream);

		fclose(wStream);
	}
	else
	{
		printf("Write Stream Open Error!\n");

		return;
	}

	FILE* rStream = fopen("01.txt", "rt");

	if (rStream != NULL)
	{
		char string[100] = "";

		while (fgets(string, sizeof(string), rStream) != NULL)
			printf("%s", string);

		printf("%s", string);
		
		fclose(rStream);
	}
	else
	{
		printf("Read Stream Open Error!\n");

		return;
	}

	printf("\n");

	FILE* wrStream = fopen("02.txt", "r+t");

	if (wrStream != NULL)
	{
		for (int i = 0; i < 10; ++i)
			fputs("Hello, World!\n", wrStream);

		fseek(wrStream, 0, SEEK_SET);

		char string[100] = "";

		while (fgets(string, sizeof(string), wrStream) != NULL)
			printf("%s", string);

		printf("%s", string);

		fclose(wrStream);

		
	}
	else
	{
		printf("Write Read Stream Open Error!\n");
		
		return;
	}
}

void BinaryIO()
{
	FILE* wStream = fopen("01.bin", "wb");

	char buffer[20] = { "Hello, World!\n" };
	size_t elemCount = strlen(buffer);
	size_t repeatCount = 10;

	if (wStream != NULL)
	{
		for (int i = 0; i < repeatCount; ++i)
			fwrite(buffer, sizeof(buffer[0]), elemCount, wStream);

		int arr[20] = { 0 };
		const int len = sizeof(arr) / sizeof(arr[0]);

		for (int i = 0; i < len; ++i)
			arr[i] = i + 1;

		fwrite(arr, sizeof(arr[0]), len, wStream);

		fclose(wStream);
	}
	else
	{
		printf("Write Stream Open Error!\n");

		return;
	}

	FILE* rStream = fopen("01.bin", "rb");

	if (rStream != NULL)
	{
		char string[200] = "";
		fread(string, sizeof(string[0]), elemCount * repeatCount, rStream);
		printf("%s\n", string);

		int arr[20] = { 0 };
		const int len = sizeof(arr) / sizeof(arr[0]);

		fread(arr, sizeof(arr[0]), len, rStream);

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
