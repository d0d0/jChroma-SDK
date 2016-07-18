
#ifndef _MOUSEMAT_H_
#define _MOUSEMAT_H_

#pragma once

#include <windows.h>
#include "SDK/RzChromaSDKTypes.h"
#include "structs.h"

class Mousemat {
	typedef RZRESULT(*SETEFFECT)(RZEFFECTID EffectId);
	typedef RZRESULT(*DELETEEFFECT)(RZEFFECTID EffectId);
	SETEFFECT SetEffect = NULL;
	DELETEEFFECT DeleteEffect = NULL;
public:
	Mousemat();
	~Mousemat();
	BOOL Initialize(HMODULE m_ChromaSDKModule);
	void ShowColor(COLORREF Color);
	void ShowLevel(UINT Hp, UINT Ammo);
	void ShowAlert(COLORREF Color);
	void ShowGauge(UINT Level);
	void ShowDamageEffect();
	void ResetEffects();
	void SetColors(const MousematColorStruct* colors, int numVal);
};

#endif