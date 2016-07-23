#include "afx.h"
#include "ChromaSDKImpl.h"

#include <iostream>
#include "types.h"

#ifdef _WIN64
#define CHROMASDKDLL        _T("RzChromaSDK64.dll")
#else
#define CHROMASDKDLL        _T("RzChromaSDK.dll")
#endif

using namespace ChromaSDK;
using namespace ChromaSDK::Keyboard;
using namespace ChromaSDK::Keypad;
using namespace ChromaSDK::Mouse;
using namespace ChromaSDK::Mousepad;
using namespace ChromaSDK::Headset;

DWORD WINAPI Thread_LoadingAnimationOnKeyboard(LPVOID lpParameter)
{
	if (CreateKeyboardEffect)
	{
		// Loading animation
		ChromaSDK::Keyboard::CUSTOM_EFFECT_TYPE Effect = {};

		RZEFFECTID Frame0 = GUID_NULL;
		RZEFFECTID Frame1 = GUID_NULL;
		RZEFFECTID Frame2 = GUID_NULL;
		RZEFFECTID Frame3 = GUID_NULL;
		RZEFFECTID Frame4 = GUID_NULL;
		RZEFFECTID Frame5 = GUID_NULL;
		RZEFFECTID Frame6 = GUID_NULL;

		// Create the animation frames if not created
		CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_NONE, NULL, &Frame0);

		for (UINT r = 0; r < ChromaSDK::Keyboard::MAX_ROW; r++)
		{
			for (UINT c = 0; c < 3; c++)
			{
				Effect.Color[r][c] = ORANGE;
			}
		}

		CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_CUSTOM, &Effect, &Frame1);

		for (UINT r = 0; r < ChromaSDK::Keyboard::MAX_ROW; r++)
		{
			for (UINT c = 0; c < 6; c++)
			{
				Effect.Color[r][c] = ORANGE;
			}
		}

		CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_CUSTOM, &Effect, &Frame2);

		for (UINT r = 0; r < ChromaSDK::Keyboard::MAX_ROW; r++)
		{
			for (UINT c = 0; c < 9; c++)
			{
				Effect.Color[r][c] = ORANGE;
			}
		}

		CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_CUSTOM, &Effect, &Frame3);

		for (UINT r = 0; r < ChromaSDK::Keyboard::MAX_ROW; r++)
		{
			for (UINT c = 0; c < 12; c++)
			{
				Effect.Color[r][c] = ORANGE;
			}
		}

		CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_CUSTOM, &Effect, &Frame4);

		for (UINT r = 0; r < ChromaSDK::Keyboard::MAX_ROW; r++)
		{
			for (UINT c = 0; c < 15; c++)
			{
				Effect.Color[r][c] = ORANGE;
			}
		}

		CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_CUSTOM, &Effect, &Frame5);

		for (UINT r = 0; r < ChromaSDK::Keyboard::MAX_ROW; r++)
		{
			for (UINT c = 0; c < 18; c++)
			{
				Effect.Color[r][c] = ORANGE;
			}
		}

		CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_CUSTOM, &Effect, &Frame6);

		// Play the animation
		SetEffect(Frame0);
		Sleep(500);
		SetEffect(Frame1);
		Sleep(100);
		SetEffect(Frame2);
		Sleep(100);
		SetEffect(Frame3);
		Sleep(100);
		SetEffect(Frame4);
		Sleep(100);
		SetEffect(Frame5);
		Sleep(100);
		SetEffect(Frame6);
		Sleep(100);

		ChromaSDK::Keyboard::STATIC_EFFECT_TYPE StaticEffect = {};
		StaticEffect.Color = ORANGE;

		CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_STATIC, &StaticEffect, NULL);
	}

	return 0;
}

DWORD WINAPI Thread_LoadingAnimationOnKeypad(LPVOID lpParameter)
{
	RZDEVICEID DeviceId = GUID_NULL;
	PTSTR szDevice = (PTSTR)lpParameter;
	if (_tcsicmp(szDevice, _T("Orbweaver")) == 0)
	{
		DeviceId = ORBWEAVER_CHROMA;
	}
	else if (_tcsicmp(szDevice, _T("Tartarus")) == 0)
	{
		DeviceId = TARTARUS_CHROMA;
	}

	if (CreateKeypadEffect)
	{
		ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE Effect = {};

		RZEFFECTID Frame0 = GUID_NULL;
		RZEFFECTID Frame1 = GUID_NULL;
		RZEFFECTID Frame2 = GUID_NULL;
		RZEFFECTID Frame3 = GUID_NULL;
		RZEFFECTID Frame4 = GUID_NULL;
		RZEFFECTID Frame5 = GUID_NULL;

		if (DeviceId == ORBWEAVER_CHROMA)    // Create effects for Orbweaver)
		{
			CreateEffect(DeviceId, ChromaSDK::CHROMA_NONE, NULL, &Frame0);

			for (UINT i = 0; i < 1; i++)
			{
				for (UINT j = 0; j < ChromaSDK::Keypad::MAX_ROW; j++)
				{
					Effect.Color[j][i] = ORANGE;
				}
			}

			CreateEffect(DeviceId, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame1);

			for (UINT i = 0; i < 2; i++)
			{
				for (UINT j = 0; j < ChromaSDK::Keypad::MAX_ROW; j++)
				{
					Effect.Color[j][i] = ORANGE;
				}
			}

			CreateEffect(DeviceId, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame2);

			for (UINT i = 0; i < 3; i++)
			{
				for (UINT j = 0; j < ChromaSDK::Keypad::MAX_ROW; j++)
				{
					Effect.Color[j][i] = ORANGE;
				}
			}

			CreateEffect(DeviceId, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame3);

			for (UINT i = 0; i < 4; i++)
			{
				for (UINT j = 0; j < ChromaSDK::Keypad::MAX_ROW; j++)
				{
					Effect.Color[j][i] = ORANGE;
				}
			}

			CreateEffect(DeviceId, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame4);

			for (UINT i = 0; i < 5; i++)
			{
				for (UINT j = 0; j < ChromaSDK::Keypad::MAX_ROW; j++)
				{
					Effect.Color[j][i] = ORANGE;
				}
			}

			CreateEffect(DeviceId, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame5);
		}
		else if (DeviceId == TARTARUS_CHROMA)    // Create effect for Tartarus
		{
			CreateEffect(DeviceId, ChromaSDK::CHROMA_NONE, NULL, &Frame0);

			Effect.Color[0][0] = RGB((255.0 / 100.0*0.2), ((165.0 / 100.0)*0.2), 00);     // Orange with 20% brightness

			CreateEffect(DeviceId, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame1);

			Effect.Color[0][0] = RGB((255.0 / 100.0*0.4), ((165.0 / 100.0)*0.4), 00);     // Orange with 40% brightness

			CreateEffect(DeviceId, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame2);

			Effect.Color[0][0] = RGB((255.0 / 100.0*0.6), ((165.0 / 100.0)*0.6), 00);     // Orange with 60% brightness

			CreateEffect(DeviceId, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame3);

			Effect.Color[0][0] = RGB((255.0 / 100.0*0.8), ((165.0 / 100.0)*0.8), 00);     // Orange with 80% brightness

			CreateEffect(DeviceId, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame4);

			Effect.Color[0][0] = ORANGE;                                            // Orange with 100% brightness

			CreateEffect(DeviceId, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame5);
		}

		// Play the animation
		SetEffect(Frame0);
		Sleep(500);
		SetEffect(Frame1);
		Sleep(100);
		SetEffect(Frame2);
		Sleep(100);
		SetEffect(Frame3);
		Sleep(100);
		SetEffect(Frame4);
		Sleep(100);
		SetEffect(Frame5);
	}

	return 0;
}

