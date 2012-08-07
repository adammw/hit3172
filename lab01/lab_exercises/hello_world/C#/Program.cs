class Program {
	public static void Main() {
		Message msg1 = new Message("Hello World");
		Message msg2 = new Message("This is a C# program");
		Message msg3 = new Message("With 3 Message objects");

		msg1.Print();
		msg2.Print();
		msg3.Print();
	}
}