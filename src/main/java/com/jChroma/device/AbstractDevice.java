package com.jChroma.device;

import com.jChroma.inteface.structs.BreathingEffectStruct;
import com.jChroma.utils.BreathingEffectType;
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

    void setStaticColorMode(Color color, DeviceTypes deviceType) {

        this.setStaticColorMode(color.getRed(), color.getGreen(), color.getBlue(), deviceType);
    }

    void setStaticColorMode(Colors color, DeviceTypes deviceType) {

        this.setStaticColorMode(color.getR(), color.getG(), color.getB(), deviceType);
    }

    void setStaticColorMode(int r, int g, int b, DeviceTypes deviceType) {

        jChromaInterface.setStaticColorMode(0, deviceType.getValue(), r, g, b);
    }

    void setBreathingMode(BreathingEffectType breathingEffectType, DeviceTypes deviceType){
        BreathingEffectStruct.ByReference byReference= new BreathingEffectStruct.ByReference();

        byReference.color1R = breathingEffectType.getColor1().getR();
        byReference.color1G = breathingEffectType.getColor1().getG();
        byReference.color1B = breathingEffectType.getColor1().getB();

        byReference.color2R = breathingEffectType.getColor2().getR();
        byReference.color2G = breathingEffectType.getColor2().getG();
        byReference.color2B = breathingEffectType.getColor2().getB();

        byReference.type = breathingEffectType.getBreathingType().getValue();

        jChromaInterface.setBreathingMode(0, deviceType.getValue(), byReference);
    }

    void showDamageEffect(DeviceTypes deviceType) {

        jChromaInterface.showDamageEffect(0, deviceType.getValue());
    }
}
