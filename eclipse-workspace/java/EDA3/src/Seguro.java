import java.util.ArrayList;

public class Seguro {
		public String nombre;
		public double monto=0;
		public int cantPersonas=0;
		public ArrayList<String> serviciosAdicionales= new ArrayList<String>();
		
		public Seguro(String _nombre,double _monto, int _cantPersonas) {
			this.nombre=_nombre;
			this.monto=_monto;
			this.cantPersonas=_cantPersonas;
		}
		
		public String getNombre() {
			return this.nombre;
		}
		
		public void setMonto(double _monto) {
			this.monto=_monto;
		}
		public void setCantPersonas(int _cantPersonas) {
			this.cantPersonas=_cantPersonas;
		}
		public void addServicio(String _servicio) {
			this.serviciosAdicionales.add(_servicio);
		}
		
		public double getMonto() {
			return this.monto;
		}
		public int getCantPersonas() {
			return this.cantPersonas;
		}
		public ArrayList<String> getServAdi() {
			return this.serviciosAdicionales;
		}
		
		public String toString() {
			String str="SEGURO "+this.nombre+" Monto mensual: "+this.monto+", cubre a "+this.cantPersonas+" persona(s) \n Servicios: \n";
			for(String i: serviciosAdicionales)
				str+=i+" \n";
			return str;
		}
	
}
