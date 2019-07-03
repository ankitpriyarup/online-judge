private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args: Array<String>) {
    val (n, m) = readInts()
    val a = ArrayList(readStrings().map { it.toLong() })
    for (i in 1 until n) {
        a[i] += a[i - 1]
    }

    val q = readInt()
    val res = Array<String>(q) { "" }

    for (tc in 0 until q) {
        // println("-------")
        val b = ArrayList(readInts())
        b[0] = 0
        b.add(m + 1)

        val k = b.size
        var p = 0
        var bef = 0L
        for (x in 1 until k) {
            if (p >= n) break

            val gap = b[x] - b[x - 1] - 1
            // println("GAP: " + gap.toString())
            if (a[p] - bef > gap) {
                continue;
            } else if (a[n - 1] - bef <= gap) {
                p = n
                break
            }

            var lo = p
            var hi = n - 1
            while (lo + 1 < hi) {
                val mid = lo + (hi - lo) / 2
                val range = a[mid] - bef
                if (range <= gap) {
                    lo = mid
                } else {
                    hi = mid
                }
            }

            p = hi
            bef = a[lo]
            // println("P: " + p.toString())
        }

        if (p >= n) {
            res[tc] = "YES"
        } else {
            res[tc] = "NO"
        }
    }

    println(res.joinToString("\n"))
}
