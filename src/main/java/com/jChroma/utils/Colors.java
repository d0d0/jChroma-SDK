package com.jChroma.utils;

import java.awt.*;

public enum Colors {
    BLACK(0, 0, 0),
    BLUE(0, 0, 255),
    CYAN(0, 255, 255),
    GREEN(0, 255, 0),
    GREY(125, 125, 125),
    ORANGE(255, 165, 0),
    PINK(255, 192, 203),
    PURPLE(128, 0, 128),
    RED(255, 0, 0),
    YELLOW(255, 255, 0),
    WHITE(255, 255, 255);

    private final int r;
    private final int g;
    private final int b;
    private final String rgb;

    Colors(final int r, final int g, final int b) {

        this.r = r;
        this.g = g;
        this.b = b;
        this.rgb = r + ", " + g + ", " + b;
    }

    public String getRGB() {

        return this.rgb;
    }

    public Color getColor() {

        return new Color(this.getR(), this.getG(), this.getB());
    }

    public int getARGB() {

        return 0xFF000000 | ((getR() << 16) & 0x00FF0000) | ((getG() << 8) & 0x0000FF00) | getB();
    }

    public int getR() {
        return r;
    }

    public int getG() {
        return g;
    }

    public int getB() {
        return b;
    }
}
