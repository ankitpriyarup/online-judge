private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args: Array<String>) {
    val t = readInt()
    for (x in 0 until t) {
        val n = readInt()
        val ans = when (n % 2) {
            0 -> n / 2
            1 -> 1 + (n - 3) / 2
            else -> 0
        }
        println(ans)
    }
}
