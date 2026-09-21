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
