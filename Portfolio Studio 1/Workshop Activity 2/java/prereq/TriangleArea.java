package prereq;

import java.util.Scanner;

public class TriangleArea {
   public static void main(String[] args) {
      Scanner scnr = new Scanner(System.in);
      
      Triangle triangle1 = new Triangle();
      Triangle triangle2 = new Triangle();

      // TODO: Read and set base and height for triangle1 (use setBase() and setHeight())
      triangle1.setBase(scnr.nextDouble());
      triangle1.setHeight(scnr.nextDouble());
      
      // TODO: Read and set base and height for triangle2 (use setBase() and setHeight())
      triangle2.setBase(scnr.nextDouble());
      triangle2.setHeight(scnr.nextDouble());

      // TODO: Determine larger triangle (use getArea())
      double largerArea = 0.0;
      if (triangle1.getArea() > triangle2.getArea()) {
         largerArea = triangle1.getArea();
      }
      else {
         largerArea = triangle2.getArea();
      }

      // Branchless ver.
      // double largerArea = ((triangle1.getArea() >= triangle2.getArea()) * triangle1.getArea()) + ((triangle2.getArea() > triangle1.getArea()) * triangle2.getArea());
      
      System.out.println("Triangle with larger area:");
      // TODO: Output larger triangle's info (use printInfo())
      if (largerArea == triangle1.getArea()) {
         triangle1.printInfo();
      }
      else {
         triangle2.printInfo();
      }
   }
}
