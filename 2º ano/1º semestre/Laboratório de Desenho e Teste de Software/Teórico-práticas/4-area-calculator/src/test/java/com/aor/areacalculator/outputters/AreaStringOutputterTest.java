package com.aor.areacalculator.outputters;

import com.aor.areacalculator.aggregators.SumProvider;
import org.junit.jupiter.api.Test;
import org.mockito.Mock;
import org.mockito.Mockito;

import static org.junit.jupiter.api.Assertions.*;

class AreaStringOutputterTest {

    @Test
    void output() {
        SumProvider sumProvider = Mockito.mock(SumProvider.class);
        Mockito.when(sumProvider.sum()).thenReturn(1.5);

        AreaStringOutputter outputter = new AreaStringOutputter(sumProvider);
        assertEquals("Sum of areas: 1.5", outputter.output());
    }

}