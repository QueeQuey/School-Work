package composite;

import java.util.ArrayList;
import java.util.Arrays;

public class CompositeProductSet implements ProductSet{
    //Creates a list of Products to be itterated through in an array list
    private final ArrayList<ProductSet> children = new ArrayList<ProductSet>();
    //Adds everything
    public CompositeProductSet(ProductSet... productsets){
        children.addAll(Arrays.asList(productsets));
    }
    //Calculates the price of everything
    @Override
    public int calculatePrice(){
        return children.stream().mapToInt(ProductSet::calculatePrice).sum();
    }

    public ArrayList<ProductSet> getChildren(){
        return this.children;
    }
}
