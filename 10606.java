import java.math.BigInteger;
import java.util.Scanner;

public class 10606 {
	public static void main(String args[]) {
		BigInteger x, low, high, mid;
		String line;
		Scanner sc = new Scanner(System.in);
		while(true) {
			line = sc.nextLine();
			x = new BigInteger(line);
			if (x.compareTo(BigInteger.ZERO) == 0) break;
			low = BigInteger.ONE;
			high = x;
			mid = BigInteger.ONE;
			while((low.add(BigInteger.ONE)).compareTo(high) < 0) {
				mid = (low.add(high)).divide(BigInteger.valueOf(2));
				if ((mid.multiply(mid)).compareTo(x) < 0)
					low = mid;
				else if ((mid.multiply(mid)).compareTo(x) == 0) {
					low = mid;
					break;
				}
				else
					high = mid;
			}
			System.out.println((low.multiply(low)).toString());
		}
		sc.close();
	}
}
