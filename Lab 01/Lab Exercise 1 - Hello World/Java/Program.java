class Program {
	public static void main(String[] args) {
		Message msg1 = new Message("Hello World");
		Message msg2 = new Message("This is a Java program");
		Message msg3 = new Message("With 3 Message objects");

		msg1.print();
		msg2.print();
		msg3.print();
	}
}