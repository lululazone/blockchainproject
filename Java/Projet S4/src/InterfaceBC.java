
import java.awt.Color;
import java.awt.event.*;


import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;

public class InterfaceBC implements ActionListener{
	static float difficulty;
	static int nbBlocs;
	public String textvalue;
	static int nbTransactions;
	static boolean isOneBlock;
	static boolean verif;
	static JFrame f= new JFrame("Interface de gestion BlockChain");   
    JLabel nbBloc = new JLabel("Nombre de Blocs :");
    JLabel nbMaxTr = new JLabel("Max de Transaction : ");
    JLabel chDifficulte = new JLabel("Choix difficultée : ");
    JButton demarrerprgm = new JButton("Simulation");
    JButton afficherbloc = new JButton("Afficher un bloc");
    JTextField SaisienbBloc = new JTextField(10);
    JTextField SaisieMaxTr = new JTextField(10);
    JTextField SaisieDifficultee = new JTextField(10);
    JFileChooser chooser = new JFileChooser();
    JButton lecturefichier = new JButton("Ouvrir fichier");
    FileNameExtensionFilter filter = new FileNameExtensionFilter(
            "Fichiers JSON", "JSON");
    
    
      

	public InterfaceBC() {
		chooser.setFileFilter(filter);
		
		demarrerprgm.addActionListener(this);
	    demarrerprgm.setBackground(Color.ORANGE);
	    afficherbloc.setBounds(266, 265, 133, 50);
	    lecturefichier.setBounds(133, 265, 133, 50);
	    SaisienbBloc.setBounds(175,65,50,25);
	    SaisieMaxTr.setBounds(175, 165, 50, 25);
	    lecturefichier.addActionListener(this);
	    afficherbloc.addActionListener(this);
	    nbMaxTr.setBounds(50,150,100,50);
	    demarrerprgm.setBounds(0, 265, 133, 50);
	    chDifficulte.setBounds(50,200,150,50);
	    SaisieDifficultee.setBounds(150,215,50,25);
	    nbBloc.setBounds(50,50,125,50);
        f.add(afficherbloc);
        f.add(SaisieDifficultee);
        f.add(nbBloc);
        f.add(lecturefichier);
        f.add(demarrerprgm);
        f.add(chDifficulte);
        f.add(nbMaxTr);
        f.add(SaisienbBloc);
        f.add(SaisieMaxTr);
        f.setSize(400,400);  
        f.setLayout(null);  
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        

		
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == demarrerprgm || e.getSource() == afficherbloc ) {
			if(SaisieMaxTr.getText().isBlank() || SaisienbBloc.getText().isBlank()|| SaisieDifficultee.getText().isBlank() ) {
				JOptionPane.showMessageDialog(f, "Veuillez remplir toute les cases !", "Attention",
	        	        JOptionPane.WARNING_MESSAGE);
			}
			else {
		        nbTransactions = Integer.parseInt(SaisieMaxTr.getText());
		        nbBlocs = Integer.parseInt(SaisienbBloc.getText());
		        difficulty = Float.parseFloat(SaisieDifficultee.getText());
		        System.out.printf("Difficulté: %f", difficulty);
		        System.out.printf("Nombre blocs: %d",nbBlocs);
		        System.out.printf("Nombre Transactions: %d", nbTransactions);
		        f.setVisible(false);
		        if(nbBlocs == 0 || nbTransactions == 0) {
		        	JOptionPane.showMessageDialog(f, "Les données saisies sont incorrectes", "Attention",
		        	        JOptionPane.WARNING_MESSAGE);
		        	f.setVisible(true);
		        }
		        	else {
		        		if(e.getSource() == afficherbloc) {
		        			int numbloc = Integer.parseInt(JOptionPane.showInputDialog(null, "Numero bloc a afficher :"));
		        			isOneBlock  = true;
		        			BlockChain bc = new BlockChain();
		        			JOptionPane.showMessageDialog(f, "Id bloc "+bc.blockchain.get(numbloc)+"\n Block hash :"+bc.blockchain.get(numbloc).hash+" \n Tx Block :"
		        			+bc.blockchain.get(numbloc).transactions,"Bloc "+numbloc,JOptionPane.INFORMATION_MESSAGE);
		        			BCJsonUtils.BCJsonWriter(bc, "test"+".JSON");
		        			
		        		}
		        		else {
		        		String nomfichier = JOptionPane.showInputDialog(null, "Nom du fichier destination:");
		        		isOneBlock = false;
			        	BlockChain bc = new BlockChain();
			        	System.out.println("On teste si la chaine est valide : " + verif) ;
			        	BCJsonUtils.BCJsonWriter(bc, nomfichier+".JSON");
		        			}
			 
			        	
			        	
		        	}
		        }
	        	
	        }
		if(e.getSource() == lecturefichier) {
			int returnVal = chooser.showOpenDialog(f);
			if(returnVal == JFileChooser.APPROVE_OPTION) {
			       System.out.println("You chose to open this file: " +
			            chooser.getSelectedFile().getName());
			       isOneBlock = false;
			       BCJsonUtils.BCJsonReader(chooser.getSelectedFile().getName());
			    }
			
		}
		
			
	
		
	}

	


	}

