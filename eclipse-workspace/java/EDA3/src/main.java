import java.util.*;
public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		AgenciaSeguros miAgencia = new AgenciaSeguros("Mi Agencia", "Avenida Las Americas 123");
		
		SeguroPersonal seguroPersonal=new SeguroPersonal(150, 1);
		SeguroFamiliar seguroFamiliar= new SeguroFamiliar(350,4);
		SeguroVehicular seguroVehicular= new SeguroVehicular(500,4);
		
		miAgencia.addSeguro(seguroVehicular);
		miAgencia.addSeguro(seguroFamiliar);
		miAgencia.addSeguro(seguroPersonal);
		
		Agente agente1= new Agente("Jose", 23,"Calle 1", 1000);
		Agente agente2= new Agente("Juan", 32,"Calle 2", 2200);
		//Agente agente3= new Agente("Carlos", 25,"Calle 3", 1500);
		//Agente agente4= new Agente("Luis", 40,"Calle 4", 3200);
		
		miAgencia.addAgente(agente1);
		miAgencia.addAgente(agente2);
		//miAgencia.agentes.insert(agente3);
		//miAgencia.agentes.insert(agente4);
		
		Cliente cliente1= new Cliente("Maria","Avenida 1", 1122);
		Cliente cliente2= new Cliente("Juana","Avenida 2", 2233);
		Cliente cliente3= new Cliente("Isma","Avenida 3", 3344);
		Cliente cliente4= new Cliente("Jesus","Avenida 4", 4455);
		Cliente cliente5= new Cliente("Fernanda","Avenida 5", 5566);
		
		cliente1.setSeguro(seguroVehicular);
		cliente2.setSeguro(seguroPersonal);
		cliente3.setSeguro(seguroFamiliar);
		cliente4.setSeguro(seguroFamiliar);
		cliente5.setSeguro(seguroVehicular);
		
		miAgencia.addCliente(cliente1);
		miAgencia.addCliente(cliente2);
		miAgencia.addCliente(cliente3);
		miAgencia.addCliente(cliente4);
		miAgencia.addCliente(cliente5);
		
		
		
		System.out.println("Agentes:");
		System.out.println(miAgencia.showAgentes());
		System.out.println("----------------");
		//miAgencia.showClientes();
		System.out.println("Clientes:");
		System.out.println(miAgencia.showClientes());
		System.out.println("----------------");
		System.out.println("Buscar Clientes de Agente2 ");
		for(Cliente i: miAgencia.searchClientebyAgente(agente2))
			System.out.println(i);
		System.out.println("-----------------");
		
		
		System.out.println("Mostrar Clientes de Agente 2");
		agente2.showClientes();
		System.out.println("--------------------");
		
		System.out.println("Mostrar Agente de Cliente 4");
		System.out.println(cliente4.getAgente());
		System.out.println("--------------------");
		
		System.out.println("Mostrar Agente de Cliente 5"); // no tiene agente asignado
		System.out.println(cliente5.getAgente());
		System.out.println("--------------------");
		
		System.out.println("Eliminando Cliente 1");
		System.out.println("Clientes:");
		agente1.removeCliente(cliente1);
		agente1.showClientes();
		System.out.println("--------------------");
		
		System.out.println("Eliminando Agente 2");
		miAgencia.removeAgente(agente2);

		
	}

}
