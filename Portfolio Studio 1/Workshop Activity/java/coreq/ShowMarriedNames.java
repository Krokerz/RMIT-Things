package coreq;

import java.util.Scanner;

public class ShowMarriedNames {
   public static void main(String[] args) {
      Scanner scnr = new Scanner(System.in);
      String firstName1;
      String lastName1;
      String firstName2;
      String lastName2;
      
      System.out.println("What is the first person's first name?");
      firstName1 = scnr.nextLine();
      System.out.println("What is the first person's last name?");
      lastName1  = scnr.nextLine();
      
      //FIXME ask for the second person first and last name and store these 2 information
      

      System.out.println("Here are some common married-couple names:");
      //first option: they both keep their original last names
      System.out.println(firstName1 + " " + lastName1 + " and " +
                         firstName2 + " " + lastName2);
      //FIXME print the 2 option were they both keep one of the name (lastName1 or lastName2)
      
      
      // FIXME: Print two hyphenated last name options, with either last name
      //        appearing first. (A hyphen can be written as "-")
      
   }
}