struct _ActiveKeysData
{
	UINT numKeys;
	UINT Key[20];
	COLORREF Color;
} ActiveKeysData;

DWORD WINAPI Thread_AnimateActiveKeysOnKeyboard(LPVOID lpParameter)
{
	Keyboard::CUSTOM_KEY_EFFECT_TYPE Effect = {};

	// Fill up the key effects.
	for (UINT i = 0; i < ActiveKeysData.numKeys; i++)
	{
		COLORREF Color = 0x01000000 | ActiveKeysData.Color;

		switch (ActiveKeysData.Key[i])
		{
		case 0x41: Effect.Key[HIBYTE(RZKEY_A)][LOBYTE(RZKEY_A)] = Color; break;
		case 0x42: Effect.Key[HIBYTE(RZKEY_B)][LOBYTE(RZKEY_B)] = Color; break;
		case 0x43: Effect.Key[HIBYTE(RZKEY_C)][LOBYTE(RZKEY_C)] = Color; break;
		case 0x44: Effect.Key[HIBYTE(RZKEY_D)][LOBYTE(RZKEY_D)] = Color; break;
		case 0x45: Effect.Key[HIBYTE(RZKEY_E)][LOBYTE(RZKEY_E)] = Color; break;
		case 0x46: Effect.Key[HIBYTE(RZKEY_F)][LOBYTE(RZKEY_F)] = Color; break;
		case 0x47: Effect.Key[HIBYTE(RZKEY_G)][LOBYTE(RZKEY_G)] = Color; break;
		case 0x48: Effect.Key[HIBYTE(RZKEY_H)][LOBYTE(RZKEY_H)] = Color; break;
		case 0x49: Effect.Key[HIBYTE(RZKEY_I)][LOBYTE(RZKEY_I)] = Color; break;
		case 0x4A: Effect.Key[HIBYTE(RZKEY_J)][LOBYTE(RZKEY_J)] = Color; break;
		case 0x4B: Effect.Key[HIBYTE(RZKEY_K)][LOBYTE(RZKEY_K)] = Color; break;
		case 0x4C: Effect.Key[HIBYTE(RZKEY_L)][LOBYTE(RZKEY_L)] = Color; break;
		case 0x4D: Effect.Key[HIBYTE(RZKEY_M)][LOBYTE(RZKEY_M)] = Color; break;
		case 0x4E: Effect.Key[HIBYTE(RZKEY_N)][LOBYTE(RZKEY_N)] = Color; break;
		case 0x4F: Effect.Key[HIBYTE(RZKEY_O)][LOBYTE(RZKEY_O)] = Color; break;
		case 0x50: Effect.Key[HIBYTE(RZKEY_P)][LOBYTE(RZKEY_P)] = Color; break;
		case 0x51: Effect.Key[HIBYTE(RZKEY_Q)][LOBYTE(RZKEY_Q)] = Color; break;
		case 0x52: Effect.Key[HIBYTE(RZKEY_R)][LOBYTE(RZKEY_R)] = Color; break;
		case 0x53: Effect.Key[HIBYTE(RZKEY_S)][LOBYTE(RZKEY_S)] = Color; break;
		case 0x54: Effect.Key[HIBYTE(RZKEY_T)][LOBYTE(RZKEY_T)] = Color; break;
		case 0x55: Effect.Key[HIBYTE(RZKEY_U)][LOBYTE(RZKEY_U)] = Color; break;
		case 0x56: Effect.Key[HIBYTE(RZKEY_V)][LOBYTE(RZKEY_V)] = Color; break;
		case 0x57: Effect.Key[HIBYTE(RZKEY_W)][LOBYTE(RZKEY_W)] = Color; break;
		case 0x58: Effect.Key[HIBYTE(RZKEY_X)][LOBYTE(RZKEY_X)] = Color; break;
		case 0x59: Effect.Key[HIBYTE(RZKEY_Y)][LOBYTE(RZKEY_Y)] = Color; break;
		case 0x5A: Effect.Key[HIBYTE(RZKEY_Z)][LOBYTE(RZKEY_Z)] = Color; break;
		case VK_LCONTROL: Effect.Key[HIBYTE(RZKEY_LCTRL)][LOBYTE(RZKEY_LCTRL)] = Color; break;
		case VK_LSHIFT: Effect.Key[HIBYTE(RZKEY_LSHIFT)][LOBYTE(RZKEY_LSHIFT)] = Color; break;
		case VK_SPACE: Effect.Key[HIBYTE(RZKEY_SPACE)][LOBYTE(RZKEY_SPACE)] = Color; break;
		case VK_ESCAPE: Effect.Key[HIBYTE(RZKEY_ESC)][LOBYTE(RZKEY_ESC)] = Color; break;
		case VK_RETURN: Effect.Key[HIBYTE(RZKEY_ENTER)][LOBYTE(RZKEY_ENTER)] = Color; break;
		case VK_UP: Effect.Key[HIBYTE(RZKEY_UP)][LOBYTE(RZKEY_UP)] = Color; break;
		case VK_DOWN: Effect.Key[HIBYTE(RZKEY_DOWN)][LOBYTE(RZKEY_DOWN)] = Color; break;
		case VK_LEFT: Effect.Key[HIBYTE(RZKEY_LEFT)][LOBYTE(RZKEY_LEFT)] = Color; break;
		case VK_RIGHT: Effect.Key[HIBYTE(RZKEY_RIGHT)][LOBYTE(RZKEY_RIGHT)] = Color; break;
		}
	}

	CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM_KEY, &Effect, NULL);

	Sleep(50);

	// Create a waterfall effect
	for (int i = 0; i < Keyboard::MAX_ROW + 3; i++)
	{
		ZeroMemory(Effect.Color, sizeof(Effect.Color));

		for (int row = 0; row < Keyboard::MAX_ROW; row++)
		{
			for (int col = 0; col < Keyboard::MAX_COLUMN; col++)
			{
				if ((i == row) && (i < Keyboard::MAX_ROW))
				{
					Effect.Color[row][col] = RGB(GetRValue(ORANGE),
						GetGValue(ORANGE),
						GetBValue(ORANGE));
				}

				if ((i - 1) == row)
				{
					Effect.Color[row][col] = RGB(0.3 * GetRValue(ORANGE),
						0.3 * GetGValue(ORANGE),
						0.3 * GetBValue(ORANGE));
				}

				if ((i - 2) == row)
				{
					Effect.Color[row][col] = RGB(0.1 * GetRValue(ORANGE),
						0.1 * GetGValue(ORANGE),
						0.1 * GetBValue(ORANGE));
				}
			}
		}

		CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM_KEY, &Effect, NULL);

		Sleep(50);
	}

	return 0;
}

