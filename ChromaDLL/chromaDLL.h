#include "ChromaSDKImpl.h"
#include "structs.h"

namespace chromaDLLNS
{
	class chromaDLL
	{
	public:
		CChromaSDKImpl m_ChromaSDKImpl;
		void initialize();
		void unInitialize();
		void playLoadingAnimation(int deviceType);
		void showDamageEffect(int deviceType);
		void showGauge(int i, int deviceType);
		void setStaticColorMode(int deviceType, int r, int g, int b);
		void setBreathingMode(int deviceType, const BreathingEffectStruct* breathingEffectStruct);
		void setColors(const MousematColorStruct* colors, int numVals);
	};
}