package prereq;

import java.util.ArrayList;
import java.util.Scanner;

public class WordFrequencies {
   public static void main(String[] args) {  
      Scanner scnr = new Scanner(System.in);
      int num = 0;  
      ArrayList<String> strArr = new ArrayList<String>();  
      // STEP 1: Read the number of words into an integer
      num = scnr.nextInt();

      // STEP 2: Read the words, one-at-a-time into an ArrayList
      for (int i = 0; i < num; ++i) {
         strArr.add(scnr.next());
      }

      // STEP 3: Find the number of times the *first* word appears in the ArrayList.
      //         Print out this number in the required format.
      int countf = 0;
      for (int i = 0; i < num; ++i) {
         if (strArr.get(i).equals(strArr.get(0))) {
            ++countf;
         }
      }
      System.out.println(strArr.get(0) + " - " + countf);

      // STEP 4: Question - What do you need to change in your Step 3 code
      //                    to find the number of times the *second* word
      //                    appears in the ArrayList?
                              // change the indexes from 0 to 1

      //         Question - What about the *third* word?
                              // change the indexes from 0 to 2
      //         Question - Do you see a pattern emerging?
                              // yes, change the index to the index of the string you want to find the frequency of

      // STEP 5: Turn your code in Step 3 into a loop that checks every word in the ArrayList

      for (int i = 0; i < num; ++i) {
         int count = 0;
         for (int j = 0; j < num; ++j) {
            if (strArr.get(j).equals(strArr.get(i))) {
               ++count;
            }
         }
         System.out.println(strArr.get(i) + " - " + count);
      }
   }
}