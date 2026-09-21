-- Style 1: Using an anonymous function with `map`
style1 :: [Int] -> [Int]
style1 list = map (\x -> x * x) list

-- Style 2: Using `where` to define the square function
squareAll :: [Int] -> [Int]
squareAll list = map square list
  where square x = x * x

-- Main function to test both styles
main :: IO ()
main = do
    let result1 = style1 [4, 5, 6, 7]
    let result2 = squareAll [4, 5, 6, 7]
    putStrLn ("Style 1 Output: " ++ show result1)
    putStrLn ("Style 2 Output: " ++ show result2)