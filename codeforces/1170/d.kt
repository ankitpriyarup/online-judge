import java.io.*
import java.util.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args: Array<String>) {
    val n = readInt()
    val a = readInts()
    val m = a.count({ it == -1 })
    val res = mutableListOf<MutableList<Int>>()
    val ts = TreeSet<Int>()
    for (x in 0 until m) {
        res.add(mutableListOf<Int>())
        ts.add(x)
    }

    var p = 0
    for (i in 0 until n) {
        if (a[i] == -1) {
            ts.remove(p)
        } else {
            res[p].add(a[i])
        }
        if (ts.isEmpty()) break;

        if (p >= ts.last()) {
            p = ts.first()
        } else {
            p = ts.higher(p)
        }
    }

    println(m)
    val outpr = mutableListOf<String>()
    for (i in 0 until m) {
        outpr.add(String.format("%d %s", res[i].size, res[i].joinToString(" ")))
    }
    println(outpr.joinToString("\n"))
}
