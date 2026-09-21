mysort :: (Ord a) => (a -> a -> Bool) -> [a] -> [a]
mysort comp []     = []
mysort comp (h:xs) = (mysort comp lesser) ++ [h] ++ (mysort comp greater) where
  --lesser  = filter (comp h) xs
  --greater = filter (not . comp h) xs
  --The above original did it backwards. Just need to do the reverse.
  lesser  = filter (\x -> comp x h) xs
  greater = filter (\x -> not (comp x h)) xs

-- (a) Sort by rightmost digit
compareRightmost :: Int -> Int -> Bool
compareRightmost x y = (x `mod` 10) < (y `mod` 10)

sortRightmost :: [Int] -> [Int]
sortRightmost = mysort compareRightmost

-- (b) Sort by leftmost character
compareLeftmost :: String -> String -> Bool
compareLeftmost s1 s2 = head s1 < head s2

sortLeftmost :: [String] -> [String]
sortLeftmost = mysort compareLeftmost

-- Main function to test
main :: IO ()
main = do
  print $ sortRightmost [231, 53, 42, 338] -- Output: [231, 42, 53, 338]
  print $ sortLeftmost ["abc", "efg", "bcd", "de"] -- Output: ["abc", "bcd", "de", "efg"]
