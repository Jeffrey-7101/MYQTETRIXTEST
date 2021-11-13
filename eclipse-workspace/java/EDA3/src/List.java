
public class List<T> {
	NodeList<T> first;
	NodeList<T> last;
	int size=0;
	
	public List() {
		this.first=null;
		this.last=null;
	}
	
	public boolean isEmpty() {
		if(this.first==null)
			return true;
		return false;
	}
	
	public boolean add(T d) {
		
		NodeList<T> newNode= new NodeList(d);
		
		if(this.isEmpty()) {
			this.first=newNode;
			this.last=this.first;
		} else {
			this.last.nextNode=newNode;
			this.last=this.last.nextNode;
		}
		this.size++;
		return true;
	}
	
	public boolean contains(T d) {
		NodeList<T> iterNode=new NodeList();
		iterNode=this.first;
		
		while(iterNode != null) {
			if(iterNode.data==d)
				return true;
			iterNode=iterNode.nextNode;
		}
		return false;
	}
	
	public int lastIndexOf(T d) {
		NodeList<T> iterNode=new NodeList();
		iterNode=this.first;
		int index=0;
		while(iterNode != null) {
			if(iterNode.data==d)
				return index;
			iterNode=iterNode.nextNode;
			index++;
		}
		return -1;
	}
	
	public T get(int index) {
		NodeList<T> iterNode=new NodeList();
		iterNode= this.first;
		int iter=0;
		while(iter!= index) {	
			iterNode=iterNode.nextNode;
			
			iter++;
			if(iterNode == null) {
				return null;
			}
		}
		
		return iterNode.data;
		
	}
}
