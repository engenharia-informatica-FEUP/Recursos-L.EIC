package com.aor.areacalculator.aggregators;

import com.aor.areacalculator.shapes.Circle;
import com.aor.areacalculator.shapes.HasArea;
import com.aor.areacalculator.shapes.House;
import com.aor.areacalculator.shapes.Triangle;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

class CityTest {

    @Test
    void sum() {
        List<House> houses = new ArrayList<>();
        houses.add(new House(0));
        houses.add(new House(10.5));
        houses.add(new House(18.3));

        City city = new City(houses);
        assertEquals(28.8, city.sum(), 0.1);
    }

    @Test
    void sumUsingMock() {
        List<House> houses = new ArrayList<>();

        House a1 = Mockito.mock(House.class);
        House a2 = Mockito.mock(House.class);
        House a3 = Mockito.mock(House.class);

        Mockito.when(a1.getArea()).thenReturn(0.0);
        Mockito.when(a2.getArea()).thenReturn(5.4);
        Mockito.when(a3.getArea()).thenReturn(7.8);

        houses.add(a1);
        houses.add(a2);
        houses.add(a3);

        City city = new City(houses);
        assertEquals(13.2, city.sum(), 0.1);
    }
}