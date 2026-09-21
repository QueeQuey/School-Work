import scala.io.Source
object Task2 {
  def main (args:Array[String]) = {
    //var price = 0
    //var costliestItem = " "
    var lineCount = -1

    //Below we get a file-handler for the file “data.txt”
    val fileHandler = Source.fromFile("data.txt")
    val lineIterator = fileHandler.getLines()

    //Iterate over all lines
    var penPrice = 0;
    var highestCost = 0;
    var highestName = "";
    for(line <- lineIterator){
      //(a) Increment the lineCount
      lineCount += 1;

      ////(b) Process the current line

      val list = line.split(' ');
      val itemName = list(0);
      val priceItem = list(2).toInt;


      if(itemName == "Pen"){
        penPrice = priceItem;
      }
      if(priceItem >= highestCost){
        highestCost = priceItem;
        highestName = itemName;
      }

      //(c) you may need to change the price item in the third column from String to Int. If s is a string, then s.toInt gives the corresponding Int
    }
    println("Item count = " + (lineCount + 1));
    println("The pen costs: " + (penPrice));
    println("The most expensive item is " + highestName + " at $" + highestCost);
    // Print all the outputs
    fileHandler.close()
  }
}