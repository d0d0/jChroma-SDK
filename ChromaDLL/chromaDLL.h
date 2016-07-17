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
		void playLoadingAnimation();
		void showDamageEffect();
		void showGauge(int i, int j);
	};
}