private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args: Array<String>) {
    val n = readInt()
    val s = readLn()
    val freq = Array(26) { 0 }
    for (c in s) {
        freq[c - 'a']++
    }

    val valid = n == 1 || freq.filter({ it > 0 }).size == 1 || freq.any({ it > 1 })
    println(if (valid) "Yes" else "No")
}
