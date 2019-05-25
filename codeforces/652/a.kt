private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args: Array<String>) {
    val (h1, h2) = readInts()
    val (a, b) = readInts()

    // get to 10 pm
    var x = h1
    x += 8 * a
    if (x >= h2) {
        println(0)
        return
    }
    if (a <= b) {
        println(-1)
        return
    }

    var ans = 0
    while (x < h2) {
        x += 12 * (a - b)
        ans += 1
    }

    println(ans)
}
