package com.jChroma;


import com.jChroma.device.AbstractDevice;
import com.jChroma.device.Mousemat;
import com.jChroma.inteface.jChromaInterface;
import com.jChroma.utils.Devices;

public class Chroma {

    private jChromaInterface jChromaInterface;

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
        this.jChromaInterface.initialize();
    }

    public AbstractDevice getDevice(Devices deviceType) {

        if (deviceType == Devices.MOUSEMAT_DEVICES) {

            return getMousemat();
        }

        return null;
    }

    public Mousemat getMousemat() {

        return Mousemat.getInstance();
    }
}

