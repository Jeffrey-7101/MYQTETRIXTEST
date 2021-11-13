

public class Node<E extends Comparable<? super E>> {
    private E data;
    Node<E> left;
    Node<E> right;
    private int height;
    private int balanceFactor;

    /**
     * Create an AVL node with the specified data.
     *
     * @param data the data to be stored in this node
     */
    public Node(E data) {
        this.data = data;
        this.left=this.right=null;
    }
    
    public Node(E _data, Node<E> _left, Node<E> _right) {
    	this.data=_data;
    	this.left=_left;
    	this.right=_right;
    }
    /**
     * Get the data in this node.
     *
     * @return data in this node
     */
    public E getData() {
        return data;
    }

    /**
     * Set the data in this node.
     *
     * @param data data to store in this node
     */
    public void setData(E data) {
        this.data = data;
    }

    /**
     * Get the node to the left of this node.
     *
     * @return node to the left of this node.
     */
    public Node<E> getLeft() {
        return left;
    }

    /**
     * Set the node to the left of this node.
     *
     * @param left node to the left of this node
     */
    public void setLeft(Node<E> left) {
        this.left = left;
    }

    /**
     * Get the node to the right of this node.
     *
     * @return node to the right of this node.
     */
    public Node<E> getRight() {
        return right;
    }

    /**
     * Set the node to the right of this node.
     *
     * @param right node to the right of this node
     */
    public void setRight(Node<E> right) {
        this.right = right;
    }

    /**
     * Get the height of this node.
     *
     * @return height of this node
     */
    public int getHeight() {
        return height;
    }

    /**
     * Set the height of this node.
     *
     * @param height height of this node
     */
    public void setHeight(int height) {
        this.height = height;
    }

    /**
     * Get the balance factor of this node.
     *
     * @return balance factor of this node.
     */
    public int getBalanceFactor() {
        return balanceFactor;
    }

    /**
     * Set the balance factor of this node.
     *
     * @param balanceFactor balance factor of this node
     */
    public void setBalanceFactor(int balanceFactor) {
        this.balanceFactor = balanceFactor;
    }

    @Override
    public String toString() {
        return String.format("Node containing %s (height %d, balance factor %d",
                data.toString(), height, balanceFactor);
    }
    
    public boolean isLeaf() {
		return this.left ==null && this.right==null;
	}
}
