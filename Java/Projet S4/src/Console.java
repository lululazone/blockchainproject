import java.io.PrintStream;

import javax.swing.*;

public class Console {
	public void ManageConsole(JFrame f, JTextArea area) {
		f.setSize(400,400); 
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		PrintStream printStream = new PrintStream(new CustomOutputStream(area));
		System.setOut(printStream);
    	System.setErr(printStream); 
	    area.setEditable(true);
		area.setBounds(0,0, 400,400);  
		f.setVisible(true);
		JScrollPane scroll = new JScrollPane(area);
		scroll.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		f.add(scroll);
	}

}
