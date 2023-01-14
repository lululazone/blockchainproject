

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Date;
import javax.swing.*;


public class BlockChain{
	public ArrayList<Block> blockchain = new ArrayList<Block>();
	
	public static Transactions genesisTransaction;
	public static Transactions tx;
	public static HelicopterMoney hmoney;
	public Randomizer rd = new Randomizer();
	public String coinbase = "User0";
	int rd_tx;
	public String creator = "User1";
	public String[] UserN = {creator,"Robert","Jule","Maxime","Antoine","Emilien","Dark Vador","Lucas","Walter White","Juliette"};
	int NB_MAX_USER = 100;
	int i;
	
	
	
	
	
	
	public BlockChain(){
		JFrame f= new JFrame("Resultat BlockChain");
		JTextArea area=new JTextArea("Resultat: \n");
		if(!InterfaceBC.isOneBlock) {
			Console console = new Console(); //genere une console pour afficher les resultats
			console.ManageConsole(f, area);
		}
		else {
			PrintStream printStream = new PrintStream(new CustomOutputStream(area));
			System.setOut(printStream);
		}
		genesisTransaction = new Transactions(coinbase, creator, (long) (50*Math.pow(10, 8)));
	    genesisTransaction.hash_tx = "0";
		int i = 1;
		Block genesis = new Block("0");
		genesis.addTransaction(genesisTransaction);
		addBlock(genesis);
		System.out.println("Transaction genesis achevee ! ");
		hmoney = new HelicopterMoney(coinbase, UserN,genesis);
		hmoney.MakeHelicopter();
	    while(i!=InterfaceBC.nbBlocs ) {
	    	
	    	int cpt = 0;
	    	Block block = new Block(blockchain.get(blockchain.size()-1).hash);
	    	rd_tx = rd.randInt(InterfaceBC.nbTransactions);
	    	while(cpt!=rd_tx) { 
	    		int user1 = rd.randInt(9); //generation de tx aléatoire...
	    		int user2 = rd.randInt(9);
	    		int valeur = rd.randInt(9);
	    		while(user1 == user2) {
	    			user2 = rd.randInt(9);
	    		}
	    		System.out.println(UserN[user1]+" essaie d'envoyer "+valeur+" Bnb a "+UserN[user2]);
	    		long money = (long) (valeur*Math.pow(10, 8));
	    		Transactions tx = new Transactions(UserN[user1],UserN[user2],money);
	    		tx = new Transactions(UserN[user1], UserN[user2], money);
	    		System.out.println("Valeur Transaction" + tx.send(UserN[user1],UserN[user2],money).tx_string);
	    		block.addTransaction(tx);
	    		block.Tx_number++;
	    		cpt++;
	    	}
	    	area.update(area.getGraphics()); // Utilise pour mettre a jour la console
	    	block.merkleT_Hash = MerkleTree.CalculMerkleHash(block.transactions); // On calcule le merkle tree de toute les transactions du bloc courant
	    	blockchain.add(block);
	    	System.out.println("On tente de miner le block : " +i+ "Previous Hash: "+blockchain.get(i).getPrev_Hash()+" Hash: "+blockchain.get(i).hash+ "TimeStamp: "+ new Date(blockchain.get(i).getTimestamp()));
	    	blockchain.get(i).mineBlock();
	    	i++;
	    }
	    //Partie de la verification
	    Block currentBlock; 
		Block previousBlock;
		InterfaceBC.verif = true;
		
		System.out.println("Verification des hash...");
		//Debut de verification de la BC on verifie les hash
		for(int j=1; j < InterfaceBC.nbBlocs; j++) {
			currentBlock = blockchain.get(j);
			previousBlock = blockchain.get(j-1);
			//On verifie le hash courant
			if(!currentBlock.hash.equals(currentBlock.calculHash()) ){			
				InterfaceBC.verif = false;
				
			}
			//On verifie le hash precedent 
			if(!previousBlock.hash.equals(currentBlock.prev_Hash) ) {
				InterfaceBC.verif = false;
				
			}
			
		}
		//On verifie la presence du block genesis 
		System.out.println("Verification genesis ...");
		if(!blockchain.get(0).prev_Hash.equals("0")) {
			InterfaceBC.verif = false;
			
		}
		//On verifie la validite du hash de merkle
		System.out.println("Verification hash de merkle....");
		for(int j=1; j < InterfaceBC.nbBlocs; j++) {
			currentBlock = blockchain.get(j);
			if(!currentBlock.merkleT_Hash.equals(MerkleTree.CalculMerkleHash(currentBlock.transactions))) {
				InterfaceBC.verif = false;
				
				
			}
		}
		
		
	    
	    	
	}

	public ArrayList<Block> getBlockchain() {
		return blockchain;
	}
	
	
	
	/**
	 * @return the blockchain
	 */

	/**
	 * @param blockchain the blockchain to set
	 */
	public void setBlockchain(ArrayList<Block> blockchain) {
		this.blockchain = blockchain;
	}
	/**
	 * @param blockchain
	 */
	public BlockChain(ArrayList<Block> blockchain) {
		this.blockchain = blockchain;
	}
	public void genesisBlock(String text) {
		blockchain.add(new Block("0"));
	}
	
	
	public void addBlock(Block block){
		blockchain.add(block);
	}
	
	
				
		
	

}
