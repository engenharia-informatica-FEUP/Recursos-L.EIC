package com.aor.areacalculator.aggregators;

import com.aor.areacalculator.shapes.House;

import java.util.List;

public class City implements SumProvider {
    private List<House> houses;

    public City(List<House> houses) {
        this.houses = houses;
    }

    public double sum() {
        double sum = 0;
        for (House shape : houses)
            sum += shape.getArea();
        return sum;
    }
}
