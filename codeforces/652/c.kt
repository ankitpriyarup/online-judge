private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args: Array<String>) {
    val (n, m) = readInts()
    val p = readInts().map { it - 1 }
    val inv = IntArray(n)
    for (i in 0 until n) {
        inv[p[i]] = i
    }

    val ends = IntArray(n) { n }
    for (i in 0 until m) {
        val (a, b) = readInts()
        val x = inv[a - 1]
        val y = inv[b - 1]
        if (x < y) {
            ends[x] = Math.min(ends[x], y)
        } else {
            ends[y] = Math.min(ends[y], x)
        }
    }

    var ans: Long = 0
    var r = n - 1
    for (l in n - 1 downTo 0) {
        r = Math.min(r, ends[l] - 1)
        ans += (r - l + 1)
    }

    println(ans)
}
