File Name:  taskB.hs
Purpose:    The purpose of this file is to sort a list of books
            in ascending and descending order by ISBN, and in
            alphabetical order according to the title. The sorting
            method used within this program is a quick sort algorithm.

Run Instructions:
{

ghci
:load taskB.hs
main

}

Output:
{

ghci> :load taskB.hs
[1 of 2] Compiling Main             ( taskB.hs, interpreted )
Ok, one module loaded.
ghci> main
Printing books according to ISBN (ascending)
ISBN: 12345, Title: John Doe, Author: Scala
ISBN: 54321, Title: Alice Brown, Author: Ruby
ISBN: 67890, Title: Jane Smith, Author: Haskell

Printing books according to ISBN (descending)
ISBN: 67890, Title: Jane Smith, Author: Haskell
ISBN: 54321, Title: Alice Brown, Author: Ruby
ISBN: 12345, Title: John Doe, Author: Scala

Printing books according to Title (ascending)
ISBN: 67890, Title: Jane Smith, Author: Haskell
ISBN: 54321, Title: Alice Brown, Author: Ruby
ISBN: 12345, Title: John Doe, Author: Scala


}