CChromaSDKImpl::CChromaSDKImpl() :m_ChromaSDKModule(NULL)
{
}

CChromaSDKImpl::~CChromaSDKImpl()
{
}

BOOL CChromaSDKImpl::Initialize()
{
	if (m_ChromaSDKModule == NULL)
	{
		m_ChromaSDKModule = LoadLibrary(CHROMASDKDLL);
		if (m_ChromaSDKModule == NULL)
		{
			ASSERT(GetLastError() == ERROR_SUCCESS);
			return FALSE;
		}
	}

	if (Init == NULL)
	{
		RZRESULT Result = RZRESULT_INVALID;
		Init = (INIT)GetProcAddress(m_ChromaSDKModule, "Init");
		if (Init)
		{
			Result = Init();
			if (Result == RZRESULT_SUCCESS)
			{
				CreateEffect = (CREATEEFFECT)GetProcAddress(m_ChromaSDKModule, "CreateEffect");
				CreateKeyboardEffect = (CREATEKEYBOARDEFFECT)GetProcAddress(m_ChromaSDKModule, "CreateKeyboardEffect");
				CreateHeadsetEffect = (CREATEHEADSETEFFECT)GetProcAddress(m_ChromaSDKModule, "CreateHeadsetEffect");
				CreateKeypadEffect = (CREATEKEYPADEFFECT)GetProcAddress(m_ChromaSDKModule, "CreateKeypadEffect");
				SetEffect = (SETEFFECT)GetProcAddress(m_ChromaSDKModule, "SetEffect");
				DeleteEffect = (DELETEEFFECT)GetProcAddress(m_ChromaSDKModule, "DeleteEffect");
				QueryDevice = (QUERYDEVICE)GetProcAddress(m_ChromaSDKModule, "QueryDevice");

				if (CreateEffect &&
					CreateKeyboardEffect &&
					mouseDevice.Initialize(m_ChromaSDKModule) &&
					CreateHeadsetEffect &&
					mousemat.Initialize(m_ChromaSDKModule) &&
					CreateKeypadEffect &&
					SetEffect &&
					DeleteEffect &&
					QueryDevice)
				{
					return TRUE;
				}
				else
				{
					return FALSE;
				}
			}
		}
	}

	return TRUE;
}

BOOL CChromaSDKImpl::UnInitialize()
{
	if (m_ChromaSDKModule != NULL)
	{
		RZRESULT Result = RZRESULT_INVALID;
		UNINIT UnInit = (UNINIT)GetProcAddress(m_ChromaSDKModule, "UnInit");
		if (UnInit)
		{
			Result = UnInit();
			ASSERT(Result == RZRESULT_SUCCESS);
		}

		FreeLibrary(m_ChromaSDKModule);
		m_ChromaSDKModule = NULL;

		return TRUE;
	}

	return FALSE;
}

void CChromaSDKImpl::PlayLoadingAnimation(UINT DeviceType) {
	HANDLE hWorkerThread = NULL;
	switch (DeviceType)
	{
	case 1:
		hWorkerThread = CreateThread(NULL, 0, Thread_LoadingAnimationOnKeyboard, this, 0, NULL);
		CloseHandle(hWorkerThread);
		break;
	case 2:
		hWorkerThread = CreateThread(NULL, 0, Mousemat::Thread_LoadingAnimationOnMousepad, this, 0, NULL);
		CloseHandle(hWorkerThread);
		break;
	case 3:
		hWorkerThread = CreateThread(NULL, 0, MouseDevice::Thread_LoadingAnimationOnMice, this, 0, NULL);
		CloseHandle(hWorkerThread);
		break;
	case 4:
		break;
	case 5:
		hWorkerThread = CreateThread(NULL, 0, Thread_LoadingAnimationOnKeypad, _T("Orbweaver"), 0, NULL);
		CloseHandle(hWorkerThread);
		hWorkerThread = CreateThread(NULL, 0, Thread_LoadingAnimationOnKeypad, _T("Tartarus"), 0, NULL);
		CloseHandle(hWorkerThread);
		break;
	}
}

