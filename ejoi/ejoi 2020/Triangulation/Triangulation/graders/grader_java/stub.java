import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;

public class stub {

    static class InputReader {
        private final InputStream stream;
        private final byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(final InputStream stream) {
            this.stream = stream;
        }

        public void close() {
            try {
                this.stream.close();
            } catch (final IOException e) {
            }
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (final IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = eatWhite();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String readString() {
            int c = eatWhite();
            final StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c))
                    res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public String readLine() {
            final StringBuilder res = new StringBuilder();
            while (true) {
                final int c = read();
                if (c == '\n' || c == '\r' || c == -1)
                    break;
                if (Character.isValidCodePoint(c))
                    res.appendCodePoint(c);
            }
            return res.toString();
        }

        private int eatWhite() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            return c;
        }

        public static boolean isSpaceChar(final int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }

    public static int n, h;
    public static InputReader fifo_in;

    public static void invalid() {
        System.err.println("Invalid Query");
        System.exit(1);
    }

    public static int query(int a, int b) {
        if (a < 0 || a >= n)
            invalid();
        if (b < 0 || b >= n)
            invalid();
        System.out.printf("? %d %d\n", a, b);
        System.out.flush();
        int res = fifo_in.readInt();
        return res;
    }

    static void answer(int a, int b) {
        System.out.printf("Guess: %d %d\n", a, b);
        System.exit(0);
    }

    public static void main(final String[] args) {
        System.out.print("Enter n: ");
        fifo_in = new InputReader(System.in);
        n = fifo_in.readInt();

        int res = new Triangulation().solve(n);
        answer(res / n, res % n);
        System.out.println("Something went wrong");
    }
}