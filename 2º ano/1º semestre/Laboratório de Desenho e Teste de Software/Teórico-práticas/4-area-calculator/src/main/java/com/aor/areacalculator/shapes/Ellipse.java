package com.aor.areacalculator.shapes;

public class Ellipse implements AreaShape {
    private double radiusX;
    private double radiusY;

    public Ellipse(double radiusX, double radiusY) {
        this.radiusX = radiusX;
        this.radiusY = radiusY;
    }

    public double getRadiusX() {
        return radiusX;
    }

    public void setRadiusX(double radiusX) {
        this.radiusX = radiusX;
    }

    public double getRadiusY() {
        return radiusY;
    }

    public void setRadiusY(double radiusY) {
        this.radiusY = radiusY;
    }

    @Override
    public double getArea() {
        return Math.PI * radiusX * radiusY;
    }

    @Override
    public void draw() {
        System.out.println("ELLIPSE");
    }
}
