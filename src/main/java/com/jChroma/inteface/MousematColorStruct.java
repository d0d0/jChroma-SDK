package com.jChroma.inteface;

import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

public class MousematColorStruct extends Structure {

    public static class ByReference extends MousematColorStruct implements Structure.ByReference {}

    public int b;

    public int g;

    public int position;

    public int r;

    @Override
    public List getFieldOrder() {
        return Arrays.asList("position", "r", "g", "b");
    }
}