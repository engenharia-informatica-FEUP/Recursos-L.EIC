import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class IcecreamMachine
{
    private Icecream icecream;
    private Stack<Command> commands = new Stack<>();

    public IcecreamMachine(Icecream icecream)
    {
        this.icecream = icecream;
    }

    public void executeCommand(Command command)
    {
        this.commands.push(command);
        command.execute(this.icecream);
    }

    public void undoLastCommand()
    {
        this.commands.peek().undo(this.icecream);
        this.commands.pop();
    }
}
