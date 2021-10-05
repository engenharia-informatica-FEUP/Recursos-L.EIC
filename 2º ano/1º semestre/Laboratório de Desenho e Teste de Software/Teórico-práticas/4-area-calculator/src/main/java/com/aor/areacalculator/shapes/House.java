package com.aor.areacalculator.shapes;

public class House implements HasArea {
    private double area;

    public House(double area) {
        this.area = area;
    }

    @Override
    public double getArea() {
        return area;
    }

    public void setArea(double area) {
        this.area = area;
    }
}
