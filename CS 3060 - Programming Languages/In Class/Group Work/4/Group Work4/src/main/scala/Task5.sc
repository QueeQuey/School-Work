import scala.io.Source
//object Task5 {
  //def main(args: Array[String]) = {
    val list = List(1, 9, 7, 4)

    list.foreach(x => println(x * x)) // Prints out the square of each!

    val list2 = list.map(x => x * x) // Prints out the whole list squared due to applying to the whole map!

    val list3 = list.filter(x => x > 7) // Only outputs List(9) since 9 is the first element greater to 7.

    val y = list.exists(x => x > 5) // Returns true since a number greater than 5 exists in the list.

    val z = list.forall(x => x > 5) // False because not all are greater than 5.

    //}
//}