package com.jChroma.inteface;

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

    void showColor(int ignored, int r, int g, int b, int deviceType);

    void setColors(int ignored, MousematColorStruct.ByReference colors, int numVals);
}
