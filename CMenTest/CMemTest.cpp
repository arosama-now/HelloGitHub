/**
* @file CMemTest.cpp
* @brief メモリーリークテスト用
* @author 下浦　大和
* @date 2019/05/29
* @details  メモリリークをテストするために意図的に発生させています。
*/


#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <crtdbg.h>

// #include "pch.h"
#include <iostream>

#ifdef _DEBUG
#define DBG_NEW new (_NORMAL_BLOCK , __FILE__ , __LINE__)
#else
#define DBG_NEW new
#endif

struct PointData {
	int x;
	int y;
	int z;
};
struct CharacterData {
	char name[100];
	int hp;
	int mp;
};
/**
* @brief 食材を料理してくれます
* @param[in] にんじん、ジャガイモ、玉ねぎ、各種スパイス
* @param[out] カレー
* @return bool 常にtrueを返します
* @details ニンジンとジャガイモは一口大に切りetc...
*/
int main() {
	char *c = (char*)_alloca(100);
	char *b = (char*)_alloca(100);
	b = c;
	*b = 'a';
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//	_crtBreakAlloc = 160;
	PointData* pPointData = DBG_NEW PointData;

	for (int i = 0; i < 50; i++) {
		delete pPointData;
		pPointData = DBG_NEW PointData;
	}
	_RPT0(_CRT_WARN, "SetBreak Point");

	CharacterData* pCharacterData = DBG_NEW CharacterData;
	for (int i = 0; i < 50; i++) {
		delete pCharacterData;
		pCharacterData = DBG_NEW CharacterData;
	}
	delete pPointData;
	delete pCharacterData;
    
	_CrtDumpMemoryLeaks();

	return 0;
}