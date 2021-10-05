import java.util.List;

public class SlicedPizza implements Pizza
{
    private Pizza pizza;
    private int slices;
    private double price;

    public SlicedPizza(Pizza pizza, int slices)
    {
        this.pizza = pizza;
        this.slices = slices;
    }

    public int getSlices() { return this.slices; }

    @Override
    public List<Ingredient> getIngredients() { return this.pizza.getIngredients(); }

    @Override
    public boolean contains(Ingredient ingredient)
    {
        for (Ingredient i: pizza.getIngredients())
        {
            if(i.equals(ingredient) || i.getName().equals(ingredient.getName()))
                return true;
        }
        return false;
    }

    @Override
    public boolean addIngredient(Ingredient ingredient)
    {
        if(!this.contains(ingredient))
        {
            this.pizza.addIngredient(ingredient);
            return true;
        }
        return false;
    }

    @Override
    public int getIngredientCount() { return this.pizza.getIngredientCount(); }

    @Override
    public double getPrice() { return this.pizza.getPrice() + 2.0; }

    @Override
    public void setPrice(double price) { this.pizza.setPrice(price); }
}
