import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Concert
{
    private final List<Act> acts = new ArrayList<>();
    private final String city;
    private final String country;
    private final String date;
    private int id = 1;

    public Concert(String city, String country, String date)
    {
        this.city = city;
        this.country = country;
        this.date = date;
    }

    public int getId() { return this.id; }

    public void incrementId() { id++; }

    public List<Act> getActs() { return this.acts; }

    public void addAct(Act act){ acts.add(act); }

    public String getCity() {return this.city; }

    public String getCountry() { return this.country; }

    public String getDate() { return this.date; }

    @Override
    public boolean equals(Object o)
    {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Concert concert = (Concert) o;
        return Objects.equals(city, concert.city) && Objects.equals(country, concert.country) && Objects.equals(date, concert.date);
    }

    @Override
    public int hashCode() {
        return Objects.hash(city, country, date);
    }

    public boolean isValid(Ticket ticket)
    {
        return ticket.getConcert().equals(this);
    }

    public boolean participates(Artist artist)
    {

        for (Act act : this.getActs())
        {
            if (act instanceof Band && ((Band) act).getArtists().contains(artist))
                return true;
            else if(act.equals(artist))
                return true;
        }
        return false;
    }
}
