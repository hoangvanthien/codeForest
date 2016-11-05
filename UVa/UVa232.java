/**
 * Created by macbookair on 6/22/16.
 */

import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class UVa232 {
	//class Main {
	public static void main(String[] args) throws IOException {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
//		if (System.getProperty("ONLINE_JUDGE") == null) {
//			inputStream = new FileInputStream("input.inp");
//			outputStream = new FileOutputStream("output.out");
//		} else {
//			inputStream = System.in;
//			outputStream = System.out;
//		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(in, out);
		out.close();
	}

	static final int N = 100005;
	static final int oo = 1000000007;
	static final double pi = Math.acos(-1);

	static class Task {


		public void solve(InputReader in, PrintWriter out) {
			int __case = 0;
			while (true) {

				char[][] a = new char[11][11];
				int[][] ind = new int[11][11];
				int m = in.nextInt(), n = 0;
				if (m == 0) break;
				else n = in.nextInt();
				if (__case != 0) out.println();
				for (int i = 1; i <= m; ++i) {
					String s = in.next();
					for (int j = 1; j <= n; ++j) a[i][j] = s.charAt(j - 1);
				}
				int cnt = 0;
				for (int i = 1; i <= m; ++i)
					for (int j = 1; j <= n; ++j)
						if (a[i][j] != '*') {
							if (i - 1 == 0 || j - 1 == 0) ind[i][j] = ++cnt;
							else if (a[i - 1][j] == '*' || a[i][j - 1] == '*') ind[i][j] = ++cnt;
						}
				ArrayList<String> across = new ArrayList(), down = new ArrayList();
				ArrayList<Integer> _across = new ArrayList(), _down = new ArrayList();
				for (int i = 1; i <= m; ++i)
					for (int j = 1; j <= n; ++j)
						if (ind[i][j] != 0) {
							int k = j;
//							String temp = String.format("%d.", ind[i][j]);
							String temp = "";
							if (j - 1 == 0 || a[i][j - 1] == '*') {
								while (k <= n && a[i][k] != '*') temp += a[i][k++];
								across.add(temp);
								_across.add(ind[i][j]);
							}
							if (i - 1 == 0 || a[i - 1][j] == '*') {
								k = i;
//								temp = String.format("%d.", ind[i][j]);
								temp = "";
								while (k <= m && a[k][j] != '*') temp += a[k++][j];
								down.add(temp);
								_down.add(ind[i][j]);
							}
						}
				out.format("puzzle #%d:\nAcross\n", ++__case);
				for (int i = 0; i < across.size(); ++i) {
					out.format("%3d.", _across.get(i));
					out.println(across.get(i));
				}
				out.println("Down");
				for (int i = 0; i < down.size(); ++i) {
					out.format("%3d.", _down.get(i));
					out.println(down.get(i));
				}

			}
		}
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public char nextChar() {
			return next().charAt(0);
		}
	}
}
