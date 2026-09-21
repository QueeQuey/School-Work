class Calculator
  def add(a, b, c=0)
    a + b + c
  end
end
x = Calculator.new
result = x.add(5, 10)
puts result