package prereq;

public class Listing {
   // These are examples properties
   // TODO: Add more properties
   private String title;
   private double price;
   private String desc;
   private int rating;
   private String image;
   private String location;
   private String category;
   
   public Listing() {
      title = "none";
      price = -1.0;
      desc = "none";
      rating = -1;
      image = "none";
      location = "none";
      category = "none";
   }

   // TODO: Add your setter/getter here
   // Setter
   public void setTitle(String x) {
      title = x;
   }

   public void setPrice(double x) {
      price = x;
   }
   
   public void setDesc(String x) {
      desc = x;
   }

   public void setRating(int x) {
      if ((0 <= x) && (x <= 5)){
         rating = x;
      }
   }

   public void setImage(String x) {
      image = x;
   }

   public void setLocation(String x) {
      location = x;
   }

   public void setCategory(String x) {
      category = x;
   }

   // Getter
   public String getTitle() {
      return title;
   }

   public double getPrice() {
      return price;
   }
   
   public String getDesc() {
     return desc;
   }

   public int getRating() {
      return rating;
   }

   public String getImage() {
      return image;
   }

   public String getLocation() {
      return location;
   }

   public String getCategory() {
      return category;
   }
   
   public void printInfo() {
      // TODO: Complete this to print out the information of the Listing
      System.out.println("Item: " + title);
      System.out.println("\tCategory: " + category);
      System.out.println("\tImage: " + image);
      System.out.println("\tRating: " + rating);
      System.out.printf("\tPrice: %.2f%n", price);
      System.out.println("\tDescription: " + desc);
      System.out.println("\tLocation: " + location);
      System.out.println();
   }
}