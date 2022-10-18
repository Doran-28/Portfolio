package AssignmentTwo;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.ScrollPaneConstants;

public class IntegerQueueGUI extends JFrame {

	private static Queue<Integer> myQueue;

	// PLeft contains p1,p2,p3
	private static JPanel pLeft;

	// p1 for creating array
	private static JPanel p1;
	private static JLabel createLabel;
	private static JTextField createField;
	private static JButton createButton;
	private static JLabel createLabel2;

	// p2 for adding/removing elements
	private static JPanel p2;
	private static JLabel addL;
	private static JLabel removeL;
	private static JTextField addT;
	private static JButton addB;
	private static JButton removeB;

	// p3 for changing/viewing current element
	private static JPanel p3;
	private static JButton clearB;
	private static JLabel clearL;
	private static JButton sizeB;
	private static JLabel sizeL;
	private static JButton frontB;
	private static JLabel frontL;

	// pRight for text area
	private static JPanel pRight;
	private static JScrollPane scroll;
	private static JTextArea textArea;
	private static JButton exit;

	public IntegerQueueGUI() {

		pLeft = new JPanel();
		pLeft.setLayout(new GridLayout(3, 1));

		p1 = new JPanel();
		p1.setBorder(BorderFactory.createTitledBorder("Create"));
		createLabel = new JLabel("Initialize the size of the queue	--");
		createField = new JTextField(10);
		createButton = new JButton("Create");
		createLabel2 = new JLabel("Default size is 10");
		createButton.addActionListener(new Create());
		p1.add(createLabel);
		p1.add(createLabel2);
		p1.add(createField);
		p1.add(createButton);

		p2 = new JPanel();
		p2.setBorder(BorderFactory.createTitledBorder("Add/Remove"));
		addL = new JLabel("              Add integer to the queue");
		removeL = new JLabel("         Remove integer from the queue");
		addT = new JTextField(5);
		addB = new JButton("Enqueue");
		addB.setEnabled(false);
		addB.addActionListener(new Add());
		removeB = new JButton("Dequeue");
		removeB.setEnabled(false);
		removeB.addActionListener(new Remove());
		p2.add(addL);
		p2.add(addT);
		p2.add(addB);
		p2.add(removeL);
		p2.add(removeB);

		p3 = new JPanel();
		p3.setBorder(BorderFactory.createTitledBorder("Other Controls"));
		clearB = new JButton("Clear");
		clearB.setEnabled(false);
		clearB.addActionListener(new Clear());
		sizeB = new JButton("View Size");
		sizeB.addActionListener(new Size());
		frontB = new JButton("Front");
		frontB.setEnabled(false);
		frontB.addActionListener(new Front());
		clearL = new JLabel("Clear the queue");
		sizeL = new JLabel("View number of elements in queue");
		frontL = new JLabel("View the front element");
		p3.add(clearL);
		p3.add(clearB);
		p3.add(sizeL);
		p3.add(sizeB);
		p3.add(frontL);
		p3.add(frontB);

		pRight = new JPanel();
		pRight.setLayout(new BorderLayout());
		pRight.setBorder(BorderFactory.createTitledBorder("Info"));
		textArea = new JTextArea("Start a Queue!\n\n", 27, 24);
		textArea.setEditable(false);
		scroll = new JScrollPane(textArea, ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS,
				ScrollPaneConstants.HORIZONTAL_SCROLLBAR_ALWAYS);
		exit = new JButton("Exit");
		exit.addActionListener(new Exit());
		pRight.add(scroll, BorderLayout.CENTER);
		pRight.add(exit, BorderLayout.SOUTH);

		pLeft.add(p1);
		pLeft.add(p2);
		pLeft.add(p3);

	}

	private static class Create implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			String str = createField.getText();
			int temp;
			if (str.isEmpty()) {
				myQueue = new Queue<Integer>();
				textArea.append("Created a queue with 10 spots!\n");
				addB.setEnabled(true);
			} else {
				try {
					temp = Integer.parseInt(str);
					myQueue = new Queue<Integer>(temp);
					textArea.append("Created a queue with " + temp + " spots!\n");
					addB.setEnabled(true);
				} catch (Exception ex) {
					textArea.append("Must be an integer value!\n");
				}

			}
		}
	}

	private static class Add implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			String str = addT.getText();
			int temp;
			if (str.isEmpty()) {
				textArea.append("Added nothing to queue\n");
			} else {
				try {
					temp = Integer.parseInt(str);
					myQueue.enqueue(temp);
					textArea.append(myQueue.toString() + "\n");
					removeB.setEnabled(true);
					frontB.setEnabled(true);
					clearB.setEnabled(true);
				} catch (Exception ex) {
					textArea.append("Must be an integer value!\n");
				}
			}
		}
	}

	private static class Remove implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			myQueue.dequeue();
			textArea.append(myQueue.toString() + "\n");
			if (myQueue.size() == 0) {
				removeB.setEnabled(false);
				frontB.setEnabled(false);
				clearB.setEnabled(false);
			}
		}
	}

	private static class Front implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			textArea.append("Front element: " + myQueue.front() + "\n");
		}
	}

	private static class Clear implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			myQueue.clear();
			textArea.setText("Start a Queue!\n\n");
			removeB.setEnabled(false);
			frontB.setEnabled(false);
			addB.setEnabled(false);
			clearB.setEnabled(false);

		}
	}

	private static class Size implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			textArea.append("Size of queue: " + myQueue.size() + "\n");
		}
	}

	private static class Exit implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			System.exit(0);
		}
	}

	public static void main(String[] args) {

		JFrame frame = new IntegerQueueGUI();
		frame.setLayout(new GridLayout(1, 2));
		frame.add(pLeft);
		frame.add(pRight);

		frame.setDefaultCloseOperation(EXIT_ON_CLOSE);
		frame.setTitle("Queue for Integeres!");
		frame.setSize(700, 500);
		frame.setVisible(true);
	}
}
