#pragma once

#include <QString>

namespace FCCSConst
{
	enum emFreq
	{
		GongPing = 0,
		BianPing
	};

	enum emStyle
	{
		Rect = 0,
		Round
	};
}

typedef FCCSConst::emFreq freqType;
typedef FCCSConst::emStyle styleType;