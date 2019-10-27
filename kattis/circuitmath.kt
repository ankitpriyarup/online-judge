import java.io.*
import java.util.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args: Array<String>) {
    val n = readInt()
    val values = readStrings().map { it == "T" }
    val stk = mutableListOf<Boolean>()
    for (token in readStrings().map { it[0] }) {
        when (token) {
            '-' -> {
                val a = stk.removeAt(stk.size - 1)
                stk.add(a.not()) // This is horrifying to me
            }
            '*' -> {
                val a = stk.removeAt(stk.size - 1)
                val b = stk.removeAt(stk.size - 1)
                stk.add(a and b)
            }
            '+' -> {
                val a = stk.removeAt(stk.size - 1)
                val b = stk.removeAt(stk.size - 1)
                stk.add(a or b)
            }
            else -> stk.add(values[token - 'A'])
        }
    }

    println(if (stk[0]) "T" else "F")
}
