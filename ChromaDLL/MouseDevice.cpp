#include "MouseDevice.h"

using namespace ChromaSDK;
using namespace ChromaSDK::Mouse;

typedef RZRESULT(*CREATEMOUSEEFFECT)(ChromaSDK::Mouse::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);


CREATEMOUSEEFFECT CreateMouseEffect = NULL;

MouseDevice::MouseDevice()
{
}


MouseDevice::~MouseDevice()
{
}

BOOL MouseDevice::Initialize(HMODULE m_ChromaSDKModule)
{
	CreateMouseEffect = (CREATEMOUSEEFFECT)GetProcAddress(m_ChromaSDKModule, "CreateMouseEffect");
	if (CreateMouseEffect) {

		return TRUE;
	}

	return FALSE;
}

void MouseDevice::ShowLevel(UINT Hp, UINT Ammo) {
	if (CreateMouseEffect) {
		ChromaSDK::Mouse::CUSTOM_EFFECT_TYPE Effect = {};

		UINT RemainingHealth = UINT(Hp / 100.0 * 7.0); // 7 LEDs on the left.

		COLORREF HpColor = RGB((((5 - RemainingHealth) / 5.0) * 255), ((RemainingHealth / 5.0) * 255), 0);

		// Display Hp on the left side of the mouse.
		for (UINT i = 0; i < RemainingHealth; i++)
		{
			Effect.Color[RZLED_SIDE_STRIP7 - i] = HpColor;
		}

		UINT RemainingAmmo = UINT(Ammo / 100.0 * 7.0); // 7 LEDs on the right.

													   // Display ammo/mana on the right side of the mouse.
		for (UINT i = 0; i < RemainingAmmo; i++)
		{
			Effect.Color[RZLED_SIDE_STRIP14 - i] = RGB(255, 255, 0);
		}

		CreateMouseEffect(ChromaSDK::Mouse::CHROMA_CUSTOM, &Effect, NULL);
	}
}

void MouseDevice::ShowAlert(COLORREF Color) {
	if (CreateMouseEffect) {
		RZEFFECTID Alert = GUID_NULL;
		RZEFFECTID NoAlert = GUID_NULL;

		ChromaSDK::Mouse::CUSTOM_EFFECT_TYPE2 CustomEffect = {};
		for (int i = 0; i < Mouse::MAX_ROW; i++)
		{
			for (int j = 0; j < Mouse::MAX_COLUMN; j++)
			{
				CustomEffect.Color[i][j] = Color;
			}
		}

		CreateMouseEffect(ChromaSDK::Mouse::CHROMA_CUSTOM2, &CustomEffect, &Alert);

		ChromaSDK::Mouse::NO_EFFECT_TYPE NoEffect = {};
		NoEffect.LEDId = RZLED_ALL;

		CreateMouseEffect(ChromaSDK::Mouse::CHROMA_NONE, &NoEffect, &NoAlert);

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
}

void MouseDevice::ShowDamageEffect() {
	if (CreateMouseEffect) {
		ChromaSDK::Mouse::CUSTOM_EFFECT_TYPE2 Effect = {};
		for (int i = 0; i < Mouse::MAX_ROW; i++) {
			for (int j = 0; j < Mouse::MAX_COLUMN; j++) {
				Effect.Color[i][j] = RGB(255, 0, 0);
			}
		}

		ChromaSDK::Mouse::STATIC_EFFECT_TYPE NoEffect = {};
		NoEffect.LEDId = RZLED_ALL;

		CreateMouseEffect(ChromaSDK::Mouse::CHROMA_CUSTOM2, &Effect, NULL);
		Sleep(50);
		CreateMouseEffect(ChromaSDK::Mouse::CHROMA_NONE, &NoEffect, NULL);
	}
}

void MouseDevice::ResetEffects() {
	if (CreateMouseEffect) {
		CreateMouseEffect(ChromaSDK::Mouse::CHROMA_NONE, NULL, NULL);
	}
}

DWORD WINAPI MouseDevice::Thread_LoadingAnimationOnMice(LPVOID lpParameter) {
	if (CreateMouseEffect) {
		ChromaSDK::Mouse::CUSTOM_EFFECT_TYPE2 CustomEffect = {};

		CreateMouseEffect(ChromaSDK::Mouse::CHROMA_CUSTOM2, &CustomEffect, NULL);

		Sleep(500);

		for (UINT i = 0; i < 7; i++)
		{
			CustomEffect.Color[HIBYTE(RZLED2_LEFT_SIDE7) - i][0] = RGB(255, 165, 0);
			CustomEffect.Color[HIBYTE(RZLED2_RIGHT_SIDE7) - i][6] = RGB(255, 165, 0);

			if (i == 0)
			{
				// For Razer Diamondback bottom LEDs.
				CustomEffect.Color[8][LOBYTE(RZLED2_BOTTOM1)] = RGB(255, 0, 0);
				CustomEffect.Color[8][LOBYTE(RZLED2_BOTTOM5)] = RGB(255, 0, 0);
			}
			else if (i == 2)
			{
				CustomEffect.Color[HIBYTE(RZLED2_LOGO)][LOBYTE(RZLED2_LOGO)] = RGB(255, 165, 0);

				// For Razer Diamondback bottom LEDs.
				CustomEffect.Color[8][LOBYTE(RZLED2_BOTTOM2)] = RGB(255, 0, 0);
				CustomEffect.Color[8][LOBYTE(RZLED2_BOTTOM4)] = RGB(255, 0, 0);
			}
			else if (i == 4)
			{
				// For Razer Naga Epic numpad LED.
				CustomEffect.Color[HIBYTE(RZLED2_BACKLIGHT)][LOBYTE(RZLED2_BACKLIGHT)] = RGB(255, 165, 0);
			}
			else if (i == 6)
			{
				CustomEffect.Color[HIBYTE(RZLED2_SCROLLWHEEL)][LOBYTE(RZLED2_SCROLLWHEEL)] = RGB(255, 165, 0);;

				// For Razer Diamondback bottom LEDs.
				CustomEffect.Color[8][LOBYTE(RZLED2_BOTTOM3)] = RGB(255, 0, 0);
			}

			CreateMouseEffect(ChromaSDK::Mouse::CHROMA_CUSTOM2, &CustomEffect, NULL);

			Sleep(50);
		}
	}

	return 0;
}