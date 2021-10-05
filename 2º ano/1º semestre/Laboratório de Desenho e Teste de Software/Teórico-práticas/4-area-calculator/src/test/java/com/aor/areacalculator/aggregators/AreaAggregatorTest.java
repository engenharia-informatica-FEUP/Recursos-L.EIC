package com.aor.areacalculator.aggregators;

import com.aor.areacalculator.shapes.Circle;
import com.aor.areacalculator.shapes.HasArea;
import com.aor.areacalculator.shapes.House;
import com.aor.areacalculator.shapes.Triangle;
import org.junit.jupiter.api.Test;
import org.mockito.Mock;
import org.mockito.Mockito;

import static org.junit.jupiter.api.Assertions.*;

class AreaAggregatorTest {

    @Test
    void sum() {
        AreaAggregator aggregator = new AreaAggregator();
        aggregator.addShape(new House(10));
        aggregator.addShape(new Circle(2));
        aggregator.addShape(new Triangle(1, 2));

        assertEquals(23.57, aggregator.sum(), 0.1);
    }

    @Test
    void sumUsingMock() {
        AreaAggregator aggregator = new AreaAggregator();

        HasArea a1 = Mockito.mock(HasArea.class);
        HasArea a2 = Mockito.mock(HasArea.class);
        HasArea a3 = Mockito.mock(HasArea.class);

        Mockito.when(a1.getArea()).thenReturn(0.0);
        Mockito.when(a2.getArea()).thenReturn(5.4);
        Mockito.when(a3.getArea()).thenReturn(7.8);

        aggregator.addShape(a1);
        aggregator.addShape(a2);
        aggregator.addShape(a3);

        assertEquals(13.2, aggregator.sum(), 0.1);
    }
}