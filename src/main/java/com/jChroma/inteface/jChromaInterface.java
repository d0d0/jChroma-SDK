package com.jChroma.inteface;

import com.jChroma.utils.NativeUtils;
import com.sun.jna.Library;
import com.sun.jna.Pointer;

public interface jChromaInterface extends Library {
    jChromaInterface INSTANCE = (jChromaInterface) NativeUtils.loadLibraryFromJar(System.getProperty("sun.arch.data.model").equals("32") ? "/chromaDLL.dll" : "/chromaDLL64.dll");

    // it's possible to check the platform on which program runs, for example purposes we assume that there's a linux port of the library (it's not attached to the downloadable project)
    byte giveVoidPtrGetChar(Pointer param); // char giveVoidPtrGetChar(void* param);

    int giveVoidPtrGetInt(Pointer param);   //int giveVoidPtrGetInt(void* param);

    int giveIntGetInt(int a);               // int giveIntGetInt(int a);

    void simpleCall();                      // void simpleCall();

    void initialize();

    void playLoadingAnimation();

    void unInitialize();

    void showDamageEffect();

    void showGauge(int i, int j);
}
