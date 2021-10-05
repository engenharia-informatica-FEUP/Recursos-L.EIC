import java.util.ArrayList;
import java.util.List;

public abstract class Recipe
{

    private List<Ingredient> ingredients = new ArrayList<>();
    public Recipe()
    {
    }

    public Recipe(List<Ingredient> ingredients) { this.ingredients = ingredients; }

    public void setIngredients(List<Ingredient> ingredients) { this.ingredients = ingredients; }

    public List<Ingredient> getIngredients() { return this.ingredients; }

    public abstract Pizza makeMediumPizza();
}
