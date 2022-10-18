package AssignmentTwo;

public class Queue<E> {
	
	FixedArray<E> fa;

	// Big O Notation:
	// Only one assignment
	// O(1)
	public Queue() {
		fa = new FixedArray<E>();
	}
	
	// Big O Notation:
	// Only one assignment
	// O(1)
	public Queue(int size) {
		fa = new FixedArray<E>(size);
	}
	
	// Big O Notation:
	// add() method has one for loop
	// O(n)
	public void enqueue(E in)  {
		if (fa.size() != fa.data.length)
		try {
			fa.add(in);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	// Big O Notation:
	// removeFront() has System.arraycopy()
	// O(n)
	public void dequeue() {
		fa.removeFront();
	}
	
	// Big O Notation:
	// get() method has one assignment 
	// O(1)
	public E front() {
		try {
			return fa.get(0);
		} catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}
	
	// Big O Notation:
	// Same as constructor
	// O(1)
	public void clear() {
		fa = new FixedArray<E>(fa.data.length);
	}
	
	// Big O Notation:
	// size() method has one assignment
	// O(1)
	public boolean empty() {
		if (fa.size() == 0) {
			return true;
		}
		else 
			return false;
	}
	
	// Big O Notation:
	// size() methos has one assignment
	// O(1)
	public int size() {
		return fa.size();
	}
	
	// Big O Notation:
	// Has for loop loop and a few assignments
	// O(n)
	public String toString(){
		if (fa.size() == 0)
			return "Queue is currently empty";
		else {
			StringBuilder str = new StringBuilder("Queue[");
			try {
				for (int i = 0; i < fa.data.length; i++) {
					if (fa.get(i) != null)
						str.append(fa.get(i).toString() + ", ");
				}
				str.delete(str.length() - 2, str.length());
				str.append("]");
			} catch(Exception e) {System.out.println(e.getStackTrace());}
			return str.toString();
		}
	}
	
	
}
