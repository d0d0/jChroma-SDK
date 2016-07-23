package com.jChroma.inteface.structs;

import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

public class MousematColorStruct extends Structure {

    public static class ByReference extends MousematColorStruct implements Structure.ByReference {}

    public int r;

    public int g;

    public int b;

    public int position;

    @Override
    public List getFieldOrder() {
        return Arrays.asList("position", "r", "g", "b");
    }
}