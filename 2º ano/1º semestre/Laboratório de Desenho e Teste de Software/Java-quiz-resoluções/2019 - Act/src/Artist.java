import java.util.Objects;

public class Artist extends Act
{
    private String name;
    private String country;

    Artist(String name, String country)
    {
        this.name = name;
        this.country = country;
    }

    public String getName() { return this.name; }

    public String getCountry() { return this.country; }

    @Override
    public boolean equals(Object o)
    {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Artist artist = (Artist) o;
        return Objects.equals(name, artist.name) && Objects.equals(country, artist.country);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, country);
    }
}
