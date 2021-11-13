

import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;

public class AVLTree<E extends Comparable<? super E>> implements AVLTreeInterface<E>{
	Node<E> root;
	int size;
	public boolean isEmpty() {
		return this.root==null;
	}
    /**
     * Add the data as a leaf in the AVL.  Should traverse the tree to find the
     * appropriate location. If the data being added already exists in the tree,
     * do nothing.
     *
     * @throws IllegalArgumentException if the data is null
     * @param data the data to be added
     */
   /* @Override
    public void insert(E data) {
        //TODO implement here!
    	Node<E> newNode= new Node<E>(data);
    	if(data==null)
    		throw new IllegalArgumentException("No se puede insertar valores nulos");
    	if(this.root==null) {
    		this.root= newNode;
    		System.out.println("Raiz: " + data);
    	}
    	else {
    		insert(this.root,data);
    		size++;
    	}
    }
    private void insert(Node<E> node,E _data){
    	if(node==null) {
    		System.out.println("Encontro Nodo vacio");
    		node= new Node<E>(_data,null,null);
    		System.out.println("Inserto Elemento: "+_data);
    	}
    	else if(_data.compareTo(node.getData())<0) {
    		System.out.println("Para "+_data+" se fue a la izquierda ");
    		insert(node.left,_data);
    	}else if(_data.compareTo(node.getData())>0) {
    		System.out.println("Para "+_data+" se fue a la derecha ");
    		insert(node.right,_data);
    	}else {    		
    		return;
    	}   		
    }*/
	public void insert(E data) {
		root = insert(root, data);
		this.size+=1;
	}

	private Node<E> insert(Node<E> node, E data) {
		if (node == null) {
			//System.out.println("Insertó "+data);
			return new Node<E>(data);
		}
		if (data.compareTo(node.getData()) > 0) {
			//System.out.println("Para insertar "+data+" se fue a la derecha ");
			node = new Node<E>(node.getData(), node.getLeft(), insert(node.getRight(), data));
			
		} else if (data.compareTo(node.getData()) < 0) {
			//System.out.println("Para insertar "+data+" se fue a la izquierda ");

			
			node = new Node<E>(node.getData(), insert(node.getLeft(), data),node.getRight());
		}
		return node;
	}
    /**
     * Removes the data from the tree.  There are 3 cases to consider:
     * 1: the data is a leaf.  In this case, simply remove it.
     * 2: the data has one child.  In this case, simply replace the node with
     * the child node.
     * 3: the data has 2 children.  There are generally two approaches:
     * replacing the data with either the largest element in the left subtree
     * (commonly called the predecessor), or replacing it with the smallest
     * element in the right subtree (commonly called the successor). For this
     * assignment, use the successor.
     *
     * @throws IllegalArgumentException if the data is null
     * @throws java.util.NoSuchElementException if the data is not in the tree
     * @param data data to remove from the tree
     * @return the data removed from the tree.  Do not return the same data
     * that was passed in.  Return the data that was stored in the tree.
     */
    @Override
    public E remove(E data) {
    	if(data==null)
    		throw new IllegalArgumentException("El dato es nulo");
    	else {
    		removeAux(data);
    		size--;
    	}
        return null;
    }
    private E removeAux(E _data) {
    	Node<E> iterator=this.root;
    		if(iterator==null)
    			throw new NoSuchElementException();
	    	if(iterator.isLeaf())
	    		iterator=null;
	    	else {
	    		while (iterator.getData() != null) {
	    			if (iterator.getData().compareTo(_data) == 0) {	// si encuentra el dato
	    				if(iterator.getLeft()==null && iterator.getRight()!=null) {// si el nodo solo tiene hijo derecho, lo reemplaza por este
			    			iterator=iterator.getRight();
			    		}else if(iterator.getLeft()!=null && iterator.getRight()==null) {//si el nodo solo tiene hijo izquierdo, lo reemplaza por este
			    			iterator=iterator.getLeft();
			    		
			    		}else if(iterator.getLeft()!=null && iterator.getRight()!=null) {//si el nodo tiene hijos a ambos lados, lo reemplaza por el sucesor(menor del subarbol derecho)
			    			iterator=sucesor(iterator);
			    		}
			    		else if(iterator.getLeft()==null && iterator.getRight()==null)// si el nodo no tiene hijos, solo lo elimina
			    			iterator.setData(null);
	    			}
	    			else if (iterator.getData().compareTo(_data) > 0)
	    				iterator = iterator.getLeft();
	    			else
	    				iterator = iterator.getRight();
	    		}
	    	}
    	return iterator.getData();
    }
    public Node<E> sucesor(Node<E> node){
    	Node<E> nodeAux= node.right;
    	while(nodeAux!=null)
    		nodeAux=nodeAux.left;
    	return nodeAux;
    }

