import java.time.Clock;
import java.time.ZoneId;
/*from w w w .j  av  a  2 s . c  o  m*/
public class Main {
  public static void main(String[] args) {
    Clock clock = Clock.system(ZoneId.systemDefault());
    System.out.println(clock);
    System.out.println(clock.instant());
  }
}
