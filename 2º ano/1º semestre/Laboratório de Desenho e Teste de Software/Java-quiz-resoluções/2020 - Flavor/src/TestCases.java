import static org.junit.Assert.*;

import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.util.*;

import org.junit.*;

public class TestCases {

    /**
     * Tests if all class field are private, protected
     * or package-protected. You don't have to understand
     * this code.
     * @param classes classes to be tested.
     */
    private void fieldsArentPublic(Class<?> ... classes) {
        for (Class<?> c: classes)
            for (Field f : c.getDeclaredFields())
                assertFalse(Modifier.isPublic(f.getModifiers()));
    }

    /**
     * Tests if a class is abstract. You don't have to 
     * understand this code.
     * @param c class to be tested.
     */
    private void isAbstract(Class<?> c) {
        assertTrue(Modifier.isAbstract(c.getModifiers()));
    }

    /**
     * Tests if a class does not declare a method.
     * You don't have to understand this code.
     * @param c class to be tested.
     */
    private void classNotDeclaresMethod(Class<?> c, String method) {
        try {
            assertTrue(c.getMethod(method).getDeclaringClass() != c);
        } catch (NoSuchMethodException e) { }
    }


    @Test
    public void testFlavour() {
        Flavor chocolate = new Flavor("chocolate");
        Flavor vanilla = new Flavor("vanilla");

        assertEquals("chocolate", chocolate.getName());
        assertEquals("vanilla", vanilla.getName());

        fieldsArentPublic(Flavor.class);
    }



    @Test
    public void testIcecream() {
        Flavor chocolate = new Flavor("chocolate");
        Flavor vanilla = new Flavor("vanilla");

        Icecream icecream = new Icecream();
        icecream.addScoop(chocolate);
        icecream.addScoop(vanilla);
        icecream.addScoop(chocolate);

        assertEquals(3, icecream.getScoopCount());

        fieldsArentPublic(Icecream.class);
    }



    @Test
    public void testContains() {
        Flavor chocolate = new Flavor("chocolate");
        Flavor vanilla = new Flavor("vanilla");

        Icecream icecream = new Icecream();
        icecream.addScoop(chocolate);
        icecream.addScoop(vanilla);
        icecream.addScoop(chocolate);

        assertTrue(icecream.contains("chocolate"));
        assertTrue(icecream.contains("vanilla"));
        assertFalse(icecream.contains("strawberry"));
    }



    @Test
    public void testFlavourCount() {
        Flavor chocolate = new Flavor("chocolate");
        Flavor vanilla = new Flavor("vanilla");

        Icecream icecream = new Icecream();
        icecream.addScoop(chocolate);
        icecream.addScoop(vanilla);
        icecream.addScoop(chocolate);

        assertEquals(3, icecream.getScoopCount());
        assertEquals(2, icecream.getFlavorCount());
    }



    @Test
    public void testCommands() {
        Icecream icecream = new Icecream();

        Flavor chocolate = new Flavor("chocolate");
        Flavor vanilla = new Flavor("vanilla");

        Command addChocolate = new AddScoopCommand(chocolate);
        Command addVanilla = new AddScoopCommand(vanilla);

        addChocolate.execute(icecream);
        addVanilla.execute(icecream);

        assertTrue(icecream.contains("chocolate"));
        assertTrue(icecream.contains("vanilla"));
        assertFalse(icecream.contains("strawberry"));

        isAbstract(Command.class);
        fieldsArentPublic(AddScoopCommand.class);
    }



    @Test
    public void testMachine() {
        Icecream icecream = new Icecream();
        IcecreamMachine machine = new IcecreamMachine(icecream);

        Flavor chocolate = new Flavor("chocolate");
        Flavor strawberry = new Flavor("strawberry");

        Command addChocolate = new AddScoopCommand(chocolate);
        Command addStrawberry = new AddScoopCommand(strawberry);

        machine.executeCommand(addChocolate);
        machine.executeCommand(addStrawberry);
        machine.executeCommand(addChocolate);

        assertEquals(3, icecream.getScoopCount());
        assertEquals(2, icecream.getFlavorCount());

        assertTrue(icecream.contains("chocolate"));
        assertTrue(icecream.contains("strawberry"));
        assertFalse(icecream.contains("vanilla"));

        fieldsArentPublic(IcecreamMachine.class);
    }



    @Test
    public void testUndo() {
        Icecream icecream = new Icecream();
        IcecreamMachine machine = new IcecreamMachine(icecream);

        Flavor chocolate = new Flavor("chocolate");
        Flavor strawberry = new Flavor("strawberry");
        Flavor vanilla = new Flavor("vanilla");

        Command addChocolate = new AddScoopCommand(chocolate);
        Command addStrawberry = new AddScoopCommand(strawberry);
        Command addVanilla = new AddScoopCommand(vanilla);

        machine.executeCommand(addChocolate);
        machine.executeCommand(addStrawberry);
        machine.executeCommand(addChocolate);

        assertEquals(3, icecream.getScoopCount());
        assertEquals(2, icecream.getFlavorCount());

        machine.undoLastCommand();
        machine.executeCommand(addVanilla);

        assertEquals(3, icecream.getScoopCount());
        assertEquals(3, icecream.getFlavorCount());

        assertTrue(icecream.contains("chocolate"));
        assertTrue(icecream.contains("strawberry"));
        assertTrue(icecream.contains("vanilla"));

        machine.undoLastCommand();
        machine.undoLastCommand();
        machine.executeCommand(addChocolate);

        assertEquals(2, icecream.getScoopCount());
        assertEquals(1, icecream.getFlavorCount());

        assertTrue(icecream.contains("chocolate"));
        assertFalse(icecream.contains("strawberry"));
        assertFalse(icecream.contains("vanilla"));
    }
}