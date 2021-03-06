import java.util.*
import kotlin.math.max
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args : Array<String>) {
  var t = readInt();
  for (test in 0..t - 1) {
    var s = readLn();
    var ans = 0;
    var n:Int = s.length;
    for (i in 0..n - 1) {
      if (s[i] == 'w') {
        ans += 1;
      }
      if (i < n - 1 && s[i] == 'v' && s[i + 1] == 'v') {
        ans += 1;
      }
    }
    println(ans);
  }
}

