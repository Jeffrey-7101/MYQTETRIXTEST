import java.util.ArrayList;

public class AgenciaSeguros {
	String nombre;
	String direccion;
	AVLTree<Agente> agentes=new AVLTree<Agente>();
	AVLTree<Cliente> clientes=new AVLTree<Cliente>();
	static int cantidadAgentes=0;
	static int cantidadClientes=0;
	List<Seguro> seguros=new List<Seguro>();
	
	public AgenciaSeguros(String _nombre, String _direccion){
		this.nombre=_nombre;
		this.direccion=_direccion;

	}
	
	public void addCliente(Cliente _cliente) {
		_cliente.setId(2000+cantidadClientes);
		for(Agente i: agentes.preorder()) {
			if(i.isFree()) {
				if(!_cliente.haveAgent()) {
					i.addCliente(_cliente);
					_cliente.setAgente(i);
				}	
			}
		}
		clientes.insert(_cliente);
		cantidadClientes++;
	}
	public void removeCliente(Cliente _cliente) {
		for(Cliente i: clientes.preorder()) {
			if(i==_cliente) {
				i.getAgente().removeCliente(_cliente);
				i=null;
			}
		}
	}
	
	public void addAgente(Agente newAgente) {
		newAgente.setId(1000+cantidadAgentes);
		agentes.insert(newAgente);
		cantidadAgentes++;
	}
	public void removeAgente(Agente agente) {
		Cliente[] aux= agente.getCliente();
		
		for(Agente a: agentes.preorder()) {
			if(a==agente) {
				if(!a.isFree()) {
					for(Agente i: agentes.preorder()) {
						if(i.isFree()) {
							for(Cliente k: aux) {
								i.addCliente(k);
								break;
							}
						}
							
					}
					agentes.remove(a);
						
				}
				else {
					agentes.remove(a);
				}
			}
				
		}
			
	}
	public void addSeguro(Seguro newSeguro) {
		seguros.add(newSeguro);
	}
	/*public void showAgentes() {
		for(Agente i: agentes.preorder()) {
			if(i==null) 
				System.out.println("");
			else
				System.out.println(i.toString());
		}
	}*/
	public String showAgentes() {
		String str="TIPO \t CODIGO \t NOMBRE \t EDAD \t DIRECCION \t SUELDO \n";
		for(Agente i: agentes.preorder()) {
			if(i==null) 
				str+="";
			else
				str+=(i.toString())+"\n";
		}
		return str;
	}
	/*public void showClientes() {
		for(Cliente i: clientes.preorder())
			System.out.println(i.toString());
	}*/
	public String showClientes() {
		String str="TIPO \t CODIGO \t NOMBRE \t DIRECCION \t TELEFONO \t SEGURO \n";
		for(Cliente i: clientes.preorder()) {
			if(i==null) 
				str+="";
			else
				str+=(i.toString())+"\n";
		}
		return str;
	}
	public void showSeguros() {
		for(int i=0;i<seguros.size;i++) {
			System.out.println(seguros.get(i));
		}	
	}
	
	public ArrayList<Cliente> searchClientebyAgente(Agente _agente) {
		ArrayList<Cliente> clientesEncontrados= new ArrayList<Cliente>();
		for(Cliente i : clientes.preorder()) {
			if(i.getAgente()== _agente) {
				clientesEncontrados.add(i);
			}
		}
		return clientesEncontrados;
	}
	
	public String toString() {
		return "Agencia: "+this.nombre+" Ubicada en: "+this.direccion; 
				
	}
	
}
