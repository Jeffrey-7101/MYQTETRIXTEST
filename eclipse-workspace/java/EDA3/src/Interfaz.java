import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Interfaz extends JFrame {
	
	JPanel norte;
	JPanel norte2;
	JPanel sur;
	JPanel este;
	JPanel oeste;
	JPanel centro;
	
	
	
	JLabel titulo;
	JLabel crud;
	JLabel mostrar;
	
	JButton addAgente;
	JButton addCliente;
	JButton removeAgente;
	JButton removeCliente;
	JButton mostrarAgentes;
	JButton mostrarClientes;
	
	JTextArea mesa;
	JScrollPane scroll;
	
	Listener listener= new Listener();
	
	public Interfaz() {
		setSize(800,400);
		setTitle("Agencia");
		setLayout( new BorderLayout());
		createContents();
		setVisible(true);
	}
	private void createContents() {
		//<---------Paneles BORDERLAYOUT-------->
		
		norte= new JPanel(new FlowLayout());
		norte2= new JPanel(new FlowLayout());
		sur= new JPanel(new FlowLayout());
		este= new JPanel(new FlowLayout());
		oeste= new JPanel(new GridLayout(8,1));
		centro= new JPanel(new GridLayout(1,1));
		
		titulo= new JLabel("Agencia Seguros Vida");
		titulo.setAlignmentX(CENTER_ALIGNMENT);
		norte.add(titulo);

		add(norte,BorderLayout.NORTH);
		mostrar= new JLabel("Mostrar: ");
		mostrarAgentes= new JButton("Mostrar Agentes");
		mostrarAgentes.addActionListener(listener);
		
		mostrarClientes= new JButton("Mostrar Clientes");
		mostrarClientes.addActionListener(listener);
		crud= new JLabel("Gestionar: ");
		
		addAgente= new JButton("Añadir Agente");
		addAgente.addActionListener(listener);
		
		addCliente= new JButton("Añadir Cliente");
		addCliente.addActionListener(listener);
		
		removeAgente= new JButton("Eliminar Agente");
		removeAgente.addActionListener(listener);
		
		removeCliente= new JButton("Eliminar Cliente");
		removeCliente.addActionListener(listener);
		
		oeste.add(crud);
		oeste.add(addAgente);
		oeste.add(addCliente);
		oeste.add(removeAgente);
		oeste.add(removeCliente);
		oeste.add(mostrar);
		oeste.add(mostrarAgentes);
		oeste.add(mostrarClientes);
		add(oeste,BorderLayout.WEST);
		
		
		mesa = new JTextArea();
		mesa.setEditable(false);
		mesa.setLineWrap(true);
		mesa.setWrapStyleWord(true);
		scroll= new JScrollPane(mesa);
		//centro.add(iteraciones);
		centro.add(scroll);
		add(centro,BorderLayout.CENTER);
		
	}
	
	public static void main(String[] args) {
		Interfaz interfaz= new Interfaz();
		interfaz.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	private class Listener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
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
			
			if(e.getSource()== mostrarAgentes) {
				mesa.setText(miAgencia.showAgentes());
			}
			if(e.getSource()== mostrarClientes) {
				mesa.setText(miAgencia.showClientes());
			}
		}
	}
}
