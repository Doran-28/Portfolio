package Test2;

public class Heap<E extends Comparable<E>> {

	Node<E> root;

	Heap(E data) {
		root = new Node<E>(data);
	}

	public void add(E data) {
		Node<E> node = root;
		for (int i = 0; i <= getHeight(); i++) {
			node.parent = node;
			node = node.left;
		}
		heapifyUp(node);
	}

	private void heapifyUp(Node<E> node) {
		try {
			while (node.data.compareTo(node.parent.data) > 0) {
				Node<E> temp = node;
				node = node.parent;
				node.parent = temp;
			}
		} catch (NullPointerException e) {
			System.out.println(e.getStackTrace());
		}
	}

	private int getHeight() {
		Node<E> node = root;
		int h = 0;
		while (node.left != null) {
			node = node.left;
			h++;
		}
		return h;
	}

	private class Node<E extends Comparable<E>> {

		E data;
		Node<E> parent;
		Node<E> left;
		Node<E> right;

		public Node(E data) {
			this.data = data;
			this.left = null;
			this.right = null;
			this.parent = null;
		}
	}

	public static void main(String args[]) {
		Heap<Integer> heap = new Heap<Integer>(10);
		heap.add(11);
		heap.add(13);
	}
}
