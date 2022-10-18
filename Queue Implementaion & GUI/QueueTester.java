package AssignmentTwo;

public class QueueTester {

	public static void main(String[] args) {
		
		Queue<Integer> q = new Queue<Integer>();
		
		q.enqueue(34);		
		q.enqueue(343);
		q.enqueue(32);
		
		System.out.println(q);
		System.out.println(q.size());
		
		q.dequeue();
		
		System.out.println(q);
		
		System.out.println(q.front());
		
		System.out.println(q.empty());
		
		q.clear();
		
		System.out.println(q.empty());
		

	}

}
