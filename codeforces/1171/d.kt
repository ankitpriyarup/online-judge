private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args: Array<String>) {
    val (x, y, z) = readInts()
    val (a, b, c) = readInts()
    val valid = a >= x && a + b >= x + y && a + b + c >= x + y + z
    println(if (valid) "YES" else "NO")
}
