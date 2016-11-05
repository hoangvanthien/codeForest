/**
 * Created by macbookair on 6/22/16.
 */

import java.io.*;
import java.util.StringTokenizer;

public class UVa10363 {
	public static void main(String[] args) throws IOException {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		if (System.getProperty("ONLINE_JUDGE") == null) {
			inputStream = new FileInputStream("input.inp");
			outputStream = new FileOutputStream("output.out");
		} else {
			inputStream = System.in;
			outputStream = System.out;
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(in, out);
		out.close();
	}

//	static final int N = 100005;
//	static final int oo = 1000000007;
//	static final double pi = Math.acos(-1);

	static class Task {
		int[][] a = new int[4][4];
		int winX = 0, winO = 0;

		boolean checkCol(int i) {
			if (a[1][i] == 0) return false;
			for (int j = 1; j <= 3; ++j) if (a[j][i] != a[1][i]) return false;
			if (a[1][i] == 1) winX++;
			else winO++;
			return true;
		}

		boolean checkRow(int i) {
			if (a[i][1] == 0) return false;
			for (int j = 1; j <= 3; ++j) if (a[i][j] != a[i][1]) return false;
			if (a[i][1] == 1) winX++;
			else winO++;
			return true;
		}

		void checkDiag() {
			if (a[1][1] != 0) {
				boolean flag = true;
				for (int i = 1; i <= 3; ++i)
					if (a[i][i] != a[1][1]) {
						flag = false;
						break;
					}
				if (flag) if (a[1][1] == 1) winX++;
				else winO++;
			}
			if (a[1][3] != 0) {
				boolean flag = true;
				for (int i = 1; i <= 3; ++i)
					if (a[i][4 - i] != a[1][3]) {
						flag = false;
						break;
					}
				if (flag) if (a[1][3] == 1) winX++;
				else winO++;
			}
		}

		public void solve(InputReader in, PrintWriter out) {
			int n = in.nextInt();
//			out.print(n);
//			out.flush();
			for (int ccase = 1; ccase <= n; ++ccase) {
				winX = 0;
				winO = 0;
				for (int i = 1; i <= 3; ++i) {
					String s = in.next();
//					out.println(s);
//					out.flush();
					if (i == 4) continue;
					for (int j = 1; j <= 3; ++j)
						if (s.charAt(j - 1) == 'X') a[i][j] = 1;
						else if (s.charAt(j - 1) == 'O') a[i][j] = -1;
						else a[i][j] = 0;
				}
				int cntX = 0, cntO = 0;
				for (int i = 1; i <= 3; ++i)
					for (int j = 1; j <= 3; ++j) {
						cntX += a[i][j] == 1 ? 1 : 0;
						cntO += a[i][j] == -1 ? 1 : 0;
					}
				if (cntO > cntX || cntX - cntO > 1) {
					out.println("no");
				} else {
					boolean[] c = new boolean[4], r = new boolean[4];
					for (int i = 1; i <= 3; ++i) {
						c[i] = checkCol(i);
						r[i] = checkRow(i);
					}
					checkDiag();
					if ((winX > 0 && winO > 0) || (winX > 0 && cntX - cntO != 1) || (winO > 0 && cntX != cntO) || (cntX != cntO && cntX != cntO + 1))
						out.println("no");
					else out.println("yes");
//					if ((c[1] && c[2]) || (c[1] && c[3]) || (c[2] && c[3]) || (r[1] && r[2]) || (r[2] && r[3]) || (r[1] && r[3])) {
//
//						out.println("no");
//					} else {
//						if ((winX > 0 && winO > 0) || (winX > 0 && cntO >= cntX) || (winO > 0 && cntX > cntO) || winX > 1 || winO > 1)
//							out.println("no");
//						else
//							out.println("yes");
//					}
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

	}
}
