import java.util.Random;

public class Randomizer {
	Random r = new Random();
	public int randInt(int max) {
		return r.nextInt((max - 0) + 1) + 0;
	}

}
