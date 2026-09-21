

final class TaskB$_ {
def args = TaskB_sc.args$
def scriptPath = """TaskB.sc"""
/*<script>*/
case class Book(isbn: String, author: String, title: String)

object BookSorter {
  def quickSort(books: List[Book])(compare: (Book, Book) => Boolean): List[Book] =
    if (books.length <= 1) books
    else {
      val pivot = books.head
      val (less, greater) = books.tail.partition(book => compare(book, pivot))
      quickSort(less)(compare) ++ List(pivot) ++ quickSort(greater)(compare)
    }

  def main(args: Array[String]): Unit = {
    val books = List(
      Book("12345", "John Doe", "Scala"),
      Book("67890", "Jane Smith", "Haskell"),
      Book("54321", "Alice Brown", "Ruby")
    )

    // Fixed comparison functions
    val sortedByIsbn = quickSort(books)((b1, b2) => b1.isbn < b2.isbn)
    val sortedByTitle = quickSort(books)((b1, b2) => b1.title > b2.title)
    val sortedByAuthor = quickSort(books)((b1, b2) => b1.author < b2.author)

    // Print results
    println("Sorted by ISBN:")
    sortedByIsbn.foreach(println)

    println("\nSorted by Title:")
    sortedByTitle.foreach(println)

    println("\nSorted by Author:")
    sortedByAuthor.foreach(println)
  }
}

/*</script>*/ /*<generated>*//*</generated>*/
}

object TaskB_sc {
  private var args$opt0 = Option.empty[Array[String]]
  def args$set(args: Array[String]): Unit = {
    args$opt0 = Some(args)
  }
  def args$opt: Option[Array[String]] = args$opt0
  def args$: Array[String] = args$opt.getOrElse {
    sys.error("No arguments passed to this script")
  }

  lazy val script = new TaskB$_

  def main(args: Array[String]): Unit = {
    args$set(args)
    val _ = script.hashCode() // hashCode to clear scalac warning about pure expression in statement position
  }
}

export TaskB_sc.script as `TaskB`