void CChromaSDKImpl::ShowKeys(UINT DeviceType, UINT NumKeys, UINT VKey[], COLORREF Color, BOOL Animate)
{
	RZRESULT Result = RZRESULT_INVALID;

	switch (DeviceType)
	{
	case 1:
		if (CreateKeyboardEffect)
		{
			//ChromaSDK::Keyboard::CUSTOM_KEY_EFFECT_TYPE Effect = {};

			//for(UINT i=0; i<NumKeys; i++)
			//{
			//    Color = 0x01000000 | Color;
			//    switch(VKey[i])
			//    {
			//    case 0x41: Effect.Key[HIBYTE(RZKEY_A)][LOBYTE(RZKEY_A)] = Color; break;
			//    case 0x42: Effect.Key[HIBYTE(RZKEY_B)][LOBYTE(RZKEY_B)] = Color; break;
			//    case 0x43: Effect.Key[HIBYTE(RZKEY_C)][LOBYTE(RZKEY_C)] = Color; break;
			//    case 0x44: Effect.Key[HIBYTE(RZKEY_D)][LOBYTE(RZKEY_D)] = Color; break;
			//    case 0x45: Effect.Key[HIBYTE(RZKEY_E)][LOBYTE(RZKEY_E)] = Color; break;
			//    case 0x46: Effect.Key[HIBYTE(RZKEY_F)][LOBYTE(RZKEY_F)] = Color; break;
			//    case 0x47: Effect.Key[HIBYTE(RZKEY_G)][LOBYTE(RZKEY_G)] = Color; break;
			//    case 0x48: Effect.Key[HIBYTE(RZKEY_H)][LOBYTE(RZKEY_H)] = Color; break;
			//    case 0x49: Effect.Key[HIBYTE(RZKEY_I)][LOBYTE(RZKEY_I)] = Color; break;
			//    case 0x4A: Effect.Key[HIBYTE(RZKEY_J)][LOBYTE(RZKEY_J)] = Color; break;
			//    case 0x4B: Effect.Key[HIBYTE(RZKEY_K)][LOBYTE(RZKEY_K)] = Color; break;
			//    case 0x4C: Effect.Key[HIBYTE(RZKEY_L)][LOBYTE(RZKEY_L)] = Color; break;
			//    case 0x4D: Effect.Key[HIBYTE(RZKEY_M)][LOBYTE(RZKEY_M)] = Color; break;
			//    case 0x4E: Effect.Key[HIBYTE(RZKEY_N)][LOBYTE(RZKEY_N)] = Color; break;
			//    case 0x4F: Effect.Key[HIBYTE(RZKEY_O)][LOBYTE(RZKEY_O)] = Color; break;
			//    case 0x50: Effect.Key[HIBYTE(RZKEY_P)][LOBYTE(RZKEY_P)] = Color; break;
			//    case 0x51: Effect.Key[HIBYTE(RZKEY_Q)][LOBYTE(RZKEY_Q)] = Color; break;
			//    case 0x52: Effect.Key[HIBYTE(RZKEY_R)][LOBYTE(RZKEY_R)] = Color; break;
			//    case 0x53: Effect.Key[HIBYTE(RZKEY_S)][LOBYTE(RZKEY_S)] = Color; break;
			//    case 0x54: Effect.Key[HIBYTE(RZKEY_T)][LOBYTE(RZKEY_T)] = Color; break;
			//    case 0x55: Effect.Key[HIBYTE(RZKEY_U)][LOBYTE(RZKEY_U)] = Color; break;
			//    case 0x56: Effect.Key[HIBYTE(RZKEY_V)][LOBYTE(RZKEY_V)] = Color; break;
			//    case 0x57: Effect.Key[HIBYTE(RZKEY_W)][LOBYTE(RZKEY_W)] = Color; break;
			//    case 0x58: Effect.Key[HIBYTE(RZKEY_X)][LOBYTE(RZKEY_X)] = Color; break;
			//    case 0x59: Effect.Key[HIBYTE(RZKEY_Y)][LOBYTE(RZKEY_Y)] = Color; break;
			//    case 0x5A: Effect.Key[HIBYTE(RZKEY_Z)][LOBYTE(RZKEY_Z)] = Color; break;
			//    case VK_LCONTROL: Effect.Color[HIBYTE(RZKEY_LCTRL)][LOBYTE(RZKEY_LCTRL)] = Color; break;
			//    case VK_LSHIFT: Effect.Key[HIBYTE(RZKEY_LSHIFT)][LOBYTE(RZKEY_LSHIFT)] = Color; break;
			//    case VK_SPACE: Effect.Key[HIBYTE(RZKEY_SPACE)][LOBYTE(RZKEY_SPACE)] = Color; break;
			//    case VK_ESCAPE: Effect.Key[HIBYTE(RZKEY_ESC)][LOBYTE(RZKEY_ESC)] = Color; break;
			//    case VK_UP: Effect.Key[HIBYTE(RZKEY_UP)][LOBYTE(RZKEY_UP)] = Color; break;
			//    case VK_DOWN: Effect.Key[HIBYTE(RZKEY_DOWN)][LOBYTE(RZKEY_DOWN)] = Color; break;
			//    case VK_LEFT: Effect.Key[HIBYTE(RZKEY_LEFT)][LOBYTE(RZKEY_LEFT)] = Color; break;
			//    case VK_RIGHT: Effect.Key[HIBYTE(RZKEY_RIGHT)][LOBYTE(RZKEY_RIGHT)] = Color; break;
			//    }
			//}

			//Result = CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_CUSTOM_KEY, &Effect, NULL);

			//ASSERT(Result == RZRESULT_SUCCESS);

			ActiveKeysData.numKeys = NumKeys;

			ActiveKeysData.Color = Color;

			memcpy_s(ActiveKeysData.Key,
				sizeof(ActiveKeysData.Key),
				VKey,
				(sizeof(VKey) * NumKeys));

			if (Animate == TRUE)
			{
				HANDLE hThread = CreateThread(NULL, 0, Thread_AnimateActiveKeysOnKeyboard, NULL, 0, NULL);
				if (WaitForSingleObject(hThread, 5000) == WAIT_OBJECT_0)
				{
					CloseHandle(hThread);
				}
			}
			else
			{
				Keyboard::CUSTOM_KEY_EFFECT_TYPE Effect = {};

				// Fill up the key effects.
				for (UINT i = 0; i < ActiveKeysData.numKeys; i++)
				{
					COLORREF Color = 0x01000000 | ActiveKeysData.Color;

					switch (ActiveKeysData.Key[i])
					{
					case 0x41: Effect.Key[HIBYTE(RZKEY_A)][LOBYTE(RZKEY_A)] = Color; break;
					case 0x42: Effect.Key[HIBYTE(RZKEY_B)][LOBYTE(RZKEY_B)] = Color; break;
					case 0x43: Effect.Key[HIBYTE(RZKEY_C)][LOBYTE(RZKEY_C)] = Color; break;
					case 0x44: Effect.Key[HIBYTE(RZKEY_D)][LOBYTE(RZKEY_D)] = Color; break;
					case 0x45: Effect.Key[HIBYTE(RZKEY_E)][LOBYTE(RZKEY_E)] = Color; break;
					case 0x46: Effect.Key[HIBYTE(RZKEY_F)][LOBYTE(RZKEY_F)] = Color; break;
					case 0x47: Effect.Key[HIBYTE(RZKEY_G)][LOBYTE(RZKEY_G)] = Color; break;
					case 0x48: Effect.Key[HIBYTE(RZKEY_H)][LOBYTE(RZKEY_H)] = Color; break;
					case 0x49: Effect.Key[HIBYTE(RZKEY_I)][LOBYTE(RZKEY_I)] = Color; break;
					case 0x4A: Effect.Key[HIBYTE(RZKEY_J)][LOBYTE(RZKEY_J)] = Color; break;
					case 0x4B: Effect.Key[HIBYTE(RZKEY_K)][LOBYTE(RZKEY_K)] = Color; break;
					case 0x4C: Effect.Key[HIBYTE(RZKEY_L)][LOBYTE(RZKEY_L)] = Color; break;
					case 0x4D: Effect.Key[HIBYTE(RZKEY_M)][LOBYTE(RZKEY_M)] = Color; break;
					case 0x4E: Effect.Key[HIBYTE(RZKEY_N)][LOBYTE(RZKEY_N)] = Color; break;
					case 0x4F: Effect.Key[HIBYTE(RZKEY_O)][LOBYTE(RZKEY_O)] = Color; break;
					case 0x50: Effect.Key[HIBYTE(RZKEY_P)][LOBYTE(RZKEY_P)] = Color; break;
					case 0x51: Effect.Key[HIBYTE(RZKEY_Q)][LOBYTE(RZKEY_Q)] = Color; break;
					case 0x52: Effect.Key[HIBYTE(RZKEY_R)][LOBYTE(RZKEY_R)] = Color; break;
					case 0x53: Effect.Key[HIBYTE(RZKEY_S)][LOBYTE(RZKEY_S)] = Color; break;
					case 0x54: Effect.Key[HIBYTE(RZKEY_T)][LOBYTE(RZKEY_T)] = Color; break;
					case 0x55: Effect.Key[HIBYTE(RZKEY_U)][LOBYTE(RZKEY_U)] = Color; break;
					case 0x56: Effect.Key[HIBYTE(RZKEY_V)][LOBYTE(RZKEY_V)] = Color; break;
					case 0x57: Effect.Key[HIBYTE(RZKEY_W)][LOBYTE(RZKEY_W)] = Color; break;
					case 0x58: Effect.Key[HIBYTE(RZKEY_X)][LOBYTE(RZKEY_X)] = Color; break;
					case 0x59: Effect.Key[HIBYTE(RZKEY_Y)][LOBYTE(RZKEY_Y)] = Color; break;
					case 0x5A: Effect.Key[HIBYTE(RZKEY_Z)][LOBYTE(RZKEY_Z)] = Color; break;
					case VK_LCONTROL: Effect.Key[HIBYTE(RZKEY_LCTRL)][LOBYTE(RZKEY_LCTRL)] = Color; break;
					case VK_LSHIFT: Effect.Key[HIBYTE(RZKEY_LSHIFT)][LOBYTE(RZKEY_LSHIFT)] = Color; break;
					case VK_SPACE: Effect.Key[HIBYTE(RZKEY_SPACE)][LOBYTE(RZKEY_SPACE)] = Color; break;
					case VK_ESCAPE: Effect.Key[HIBYTE(RZKEY_ESC)][LOBYTE(RZKEY_ESC)] = Color; break;
					case VK_RETURN: Effect.Key[HIBYTE(RZKEY_ENTER)][LOBYTE(RZKEY_ENTER)] = Color; break;
					case VK_UP: Effect.Key[HIBYTE(RZKEY_UP)][LOBYTE(RZKEY_UP)] = Color; break;
					case VK_DOWN: Effect.Key[HIBYTE(RZKEY_DOWN)][LOBYTE(RZKEY_DOWN)] = Color; break;
					case VK_LEFT: Effect.Key[HIBYTE(RZKEY_LEFT)][LOBYTE(RZKEY_LEFT)] = Color; break;
					case VK_RIGHT: Effect.Key[HIBYTE(RZKEY_RIGHT)][LOBYTE(RZKEY_RIGHT)] = Color; break;
					}
				}

				CreateKeyboardEffect(Keyboard::CHROMA_CUSTOM_KEY, &Effect, NULL);
			}
		}
		break;
	case 5:
		if (CreateKeypadEffect)
		{
			ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE Effect = {};

			for (UINT i = 0; i < NumKeys; i++)
			{
				switch (VKey[i])
				{
				case 0x41: Effect.Color[2][1] = Color; break;
				case 0x44: Effect.Color[2][3] = Color; break;
				case 0x53: Effect.Color[2][2] = Color; break;
				case 0x57: Effect.Color[1][2] = Color; break;
				}
			}

			Result = CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_CUSTOM, &Effect, NULL);

			ASSERT(Result == RZRESULT_SUCCESS);
		}
		break;
	}
}

