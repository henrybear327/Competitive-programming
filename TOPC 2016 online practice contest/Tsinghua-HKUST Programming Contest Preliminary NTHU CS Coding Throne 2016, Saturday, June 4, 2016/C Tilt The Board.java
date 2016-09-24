import java.io.*;
import java.util.*;

public class Main {
	public static int ans;

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));

		// Start writing your solution here.
		int ncase = sc.nextInt();

		while (ncase-- > 0) {
			ans = 0;

			int size = sc.nextInt(), redBall = sc.nextInt(), blueSquare = sc.nextInt(), holes = sc.nextInt(),
					query = sc.nextInt();
			
			Node[][] maze = new Node[size][size];
			
			for(int i = 0; i < size; i++)
				for(int j = 0; j < size; j++)
					maze[i][j] = new Node();

			// read map
			for (int i = 0; i < size; i++) {
				String str = sc.nextLine();
				char[] inp = str.toCharArray();
				
				for (int j = 0; j < size; j++) {
					if ('0' <= inp[j] && inp[j] <= '9')
						maze[i][j].setWall(inp[j] - '0');
					else
						maze[i][j].setWall(inp[j] - 'A' + 10);
				}
			}

			for (int i = 0; i < redBall; i++) {
				int x = sc.nextInt(), y = sc.nextInt();
				x--;
				y--;
				maze[x][y].hasBall = 1;
			}

			for (int i = 0; i < blueSquare; i++) {
				int x = sc.nextInt(), y = sc.nextInt();
				x--;
				y--;
				maze[x][y].hasReward = 1;
			}

			for (int i = 0; i < holes; i++) {
				int x = sc.nextInt(), y = sc.nextInt();
				x--;
				y--;
				maze[x][y].isHole = 1;
			}

			String tmp = sc.nextLine();
			char[] cmd = tmp.toCharArray();
			for (int i = 0; i < query; i++) {
				tilt(cmd[i], maze, size);
			}

			out.println(ans);
		}

		// Stop writing your solution here.
		out.close();
	}

	public static void tilt(char dir, Node[][] maze, int size) {
		int nextX, nextY;
		int checkWall;

		if (dir == 'E') {
			nextX = 0;
			nextY = -1;
			checkWall = 0;
		} else if (dir == 'W') {
			nextX = 0;
			nextY = 1;
			checkWall = 2;
		} else if (dir == 'N') {
			nextX = 1;
			nextY = 0;
			checkWall = 1;
		} else { // S
			nextX = -1;
			nextY = 0;
			checkWall = 3;
		}

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (maze[i][j].hasBall == 1) {
					int px = -1, py = -1, x = i, y = j;
					while (maze[x][y].wall[checkWall] == 0) {
						x += nextX;
						y += nextY;

						if (maze[x][y].hasReward == 1) {
							maze[x][y].hasReward = 0;
							ans++;
						}
						if (maze[x][y].isHole == 1) {
							maze[x][y].isHole = 0;
							maze[i][j].hasBall = 0;
							px = -1;
							break;
						}
						if (maze[x][y].hasBall == 0) {
							px = x;
							py = y;
						}
					}

					if (px != -1) {
						maze[i][j].hasBall = 0;
						maze[px][py].hasBall = 1;
					}
				}
			}
		}
	}

	public static class Node {
		public int wall[]; // W, S, E, N
		public int isHole;
		public int hasBall;
		public int hasReward;

		public Node() {
			wall = new int[4];
			Arrays.fill(wall, 0);
			isHole = 0;
			hasBall = 0;
			hasReward = 0;
		}

		public void setWall(int x) {
			for (int i = 0; i < 4; i++) {
				if (((x >> i) & 1) == 1) {
					wall[i] = 1;
				}
			}
		}
	}

	// PrintWriter for faster output
	public static PrintWriter out;

	// MyScanner class for faster input
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		boolean hasNext() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (Exception e) {
					return false;
				}
			}
			return true;
		}

		String next() {
			if (hasNext())
				return st.nextToken();
			return null;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
}