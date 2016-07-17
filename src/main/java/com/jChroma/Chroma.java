package com.jChroma;


import com.jChroma.inteface.jChromaInterface;

public class Chroma {

    private jChromaInterface jChromaInterface;

    private boolean initialized = false;

    public Chroma() {
        this.jChromaInterface = com.jChroma.inteface.jChromaInterface.INSTANCE;
    }

    public Chroma(boolean initialize) {
        this();
        if (initialize) {
            this.initialize();
        }
    }

    public void initialize() {
        this.jChromaInterface.initialize();
        this.initialized = true;
    }

    public void playLoadingAnimation() {
        jChromaInterface.playLoadingAnimation();
    }
}

