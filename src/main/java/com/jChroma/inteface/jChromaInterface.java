package com.jChroma.inteface;

import com.jChroma.inteface.structs.BreathingEffectStruct;
import com.jChroma.inteface.structs.MousematColorStruct;
import com.jChroma.utils.BreathingEffectType;
import com.jChroma.utils.NativeUtils;
import com.sun.jna.Library;

public interface jChromaInterface extends Library {
    jChromaInterface INSTANCE = (jChromaInterface) NativeUtils.loadLibraryFromJar(System.getProperty("sun.arch.data.model").equals("32") ? "/chromaDLL.dll" : "/chromaDLL64.dll");

    static jChromaInterface getInstance() {

        return INSTANCE;
    }

    void initialize();

    void unInitialize();

    void playLoadingAnimation(int ignored, int deviceType);

    void showDamageEffect(int ignored, int deviceType);

    void showGauge(int ignored, int i, int deviceType);

    void resetEffects(int ignored, int deviceType);

    void setStaticColorMode(int ignored, int deviceType, int r, int g, int b);

    void setBreathingMode(int ignored, int deviceType, BreathingEffectStruct.ByReference breathingType);

    void setColors(int ignored, MousematColorStruct.ByReference colors, int numVals);
}
