package com.jChroma;

import com.jChroma.utils.Colors;
import org.junit.Before;
import org.junit.Test;

import java.awt.*;
import java.util.Random;

public class ChromaTest {

    private Chroma chroma;
    private Random random = new Random();

    @Before
    public void setUp() {
        chroma = new Chroma(true);
        chroma.initialize();
    }

    @Test
    public void visualTest() throws InterruptedException {
        Thread t1 = new Thread() {
            public void run() {
                System.out.println("Loading animation started");
                chroma.getMousemat().playLoadingAnimation();
                try {
                    Thread.sleep(3000);
                    System.out.println("Loading animation stopped");
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };

        t1.start();
        t1.join();

        t1 = new Thread() {
            public void run() {
                System.out.println("Changing color to red");
                chroma.getMousemat().showColor(Colors.RED);
                System.out.println("Enjoy red color");
                try {
                    Thread.sleep(3000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };

        t1.start();
        t1.join();

        t1 = new Thread() {
            public void run() {
                for (int i = 0; i < 5; i++) {
                    Color color = new Color(random.nextInt(256), random.nextInt(256), random.nextInt(256));
                    System.out.println("Changing color to: " + color);
                    chroma.getMousemat().showColor(color);
                    System.out.println("Enjoy " + color + " color");
                    try {
                        Thread.sleep(3000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        };

        t1.start();
        t1.join();

        t1 = new Thread() {
            public void run() {
                for (int i = 0; i < 3; i++) {
                    System.out.println("Damage effect");
                    chroma.getMousemat().showDamageEffect();
                    System.out.println("Enjoy damage");
                    try {
                        Thread.sleep(3000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        };

        t1.start();
        t1.join();

        t1 = new Thread() {
            public void run() {
                System.out.println("Enjoy coloring");
                chroma.getMousemat().setColors();
                try {
                    Thread.sleep(3000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };

        t1.start();
        t1.join();
    }

    @Test
    public void makeRainbow() throws InterruptedException {
        Thread t1 = new Thread() {
            public void run() {
                System.out.println("You have rainbow now");
                chroma.getMousemat().makeRainbow();
                try {
                    Thread.sleep(5000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };

        t1.start();
        t1.join();
    }

}