package com.jChroma;

import com.jChroma.device.Mousemat;
import com.jChroma.inteface.jChromaInterface;

public class Chroma {

    private jChromaInterface jChromaInterface;
    private boolean initialized = false;

    public Chroma() {
        this.jChromaInterface = com.jChroma.inteface.jChromaInterface.getInstance();
    }

    public Chroma(boolean initialize) {
        this();
        if (initialize) {
            this.initialize();
        }
    }

    public void initialize() {
        if (!this.initialized) {
            this.jChromaInterface.initialize();
            this.initialized = true;
        }
    }

    public Mousemat getMousemat() {

        return Mousemat.getInstance();
    }
}

