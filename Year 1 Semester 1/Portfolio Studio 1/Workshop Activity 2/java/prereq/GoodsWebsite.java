package prereq;

public class GoodsWebsite {

   public static void main(String[] args) {
      
      Listing item1 = new Listing();
      Listing item2 = new Listing();
      Listing item3 = new Listing();

      // TODO: Create three listings, setting the properties
      item1.setTitle("Lawnmower Supreme 3000");
      item1.setPrice(980.0);
      item1.setDesc("The finest lawnmower the world has ever seen.");
      item1.setRating(5);
      item1.setImage("lawnmower.png");
      item1.setLocation("Melbourne");
      item1.setCategory("Garden Care");

      item2.setTitle("Severely Broken Down Chevy");
      item2.setPrice(79.99);
      item2.setDesc("To be honest, I don't know why you would buy this.");
      item2.setRating(2);
      item2.setImage("destroyed_hunk_of_metal.png");
      item2.setLocation("Brisbane");
      item2.setCategory("Vehicle");

      item3.setTitle("Merman Hiller Aeros Chair");
      item3.setPrice(2400.0);
      item3.setDesc("Experience luxury. Your back will thank you.");
      item3.setRating(4);
      item3.setImage("Aeros.png");
      item3.setLocation("Sydney");
      item3.setCategory("Furniture");
      
      // TODO: Output all of the item
      item1.printInfo();
      item2.printInfo();
      item3.printInfo();
   }
}