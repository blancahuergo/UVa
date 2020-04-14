import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger x;
		int y;
		while(true) {
			x = sc.nextBigInteger();
			if (x.compareTo(BigInteger.ZERO) == 0) break;
			y = sc.nextInt();
			System.out.println((x.pow(y)).toString());
		}
		sc.close();
	}

}
