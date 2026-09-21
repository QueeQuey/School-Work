data BTree = BLeaf Char | BinTree BTree Int BTree deriving (Show)

--Create the following binary trees:

bt1 = BLeaf 'a'
bt2 = BinTree (BLeaf 'b') 5 (BLeaf 'c')
bt3 = BinTree (BinTree (BLeaf 'd') 3 (BLeaf 'e')) 2 (BLeaf 'f')


taskb2SumNodes :: BTree -> Int
taskb2SumNodes (BLeaf _) = 0
taskb2SumNodes (BinTree left value right) = value + taskb2SumNodes left + taskb2SumNodes right


main :: IO ()
main = do
  print $ taskb2SumNodes bt1  -- Expected output: 0
  print $ taskb2SumNodes bt2  -- Expected output: 5
  print $ taskb2SumNodes bt3  -- Expected output: 5 (3 + 2)
