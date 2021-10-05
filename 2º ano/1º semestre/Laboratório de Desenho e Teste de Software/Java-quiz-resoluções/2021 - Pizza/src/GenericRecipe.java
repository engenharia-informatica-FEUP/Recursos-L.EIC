import java.util.ArrayList;
import java.util.List;

public class GenericRecipe extends Recipe
{

    public GenericRecipe(List<Ingredient> ingredients)
    {
        super(ingredients);
    }

    @Override
    public Pizza makeMediumPizza()
    {
        Pizza pizza = new MediumPizza();
        for (Ingredient i: this.getIngredients())
        {
            pizza.addIngredient(i);
        }
        return pizza;
    }
}
