import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Event
{
    private String title;
    private String date;
    private String description;
    private List<Person> people = new ArrayList<>();

    public Event(String title)
    {
        this.title = title;
        this.date = "";
        this.description = "";
    }
    public Event(String title, String date)
    {
        this.title = title;
        this.date = date;
        this.description = "";
    }
    public Event(String title, String date, String description)
    {
        this.title = title;
        this.date = date;
        this.description = description;
    }
    public Event(Event e)
    {
        this.title = e.title;
        this.date = e.date;
        this.description = e.description;
    }

    public String getTitle() { return this.title; }

    public void setTitle(String title) { this.title = title; }

    public String getDate() { return this.date; }

    public void setDate(String date) { this.date = date; }

    public String getDescription() { return this.description; }

    public void setDescription(String description) { this.description = description; }

    public List<Person> getPeople() { return this.people; }

    public void printEvent()
    {
        System.out.println(getTitle());
        System.out.println(" is a " + getDescription());
        System.out.println(" and will be held at " + getDescription() + ".");
    }

    @Override
    public String toString()
    {
        return getTitle() + " is a " + getDescription() + " and will be held at " + getDate() + ".";
    }

    @Override
    public boolean equals(Object o)
    {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Event event = (Event) o;
        return Objects.equals(title, event.title) && Objects.equals(date, event.date) && Objects.equals(description, event.description);
    }

    @Override
    public int hashCode()
    {
        return Objects.hash(title, date, description);
    }


    public int getAudienceCount()
    {
        return this.people.size();
    }

    public void addPerson(Person person)
    {
        if(!this.contains(person))
            this.people.add(person);
    }

    public boolean contains(Person person)
    {
        for (Person p: getPeople())
        {
            if(p.getName().equals(person.getName()))
                return true;
        }
        return false;
    }


    public void addEvent(Event e)
    {
        this.people.addAll(e.getPeople());
    }
}
