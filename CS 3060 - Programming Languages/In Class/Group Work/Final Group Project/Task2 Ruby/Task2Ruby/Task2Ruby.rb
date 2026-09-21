require 'benchmark'
# frozen_string_literal: true
def quick_sort(array, &block)
  return array if array.length <= 1

  pivot = array.delete_at(rand(array.length))
  less_than_pivot = array.select { |item| block.call(item, pivot) < 0 }
  greater_than_or_equal_to_pivot = array.select { |item| block.call(item, pivot) >= 0 }

  quick_sort(less_than_pivot, &block) + [pivot] + quick_sort(greater_than_or_equal_to_pivot, &block)
end

class Main
  def self.quick_sort(array, &block)
    return array if array.length <= 1

    pivot = array.delete_at(rand(array.length))
    less_than_pivot = array.select { |item| block.call(item, pivot) < 0 }
    greater_than_or_equal_to_pivot = array.select { |item| block.call(item, pivot) >= 0 }

    quick_sort(less_than_pivot, &block) + [pivot] + quick_sort(greater_than_or_equal_to_pivot, &block)
  end

  def self.write_to_file(filename, books)
    File.open(filename, "w") do |file|
      books.each do |book|
        file.puts "ISBN: #{book[:isbn]}, Author: #{book[:author]}, Title: #{book[:title]}"
      end
    end
  end

  def self.run
    # List of books as given in your format
    books = [
      { isbn: "12345", author: "John Doe", title: "Scala" },
      { isbn: "67890", author: "Jane Smith", title: "Haskell" },
      { isbn: "54321", author: "Alice Brown", title: "Ruby" }
    ]

    # Perform Benchmarking for sorting operations
    puts "Benchmarking"

    time_isbn_asc = Benchmark.realtime do
      sorted_by_isbn_asc = quick_sort(books) { |a, b| a[:isbn] <=> b[:isbn] }
    end

    time_isbn_desc = Benchmark.realtime do
      sorted_by_isbn_desc = quick_sort(books) { |a, b| b[:isbn] <=> a[:isbn] }
    end

    time_title = Benchmark.realtime do
      sorted_by_title = quick_sort(books) { |a, b| a[:title] <=> b[:title] }
    end

    puts "\nBenchmark Results:"
    puts "Sorting by ISBN (Ascending): #{time_isbn_asc} seconds"
    puts "Sorting by ISBN (Descending): #{time_isbn_desc} seconds"
    puts "Sorting by Title: #{time_title} seconds"

    # Writing the sorted results to a file (optional)
    filename = "sorted_books.txt"
    File.open(filename, "w") do |file|
      file.puts "Sorted by ISBN (Ascending):"
      write_to_file(file, quick_sort(books) { |a, b| a[:isbn] <=> b[:isbn] })

      file.puts "\nSorted by ISBN (Descending):"
      write_to_file(file, quick_sort(books) { |a, b| b[:isbn] <=> a[:isbn] })

      file.puts "\nSorted by Title:"
      write_to_file(file, quick_sort(books) { |a, b| a[:title] <=> b[:title] })

      file.puts "\nSorted by Author Name:"
      write_to_file(file, quick_sort(books) { |a, b| a[:author] <=> b[:author] })
    end

    puts "\nSorted book information has been written to 'sorted_books.txt'."
  end

  # Helper method to output book information to the file
  def self.write_to_file(file, books)
    books.each do |book|
      file.puts "ISBN: #{book[:isbn]}, Author: #{book[:author]}, Title: #{book[:title]}"
    end
  end
end

# Run the Main class
Main.run