void CChromaSDKImpl::ShowLevel(UINT DeviceType, UINT Hp, UINT Ammo)
{
	switch (DeviceType)
	{
	case 1:
		if (CreateKeyboardEffect)
		{
			RZRESULT Result = RZRESULT_INVALID;
			ChromaSDK::Keyboard::CUSTOM_KEY_EFFECT_TYPE Effect = {};

			// Function keys as health
			UINT RemainingHealth = UINT(Hp / 100.0 * 12.0); // 12 function keys

			COLORREF HpColor = RGB((((12 - RemainingHealth) / 12.0) * 255), ((RemainingHealth / 12.0) * 255), 0);

			UINT HpLevel = ChromaSDK::Keyboard::RZKEY_F1;
			for (UINT i = 0; i < RemainingHealth; i++)
			{
				// F1 key starts from row 0, column 3 to column column 15
				Effect.Key[HIBYTE(HpLevel + i)][LOBYTE(HpLevel + i)] = 0x01000000 | HpColor;
			}

			// Number keys as ammo
			UINT RemainingAmmo = UINT(Ammo / 100.0 * 10.0); // 10 number keys

			UINT AmmoLevel = ChromaSDK::Keyboard::RZKEY_1;
			for (UINT i = 0; i < RemainingAmmo; i++)
			{
				// Number keys starts from row 1, column 2 to column 12
				Effect.Key[HIBYTE(AmmoLevel + i)][LOBYTE(AmmoLevel + i)] = 0x01000000 | YELLOW;
			}

			Result = CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_CUSTOM_KEY, &Effect, NULL);

			ASSERT(Result == RZRESULT_SUCCESS);
		}
		break;
	case 2:
		mousemat.ShowLevel(Hp, Ammo);
		break;
	case 3:
		mouseDevice.ShowLevel(Hp, Ammo);
		break;
	case 4:
		if (CreateHeadsetEffect)
		{
			ChromaSDK::Headset::STATIC_EFFECT_TYPE Effect = {};
			Effect.Color = RGB((255 - ((Hp / 100.0) * 255.0)), ((Hp / 100.0) * 255.0), 0);

			CreateHeadsetEffect(ChromaSDK::Headset::CHROMA_STATIC, &Effect, NULL);
		}
		break;
	case 5:
		if (CreateKeypadEffect)
		{
			ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE Effect = {};

			FLOAT RemainingHealth = FLOAT((FLOAT)Hp / 100.0 * 5.0); // 5 keys.

			COLORREF HpColor = RGB((((5 - RemainingHealth) / 5.0) * 255), ((RemainingHealth / 5.0) * 255), 0);

			// Display Hp on keypads.
			for (UINT i = 0; i < RemainingHealth; i++)
			{
				Effect.Color[0][i] = HpColor;
			}

			UINT RemainingAmmo = UINT(Ammo / 100.0 * 5.0); // 5 keys.

			// Display ammo/mana on the last row.
			for (UINT i = 0; i < RemainingAmmo; i++)
			{
				Effect.Color[3][i] = YELLOW;
			}

			CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_CUSTOM, &Effect, NULL);
		}
		break;
	}
}

