require 'benchmark'

def Function4A(n)
  return n if n <= 1
  fib_0, fib_1 = 0, 1
  (2..n).each do
    fib_0, fib_1 = fib_0, fib_1 + fib_1
  end
  fib_1
end


def Function4B(n)
  return 1 if n == 1 || n == 2
  Function4B(n - 1) + Function4B(n - 2)
end

Benchmark.bm(7) do |x|
  output_file = File.new("Homework2_readmeTask4.txt", "w")
  y = x.report("Function 4A (Iterative): ") do
    (1..40).each do |n|
      temp_reportA = Function4A(n)
      p "Number #{n} returns: #{temp_reportA}"
    end
  end
  output_file.write("Iterative report: #{y}")

  z = x.report("Function 4B (Recursive): ") do
    (1..40).each do |n|
      temp_reportB = Function4B(n)
      p "Number #{n} returns: #{temp_reportB}"
    end
  end
  output_file.write("Recursive report: #{z}")
  output_file.close
end
