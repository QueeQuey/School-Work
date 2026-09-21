def getLastWord(t: String): String = {
  val list = t.split("\\s+")
  val listSize = list.length;
  //val int j = listSize - 2;
  val returnWord: String = list(listSize - 1)
  return returnWord;
  //(a) Get the size of list
  // (b) from list get the last item (i.e. the last word of t )
  //(c) return the last word of t
}


val secondElement =
  List(1, 2, 3) match {
    case x :: xs => xs.head
    case _ => 0
  }
println(secondElement)