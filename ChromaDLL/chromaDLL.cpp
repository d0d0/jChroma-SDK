#include "chromaDLL.h"

#include <stdexcept>

using namespace std;


namespace chromaDLLNS
{
	char chromaDLL::giveVoidPtrGetChar(void* param)
	{
		if (param != 0)
		{
			char* paramChrPtr = (char*)param;
			return *paramChrPtr;
		}
		else
		{
			return 'x';
		}

	}

	int chromaDLL::giveIntGetInt(int a)
	{
		return 2 * a;
	}

	void chromaDLL::simpleCall(void)
	{
		int x = 3;
		return;
	}

	int chromaDLL::giveVoidPtrGetInt(void* param)
	{
		if (param != 0)
		{
			int* x = (int*)param;
			return *x;

		}
		else
		{
			return -1;
		}
	}

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

	void chromaDLL::showColor(int r, int g, int b, int deviceType) {
		COLORREF color = RGB(r, g, b);
		m_ChromaSDKImpl.ShowColor(deviceType, color);
	}
}