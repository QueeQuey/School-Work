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

    # Sorting by ISBN Ascending
    sorted_by_isbn_asc = quick_sort(books) { |a, b| a[:isbn] <=> b[:isbn] }

    # Sorting by ISBN Descending
    sorted_by_isbn_desc = quick_sort(books) { |a, b| b[:isbn] <=> a[:isbn] }

    # Sorting by Title
    sorted_by_title = quick_sort(books) { |a, b| a[:title] <=> b[:title] }

    # Sorting by Author Name
    sorted_by_author = quick_sort(books) { |a, b| a[:author] <=> b[:author] }

    # Writing all sorted lists to a file
    filename = "sorted_books.txt"
    File.open(filename, "w") do |file|
      file.puts "Sorted by ISBN (Ascending):"
      write_to_file(file, sorted_by_isbn_asc)

      file.puts "\nSorted by ISBN (Descending):"
      write_to_file(file, sorted_by_isbn_desc)

      file.puts "\nSorted by Title:"
      write_to_file(file, sorted_by_title)

    end

    puts "Sorted book information has been written to 'sorted_books.txt'."
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
