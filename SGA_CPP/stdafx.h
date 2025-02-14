#pragma once

#define _CRT_SECURE_NO_WARNINGS

//C
#include <stdio.h>
#include <assert.h>

//C++
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <memory>
#include <functional>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>

#pragma warning(disable : 6031)

using namespace std;

#define SAFE_DELETE(p) { if(p) { delete(p); p = nullptr; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[](p); p = nullptr; } }
#define CALL_WITH_MAX(a, b) ((a) > (b) ? (a) : (b))

#define DECLARE_SINGLETON(CLASS_NAME)							\
private:														\
	CLASS_NAME();												\
	~CLASS_NAME();												\
	CLASS_NAME(const CLASS_NAME& other) = delete;				\
	CLASS_NAME& operator=(const CLASS_NAME& other) = delete;	\
public:															\
	static CLASS_NAME* Get()									\
	{															\
		static CLASS_NAME instance;								\
		return &instance;										\
	}