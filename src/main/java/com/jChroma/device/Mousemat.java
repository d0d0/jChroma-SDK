package com.jChroma.device;

import com.jChroma.utils.Colors;
import com.jChroma.utils.DeviceTypes;

import java.awt.*;

public final class Mousemat extends AbstractDevice {

    private static final DeviceTypes deviceType = DeviceTypes.MOUSEMAT_DEVICES;

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

    public void showDamageEffect(){

        super.showDamageEffect(deviceType);
    }
}
