package com.aor.areacalculator.outputters;

import com.aor.areacalculator.aggregators.SumProvider;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;

import static org.junit.jupiter.api.Assertions.assertEquals;

class AreaXMLOutputterTest {

    @Test
    void output() {
        SumProvider sumProvider = Mockito.mock(SumProvider.class);
        Mockito.when(sumProvider.sum()).thenReturn(1.5);

        AreaXMLOutputter outputter = new AreaXMLOutputter(sumProvider);
        assertEquals("<area>1.5</area>", outputter.output());
    }

}