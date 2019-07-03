private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args: Array<String>) {
    val t = readInt()
    for (x in 0 until t) {
        var (a, b) = readInts()
        if (a < b) {
            System.out.printf("%d %d %d\n", 1, a - 1, b - a + 1)
        } else {
            System.out.printf("%d %d %d\n", 1, b - 1, a - b + 1)
        }
    }
}
