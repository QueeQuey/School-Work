data Book = Book { isbn :: Int, author :: String, title :: String } deriving (Show, Eq)

-- Quicksort Sorting Algorithm
mySort :: (Book -> Book -> Bool) -> [Book] -> [Book]
mySort _ [] = [] --Returns an empty list if the given list is empty
mySort comp (h:t) = mySort comp lesser ++ [h] ++ mySort comp greater
    where
        lesser = filter (`comp` h) t
        greater = filter (not . (`comp` h)) t

-- Create the books
book1 = Book 12345 "John Doe" "Scala"
book2 = Book 67890 "Jane Smith" "Haskell"
book3 = Book 54321 "Alice Brown" "Ruby"

-- Adding all books to a list
books = [book1, book2, book3]

main :: IO ()
main = do
    -- Creating a format for the output of each book to improve readability

    let formatBook (Book i t a) = "ISBN: " ++ show i ++ ", Title: " ++ t ++ ", Author: " ++ a

    --Sorting array of books according to ISBN

    putStrLn "Printing books according to ISBN (ascending)"
    putStrLn $ unlines $ map formatBook $ mySort (\a b -> isbn a < isbn b) books

    --Sorting array of books according to ISBN in reverse

    putStrLn "Printing books according to ISBN (descending)"
    putStrLn $ unlines $ map formatBook $ mySort (\a b -> isbn a > isbn b) books

    --Sorting array of books according to book title

    putStrLn "Printing books according to Title (ascending)"
    putStrLn $ unlines $ map formatBook $ mySort (\a b -> title a < title b) books
