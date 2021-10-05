import java.util.List;

public interface Pizza
{
    public List<Ingredient> getIngredients();

    public boolean contains(Ingredient ingredient);

    public boolean addIngredient(Ingredient ingredient);

    public int getIngredientCount();

    double getPrice();

    void setPrice(double v);
}
