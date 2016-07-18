package com.jChroma.utils;

public enum DeviceTypes {
    ALL_DEVICES(0),
    KEYBOARD_DEVICES(1),
    MOUSEMAT_DEVICES(2),
    MOUSE_DEVICES(3),
    HEADSET_DEVICES(4),
    KEYPAD_DEVICES(5);

    private int value;

    DeviceTypes(int i) {

        this.value = i;
    }

    public int getValue(){

        return this.value;
    }
}
