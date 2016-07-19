package com.jChroma;

import com.jChroma.device.Mousemat;
import com.jChroma.inteface.jChromaInterface;

public class Chroma {

    private jChromaInterface jChromaInterface;
    private static Chroma INSTANCE;
    private boolean initialized = false;

    public static Chroma getInstance() {
        if (INSTANCE == null) {
            INSTANCE = new Chroma(true);
        }

        return INSTANCE;
    }

    private Chroma() {
        this.jChromaInterface = com.jChroma.inteface.jChromaInterface.getInstance();
    }

    private Chroma(boolean initialize) {
        this();
        if (initialize) {
            this.initialize();
        }
    }

    private void initialize() {
        if (!this.initialized) {
            this.jChromaInterface.initialize();
            this.initialized = true;
        }
    }

    public Mousemat getMousemat() {

        return Mousemat.getInstance();
    }
}

