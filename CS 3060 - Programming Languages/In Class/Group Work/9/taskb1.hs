data Tree a = Subtrees [Tree a] | Leaf a deriving (Show)

-- Depth function
depth :: Tree a -> Int
depth (Leaf _) = 1
depth (Subtrees c) = 1 + maximum (map depth c)

-- Number of leaves function
numLeaves :: Tree a -> Int
numLeaves (Leaf _) = 1
numLeaves (Subtrees c) = sum (map numLeaves c)

-- Constructing the tree
aTree :: Tree Int
aTree = Subtrees [Leaf 1, Subtrees [Leaf 2, Leaf 3], Leaf 4]

-- Calculate depth and number of leaves
treeDepth = depth aTree
treeNumLeaves = numLeaves aTree

-- Main function to print results
main :: IO ()
main = do
  putStrLn $ "Depth of the tree: " ++ show treeDepth
  putStrLn $ "Number of leaves in the tree: " ++ show treeNumLeaves
