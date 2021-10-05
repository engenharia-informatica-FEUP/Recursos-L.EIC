package com.aor.numbers;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

class DivisibleByFilterTest {

    @Test
    void acceptDivideBy2() {
        DivisibleByFilter filter = new DivisibleByFilter(2);
        List<Integer> divisible = Arrays.asList(0, 2, 4, 8, 240, 1000, 10000);
        List<Integer> notDivisible = Arrays.asList(1, 3, 5, 15, 351, 10001);

        for (int n : divisible)
            Assertions.assertTrue(filter.accept(n));

        for (int n : notDivisible)
            Assertions.assertFalse(filter.accept(n));

    }

    @Test
    void acceptDivideBy3() {
        DivisibleByFilter filter = new DivisibleByFilter(3);
        List<Integer> divisible = Arrays.asList(0, 3, 6, 9, 33, 333, 666);
        List<Integer> notDivisible = Arrays.asList(1, 2, 4, 5, 100, 1000, 10000);

        for (int n : divisible)
            Assertions.assertTrue(filter.accept(n));

        for (int n : notDivisible)
            Assertions.assertFalse(filter.accept(n));

    }
}