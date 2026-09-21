package composite;

public abstract class Product implements ProductSet {

    protected final String name;
    protected final double price;

    public Product(String name,double price){
        this.name = name;
        this.price = price;
    }

    public String getName(){
        return this.name;
    }

    public double getPrice(){
        return this.price;
    }

}