void CChromaSDKImpl::ShowAlert(UINT DeviceType, COLORREF Color)
{
	RZEFFECTID Alert = GUID_NULL;
	RZEFFECTID NoAlert = GUID_NULL;

	switch (DeviceType)
	{
	case 1:
		if (CreateKeyboardEffect)
		{
			//ChromaSDK::Keyboard::STATIC_EFFECT_TYPE StaticEffect = {};
			//StaticEffect.Color = Color;

			//CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_STATIC, &StaticEffect, &Alert);

			// Custom effect type does not have transitions between colors.
			ChromaSDK::Keyboard::CUSTOM_EFFECT_TYPE Effect = {};
			for (UINT row = 0; row < ChromaSDK::Keyboard::MAX_ROW; row++)
			{
				for (UINT col = 0; col < ChromaSDK::Keyboard::MAX_COLUMN; col++)
				{
					Effect.Color[row][col] = Color;
				}
			}

			CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_CUSTOM, &Effect, &Alert);

			CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_NONE, NULL, &NoAlert);

			for (UINT t = 0; t < 3; t++)
			{
				SetEffect(Alert);
				Sleep(200);

				SetEffect(NoAlert);
				Sleep(200);
			}

			DeleteEffect(Alert);
			DeleteEffect(NoAlert);
		}
		break;
	case 2:
		mousemat.ShowAlert(Color);
		break;
	case 3:
		mouseDevice.ShowAlert(Color);
		break;
	case 4:
		if (CreateHeadsetEffect)
		{
			ChromaSDK::Headset::STATIC_EFFECT_TYPE Effect = {};
			Effect.Color = Color;

			CreateHeadsetEffect(ChromaSDK::Headset::CHROMA_STATIC, &Effect, &Alert);
			CreateHeadsetEffect(ChromaSDK::Headset::CHROMA_NONE, NULL, &NoAlert);

			for (UINT t = 0; t < 3; t++)
			{
				SetEffect(Alert);
				Sleep(200);

				SetEffect(NoAlert);
				Sleep(200);
			}

			DeleteEffect(Alert);
			DeleteEffect(NoAlert);
		}
		break;
	case 5:
		if (CreateKeypadEffect)
		{
			ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE Effect = {};

			CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_NONE, NULL, &NoAlert);

			for (UINT i = 0; i < ChromaSDK::Keypad::MAX_ROW; i++)
			{
				for (UINT j = 0; j < ChromaSDK::Keypad::MAX_COLUMN; j++)
				{
					Effect.Color[i][j] = Color;
				}
			}

			CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_CUSTOM, &Effect, &Alert);

			for (UINT t = 0; t < 3; t++)
			{
				SetEffect(Alert);
				Sleep(200);

				SetEffect(NoAlert);
				Sleep(200);
			}
		}
		break;
	}
}

