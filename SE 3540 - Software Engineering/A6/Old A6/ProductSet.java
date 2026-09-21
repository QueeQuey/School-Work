package composite;

import java.util.ArrayList;

public interface ProductSet{

    ArrayList<Product> products = new ArrayList<Product>();
    //Sets up for a set of products to calculate the final result
    // or Group products together since an item can be a group of items
    int calculatePrice();
}