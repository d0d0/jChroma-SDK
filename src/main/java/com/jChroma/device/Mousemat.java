package com.jChroma.device;

import com.jChroma.inteface.structs.BreathingEffectStruct;
import com.jChroma.inteface.structs.MousematColorStruct;
import com.jChroma.utils.BreathingEffectType;
import com.jChroma.utils.Colors;
import com.jChroma.utils.DeviceTypes;

import java.awt.*;

public final class Mousemat extends AbstractDevice {

    private static final DeviceTypes deviceType = DeviceTypes.MOUSEMAT_DEVICES;

    private static Mousemat INSTANCE;

    private Mousemat() {
    }

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

    public void setStaticColorMode(Color color) {

        super.setStaticColorMode(color, deviceType);
    }

    public void setStaticColorMode(Colors color) {

        super.setStaticColorMode(color, deviceType);
    }

    public void setStaticColorMode(int r, int g, int b) {

        super.setStaticColorMode(r, g, b, deviceType);
    }

    public void setBreathingMode(BreathingEffectType breathingEffectType) {

        super.setBreathingMode(breathingEffectType, deviceType);
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

    public void makeRainbow() {
        MousematColorStruct.ByReference byReference = new MousematColorStruct.ByReference();

        MousematColorStruct[] mousematColorStructs = (MousematColorStruct[]) byReference.toArray(15);

        mousematColorStructs[0].position = 0;
        mousematColorStructs[0].r = 238;
        mousematColorStructs[0].g = 0;
        mousematColorStructs[0].b = 0;

        mousematColorStructs[1].position = 1;
        mousematColorStructs[1].r = 238;
        mousematColorStructs[1].g = 77;
        mousematColorStructs[1].b = 17;

        mousematColorStructs[2].position = 2;
        mousematColorStructs[2].r = 238;
        mousematColorStructs[2].g = 154;
        mousematColorStructs[2].b = 0;

        mousematColorStructs[3].position = 3;
        mousematColorStructs[3].r = 238;
        mousematColorStructs[3].g = 231;
        mousematColorStructs[3].b = 0;

        mousematColorStructs[4].position = 4;
        mousematColorStructs[4].r = 167;
        mousematColorStructs[4].g = 238;
        mousematColorStructs[4].b = 0;

        mousematColorStructs[5].position = 5;
        mousematColorStructs[5].r = 90;
        mousematColorStructs[5].g = 238;
        mousematColorStructs[5].b = 0;

        mousematColorStructs[6].position = 6;
        mousematColorStructs[6].r = 13;
        mousematColorStructs[6].g = 238;
        mousematColorStructs[6].b = 0;

        mousematColorStructs[7].position = 7;
        mousematColorStructs[7].r = 0;
        mousematColorStructs[7].g = 238;
        mousematColorStructs[7].b = 63;


        mousematColorStructs[8].position = 8;
        mousematColorStructs[8].r = 0;
        mousematColorStructs[8].g = 238;
        mousematColorStructs[8].b = 141;

        mousematColorStructs[9].position = 9;
        mousematColorStructs[9].r = 0;
        mousematColorStructs[9].g = 238;
        mousematColorStructs[9].b = 218;

        mousematColorStructs[10].position = 10;
        mousematColorStructs[10].r = 0;
        mousematColorStructs[10].g = 180;
        mousematColorStructs[10].b = 238;

        mousematColorStructs[11].position = 11;
        mousematColorStructs[11].r = 0;
        mousematColorStructs[11].g = 103;
        mousematColorStructs[11].b = 238;

        mousematColorStructs[12].position = 12;
        mousematColorStructs[12].r = 0;
        mousematColorStructs[12].g = 26;
        mousematColorStructs[12].b = 238;

        mousematColorStructs[13].position = 13;
        mousematColorStructs[13].r = 50;
        mousematColorStructs[13].g = 0;
        mousematColorStructs[13].b = 238;

        mousematColorStructs[14].position = 14;
        mousematColorStructs[14].r = 127;
        mousematColorStructs[14].g = 0;
        mousematColorStructs[14].b = 238;

        super.jChromaInterface.setColors(0, byReference, 15);
    }

    public void knightRider() throws InterruptedException {
        com.jChroma.inteface.jChromaInterface jChromaInterface = super.jChromaInterface;
        Thread t = new Thread() {
            @Override
            public void run() {
                int redPosition = 0;
                int direction = 1;
                while (true) {
                    MousematColorStruct.ByReference byReference = new MousematColorStruct.ByReference();

                    MousematColorStruct[] mousematColorStructs = (MousematColorStruct[]) byReference.toArray(15);

                    if (redPosition - direction >= 0 && redPosition - direction < 15) {
                        mousematColorStructs[redPosition - direction].r = 0;
                        mousematColorStructs[redPosition - direction].g = 0;
                        mousematColorStructs[redPosition - direction].b = 0;
                        mousematColorStructs[redPosition - direction].position = redPosition;
                    }

                    mousematColorStructs[redPosition].r = 255;
                    mousematColorStructs[redPosition].g = 0;
                    mousematColorStructs[redPosition].b = 0;
                    mousematColorStructs[redPosition].position = redPosition;

                    redPosition += direction;
                    if (redPosition == 0 || redPosition == 14) {
                        direction = direction * -1;
                    }

                    jChromaInterface.setColors(0, byReference, 15);

                    try {
                        Thread.sleep(100);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        };

        t.start();
        t.join();
    }
}
