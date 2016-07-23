#include "chromaDLL.h"

#include <stdexcept>

using namespace std;


namespace chromaDLLNS {
	void chromaDLL::initialize() {
		CChromaSDKImpl m_ChromaSDKImpl1;
		m_ChromaSDKImpl1.Initialize();
	}

	void chromaDLL::playLoadingAnimation(int deviceType) {

		m_ChromaSDKImpl.PlayLoadingAnimation(deviceType);
	}

	void chromaDLL::showDamageEffect(int deviceType) {

		m_ChromaSDKImpl.ShowDamageEffect(deviceType);
	}

	void chromaDLL::unInitialize() {

		m_ChromaSDKImpl.UnInitialize();
	}

	void chromaDLL::showGauge(int i, int deviceType) {

		m_ChromaSDKImpl.ShowGauge(deviceType, i);
	}

	void chromaDLL::setStaticColorMode(int deviceType, int r, int g, int b) {
		COLORREF color = RGB(r, g, b);

		m_ChromaSDKImpl.ShowColor(deviceType, color);
	}

	void chromaDLL::setBreathingMode(int deviceType, const BreathingEffectStruct* breathingEffectStruct) {

		m_ChromaSDKImpl.SetBreathingMode(deviceType, breathingEffectStruct);
	}

	void chromaDLL::setColors(const MousematColorStruct* colors, int numVals) {
		m_ChromaSDKImpl.SetColors(colors, numVals);
	}
}