
public class NodeList<T> {
	T data;
	NodeList<T> nextNode;
	
	public NodeList() {
		this.data=null;
		this.nextNode=null;
	}
	
	public NodeList(T d){
		this.data=d;
		this.nextNode=null;
	}
	
	public void print() {
		System.out.println(this.data);
	}

}
