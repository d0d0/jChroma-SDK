package com.jChroma.device;

import com.jChroma.utils.Colors;
import com.jChroma.utils.Devices;

import java.awt.*;

public class AbstractDevice {

    private com.jChroma.inteface.jChromaInterface jChromaInterface = com.jChroma.inteface.jChromaInterface.getInstance();

    void resetEffects(Devices deviceType) {

        jChromaInterface.resetEffects(0, deviceType.getValue());
    }

    void playLoadingAnimation(Devices deviceType) {

        jChromaInterface.playLoadingAnimation(0, deviceType.getValue());
    }

    void showColor(Color color, Devices deviceType) {

        this.showColor(color.getRed(), color.getGreen(), color.getBlue(), deviceType);
    }

    void showColor(Colors color, Devices deviceType) {

        this.showColor(color.getR(), color.getG(), color.getB(), deviceType);
    }

    void showColor(int r, int g, int b, Devices deviceType) {

        jChromaInterface.showColor(0, r, g, b, deviceType.getValue());
    }
}
