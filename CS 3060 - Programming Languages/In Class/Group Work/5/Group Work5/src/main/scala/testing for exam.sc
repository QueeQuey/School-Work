/*
object Counter {
  var count = 0

  def increment(x: Int): Unit = {
    count += x
  }
  def reset(): Unit = {
    count = 0
  }
}

Counter.increment(5)
Counter.increment(3)
println(Counter.count)
Counter.reset()
println(Counter.count)
*/
/*
object Sums {
  def sums(nums: Array[Int], target: Int): Array[Int] = {
    val index = scala.collection.mutable.Map[Int, Int]()

    for (i <- nums.indices) {
      val complement = target - nums(i)
      if (index.contains(complement)) {
        return Array(index(complement), i)
      }
      index(nums(i)) = i
    }

    Array()
  }

  def main(args: Array[String]): Unit = {
    println("Hello World")
    val nums = Array(2, 7, 11, 15)
    val target = 9
    val result = sums(nums, target)
    println(result.mkString(", "))
  }
}
*/
/*
val movies = <movies> 
  <movie> <title> The Incredibles </title> <hero> Mr. abc </hero> </movie>
  <movie> <title> WALL E </title> <hero> Mr. def </hero> </movie>
</movies>
val y = movies \ "movie"
y.map(y1 => (y1 \ "hero").map( y2 => println(y2)))

val pattern = """\w*no(u)?r""".r
val str = "British people honour while Americans honor"
println((pattern findAllIn str).mkString(","))
*/


//Variable m is a map. Map must contain a string then int. Returns a List of strings.
def foo(m: Map[String, Int]): List[String] = {
  m.filter { case (_, x) => //Only evalute the X value
      x >= 25 &&
      x <= 100 }
    .keys.toList //Get the keys, put into list.
}
//T
val m = Map("xyz" -> 17, "abc" -> 11, "ghex" -> 2, "akjsdjf" -> 57, "iaBSD" -> 99)
val result = foo(m)
//println("Running...2")
println(result) //Should ONLY return the strings, not the ints.