#include "StringUtility.h"
#include <DxLib.h>
#include <cassert>

std::wstring
StringUtility::StringToWString(const std::string& str)
{
	//in:情報側はstring(あらかじめわかっている)
	//out:戻り値はwstring(文字列数もわからない)
	std::wstring ret;
	int result = MultiByteToWideChar(
		CP_UTF8,
		0,
		str.data(),
		str.length(),
		nullptr,
		0);
	assert(result >= 0);
	ret.resize(result);
	int result = MultiByteToWideChar(
		CP_UTF8,
		0,
		str.data(),
		str.length(),
		ret.data(),
		ret.size());

	return ret;
}