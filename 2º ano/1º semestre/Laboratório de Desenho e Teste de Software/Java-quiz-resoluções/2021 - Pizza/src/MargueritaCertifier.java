public class MargueritaCertifier extends PizzaCertifier
{
    public MargueritaCertifier()
    {
    }

    @Override
    public boolean isCertified(Pizza pizza)
    {
        for (Ingredient i: pizza.getIngredients())
        {
            if (i.getName().equals("Tomato") || i.getName().equals("Mozzarella") || i.getName().equals("Basil"))
                continue;
            else
                return false;
        }
        if (pizza.getIngredients().size() != 3)
        {
            return false;
        }
        return true;
    }
}
