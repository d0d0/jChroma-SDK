package com.jChroma.device;

import com.jChroma.inteface.MousematColorStruct;
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

    public void showDamageEffect() {

        super.showDamageEffect(deviceType);
    }

    public void setColors() {
        MousematColorStruct.ByReference byReference = new MousematColorStruct.ByReference();


        MousematColorStruct[] mousematColorStructs = (MousematColorStruct[]) byReference.toArray(15);

        for (int i = 0; i < 15; i++) {
            mousematColorStructs[i].position = i;
            if (i < 15) {
                mousematColorStructs[i].r = 0;
                mousematColorStructs[i].g = 0;
                mousematColorStructs[i].b = 255;
            }
            if (i < 10) {
                mousematColorStructs[i].r = 0;
                mousematColorStructs[i].g = 255;
                mousematColorStructs[i].b = 0;
            }
            if (i < 5) {
                mousematColorStructs[i].r = 255;
                mousematColorStructs[i].g = 0;
                mousematColorStructs[i].b = 0;
            }
        }

        super.jChromaInterface.setColors(0, byReference, 15);
    }
}
