#include "ChromaSDKImpl.h"

namespace chromaDLLNS
{
	class chromaDLL
	{
	public:
		CChromaSDKImpl m_ChromaSDKImpl;
		char giveVoidPtrGetChar(void* param);
		int giveIntGetInt(int a);
		void simpleCall();
		int giveVoidPtrGetInt(void* param);
		void initialize();
		void unInitialize();
		void playLoadingAnimation(int deviceType);
		void showDamageEffect(int deviceType);
		void showGauge(int i, int deviceType);
		void showColor(int r, int g, int b, int deviceType);
	};
}