package com.jChroma.device;

import com.jChroma.utils.Colors;
import com.jChroma.utils.Devices;

import java.awt.*;

public class Mousemat extends AbstractDevice {

    private static final Devices deviceType = Devices.MOUSEMAT_DEVICES;

    private static Mousemat INSTANCE;

    public static Mousemat getInstance() {
        if (INSTANCE == null) {
            INSTANCE = new Mousemat();
        }

        return INSTANCE;
    }

    public void resetEffects() {

        super.resetEffects(deviceType);
    }

    public void playLoadingAnimation() {

        super.playLoadingAnimation(deviceType);
    }

    public void showColor(Color color) {

        super.showColor(color, deviceType);
    }

    public void showColor(Colors color) {

        super.showColor(color, deviceType);
    }

    public void showColor(int r, int g, int b) {

        super.showColor(r, g, b, deviceType);
    }
}
