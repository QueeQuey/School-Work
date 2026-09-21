/*//Variable m is a map. Map must contain a string then int. Returns a List of strings.
def foo(m: Map[String, Int]): List[String] = {
  m.filter { case (_, x) => //Only evalute the X value
      x >= 25 &&
      x <= 100 }
    .keys.toList //Get the keys, put into list.
}

//Map
val m = Map("xyz" -> 17, "abc" -> 11, "ghex" -> 2, "akjsdjf" -> 57, "iaBSD" -> 99)
val result = foo(m)
//println("Running...2")
println(result) //Should ONLY return the strings, not the ints.

 */
