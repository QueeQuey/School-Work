def foo(m: Map[String, Int]): List[String] = {
  m.filter { case (_, v) => v >= 25 && v <= 100 }
    .keys
    .toList
}