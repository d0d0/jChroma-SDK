package com.jChroma.inteface;

import com.jChroma.utils.NativeUtils;
import com.sun.jna.Library;
import com.sun.jna.Pointer;

public interface jChromaInterface extends Library {
    jChromaInterface INSTANCE = (jChromaInterface) NativeUtils.loadLibraryFromJar(System.getProperty("sun.arch.data.model").equals("32") ? "/chromaDLL.dll" : "/chromaDLL64.dll");

    static jChromaInterface getInstance() {

        return INSTANCE;
    }

    // it's possible to check the platform on which program runs, for example purposes we assume that there's a linux port of the library (it's not attached to the downloadable project)
    byte giveVoidPtrGetChar(Pointer param); // char giveVoidPtrGetChar(void* param);

    int giveVoidPtrGetInt(Pointer param);   //int giveVoidPtrGetInt(void* param);

    int giveIntGetInt(int a);               // int giveIntGetInt(int a);

    void simpleCall();                      // void simpleCall();

    void initialize();

    void unInitialize();

    void playLoadingAnimation(int ignored, int deviceType);

    void showDamageEffect(int ignored, int deviceType);

    void showGauge(int ignored, int i, int deviceType);

    void resetEffects(int ignored, int deviceType);

    void showColor(int ignored, int r, int g, int b, int deviceType);
}
