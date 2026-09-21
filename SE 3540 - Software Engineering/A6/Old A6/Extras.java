package composite;
public class Extras extends Product{
    //Class that doesn't have a price. Like a bundled in "Extras" CD that is included.
    public Extras(String name){
        super(name, 0);
    }
    @Override
    public int calculatePrice(){
        return 0;
    }
}