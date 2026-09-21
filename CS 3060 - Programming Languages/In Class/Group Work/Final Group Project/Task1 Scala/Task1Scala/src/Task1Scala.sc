import java.io.{BufferedWriter, FileWriter}
import scala.util.Random

object RandomBookGenerator {
  def main(args: Array[String]): Unit = {
    val fileName = "10000random_books.txt"
    val numberOfBooks = 10000

    def generateRandomString(length: Int): String = {
      Random.alphanumeric.take(length).mkString
    }

    def generateRandomIsbn(length: Int = 13): String = {
      Random.nextLong().abs.toString.take(length)
    }

    // Generate random book data
    val books = (1 to numberOfBooks).map { _ =>
      val firstName = generateRandomString(5)
      val lastName = generateRandomString(7)
      val isbn = generateRandomIsbn()
      val title = generateRandomString(10)
      (firstName, lastName, isbn, title)
    }

    // Sort the books by `lastName`, then by `firstName`
    val sortedBooks = books.sortBy { case (firstName, lastName, _, _) => (lastName, firstName) }

    // Write sorted data to a file
    val writer = new BufferedWriter(new FileWriter(fileName))

    sortedBooks.foreach { case (firstName, lastName, isbn, title) =>
      writer.write(firstName + " " + lastName + ", " + isbn + ", " + title + "\n")
    }

    writer.close()
    println("Written " + numberOfBooks + " books to " + fileName)
  }
}
