package com.jChroma;

import com.jChroma.utils.Colors;
import org.junit.Test;

public class ChromaTest {

    @Test
    public void visualTest() throws InterruptedException {
        Chroma chroma = new Chroma(true);
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
                try {
                    Thread.sleep(3000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println("Enjoy red color");
            }
        };

        t1.start();
        t1.join();
    }

}