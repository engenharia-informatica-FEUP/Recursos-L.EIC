import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Icecream
{
    List<Flavor> scoops = new ArrayList<>();

    public void addScoop(Flavor flavor)
    {
        this.scoops.add(flavor);
    }

    public void removeScoop(Flavor flavor)
    {
        this.scoops.remove(flavor);
    }

    public int getScoopCount()
    {
        return this.scoops.size();
    }

    public List<Flavor> getScoops()
    {
        return this.scoops;
    }

    public boolean contains(String flavor)
    {
        for (Flavor scoop: this.getScoops())
        {
            if(scoop.getName().equals(flavor))
                return true;
        }
        return false;
    }

    public int getFlavorCount()
    {
        Set<Flavor> distinct_flavors = new HashSet<Flavor>(this.getScoops());
        return distinct_flavors.size();
    }
}
