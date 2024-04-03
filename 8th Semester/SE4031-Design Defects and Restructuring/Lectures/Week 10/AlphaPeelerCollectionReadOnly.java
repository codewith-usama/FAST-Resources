// Java Program to make Collections Read-Only
// Demonstration of the Proxy pattern
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class AlphaPeelerCollectionReadOnly {
	public static void main(String[] args)
	{
		List<Integer> numbers = new ArrayList<>();
		for (int i = 1; i <= 10; i++) {
			numbers.add(i);
		}
		// Iterate on the stream of integers and print them
		numbers.stream().forEach(System.out::print);
		// Now we are adding one more element
		numbers.add(11);
		// Removing element from the list
		numbers.remove(8);
		// Updating List
		numbers.set(4, 4);

		System.out.println("\nAfter Performing Some Operations");
		numbers.stream().forEach(System.out::print);
		System.out.println("\nHence By default Collections object is Readable and Writable");

		// Now making Read-Only List
		// Using unmodifiableList() method.
		try {
			numbers = Collections.unmodifiableList(numbers);
			// This line will generate an Exception
			numbers.remove(11);
		}
		catch (UnsupportedOperationException
				unsupportedOperationException) {
			System.out.println("Exceptions is " + unsupportedOperationException);
		}
		finally {
			System.out.println(numbers.get(3));
			System.out.println("Now list is only Read-Only");
		}
	}
}


/*
12345678910
After Performing Some Operations
123446781011
Hence By default Collections object is Readable and Writable
Exceptions is java.lang.UnsupportedOperationException
4
Now list is only Read-Only
*/