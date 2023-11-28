#include<DxLib.h>
#include<cassert>
#include<iostream>
#include<fstream>
#include<cstdlib>


#include "Bg.h"

#include "Game.h"

namespace
{
	//マップチップの情報
	constexpr int kChipWidth = 32;
	constexpr int kChipHeight = 32;

	//チップを置く数
	constexpr int kChipNumX = Game::kScreenWidth / 2;
}

Bg::Bg()
{
}

Bg::~Bg()
{
}

void Bg::Init()
{
}

void Bg::Update()
{
}

void Bg::Draw() const
{
}
