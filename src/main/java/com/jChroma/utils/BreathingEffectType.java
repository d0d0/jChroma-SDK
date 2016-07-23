package com.jChroma.utils;


public class BreathingEffectType {

    public enum BreathingType {
        TWO_COLORS(1),
        RANDOM_COLORS(2);

        private final int type;

        BreathingType(int i) {
            this.type = i;
        }

        public int getValue() {

            return this.type;
        }
    }

    private BreathingType breathingType;
    private Colors color1;
    private Colors color2;

    public BreathingEffectType() {
    }

    public void setColor1(Colors color1) {
        this.color1 = color1;
    }

    public void setColor2(Colors color2) {
        this.color2 = color2;
    }

    public void setBreathingType(BreathingType breathingType) {
        this.breathingType = breathingType;
    }

    public Colors getColor1() {
        return color1;
    }

    public Colors getColor2() {
        return color2;
    }

    public BreathingType getBreathingType() {
        return breathingType;
    }

}
