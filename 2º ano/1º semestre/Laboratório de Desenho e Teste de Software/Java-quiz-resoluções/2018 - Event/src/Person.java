
public abstract class Person extends User implements Comparable
{
    private String name;
    private int age;

    public Person(String name, int age)
    {
        this.name = name;
        this.age = age;
    }
    public Person(String name)
    {
        this.name = name;
    }

    public String getName() { return this.name; }

    public int getAge() { return this.age; }

    public abstract String toString();

    @Override
    public int compareTo(Object o)
    {
        Person person = (Person) o;

        return person.getName().compareTo(name);
    }


    public String getUsername()
    {
        return this.getName() + this.getAge();
    }
}
