//Layne Woodruff, Vanessa Burback, Caeli Empcke

def foo(list1: List[String]): Unit = {
  //Can also use the character at function!
  val list2 = list1.filter(word => !(word.startsWith("c") && word.endsWith("d")))
  println(list2)
}

// Test Function
foo(List("clown","cloud","badminton","apple"))