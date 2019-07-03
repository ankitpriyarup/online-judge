private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args: Array<String>) {
    val q = readInt()
    val ans = mutableListOf<String>()
    for (x in 0 until q) {
        val s = readLn()
        val t = readLn()
        var i = 0
        var j = 0
        val n = s.length
        val m = t.length
        var valid = true
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else if (s[i] == '-' && i + 1 < n && s[i + 1] == '-') {
                i += 2;
                j++;
            } else {
                valid = false;
                break;
            }
        }

        valid = valid && (i == n) && (j == m);
        if (valid) {
            ans.add("YES");
        } else {
            ans.add("NO");
        }
    }

    println(ans.joinToString("\n"))
}
