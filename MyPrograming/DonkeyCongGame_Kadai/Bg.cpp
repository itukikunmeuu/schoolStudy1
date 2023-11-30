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
	constexpr int kChipNumX = Game::kScreenWidth / kChipWidth;
	constexpr int kChipNUmY = Game::kScreenHeight / kChipHeight;

	//マップチップの配置情報
	
}

Bg::Bg():
	m_handle(-1),
	m_graphChipNumX(0),
	m_graphChipNumY(0)
{
	//for (int y = 0; y < kChipNumY; y++)
	//{
	//	for (int x = 0; x < kChipNumX; x++)
	//	{
	//		m_chipData[y][x] = kChipData[y][x];
	//	}
	//}
}

Bg::~Bg()
{
}

void Bg::Init()
{
	//マップチップの数を数える
	int graphW;
	int graphH;
	GetGraphSize(m_handle, &graphW, &graphH);

	m_graphChipNumX = graphW / kChipWidth;
	m_graphChipNumY = graphW / kChipHeight;

	//マップチップは一データの読み込み
	
}

void Bg::Update()
{
}

void Bg::Draw() const
{
}
