import java.math.BigInteger;
import java.util.Scanner;

public class 10359 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N;
		BigInteger triang[] = new BigInteger[251];
		triang[0] = BigInteger.ONE;
		triang[1] = BigInteger.ONE;
		triang[2] = BigInteger.valueOf(3);
		for (int i = 3; i <= 250; i++) {
			triang[i] = triang[i-1].add(triang[i-2].multiply(BigInteger.valueOf(2)));
		}
		while(sc.hasNextInt()) {
			N = sc.nextInt();
			System.out.println(triang[N].toString());
		}
		sc.close();
	}
}
