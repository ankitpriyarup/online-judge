private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args: Array<String>) {
    val n = readInt()
    val a = readInts()
    var m1 = -1
    var m2 = -1
    var ans = 0
    for (x in a) {
        if (x >= m1) {
            m2 = m1;
            m1 = x;
        } else if (x >= m2) {
            m2 = x;
        } else {
            ans++
        }
    }

    println(ans)
}
