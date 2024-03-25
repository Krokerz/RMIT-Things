package prereq;

public class Triangle {
   private double base;
   private double height;
   
   public void setBase(double userBase) {
      // TODO: set base class field
      base = userBase;
   }

   public void setHeight(double userHeight) {
      // TODO: set base class field
      height = userHeight;
   }
   
   public double getArea() {
      // TODO: computer triangle area
      return 0.5 * base * height;
   }
   
   public void printInfo() {
      System.out.printf("Base: %.2f\n", base);
      System.out.printf("Height: %.2f\n", height);
      System.out.printf("Area: %.2f\n", getArea());
   }
}