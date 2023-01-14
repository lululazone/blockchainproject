


public class Transactions {
	public String hash_tx;
	public String emetteur;
	public String receveur;
	public String tx_string; 
	static int MAX_VALUE = 100;
	long satoBnb;
	
	
	
	/**
	 * @param transactionId
	 * @param satoBnb
	 */
	public Transactions(String emetteur,String receveur,long satoBnb) {
		this.satoBnb = satoBnb;
		this.receveur = receveur;
		this.emetteur = emetteur;
		this.tx_string = "Source "+emetteur+" -Destination "+receveur+satoBnb;
	}




	// Calcule hash de la transaction, sera utilise comme id et pourra etre verifie par la suite
	private String calulateHash() {
		return HashUtil.applySha256(
				tx_string
				);
	}
	
	public boolean processTransaction() {
		hash_tx = calulateHash();
		return true;
		
	}
	public Transactions send(String emetteur, String receveur,long value ) {
		Transactions newTransaction = new Transactions(emetteur, receveur , value);
		System.out.println(newTransaction.tx_string);
		


		return newTransaction;
	}
}