void CChromaSDKImpl::ShowGauge(UINT DeviceType, UINT Level)
{
	switch (DeviceType)
	{
	case 1:
		if (CreateKeyboardEffect)
		{
			RZRESULT Result = RZRESULT_INVALID;

			UINT Gauge = UINT(Level / 100.0 * 18.0);

			ChromaSDK::Keyboard::CUSTOM_EFFECT_TYPE Effect = {};
			switch (Gauge)
			{
			case 0:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = BLACK;
				break;
			case 1:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = BLACK;
				break;
			case 2:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = BLACK;
				break;
			case 3:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = BLACK;
				break;
			case 4:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = BLACK;
				break;
			case 5:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = BLACK;
				break;
			case 6:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = BLACK;
				break;
			case 7:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = BLACK;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = BLACK;
				break;
			case 8:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = BLACK;
				break;
			case 9:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = GREY;
				break;
			case 10:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = GREY;
				break;
			case 11:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = GREY;
				break;
			case 12:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = GREY;
				break;
			case 13:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = GREY;
				break;
			case 14:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = GREY;
				break;
			case 15:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = GREY;
				break;
			case 16:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = GREY;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = GREY;
				break;
			case 17:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = GREY;
				break;
			case 18:
				Effect.Color[HIBYTE(RZKEY_NUMPAD8)][LOBYTE(RZKEY_NUMPAD8)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD9)][LOBYTE(RZKEY_NUMPAD9)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD6)][LOBYTE(RZKEY_NUMPAD6)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD3)][LOBYTE(RZKEY_NUMPAD3)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD2)][LOBYTE(RZKEY_NUMPAD2)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD1)][LOBYTE(RZKEY_NUMPAD1)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD4)][LOBYTE(RZKEY_NUMPAD4)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD7)][LOBYTE(RZKEY_NUMPAD7)] = YELLOW;
				Effect.Color[HIBYTE(RZKEY_NUMPAD5)][LOBYTE(RZKEY_NUMPAD5)] = YELLOW;
				break;
			}

			Result = CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_CUSTOM, &Effect, NULL);

			ASSERT(Result == RZRESULT_SUCCESS);
		}
		break;
	case 2:
		mousemat.ShowGauge(Level);
		break;
	case 5:
		if (CreateKeypadEffect)
		{
			ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE Effect = {};

			UINT Gauge = UINT(Level / 100.0 * 14.0);

			switch (Gauge)
			{
			case 1:
				Effect.Color[0][0] = YELLOW;
				break;
			case 2:
				Effect.Color[0][0] = YELLOW;
				Effect.Color[0][1] = YELLOW;
				break;
			case 3:
				Effect.Color[0][0] = YELLOW;
				Effect.Color[0][1] = YELLOW;
				Effect.Color[0][2] = YELLOW;
				break;
			case 4:
				Effect.Color[0][0] = YELLOW;
				Effect.Color[0][1] = YELLOW;
				Effect.Color[0][2] = YELLOW;
				Effect.Color[0][3] = YELLOW;
				break;
			case 5:
				Effect.Color[0][0] = YELLOW;
				Effect.Color[0][1] = YELLOW;
				Effect.Color[0][2] = YELLOW;
				Effect.Color[0][3] = YELLOW;
				Effect.Color[0][4] = YELLOW;
				break;
			case 6:
				Effect.Color[0][0] = YELLOW;
				Effect.Color[0][1] = YELLOW;
				Effect.Color[0][2] = YELLOW;
				Effect.Color[0][3] = YELLOW;
				Effect.Color[0][4] = YELLOW;
				Effect.Color[1][4] = YELLOW;
				break;
			case 7:
				Effect.Color[0][0] = YELLOW;
				Effect.Color[0][1] = YELLOW;
				Effect.Color[0][2] = YELLOW;
				Effect.Color[0][3] = YELLOW;
				Effect.Color[0][4] = YELLOW;
				Effect.Color[1][4] = YELLOW;
				Effect.Color[2][4] = YELLOW;
				break;
			case 8:
				Effect.Color[0][0] = YELLOW;
				Effect.Color[0][1] = YELLOW;
				Effect.Color[0][2] = YELLOW;
				Effect.Color[0][3] = YELLOW;
				Effect.Color[0][4] = YELLOW;
				Effect.Color[1][4] = YELLOW;
				Effect.Color[2][4] = YELLOW;
				Effect.Color[3][4] = YELLOW;
				break;
			case 9:
				Effect.Color[0][0] = YELLOW;
				Effect.Color[0][1] = YELLOW;
				Effect.Color[0][2] = YELLOW;
				Effect.Color[0][3] = YELLOW;
				Effect.Color[0][4] = YELLOW;
				Effect.Color[1][4] = YELLOW;
				Effect.Color[2][4] = YELLOW;
				Effect.Color[3][4] = YELLOW;
				Effect.Color[3][3] = YELLOW;
				break;
			case 10:
				Effect.Color[0][0] = YELLOW;
				Effect.Color[0][1] = YELLOW;
				Effect.Color[0][2] = YELLOW;
				Effect.Color[0][3] = YELLOW;
				Effect.Color[0][4] = YELLOW;
				Effect.Color[1][4] = YELLOW;
				Effect.Color[2][4] = YELLOW;
				Effect.Color[3][4] = YELLOW;
				Effect.Color[3][3] = YELLOW;
				Effect.Color[3][2] = YELLOW;
				break;
			case 11:
				Effect.Color[0][0] = YELLOW;
				Effect.Color[0][1] = YELLOW;
				Effect.Color[0][2] = YELLOW;
				Effect.Color[0][3] = YELLOW;
				Effect.Color[0][4] = YELLOW;
				Effect.Color[1][4] = YELLOW;
				Effect.Color[2][4] = YELLOW;
				Effect.Color[3][4] = YELLOW;
				Effect.Color[3][3] = YELLOW;
				Effect.Color[3][2] = YELLOW;
				Effect.Color[3][1] = YELLOW;
				break;
			case 12:
				Effect.Color[0][0] = YELLOW;
				Effect.Color[0][1] = YELLOW;
				Effect.Color[0][2] = YELLOW;
				Effect.Color[0][3] = YELLOW;
				Effect.Color[0][4] = YELLOW;
				Effect.Color[1][4] = YELLOW;
				Effect.Color[2][4] = YELLOW;
				Effect.Color[3][4] = YELLOW;
				Effect.Color[3][3] = YELLOW;
				Effect.Color[3][2] = YELLOW;
				Effect.Color[3][1] = YELLOW;
				Effect.Color[3][0] = YELLOW;
				break;
			case 13:
				Effect.Color[0][0] = YELLOW;
				Effect.Color[0][1] = YELLOW;
				Effect.Color[0][2] = YELLOW;
				Effect.Color[0][3] = YELLOW;
				Effect.Color[0][4] = YELLOW;
				Effect.Color[1][4] = YELLOW;
				Effect.Color[2][4] = YELLOW;
				Effect.Color[3][4] = YELLOW;
				Effect.Color[3][3] = YELLOW;
				Effect.Color[3][2] = YELLOW;
				Effect.Color[3][1] = YELLOW;
				Effect.Color[3][0] = YELLOW;
				Effect.Color[2][0] = YELLOW;
				break;
			case 14:
				Effect.Color[0][0] = YELLOW;
				Effect.Color[0][1] = YELLOW;
				Effect.Color[0][2] = YELLOW;
				Effect.Color[0][3] = YELLOW;
				Effect.Color[0][4] = YELLOW;
				Effect.Color[1][4] = YELLOW;
				Effect.Color[2][4] = YELLOW;
				Effect.Color[3][4] = YELLOW;
				Effect.Color[3][3] = YELLOW;
				Effect.Color[3][2] = YELLOW;
				Effect.Color[3][1] = YELLOW;
				Effect.Color[3][0] = YELLOW;
				Effect.Color[2][0] = YELLOW;
				Effect.Color[1][0] = YELLOW;
				break;
			}

			CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_CUSTOM, &Effect, NULL);
		}
		break;
	}
}

void CChromaSDKImpl::ShowBitmap(UINT DeviceType, HBITMAP hBitmap)
{
	HWND hDesktopWin = GetDesktopWindow();
	HDC hDesktopDC = ::GetDC(hDesktopWin);
	if (hDesktopDC)
	{
		HDC hDestDC = ::CreateCompatibleDC(hDesktopDC);

		::SelectObject(hDestDC, hBitmap);

		BITMAP bm;
		::GetObject(hBitmap, sizeof(bm), &bm);

		BITMAPINFOHEADER bmi = { 0 };
		bmi.biSize = sizeof(BITMAPINFOHEADER);
		bmi.biPlanes = bm.bmPlanes;
		bmi.biBitCount = bm.bmBitsPixel;

		if (DeviceType == 1)
		{
			bmi.biWidth = ChromaSDK::Keyboard::MAX_COLUMN;
			bmi.biHeight = ChromaSDK::Keyboard::MAX_ROW;
		}
		else if (DeviceType == 5)
		{
			bmi.biWidth = ChromaSDK::Keypad::MAX_COLUMN;
			bmi.biHeight = ChromaSDK::Keypad::MAX_ROW;
		}

		bmi.biCompression = BI_RGB;
		bmi.biSizeImage = 0;

		BYTE *pBits = NULL;
		pBits = (BYTE*)malloc(4 * bmi.biWidth * bmi.biHeight);
		ZeroMemory(pBits, (4 * bmi.biWidth * bmi.biHeight));

		if ((DeviceType == 1) && CreateKeyboardEffect)
		{
			ChromaSDK::Keyboard::CUSTOM_EFFECT_TYPE Effect = {};
			for (UINT i = 0; i < ChromaSDK::Keyboard::MAX_ROW; i++)
			{
				// Get ths RGB bits for each row
				::GetDIBits(hDestDC, hBitmap, i, 1, pBits, (BITMAPINFO*)&bmi, DIB_RGB_COLORS);

				COLORREF *pColor = (COLORREF*)pBits;

				for (UINT j = 0; j < ChromaSDK::Keyboard::MAX_COLUMN; j++)
				{
					// Fill up the array
					Effect.Color[i][j] = RGB(GetBValue(*pColor), GetGValue(*pColor), GetRValue(*pColor));
					pColor++;
				}
			}

			// Set the effect
			CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_CUSTOM, &Effect, NULL);
		}
		else if ((DeviceType == 5) && CreateKeypadEffect)
		{
			ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE Effect = {};
			for (UINT i = 0; i < ChromaSDK::Keypad::MAX_ROW; i++)
			{
				// Get ths RGB bits for each row
				::GetDIBits(hDestDC, hBitmap, i, 1, pBits, (BITMAPINFO*)&bmi, DIB_RGB_COLORS);

				COLORREF *pColor = (COLORREF*)pBits;

				for (UINT j = 0; j < ChromaSDK::Keypad::MAX_COLUMN; j++)
				{
					// Fill up the array
					Effect.Color[i][j] = RGB(GetBValue(*pColor), GetGValue(*pColor), GetRValue(*pColor));
					pColor++;
				}
			}

			// Set the effect
			CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_CUSTOM, &Effect, NULL);
		}

		free(pBits);

		// Free memories.
		::DeleteDC(hDestDC);

		::ReleaseDC(hDesktopWin, hDesktopDC);
	}
}

