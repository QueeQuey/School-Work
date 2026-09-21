output_File = File.new("Homework2_readmeTask5.txt", "w")

class EditedTree
  attr_accessor :children, :node_name
  def initialize(tree_hash)
    @node_name = tree_hash.keys.first
    leaf_hash = tree_hash[@node_name]


    @children = leaf_hash.map { |child_name, grand_children|
      EditedTree.new({ child_name => grand_children }) }
  end

  def visit_all(&block)
    visit &block
    children.each {|c| c.visit_all &block}
  end


  def visit(&block)
    block.call self
  end

  def count_nodes #Similar to the Composite pattern
    1 + children.map(&:count_nodes).sum
  end

  def count_leaves
    return 1 if children.empty? # If no children, it's a leaf
    children.map(&:count_leaves).sum
  end


end

ruby_tree = EditedTree.new({
                             'ggp' => {
                         'gp1' => {
                           'p1' => { 'c1' => {} },
                           'p2' => { 'c2' => {}, 'c3' => {} }
                         },
                         'gp2' => {
                           'p3' => { 'c4' => {} },
                           'p4' => { 'c5' => {}, 'c6' => {} }
                         },
                         'gp3' => {
                           'p5' => { 'c7' => {} },
                           'p6' => { 'c8' => {}, 'c9' => {} }
                         }
                       }
                     })


#tree = EditedTree.new(tree_data)

#p "Visiting all nodes:"
ruby_tree.visit_all do |node|
  #puts node.node_name
  output_File.write("Visitng all nodes: #{node.node_name}")
end

#p "Visiting just the root node:"
#ruby_tree.visit { |node| puts node.node_name }

p "How Many nodes: #{ruby_tree.count_nodes}"
output_File.write("How Many nodes: #{ruby_tree.count_nodes}")

p "How Many leaves (children, no parents): #{ruby_tree.count_leaves}"
output_File.write("How Many leaves (children, no parents): #{ruby_tree.count_leaves}")






class TreefromBook
  attr_accessor :children, :node_name
  def initialize(name, children=[])
    @children = children
    @node_name = name
  end

  def visit_all(&block)
    visit &block
    children.each {|c| c.visit_all &block}
  end


  def visit(&block)
      block.call self
    end
end
#ruby_tree_from_book = TreefromBook.new( "Ruby", [TreefromBook.new("Reia"), TreefromBook.new("MacRuby")] )
#puts "Visiting a node"
#ruby_tree_from_book.visit {|node| puts node.node_name}
#puts
#puts "visiting entire tree"
#ruby_tree_from_book.visit_all {|node| puts node.node_name}




output_File.close