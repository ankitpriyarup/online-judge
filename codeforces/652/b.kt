private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args: Array<String>) {
    val n = readInt()
    var a = readInts()
    a = a.sorted()
    val b = mutableListOf<Int>()
    var l = 0
    var r = n - 1
    while (l < r) {
        b.add(a[l])
        b.add(a[r])
        l++
        r--
    }

    if (l == r) {
        b.add(a[l])
    }
    println(b.joinToString(" "))
}
