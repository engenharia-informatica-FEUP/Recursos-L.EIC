package com.aor.hero;

import java.io.IOException;

public class Application {
    public static void main(String[] args) {
        try {
            new Game(60, 30).run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}