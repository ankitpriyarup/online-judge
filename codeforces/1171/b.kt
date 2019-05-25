private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args: Array<String>) {
    val (y, b, r) = readInts()
    val x = Math.min(y + 1, Math.min(b, r - 1))
    println(3 * x)
}
