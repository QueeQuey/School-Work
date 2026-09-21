import scala.io.Source
object Task3 {
  def main (args:Array[String]) = {
    val x = List(3, 0, 20, 5, 0, 0, 13)
    val y = foo(x)
    println(y)
  }
}

def foo(x: List[Int]): List[Int] = {
  val zeros = x.filter(_== 0) // List of all 0s
  val nonZeros = x.filter(_!= 0) // List of all non-zeros
  zeros ++ nonZeros
}

