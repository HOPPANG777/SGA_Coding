#pragma once
// 중복된 헤더를 제외해주는 역할

#define _CRT_SECURE_NO_WARNINGS	// scanf경고 무시

// 언어의 표준 헤더
// std -> Standard Input Output(표준입출력) 헤더
#include <stdio.h>
// C언어 유틸리티 추가 Ex) system("pause"), system("cls")
#include <stdlib.h>		
// bool 추가해주는 헤더
#include <stdbool.h>	
// 문자열 관련 헤더
#include <string.h>		
// 시간, 날씨 관련 헤더
#include <time.h>		
// windows 콘솔창 관련 헤더
#include <Windows.h>	
// 
#include <assert.h>

#pragma warning(disable : 6031)	// scanf반환값 경고 무시

#define SAFE_FREE(p) if (p) { free(p); p = NULL; }
#define VALUE 30
