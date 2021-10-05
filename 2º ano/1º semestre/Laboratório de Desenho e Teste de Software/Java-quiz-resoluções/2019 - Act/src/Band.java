import java.util.ArrayList;
import java.util.List;

public class Band extends Act
{
    private final String name;
    private final String country;
    private final List<Artist> artists = new ArrayList<>();

    Band(String name, String country)
    {
        this.name = name;
        this.country = country;
    }

    public String getName() { return this.name; }

    public String getCountry() { return this.country; }

    public void addArtist(Artist artist)
    {
        this.artists.add(artist);
    }

    public List<Artist> getArtists()
    {
        return this.artists;
    }

    public boolean containsArtist(Artist artist)
    {
        for(int i = 0; i < this.getArtists().size(); i++)
        {
            if(this.getArtists().get(i).equals(artist))
            {
                return true;
            }
        }
        return false;
    }
}
