// Java program to demonstrate  synchronizedList() method for String Value 
import java.util.*; 
public class AlphaPeelerSynchronizedList { 
	public static void main(String[] argv) throws Exception 
	{ 
		try { 
			List<String> list = new ArrayList<String>(); 
			list.add("A"); 
			list.add("B"); 
			list.add("C"); 
			list.add("D"); 
			list.add("E"); 
			System.out.println("List : " + list); 

			// create a synchronized list 
			List<String> synlist = Collections.synchronizedList(list); 
			// printing the Collection 
			System.out.println("Synchronized list is : " + synlist); 
		} 
		catch (IllegalArgumentException e) { 
			System.out.println("Exception thrown : " + e); 
		} 
	} 
} 
/*
Output:
List : [A, B, C, D, E]
Synchronized list is : [A, B, C, D, E]
*/