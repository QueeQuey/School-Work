import scala.None.foreach
import scala.io.Source
//object Task4 {
  //def main(args: Array[String]) = {
    //}
//}

//Layne Woodruff, Vanessa Burback, Caeli Empcke
class Matrix(m :Int, n :Int) {
    val rand = new scala.util.Random
    var mat:List[List[Int]] = Nil
    for(i <- 0 until m) {
        mat = mat :+ List.fill(n)(rand.nextInt(10))
    }
}

class PrintMat(mat: List[List[Int]]) {
    def printMatrix(): Unit = {
        mat.foreach { row =>
            println(row.mkString(" "))
        }
    }
}

def addMatrix(mat: List[List[Int]], mat2: List[List[Int]]): Matrix = {
    if (mat.length != mat2.length || mat.head.length != mat2.head.length) {
        println("Matrices are different sizes!")
        throw new IllegalArgumentException("Different size Matrices")
    }

    val m = mat.length
    val n = mat.head.length
    val result: List[List[Int]] = (for (i <- 0 until m) yield {
        (for (j <- 0 until n) yield {
            mat(i)(j) + mat2(i)(j)
        }).toList
    }).toList

    val sumMatrix = new Matrix(m, n)
    sumMatrix.mat = result
    sumMatrix
}


val matrix1 = new Matrix(4,5)
val matrix2 = new Matrix(4,5)
val matrix1Print = new PrintMat(matrix1.mat)
val matrix2Print = new PrintMat(matrix2.mat)
matrix1Print.printMatrix()
matrix2Print.printMatrix()


val resultMatrix = addMatrix(matrix1.mat, matrix2.mat)
val matrixPrint = new PrintMat(resultMatrix.mat)
matrixPrint.printMatrix()


