import scala.None.foreach
import scala.io.Source
//object Task4 {
  //def main(args: Array[String]) = {
    //}
//}

class Matrix(m :Int, n :Int) {
    var mat:List[List[Int]] = Nil
    for(i <- 0 until m) {
        mat = mat :+ List.fill(n)(0)
    }
}

class PrintMat(mat: List[List[Int]]) {
    def printMatrix(): Unit = {
        mat.foreach { row =>
            println(row.mkString(" "))
        }
    }
}

val matrix = new Matrix(3,4)
val matrix1 = new Matrix(3,5)
val matrix2 = new Matrix(15,10)


val matrixPrint = new PrintMat(matrix.mat)
val matrix1Print = new PrintMat(matrix1.mat)
val matrix2Print = new PrintMat(matrix2.mat)
matrixPrint.printMatrix()
matrix1Print.printMatrix()
matrix2Print.printMatrix()


//matrix foreach { row => row foreach print; println }

//printMat(matrix)
//println(matrix.mat(1))
//println(matrix.mat(0))
