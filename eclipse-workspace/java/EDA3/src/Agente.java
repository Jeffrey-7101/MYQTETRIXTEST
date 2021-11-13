
public class Agente implements Comparable<Agente>{
	private String nombre, direccion;
	private double sueldo;
	private int edad;
	private int id;
	//static int cantidad=0;
	private Cliente[] clientes=new Cliente[2];
	
	public Agente(String _nombre,int _edad, String _direccion,double _sueldo) {
		this.nombre=_nombre;
		this.direccion=_direccion;
		this.edad=_edad;
		this.sueldo=_sueldo;
	}
	
	public boolean isFree() {
		if(clientes[0]!= null && clientes[1]!= null)
			return false;
		else if(clientes[0]== null && clientes[1]!= null)
			return true;
		else if(clientes[0]!= null && clientes[1]== null)
			return true;
		else
			return true;
	}
	
	public void addCliente(Cliente _cliente) {
		
		if(!isFree()) {
			System.out.println("Agente Ocupado");
		}
		else {	
		for(int i=0;i<2;i++) {
			if(clientes[i] == null) {
				clientes[i]=_cliente;
				break;
				}
			}
		}		
	}
	
	public void removeCliente(Cliente _cliente) {
		for(int i=0;i<2;i++) {
			if(clientes[i]==_cliente) {
				_cliente.setAgente(null);
				clientes[i]=null;
			}
		}
		
	}
	
	public void showClientes() {
		for(int i=0;i<2;i++) {
			if(clientes[i]==null)
				System.out.println("null");
			else
				System.out.println(clientes[i].toString());
		}
	}
	public Cliente[] getCliente() {
		return this.clientes;
	}
	public void setId(int _id) {
		 this.id=_id;
	}
	public String getNombre() {
		return nombre;
	}
	public String getDireccion() {
		return direccion;
	}
	public double getSueldo() {
		return sueldo;
	}
	public int getId() {
		return this.id;
	}
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	public void setDireccion(String direccion) {
		this.direccion = direccion;
	}
	public void setSueldo(double sueldo) {
		this.sueldo = sueldo;
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		String str="AGENTE \t"+this.getId()+"\t"+this.nombre+"\t"+this.edad+"\t"+this.direccion+"\t"+this.sueldo;
		/*for(int i=0;i<2;i++) {
			str+=clientes[i];
		}*/
		return str;
	}
	@Override
	public int compareTo(Agente o) {
		// TODO Auto-generated method stub
		
		return this.compare(o);
	}
	public int compare(Agente a) {
		if(this.edad>a.edad)
			return 1;
		else if(this.edad<a.edad)
			return -1;
		else 
			return 0;
	}

}
