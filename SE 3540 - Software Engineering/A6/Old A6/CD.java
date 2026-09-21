package composite;
public class CD extends Product{
    //Class that takes in the CD name. Needs to be seperate from book due to no isbn
    public CD(String name, double price){
        super(name, price);
    }
    @Override
    public int calculatePrice(){
        return 2;
        //return getPrice();
    }
}