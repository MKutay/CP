private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args : Array<String>) {
  var n = readInt();
  var a:List<Int> = readInts();
  var w = 'l';
  var ans:String = "";
  for (j in n - 1 downTo 1) {
    if (a[j] > 0) {
      for (i in 0..a[j] - 1) {
        for (k in 0..j) {
          ans += w;
        }
        if (w == 'l') {
          w = 'o';
        } else {
          w = 'l';
        }
      }
      for (i in j - 1 downTo 0) {
        a[i] -= (a[j] * (j - i + 1)).toInt();
      }
    }
  }
  println(ans);
}

