//Layne Woodruff, Vanessa Burback, Caeli Empcke
import scala.collection.parallel.CollectionConverters._

val list1 = (1 to 10).toList // make a list of 1 to 10

val list2 = (1 to 10).toList.par  //make a par version of the list

//val list2 = list1.par
val list3 = list2.map(x => x * x * x) // get list of cubes
println(list3.reduce(_ * _)) // compute and print the prod
