package com.jChroma.device;

import com.jChroma.utils.Colors;
import com.jChroma.utils.DeviceTypes;

import java.awt.*;

abstract class AbstractDevice {

    protected com.jChroma.inteface.jChromaInterface jChromaInterface = com.jChroma.inteface.jChromaInterface.getInstance();

    void resetEffects(DeviceTypes deviceType) {

        jChromaInterface.resetEffects(0, deviceType.getValue());
    }

    void playLoadingAnimation(DeviceTypes deviceType) {

        jChromaInterface.playLoadingAnimation(0, deviceType.getValue());
    }

    void showColor(Color color, DeviceTypes deviceType) {

        this.showColor(color.getRed(), color.getGreen(), color.getBlue(), deviceType);
    }

    void showColor(Colors color, DeviceTypes deviceType) {

        this.showColor(color.getR(), color.getG(), color.getB(), deviceType);
    }

    void showColor(int r, int g, int b, DeviceTypes deviceType) {

        jChromaInterface.showColor(0, r, g, b, deviceType.getValue());
    }

    void showDamageEffect(DeviceTypes deviceType) {

        jChromaInterface.showDamageEffect(0, deviceType.getValue());
    }
}
