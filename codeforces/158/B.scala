import scala.io.StdIn
import scala.language.implicitConversions

object B {
  implicit def toInt(b: Boolean) = if (b) 1 else 0

  def main(args: Array[String]) = {
    val n = StdIn.readLine.toInt
    val s = StdIn.readLine.split(" ").map(_.toInt)
    val freqMap: Map[Int, Int] = s.groupBy(x => x).mapValues(_.length)
    
    val ones = freqMap.getOrElse(1, 0)
    val twos = freqMap.getOrElse(2, 0)
    val threes = freqMap.getOrElse(3, 0)
    val fours = freqMap.getOrElse(4, 0)

    val mod = if (twos % 2 == 1) 2 else 0
    val ans = fours + threes + (twos + 1) / 2 + Math.max(ones - threes - mod + 3, 0) / 4
    println(ans)
  }
}
