//Layne Woodruff, Vanessa Burback, Caeli Empcke

// foo returns size of the input list x
def foo(x:List[Int]): Int= {
  x match {
    case h::t => 1 + foo(t)
    case _ => 0
  }
}
println(foo(List(1,2,3,4)))
println(foo(List(1,2,3,4,5)))
