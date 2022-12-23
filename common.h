#pragma once

#include <fstream>
#include <iostream>
#include <cmath>
#include <Siv3D.hpp>
#include "data_generated.h"

using namespace std;
using Data::GetData_list;
using Data::Language;

typedef struct {
	String name;
	int32 hp;
	int32 ap;
	int32 dp;
	int32 speed;
	String name_id;
	String emoji;
} Monster;

typedef struct {
	String japanese_text;
	String english_text;
	String chinese_text;
} Text;

typedef struct {
	int32 hp;
	int32 ap;
	int32 dp;
} Player;

// 共有するデータ
struct GameData
{
	int32 score = 0;
	Array<Monster> monsters;
	HashTable<String, Text> texts;
	Language lang = Data::Language_Japanese;
	int32 selected_monster = 0;
	Player player;
};

String get_text(String id, Data::Language lang, HashTable<String, Text>& texts);

#define MAX_DIGIT 100000

using Data::GetData_list;
using Data::Language;

// 共有するデータの型を指定
using App = SceneManager<String, GameData>;
