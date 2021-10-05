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
     * Tests if a class is an interface. You don't have to 
     * understand this code.
     * @param c class to be tested.
     */
    private void isInterface(Class<?> c) {
        assertTrue(Modifier.isInterface(c.getModifiers()));
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
    public void testIngredient() {
        Ingredient ingredient1 = new Ingredient("Tomato");
        Ingredient ingredient2 = new Ingredient("Cheese");
        Ingredient ingredient3 = new Ingredient("Ham");
        Ingredient ingredient4 = new Ingredient("Cheese");

        assertEquals("Tomato", ingredient1.getName());
        assertEquals("Cheese", ingredient2.getName());
        assertEquals("Ham", ingredient3.getName());
        assertEquals("Cheese", ingredient4.getName());

        fieldsArentPublic(Ingredient.class);
    }



    @Test
    public void testPizza() {
        Ingredient ingredient1 = new Ingredient("Tomato");
        Ingredient ingredient2 = new Ingredient("Cheese");
        Ingredient ingredient3 = new Ingredient("Ham");

        Pizza pizza = new MediumPizza();
        // Method addIngredient returns true if ingredient added to pizza
        assertTrue(pizza.addIngredient(ingredient1));
        assertTrue(pizza.addIngredient(ingredient2));
        assertEquals(2, pizza.getIngredientCount());

        assertTrue(pizza.addIngredient(ingredient3));
        assertEquals(3, pizza.getIngredientCount());

        isInterface(Pizza.class);
        fieldsArentPublic(MediumPizza.class);
    }



    @Test
    public void testRepeatedIngredients() {
        Ingredient ingredient1 = new Ingredient("Tomato");
        Ingredient ingredient2 = new Ingredient("Cheese");
        Ingredient ingredient3 = new Ingredient("Cheese");

        Pizza pizza = new MediumPizza();
        // Method addIngredient only adds ingredient if
        // ingredient different from previous ingredients
        assertTrue(pizza.addIngredient(ingredient1));
        assertEquals(1, pizza.getIngredientCount());

        assertFalse(pizza.addIngredient(ingredient1)); // Ingredient is the same
        assertEquals(1, pizza.getIngredientCount());

        assertTrue(pizza.addIngredient(ingredient2));
        assertEquals(2, pizza.getIngredientCount());

        assertFalse(pizza.addIngredient(ingredient3)); // Ingredient has the same name
        assertEquals(2, pizza.getIngredientCount());

        isInterface(Pizza.class);
        fieldsArentPublic(MediumPizza.class);
    }



    @Test
    public void testMargueritaCertifier() {
        // A Marguerita Pizza must have Tomato, Basil,
        // and Mozzarella; and no other ingredient
        PizzaCertifier certifier = new MargueritaCertifier();

        Pizza pizza1 = new MediumPizza();
        pizza1.addIngredient(new Ingredient("Tomato"));
        pizza1.addIngredient(new Ingredient("Mozzarella"));
        pizza1.addIngredient(new Ingredient("Basil"));
        assertTrue(certifier.isCertified(pizza1));

        Pizza pizza2 = new MediumPizza();
        pizza2.addIngredient(new Ingredient("Mozzarella"));
        pizza2.addIngredient(new Ingredient("Tomato"));
        pizza2.addIngredient(new Ingredient("Basil"));
        assertTrue(certifier.isCertified(pizza2));

        Pizza pizza3 = new MediumPizza();
        pizza3.addIngredient(new Ingredient("Mozzarella"));
        pizza3.addIngredient(new Ingredient("Tomato"));
        assertFalse(certifier.isCertified(pizza3));

        pizza1.addIngredient(new Ingredient("Ham"));
        assertFalse(certifier.isCertified(pizza1));

        pizza3.addIngredient(new Ingredient("Basil"));
        assertTrue(certifier.isCertified(pizza3));

        isAbstract(PizzaCertifier.class);
        fieldsArentPublic(MargueritaCertifier.class);
    }



    @Test
    public void testRecipe() {
        PizzaCertifier certifier = new MargueritaCertifier();
        Recipe recipe = new MargueritaRecipe();
        Pizza pizza = recipe.makeMediumPizza();

        assertTrue(certifier.isCertified(pizza));

        isAbstract(Recipe.class);
        fieldsArentPublic(MargueritaRecipe.class);
    }



    @Test
    public void testGenericRecipe() {
        PizzaCertifier certifier = new MargueritaCertifier();

        List<Ingredient> ingredients = new ArrayList<>();
        ingredients.add(new Ingredient("Mozzarella"));
        ingredients.add(new Ingredient("Ham"));
        ingredients.add(new Ingredient("Pineapple"));

        Recipe recipe = new GenericRecipe(ingredients);
        Pizza pizza1 = recipe.makeMediumPizza();
        assertFalse(certifier.isCertified(pizza1));

        ingredients.remove(2);
        ingredients.remove(1);
        ingredients.add(new Ingredient("Tomato"));
        ingredients.add(new Ingredient("Basil"));

        Pizza pizza2 = recipe.makeMediumPizza();
        assertTrue(certifier.isCertified(pizza2));

        fieldsArentPublic(GenericRecipe.class);
    }



    @Test
    public void testSlicedPizza() {
        PizzaCertifier certifier = new MargueritaCertifier();

        Recipe recipe = new MargueritaRecipe();

        Pizza pizza = recipe.makeMediumPizza();
        Pizza sliced = new SlicedPizza(pizza, 8);

        assertTrue(certifier.isCertified(pizza));
        assertTrue(certifier.isCertified(sliced));

        assertEquals(8, ((SlicedPizza) sliced).getSlices());

        fieldsArentPublic(SlicedPizza.class);
        assertTrue(sliced instanceof Pizza);
        assertTrue(pizza instanceof Pizza);
    }



    @Test
    public void testPizzaPrice()
    {
        Recipe recipe = new MargueritaRecipe();

        Pizza pizza = recipe.makeMediumPizza();
        assertEquals(0, pizza.getPrice(), 0.01);

        pizza.setPrice(8.0);
        assertEquals(8.0, pizza.getPrice(), 0.01);

        // A sliced pizza always costs 2 more moneys
        Pizza sliced = new SlicedPizza(pizza, 8);
        assertEquals(10.0, sliced.getPrice(), 0.01);

        // Even if price of original pizza changes after slicing
        pizza.setPrice(6.0);
        assertEquals(8.0, sliced.getPrice(), 0.01);
    }

    @Test
    public void extraTest()
    {
        Recipe recipe = new MargueritaRecipe();
        Pizza pizza = recipe.makeMediumPizza();
        assertEquals(0, pizza.getPrice(), 0.01);
        pizza.setPrice(8.0);
        assertEquals(8.0, pizza.getPrice(), 0.01);
        // A sliced pizza always costs 2 more moneys
        Pizza sliced = new SlicedPizza(pizza, 8);
        assertEquals(10.0, sliced.getPrice(), 0.01);
        // Even if price of original pizza changes after slicing
        pizza.setPrice(6.0);
        assertEquals(8.0, sliced.getPrice(), 0.01);
        // If the price of the sliced pizza changes
        sliced.setPrice(4.0);
        assertEquals(6.0, sliced.getPrice(), 0.01);

    }

}