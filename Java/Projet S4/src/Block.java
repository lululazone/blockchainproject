
import java.util.ArrayList;
import java.util.Date;

public class Block {

	public String hash;
	public String prev_Hash;
	public ArrayList<Transactions> transactions;
	public int Tx_number;
	public String merkleT_Hash;
	public long Timestamp;
	private int nonce;

	public Block(String prev_Hash) {
		this.prev_Hash = prev_Hash;
		this.Timestamp = new Date().getTime();
		this.hash = calculHash();
		this.transactions = new ArrayList<Transactions>();
	}

	public String calculHash() {
		String calculhash = HashUtil
				.applySha256(prev_Hash + Long.toString(Timestamp) + Integer.toString(nonce) + merkleT_Hash);
		return calculhash;
	}
	/**
	 * @return the hash
	 */
	public String getHash() {
		return hash;
	}

	/**
	 * @param hash the hash to set
	 */
	public void setHash(String hash) {
		this.hash = hash;
	}

	/**
	 * @return the prev_Hash
	 */
	public String getPrev_Hash() {
		return prev_Hash;
	}

	/**
	 * @param prev_Hash the prev_Hash to set
	 */
	public void setPrev_Hash(String prev_Hash) {
		this.prev_Hash = prev_Hash;
	}



	/**
	 * @return the timestamp
	 */
	public long getTimestamp() {
		return Timestamp;
	}

	/**
	 * @param timestamp the timestamp to set
	 */
	public void setTimestamp(long timestamp) {
		Timestamp = timestamp;
	}

	/**
	 * @return the nonce
	 */
	public int getNonce() {
		return nonce;
	}

	/**
	 * @param nonce the nonce to set
	 */
	public void setNonce(int nonce) {
		this.nonce = nonce;
	}

	public void mineBlock() {
		String target = new String(new char[(int) InterfaceBC.difficulty]).replace('\0', '0');  
		while(!hash.substring( 0, (int)InterfaceBC.difficulty).equals(target)) {
			nonce ++;
			hash = calculHash();
		}
		
		System.out.println("Block minee avec succes : " + hash);
	}
	
	public boolean addTransaction(Transactions transaction) {
		//On fait la transaction sauf si genesis.
		if(transaction == null) return false;		
		if((prev_Hash != "0")) {
			if((!transaction.processTransaction())) {
				System.out.println("--Erreur de Transaction--");
				return false;
			}
		}
		transactions.add(transaction);
		System.out.println("--Transaction accomplie--");
		return true;
	}
	

}
