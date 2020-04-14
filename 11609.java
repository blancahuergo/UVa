import java.math.BigInteger;
import java.util.Scanner;

public class 11609 {
	public static void main(String[] args) {
		int T, N;
		BigInteger ans, two, mod;
		two = BigInteger.valueOf(2);
		mod = BigInteger.valueOf(1000000007);
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			N = sc.nextInt();
			ans = two.modPow(BigInteger.valueOf(N-1), mod).multiply(BigInteger.valueOf(N)).mod(mod);
			System.out.println("Case #" + t + ": " + ans.toString());
		}
		sc.close();
	}
}
