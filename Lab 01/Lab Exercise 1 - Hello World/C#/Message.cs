using System;

class Message {
	private string _text;
	public Message(string txt) {
		_text = txt; 
	}
	public void Print() {
         Console.WriteLine(_text);
     }
}