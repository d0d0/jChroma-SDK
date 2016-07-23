package com.jChroma.inteface.structs;

import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

public class BreathingEffectStruct extends Structure {

    public static class ByReference extends BreathingEffectStruct implements Structure.ByReference {}

    public int type;

    public int color1R;

    public int color1G;

    public int color1B;

    public int color2R;

    public int color2G;

    public int color2B;

    @Override
    public List getFieldOrder() {
        return Arrays.asList("type", "color1R", "color1G", "color1B", "color2R", "color2G", "color2B");
    }
}
