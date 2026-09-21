//Layne Woodruff, Vanessa Burback, Caeli Empcke
def foo(list1:List[String]):Unit  = {
  // Reading through the list word-by-word
  val list3:List[String] = list1.map(word =>
    // Checking for "bad" within each element in the list
    if (word.contains("bad")) {
      // Replace any words with "bad" in them
      "replaced"
    } else {
      // Keep any words without "bad"
      word
    }
  )
  println(list3)
}

foo(List("clown","cloud","badminton","apple"))