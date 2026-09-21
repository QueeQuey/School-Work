-- Binary tree data type
data BinaryTree a = Empty
                  | Node a (BinaryTree a) (BinaryTree a)
                  deriving (Show, Eq)

-- Function to calculate the height of a binary tree
treeHeight :: BinaryTree a -> Int
treeHeight Empty = 0
treeHeight (Node _ left right) = 1 + max (treeHeight left) (treeHeight right)

-- Function to check if the tree is unbalanced
foo :: BinaryTree a -> Bool
foo Empty = False -- An empty tree is not unbalanced
foo (Node _ left right) =
  abs (treeHeight left - treeHeight right) > 1 || foo left || foo right

-- Example binary trees
balancedTree :: BinaryTree Int
balancedTree = Node 1 (Node 2 Empty Empty) (Node 3 Empty Empty)

unbalancedTree :: BinaryTree Int
unbalancedTree = Node 1 (Node 2 (Node 4 Empty Empty) Empty) Empty

main :: IO ()
main = do
  print $ foo balancedTree   -- Output: False (tree is balanced)
  print $ foo unbalancedTree -- Output: True (tree is unbalanced)