void CChromaSDKImpl::ShowDamageEffect(UINT DeviceType)
{
	switch (DeviceType)
	{
	case 1:
		if (CreateKeyboardEffect)
		{
			RZRESULT Result = RZRESULT_INVALID;
			ChromaSDK::Keyboard::STATIC_EFFECT_TYPE HitEffect = {};
			HitEffect.Color = RED;

			// Flash red quickly
			CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_STATIC, &HitEffect, NULL);
			Sleep(50);
			CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_NONE, NULL, NULL);
		}
		break;
	case 2:
		mousemat.ShowDamageEffect();
		break;
	case 3:
		mouseDevice.ShowDamageEffect();
		break;
	case 4:
		if (CreateHeadsetEffect)
		{
			ChromaSDK::Headset::STATIC_EFFECT_TYPE Effect = {};
			Effect.Color = RED;

			CreateHeadsetEffect(ChromaSDK::Headset::CHROMA_STATIC, &Effect, NULL);
			Sleep(50);
			CreateHeadsetEffect(ChromaSDK::Headset::CHROMA_NONE, NULL, NULL);
		}
		break;
	}
}

void CChromaSDKImpl::ShowColor(UINT DeviceType, COLORREF Color)
{
	switch (DeviceType)
	{
	case 1:
		if (CreateKeyboardEffect)
		{
			//// Static effect type have transition between colors.
			//ChromaSDK::Keyboard::STATIC_EFFECT_TYPE Effect = {};
			//Effect.Color = Color;

			//RZRESULT Result = CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_STATIC, &Effect, NULL);

			// Custom effect type does not have transitions between colors.
			ChromaSDK::Keyboard::CUSTOM_EFFECT_TYPE Effect = {};
			for (UINT row = 0; row < ChromaSDK::Keyboard::MAX_ROW; row++)
			{
				for (UINT col = 0; col < ChromaSDK::Keyboard::MAX_COLUMN; col++)
				{
					Effect.Color[row][col] = Color;
				}
			}

			RZRESULT Result = CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_CUSTOM, &Effect, NULL);

			ASSERT(Result == RZRESULT_SUCCESS);
		}
		break;
	case 2:
		mousemat.ShowColor(Color);
		break;
	case 4:
		if (CreateHeadsetEffect)
		{
			ChromaSDK::Headset::STATIC_EFFECT_TYPE Effect = {};
			Effect.Color = Color;

			RZRESULT Result = CreateHeadsetEffect(ChromaSDK::Headset::CHROMA_STATIC, &Effect, NULL);

			ASSERT(Result == RZRESULT_SUCCESS);
		}
		break;
	case 5:
		if (CreateKeypadEffect)
		{
			ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE Effect = {};

			for (UINT i = 0; i < ChromaSDK::Keypad::MAX_ROW; i++)
			{
				for (UINT j = 0; j < ChromaSDK::Keypad::MAX_COLUMN; j++)
				{
					Effect.Color[i][j] = Color;
				}
			}

			RZRESULT Result = CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_CUSTOM, &Effect, NULL);

			ASSERT(Result == RZRESULT_SUCCESS);
		}
		break;
	}
}

void CChromaSDKImpl::SetBreathingMode(UINT DeviceType, const BreathingEffectStruct* breathingEffectStruct) {
	switch (DeviceType) {
	case 1:
	    // TODO: Keyboard
		break;
	case 2:
		mousemat.SetBreathing(breathingEffectStruct);
		break;
	case 3:
	    // TODO: Mouse
		break;
	case 4:
	    // TODO: Headset
		break;
	case 5:
	    // TODO: Keypad
		break;
	}
}

void CChromaSDKImpl::ResetEffects(UINT DeviceType)
{
	switch (DeviceType)
	{
	case 0:
		if (CreateKeyboardEffect)
		{
			CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_NONE, NULL, NULL);
		}

		mousemat.ResetEffects();

		mouseDevice.ResetEffects();

		if (CreateHeadsetEffect)
		{
			CreateHeadsetEffect(ChromaSDK::Headset::CHROMA_NONE, NULL, NULL);
		}

		if (CreateKeypadEffect)
		{
			CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_NONE, NULL, NULL);
		}
		break;
	case 1:
		if (CreateKeyboardEffect)
		{
			CreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_NONE, NULL, NULL);
		}
		break;
	case 2:
		mousemat.ResetEffects();
		break;
	case 3:
		mouseDevice.ResetEffects();
		break;
	case 4:
		if (CreateHeadsetEffect)
		{
			CreateHeadsetEffect(ChromaSDK::Headset::CHROMA_NONE, NULL, NULL);
		}
		break;
	case 5:
		if (CreateKeypadEffect)
		{
			CreateKeypadEffect(ChromaSDK::Keypad::CHROMA_NONE, NULL, NULL);
		}
		break;
	}
}

BOOL CChromaSDKImpl::IsDeviceConnected(RZDEVICEID DeviceId)
{
	if (QueryDevice != NULL)
	{
		ChromaSDK::DEVICE_INFO_TYPE DeviceInfo = {};
		RZRESULT Result = QueryDevice(DeviceId, DeviceInfo);

		ASSERT(Result == RZRESULT_SUCCESS);

		return DeviceInfo.Connected;
	}

	return FALSE;
}

void CChromaSDKImpl::SetColors(const MousematColorStruct* colors, int numVal) {
	mousemat.SetColors(colors, numVal);
}