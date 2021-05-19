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

    static int swaps = 0;
    static int tries = 0;
    static int n = 52;
    static int cards[];
    static int swapNum = 0, tryNum = 0;
    static int S, T, target;

    static void doSwap(int s1, int s2) {
        if (s1 < 0 || s2 < 0 || s1 >= n || s2 >= n) {
            System.out.printf("Invalid swap: %d %d\n", s1, s2);
            System.exit(0);
        }
        int tmp = cards[s1];
        cards[s1] = cards[s2];
        cards[s2] = tmp;

        System.out.printf("Swap #%d: %d %d\n", ++swapNum, s1, s2);
        if (swapNum > S) {
            System.out.printf("Swap limit exceeded.\n");
            System.exit(0);
        }

    }

    static int guess(int idx) {
        if (idx < 0 || idx >= n) {
            System.out.printf("Invalid try: %d\n", idx);
            System.exit(0);
        }
        System.out.printf("Try #%d: index = %d, value = %d\n", tryNum++, idx, cards[idx]);
        if (tryNum > T) {
            System.out.printf("Guess limit exceeded.\n");
            System.exit(0);
        }

        if (cards[idx] == target) {
            System.out.printf("Correct!");
            System.exit(0);
        }
        return cards[idx];
    }

    public static void main(final String[] args) throws IOException {

        InputReader reader = new InputReader(System.in);
        System.out.printf("Enter input:\n");
        S = reader.readInt();
        T = reader.readInt();
        int[] c = new int[52];
        cards = new int[52];

        for (int i = 0; i < n; i++) {
            cards[i] = reader.readInt();
            c[i] = cards[i];
        }

        FirstPlayer f = new FirstPlayer();
        SecondPlayer s = new SecondPlayer();
        f.swapCards(c, S, T);

        target = reader.readInt();

        s.guessCard(S, T, target);

    }
}