    /**
     * Returns the data in the tree matching the parameter passed in.
     *
     * @throws IllegalArgumentException if the data is null
     * @throws java.util.NoSuchElementException if the data is not found
     * @param data data to get in the AVL tree
     * @return the data in the tree equal to the parameter.  Do not return the
     * same data that was passed in.  Return the data that was stored in the
     * tree.
     */
    @Override
    public E get(E data) {
        //TODO implement here!
    	if(data==null)
    		throw new IllegalArgumentException("No se puede buscar datos nulos");
    	else {
    		Node<E> temp=getAux(data);
    		if(temp==null)
    			throw new NoSuchElementException();
    		else
    			return temp.getData();
    	}
    }
    private Node<E> getAux(E _data) {
    	Node<E> iterator = this.root;
		while (iterator != null) {
			if (iterator.getData().compareTo(_data) == 0)
				return iterator;
			else if (iterator.getData().compareTo(_data) > 0)
				iterator = iterator.getLeft();
			else
				iterator = iterator.getRight();
		}
		return iterator;
    }

    /**
     * Returns whether or not the parameter is contained within the tree.
     *
     * @throws IllegalArgumentException if the data is null
     * @param data data to find in the AVL tree
     * @return whether or not the parameter is contained within the tree
     */
    @Override
    public boolean contains(E data) {
        //TODO implement here!
    	if(data==null)
    		throw new IllegalArgumentException("No se admiten datos nulos");
    	else {
    		return searchAux(data);	
    	}
    }
    private boolean searchAux(E _data) {
    	Node<E> iterator = this.root;
		while (iterator != null) {
			if (iterator.getData().compareTo(_data) == 0)
				return true;
			else if (iterator.getData().compareTo(_data) > 0)
				iterator = iterator.getLeft();
			else
				iterator = iterator.getRight();
		}
		return false;
    }

    /**
     * Get the number of elements in the tree.
     *
     * @return the number of elements in the tree
     */
    @Override
    public int size() {
        //TODO implement here!
    	 return this.size;
    }

    /**
     * Get the preorder traversal of the tree.
     *
     * @return a preorder traversal of the tree, or an empty list
     */
    @Override
    public List<E> preorder() {
        //TODO implement here!
    	if(isEmpty())
    		return null;
    	else {
    		List<E> preOrderList = new ArrayList<E>();
			return recorridoPreOrder(this.root,preOrderList);
    	}
    }
    
    private List<E> recorridoPreOrder(Node<E>node, List<E> lista){
		
    	if(node==null)
    		return lista;
    	
    	lista.add(node.getData());
    	recorridoPreOrder(node.left, lista);
    	recorridoPreOrder(node.right, lista);
    	
    	return lista;
    }

    /**
     * Get the postorder traversal of the tree.
     *
     * @return a postorder traversal of the tree, or an empty list
     */
    @Override
    public List<E> postorder() {
        //TODO implement here!
    	if(isEmpty())
    		return null;
    	else {
    		List<E> postOrderList = new ArrayList<E>();
    		recorridoPostorden(this.root,postOrderList);
    		return postOrderList;
    	}
    }
    
    private void recorridoPostorden( Node<E> node, List<E> list){
        if(node == null)
            return;
        
        recorridoPostorden(node.left,list);
        recorridoPostorden(node.right,list);
        list.add(node.getData());
    }
    
    /**
     * Get the inorder traversal of the tree.
     *
     * @return an inorder traversal of the tree, or an empty list
     */
    @Override

    public List<E> inorder(){
    	//TODO implement here!
    	if(isEmpty())
    		return null;
    	else {
    		List<E> inOrderList = new ArrayList<E>();
    		recorridoInorden(this.root,inOrderList);
    		return inOrderList;
    	}
    }

    private void recorridoInorden( Node<E> node, List<E> list){
        if(node == null)
            return;
        
        recorridoInorden(node.left,list);
        list.add(node.getData());
        recorridoInorden(node.right,list);
    }

    /**
     * Clear the tree.
     */
    @Override
    public void clear() {
        //TODO implement here!
    	this.root=null;
    }

    /**
     * Return the height of the root of the tree.
     *
     * This method does not need to traverse the entire tree.
     *
     * @return the height of the root of the tree, -1 if the tree is empty
     */
    @Override
    public int height() {
        //TODO implement here!
        return 0;
    }

    /**
     * @return the root of the tree
     */
    
    public Node<E> getRoot() {
        //TODO implement here!
        return this.root;
    }

    
    public static void main(String[] args) {
		AVLTree<String> tree= new AVLTree<String>();
		tree.insert("D");
		tree.insert("B");
		tree.insert("U");
		tree.insert("A");
		tree.insert("C");
		tree.insert("J");
		tree.insert("V");
		System.out.println(tree.getRoot().getData());
		System.out.println(tree.size);
		System.out.println(tree.contains("C"));
		
		for(String i: tree.preorder())
			System.out.print(i+", ");
		System.out.println();
		
		
		for(String i: tree.inorder())
			System.out.print(i+", ");
		System.out.println();
		
		for(String i: tree.postorder())
			System.out.print(i+", ");
		System.out.println();
		
		tree.remove("V");
		tree.remove("A");
		for(String i: tree.preorder())
			System.out.print(i+", ");
		System.out.println();
		
		
		for(String i: tree.inorder())
			System.out.print(i+", ");
		System.out.println();
		
		for(String i: tree.postorder())
			System.out.print(i+", ");
		System.out.println();
	}
    
}
