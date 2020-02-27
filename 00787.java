import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

class Main {
	public static BigInteger buildDP(ArrayList<BigInteger> seq) {
		BigInteger record = seq.get(0), cur_tot;
		for (int i = 0; i < seq.size(); i++) {
			cur_tot = seq.get(i);
			record = record.max(cur_tot);
			for (int j = i+1; j < seq.size(); j++) {
				cur_tot = cur_tot.multiply(seq.get(j));
				record = record.max(cur_tot);
			}
		}
		return record;
	}
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N;
		BigInteger ans;
		ArrayList<BigInteger> seq = new ArrayList<BigInteger>();
		while(sc.hasNext()) {
			seq.clear();
			N = 0;
			while (true) {
				N = sc.nextInt();
				if (N == -999999) break;
				seq.add(BigInteger.valueOf(N));
			}
			ans = buildDP(seq);
			System.out.println(ans);
		}
		sc.close();
	}
}
