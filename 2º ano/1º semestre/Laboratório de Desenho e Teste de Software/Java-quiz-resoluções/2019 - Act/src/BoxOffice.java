import java.util.ArrayList;
import java.util.List;

public class BoxOffice
{
    static List<Ticket> buy(Concert concert, int quantity) throws InvalidTicket
    {
        List<Ticket> tickets = new ArrayList<>();

        for (int i = 1; i <= quantity; i++)
        {
            tickets.add(new Ticket(concert.getId(), concert));
            concert.incrementId();
        }
        return tickets;
    }
}
