import java.io.*;
import java.util.*;

public class Main {
    static int x;
    static int y;
    static int z;
    static int[][][] arr = new int[21][21][21];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        try {
            for (int x = 0; x <= 20; x++) {
                for (int y = 0; y <= 20; y++) {
                    for (int z = 0; z <= 20; z++) {
                        arr[x][y][z] = w(x, y, z);
                    }
                }
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }


        int de = 1;
        while (true) {
            StringTokenizer st;
            st = new StringTokenizer(br.readLine());

            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            z = Integer.parseInt(st.nextToken());

            if (x == -1 && y == -1 && z == -1) {
                break;
            }

            int num = w(x,y,z);
            bw.write("w(" + x + ", " + y + ", " + z + ") = " + num + "\n");
            bw.flush();
        }

        bw.close();
        br.close();
    }

    private static int w(int x, int y, int z) {
        if (x <= 0 || y <= 0 || z <= 0) {
            return 1;
        } else if (x > 20 || y > 20 || z > 20) {
            return w(20, 20, 20);
        } else if (x<y && y<z) {
            if(arr[x][y][z] != 0) {
                return arr[x][y][z];
            }
            return w(x,y,z-1)+w(x,y-1,z-1)-w(x,y-1,z);
        } else {
            if(arr[x][y][z] != 0) {
                return arr[x][y][z];
            }
            return w(x-1,y,z)+w(x-1,y-1,z)+w(x-1,y,z-1)-w(x-1,y-1,z-1);
        }
    }
}