//Simple database simulation program using one-dimensional arrays and only one class to function.
//Feel free to edit this if you wish.

import java.util.Arrays;
import java.util.Scanner;

public class Database {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		boolean allSlotsFilled = false;
		
		String info;
		int slot;
		
		System.out.println("|| DATABASE v1.0 ||");
		System.out.println(">> Database developed by Eddie Cibotaru");
		System.out.println();
		System.out.println("How many people are you entering into the database? You cannot enter more than 10 people.");
		
		int i = input.nextInt();
		int i_range = i-1;
		
		if (i > 10 || i <= 0) {
			
			do {
				
				System.out.println("The slot range cannot be greater than 10 nor equal or be less than 0. Please try again.");
				i = input.nextInt();
			}
			while (i > 10 || i <= 0);
		}
		
		if (i <= 10 && i >= 0) {
			
			i_range = i-1;
			System.out.printf("The slots in this database range from %d to %d.\n", 0, i_range);
		}
		
		String[] people = new String[i];
		
		do {
			
			System.out.println();
			System.out.println("Which slot would you like to edit?");
			slot = input.nextInt();
			
			if (slot > i_range || slot < 0) {

				System.out.println("That slot does not exist!");
			}

			if (slot <= i_range && slot >= 0) {
				
				System.out.println("Please enter the information for that slot.");
				input.nextLine();
				info = input.nextLine();
				people[slot] = info;
			
			people[slot] = info;
			System.out.printf("Slot %d has been successfully filled with the following information: %s.\n", slot, info);
		
			//Loop checks to see if all slots are filled
			for (int k = 0; k < people.length; k++) {

				if (!Arrays.asList(people).contains(null)) {
					
						allSlotsFilled = true;
						
					}
				}
			
			if (allSlotsFilled == true) {
				
					System.out.println();
					System.out.println("Type anything below to see all your database entries.");
					
					@SuppressWarnings("unused")
					String answer = input.nextLine();
				
					System.out.println("DATABASE ENTRIES:");
					System.out.println("--------------------");
					for (int q = 0; q < people.length; q++) {
					
						System.out.printf("Slot %d: %s\n", q, people[q]);
					}
					System.out.println("--------------------");
					System.out.println();
					System.out.println("Thanks for using this neat little program!");
					System.out.println("The program has now terminated.");
				}
			}
		}
		
		while (allSlotsFilled == false);
		
		input.close();
	}
}