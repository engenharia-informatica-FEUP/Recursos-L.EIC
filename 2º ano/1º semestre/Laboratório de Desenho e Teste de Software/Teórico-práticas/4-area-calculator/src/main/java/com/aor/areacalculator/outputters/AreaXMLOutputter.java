package com.aor.areacalculator.outputters;

import com.aor.areacalculator.aggregators.SumProvider;

public class AreaXMLOutputter {
    private SumProvider sumProvider;

    public AreaXMLOutputter(SumProvider sumProvider) {
        this.sumProvider = sumProvider;
    }

    public String output() {
        return "<area>" + sumProvider.sum() + "</area>";
    }
}
