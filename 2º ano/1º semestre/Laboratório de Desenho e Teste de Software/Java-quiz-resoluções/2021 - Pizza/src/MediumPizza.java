import java.util.ArrayList;
import java.util.List;

public class MediumPizza implements Pizza
{
    private List<Ingredient> ingredients = new ArrayList<>();
    private double price = 0;

    public MediumPizza()
    {
    }
    @Override
    public List<Ingredient> getIngredients()
    {
        return this.ingredients;
    }

    @Override
    public boolean contains(Ingredient ingredient)
    {
        for (Ingredient i: getIngredients())
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
            this.ingredients.add(ingredient);
            return true;
        }
        return false;
    }

    @Override
    public int getIngredientCount() { return this.ingredients.size(); }

    @Override
    public double getPrice() { return this.price; }

    @Override
    public void setPrice(double price) { this.price = price; }
}
