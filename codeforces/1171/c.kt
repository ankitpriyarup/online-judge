private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args: Array<String>) {
    val t = readInt()
    for (x in 0 until t) {
        val s = readLn().toCharArray()
        s.sort()
        val ans = if (s.first() == s.last()) "-1" else String(s)
        println(ans)
    }
}
