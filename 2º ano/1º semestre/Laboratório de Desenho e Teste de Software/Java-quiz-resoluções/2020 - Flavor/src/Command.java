public interface Command
{
    void execute(Icecream icecream);
    void undo(Icecream icecream);
}
