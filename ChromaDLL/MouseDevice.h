
#ifndef _MOUSE_DEVICE_H
#define _MOUSE_DEVICE_H

#pragma once
#include <windows.h>
#include "SDK/RzChromaSDKDefines.h"
#include "SDK/RzChromaSDKTypes.h"
#include "SDK/RzErrors.h"

class MouseDevice {
	typedef RZRESULT(*SETEFFECT)(RZEFFECTID EffectId);
	typedef RZRESULT(*DELETEEFFECT)(RZEFFECTID EffectId);
	SETEFFECT SetEffect = NULL;
	DELETEEFFECT DeleteEffect = NULL;
public:
	MouseDevice();
	~MouseDevice();
	BOOL Initialize(HMODULE m_ChromaSDKModule);
	void ShowLevel(UINT Hp, UINT Ammo);
	void ShowAlert(COLORREF Color);
	void ShowDamageEffect();
	void ResetEffects();
	static DWORD WINAPI Thread_LoadingAnimationOnMice(LPVOID lpParameter);
};

#endif // !_MOUSE_H


