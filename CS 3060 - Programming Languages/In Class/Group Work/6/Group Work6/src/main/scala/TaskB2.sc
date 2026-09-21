import scala.None.foreach
import scala.io._
import scala.collection.parallel.CollectionConverters._
//Layne Woodruff, Vanessa Burback, Caeli Empcke
def numberofPages(url: String): Int = {
    val page = io.Source.fromURL(url).mkString
    val linkRegex = "(?i)<a.+?href=\"(http.+?)\".*?>(.+?)</a>".r
    linkRegex.findAllIn(page).matchData.toList.size
    //Returns number of the links on the page
}


val urls = List("https://www.bbc.com/", "https://www.cnn.com/", "https://box.com", "https://dropbox.com")

//Serial time
val t1 = System.currentTimeMillis()
val serialTotalLinks = urls.map(url => numberofPages(url)).sum
val t2 = System.currentTimeMillis()

val t3 = System.currentTimeMillis()
val parallelTotalLinks = urls.par.map(url => numberofPages(url)).sum
val t4 = System.currentTimeMillis()


println("Total number of Links " + parallelTotalLinks)
println("Serial exec time = " + (t2 - t1))
println("Parallel exec time = " + (t4 - t3))
