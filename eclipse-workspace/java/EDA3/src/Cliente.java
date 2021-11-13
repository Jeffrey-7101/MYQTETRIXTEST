
public class Cliente implements Comparable<Cliente> {
	private String nombre,direcci�n;
	private Seguro seguro;
	private int telefono;
	private int Id;
	private Agente agente;
	//static int cantidad=0;
	public Cliente() {
		
	}
	public Cliente(String _nombre,String _direccion, int _telefono) {
		this.nombre=_nombre;
		this.direcci�n=_direccion;
		//this.seguro=_tipoPlan;
		this.telefono=_telefono;
	}
	public void setAgente(Agente _agente) {
		this.agente=_agente;
	}
	
	public boolean haveAgent() {
		if(this.agente==null)
			return false;
		return true;
	}
	
	public String getNombre() {
		return nombre;
	}
	public String getDirecci�n() {
		return direcci�n;
	}
	public Seguro getSeguro() {
		return seguro;
	}
	public int getTelefono() {
		return telefono;
	}
	public int getId() {
		return Id;
	}
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	public void setDirecci�n(String direcci�n) {
		this.direcci�n = direcci�n;
	}
	public void setSeguro(Seguro _tipoPlan) {
		this.seguro = _tipoPlan;
	}
	public void setTelefono(int telefono) {
		this.telefono = telefono;
	}
	public void setId(int _id) {
		this.Id=_id;
	}
	
	public Agente getAgente() {
		return this.agente;
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "CLIENTE \t "+this.Id+"\t"+this.nombre+"\t"+this.direcci�n+"\t"+this.telefono+"\t"+this.seguro.getNombre();
	}
	@Override
	public int compareTo(Cliente o) {
		// TODO Auto-generated method stub
		return this.nombre.compareTo(o.nombre);
	}
	
}
