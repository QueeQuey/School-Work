package composite;

import java.io.InputStream;
import java.util.ArrayList;
import java.util.Optional;

import javax.imageio.metadata.IIOMetadataNode;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Class for managing items.
 * 
 */
 
public class ItemManager {
	CompositeProductSet compositeProductSet;
	Document xmlDoc;
	// make one type for all products or one for each type of product (must not be abstract)
	static Product instCD = new CD("test", 00 );
	static Product instBook = new Book("test", 00, null );
	static CompositeProductSet instCps = new CompositeProductSet();
	private static final Class CLASS_CD = instCD.getClass();
	private static final Class CLASS_BOOK = instBook.getClass();
	private static final Class CLASS_CPS = instCps.getClass();
	
	public ItemManager() {
	}

	/**
	 * Reads the xml data from the input stream or throws an Exception if anything
	 * goes wrong (e.g., the xml code is invalid or some price attribute cannot be converted to type double).
	 * Items are assumed to have a unique name.
	 * The input stream is allowed to have empty lists.
	 * This is the only method where xml is handled in this assignment. No other method in this class should contain (or call)
	 * xml-specific code.
	 */
	public void readXml(InputStream xmlData) throws Exception{
		DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
		DocumentBuilder db = dbf.newDocumentBuilder();
		// convert xml data to dom document
		xmlDoc = db.parse(xmlData);
		// access elements from the doc as NodeList
		// get the NodeList for all the productSet
		NodeList productSets = xmlDoc.getChildNodes();
		int i = 0;
		Node node = productSets.item(i);
		// make it into a ProductSet
		while (node != null){
			if (node.getClass() == CLASS_CPS){
				i ++;
				ArrayList<Product> passProductSet = new ArrayList<Product>(null);
				node = productSets.item(i);
				while (node.getClass() != CLASS_CPS ){
					Product newProduct = null;
					if (node.getClass() == CLASS_BOOK){
						// error need to fix problem with converting value to double -- Changed values to doubles within the class
						newProduct = new Book(node.getNodeName(), Double.parseDouble(node.getNodeValue()), node.getNodeName());
					}
					if (node.getClass() == CLASS_CD){
						// error need to fix problem with converting value to double -- Changed values to doubles within the class
						newProduct = new CD(node.getNodeName(), Double.parseDouble(node.getNodeValue()));
					}
					passProductSet.add(newProduct);
				}
				int count = 0;
				// convert passProductSet into an immutable array
				for (Product product : passProductSet){
					count ++;
				}
				Product[] productsAsList = new Product[count];
				count = 0;
				for (Product product : passProductSet){
					productsAsList[count] = product;
				}
				// get the array for new product set;
				compositeProductSet = new CompositeProductSet(productsAsList);

			}
			i ++;
			node = productSets.item(i);
		}
	}


	/**
	 * Returns an {@code Optional} instance representing the price of the item (cd,
	 * book, or list) with the given name; the {@code Optional} is empty, if
	 * no such item exists
	 */
	public Optional<Double> getPrice(String item){
		// NOTE MUST BE RECONSTRUCTED - to use the classes instead of XML code
		//check every item in array to see if it matches
		if (compositeProductSet != null){
			// checks is if the node list contains listed item
			//TODO: find a way to access the names of the products in the list
			if (compositeProductSet.getChildren().contains(item)){
				compositeProductSet.getChildren().remove(compositeProductSet.getChildren().indexOf(item));
				int indexPr = 0;
				for (int index = 0; index < compositeProductSet.getChildren().size(); index++){
					//TODO find a way to access the items in current set
					ProductSet currentSet = compositeProductSet.getChildren().get(index);
					/*//TODO figure out how to iterate over the children's"children"
					Product currentProduct = currentSet.getChildren().get(indexPr);
					if(currentProductSet.get(index)){
						IIOMetadataNode node = (IIOMetadataNode) searchResults.item(index);
						// something else in order to get node price?
						String price = node.getAttribute("price");
						return Optional.of(Double.valueOf(price));
					}					
					*/
				}
			}
			
		}
		return Optional.of(null);
	}

	/**
	 * removes the item with the given name, unless it's the root
	 * returns true if the operation succeeded (item found and removed)
	 * returns false if item is the root, or it is not found, or it cannot be removed due to some other error
	 */
	public boolean removeItem(String item) {
		NodeList searchResults = (NodeList) compositeProductSet;
		if (searchResults != null){
			//TODO: find a way to access the names of the products in the list
			if(compositeProductSet.getChildren().contains(item)){
				compositeProductSet.getChildren().remove(compositeProductSet.getChildren().indexOf(item));
				return true;
			}		
		}
		return false;
	}

	/**
	 * changes the price of the item with the given name; 
	 * returns false if item is not found or it is a list, or if the price is smaller than or equal to 0,
	 * returns false if the price could not be changed for any other reason;
	 * returns true if the price was changed successfully (i.e., the item had a different price before); 
	 */
	public boolean changePrice(String item, double price) {
		return false;
	}
}