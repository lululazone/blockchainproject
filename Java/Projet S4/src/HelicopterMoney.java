
public class HelicopterMoney {
	public static Transactions genesisTransaction;
	String Creator;
	String[] UserN;
	String coinbase;
	Block block;
	int i;
	

	public HelicopterMoney(String coinbase2, String[] userN2,Block block) {
		this.UserN = userN2;
		this.coinbase = coinbase2;
		this.block = block;
	}
	public void MakeHelicopter() {
		//phase HelicopterMoney
		long money = (long) (50*Math.pow(10, 8)); // On convertit les Bnb en satoBnb
		for(i = 0;i<5;i++) {
			block.addTransaction(new Transactions(coinbase, UserN[i],money));
		}
	}

	

	
	
	
}
