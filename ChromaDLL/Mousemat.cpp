#include "Mousemat.h"

using namespace ChromaSDK;

typedef RZRESULT(*CREATEMOUSEPADEFFECT)(ChromaSDK::Mousepad::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);

CREATEMOUSEPADEFFECT CreateMousepadEffect = NULL;

Mousemat::Mousemat()
{
}


Mousemat::~Mousemat()
{
}

BOOL Mousemat::Initialize(HMODULE m_ChromaSDKModule)
{
	CreateMousepadEffect = (CREATEMOUSEPADEFFECT)GetProcAddress(m_ChromaSDKModule, "CreateMousepadEffect");

	if (CreateMousepadEffect) {

		return TRUE;
	}

	return FALSE;
}

void Mousemat::ShowColor(COLORREF Color) {
	if (CreateMousepadEffect) {
		ChromaSDK::Mousepad::STATIC_EFFECT_TYPE Effect = {};
		Effect.Color = Color;

		CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_STATIC, &Effect, NULL);
	}
}

void Mousemat::ShowLevel(UINT Hp, UINT Ammo) {
	if (CreateMousepadEffect)
	{
		ChromaSDK::Mousepad::CUSTOM_EFFECT_TYPE Effect = {};

		FLOAT RemainingHealth = FLOAT((FLOAT)Hp / 100.0 * 5.0); // 5 LEDs on the left.

		COLORREF HpColor;
		if (RemainingHealth == 0.0)
		{
			HpColor = RGB(255, 0, 0);

			Effect.Color[10] = HpColor;
			Effect.Color[11] = HpColor;
			Effect.Color[12] = HpColor;
			Effect.Color[13] = HpColor;
			Effect.Color[14] = HpColor;
		}
		else
		{
			HpColor = RGB((((5 - RemainingHealth) / 5.0) * 255), ((RemainingHealth / 5.0) * 255), 0);

			for (UINT i = 0; i < RemainingHealth; i++)
			{
				// Display Hp on the left side of the mouse mat.
				Effect.Color[10 + i] = HpColor;
			}
		}

		// Number keys as ammo
		UINT RemainingAmmo = UINT(Ammo / 100.0 * 5.0); // 5 LEDs on the right.

		for (UINT i = 0; i < RemainingAmmo; i++) {
			// Display ammo/mana on the right side.
			Effect.Color[4 - i] = RGB(255, 255, 0);
		}

		CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_CUSTOM, &Effect, NULL);
	}
}

void Mousemat::ShowAlert(COLORREF Color) {
	if (CreateMousepadEffect) {
		RZEFFECTID Alert = GUID_NULL;
		RZEFFECTID NoAlert = GUID_NULL;
		ChromaSDK::Mousepad::STATIC_EFFECT_TYPE StaticEffect = {};
		StaticEffect.Color = Color;

		CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_STATIC, &StaticEffect, &Alert);
		CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_NONE, NULL, &NoAlert);

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

void Mousemat::ShowGauge(UINT Level) {
	if (CreateMousepadEffect) {
		UINT Gauge = UINT(Level / 100.0 * 15.0);

		ChromaSDK::Mousepad::CUSTOM_EFFECT_TYPE Effect = {};

		for (UINT i = 0; i < Gauge; i++)
		{
			Effect.Color[i] = RGB(255, 0, 0);
		}

		CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_CUSTOM, &Effect, NULL);
	}
}

void Mousemat::ShowDamageEffect() {
	if (CreateMousepadEffect) {
		ChromaSDK::Mousepad::STATIC_EFFECT_TYPE Effect = {};
		Effect.Color = RGB(255, 0, 0);

		CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_STATIC, &Effect, NULL);
		Sleep(50);
		CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_NONE, NULL, NULL);
	}
}

void Mousemat::ResetEffects() {
	if (CreateMousepadEffect) {
		CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_NONE, NULL, NULL);
	}
}

void Mousemat::SetColors(const MousematColorStruct* colors, int numVal) {
	if (CreateMousepadEffect) {
		CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_NONE, NULL, NULL);

		ChromaSDK::Mousepad::CUSTOM_EFFECT_TYPE CustomEffect = {};

		for (int i = 0; i < numVal; i++) {
			CustomEffect.Color[colors[i].position] = RGB(colors[i].r, colors[i].g, colors[i].b);
		}

		CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_CUSTOM, &CustomEffect, NULL);
	}
}

void Mousemat::SetBreathing(const BreathingEffectStruct* breathingEffectStruct) {
	if (CreateMousepadEffect) {
		CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_NONE, NULL, NULL);

		ChromaSDK::Mousepad::BREATHING_EFFECT_TYPE BreathingEffect = {};

		if (breathingEffectStruct->type == 1) {
			BreathingEffect.Type = ChromaSDK::Mousepad::BREATHING_EFFECT_TYPE::Type::TWO_COLORS;

			BreathingEffect.Color1 = RGB(breathingEffectStruct->color1R, breathingEffectStruct->color1G, breathingEffectStruct->color1B);
			BreathingEffect.Color2 = RGB(breathingEffectStruct->color2R, breathingEffectStruct->color2G, breathingEffectStruct->color2B);
		}

		if (breathingEffectStruct->type == 2) {
			BreathingEffect.Type = ChromaSDK::Mousepad::BREATHING_EFFECT_TYPE::Type::RANDOM_COLORS;
		}

		CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_BREATHING, &BreathingEffect, NULL);
	}
}

DWORD WINAPI Mousemat::Thread_LoadingAnimationOnMousepad(LPVOID lpParameter) {
	if (CreateMousepadEffect) {
		CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_NONE, NULL, NULL);
		Sleep(500);

		ChromaSDK::Mousepad::CUSTOM_EFFECT_TYPE CustomEffect = {};
		for (UINT i = ChromaSDK::Mousepad::MAX_LEDS - 1; i > 0; --i)
		{
			CustomEffect.Color[i] = RGB(255, 165, 00);

			CreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_CUSTOM, &CustomEffect, NULL);

			Sleep(50);
		}
	}

	return 0;
}