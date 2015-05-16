import scala.io.StdIn

object A {
  def main(args: Array[String]) = {
    val n :: m :: _ = StdIn.readf("{0,number} {1,number}").collect { case l: Long => l}
    println(n * m / 2)
  }
}
