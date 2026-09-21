package composite;
public class Book extends Product{
    //Class that takes in the books (or any item
    public Book(String name, double price, String isbn){
        super(name, price);
    }

    @Override
    public int calculatePrice(){
        return 1;
        //return getPrice();
    }
}