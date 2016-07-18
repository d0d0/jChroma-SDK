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
		void showColor(int r, int g, int b, int deviceType);
		void setColors(const MousematColorStruct* colors, int numVals);
	};
}