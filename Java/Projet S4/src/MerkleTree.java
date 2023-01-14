import java.util.ArrayList;

public class MerkleTree {
	public static String CalculMerkleHash(ArrayList<Transactions> transactions) {
		int count = transactions.size(); 
		ArrayList<String> previousTreeLayer = new ArrayList<String>();
		for(Transactions transaction : transactions) { //On range les transactions dans un arbre
			previousTreeLayer.add(transaction.hash_tx);
		}
		ArrayList<String> treeLayer = previousTreeLayer;
		while(count > 1) {
			treeLayer = new ArrayList<String>();
			for(int i=1; i < previousTreeLayer.size(); i++) {
				treeLayer.add(HashUtil.applySha256(previousTreeLayer.get(i-1) + previousTreeLayer.get(i)));
				//On applique le hash de deux hash concatenee
			}
			count = treeLayer.size();
			previousTreeLayer = treeLayer;
		}
		String merkleRoot = (treeLayer.size() == 1) ? treeLayer.get(0) : ""; //Si treeLayersize = 1 mroot == tlayer.get(0) sinon mroot = "";
		return merkleRoot;
	}
}
