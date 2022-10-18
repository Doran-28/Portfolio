package AssignmentTwo;

public class FixedArray<E> {
	E[] data; // This is our array, or our data. It is of type "E", which is a variable or any possible data type (e.g., Integer, or Dog)
	int items = 0; // Represents the current number of items in our array. 

	public FixedArray(){
		this(10);
	}
	public FixedArray(int size){
		data = (E[]) new Object[size];
	}
	// Add something to the first available slot
	public void add(E addIn) throws Exception{
		// E will always be an object. Generics are always object. 
		// i.e., it'll always be Integer, not int.
		// So an empty slot will always be null.
		int i;
		for(i = 0; i < data.length; i++){ // We iterate over the array to find the next open slot.
			if(data[i] == null){ 
				data[i] = addIn;
				items++;
				break;
			}
		}
		if(i == data.length) throw new Exception("Data is full!"); // By definition, FixedArray cannot be resized!
	}
	// Take out first instance of object
	public void remove(E takeOut){
		// We'll assume we only want to remove the first instance of our variable
		for(int i = 0; i < data.length; i++){
			if(data[i] == takeOut){
				data[i] = null;
				items--;
			}
		}
	}
	// Added method for using queues
	// Remove index 0 and shifts all elements down to fill the array
	public void removeFront() {
		if (data.length > 0) {
			E[] temp = (E[]) new Object [data.length];
			data[0] = null;
			System.arraycopy(data, 1, temp, 0, data.length - 1);
			data = temp;
			items--;
		}
	}
	//Added method for using stacks
	public E removeBack() {
		if (data.length > 0) {
			for (int i = 0; i < data.length; i++) {
				if (data[i] == null) {
					E temp = data[i - 1];
					data[i-1] = null;
					return temp;
				}else {
					System.out.println("Array is full");
					return null;
				}
			}
		}else {
			System.out.println("Array is empty");
		}
		return null;
	}
	
	// This gets the value at a specified index
	public E get(int index) throws Exception{ 
		if(index >= data.length) throw new Exception("This index is out of bounds!");
		return data[index]; 
	}
	// This sets the value at a specified index
	public void set(int index, E value) throws Exception{
		if(index >= data.length) throw new Exception("This index is out of bounds!");
		if(value != null && data[index] == null) items++;
		else if(value == null && data[index] != null) items--;
		data[index] = value;
	}
	// This returns the number of items in the fixed array
	public int size(){ return items; }
}