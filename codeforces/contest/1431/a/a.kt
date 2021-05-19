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
    var n = readInt();
    var a = readLongs();
    var ans:Long = 0;
    for (i in 0..n - 1) {
      var p:Long = 0;
      for (j in 0..n - 1) {
        if (a[i] <= a[j]) {
          p += 1;
        }
      }
      ans = max(p * a[i], ans);
    }
    println(ans);
  }
}

