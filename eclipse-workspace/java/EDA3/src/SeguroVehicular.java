
public class SeguroVehicular extends Seguro {

	public SeguroVehicular(double _monto, int _cantPersonas) {
		super("Vehicular",_monto, _cantPersonas);
		// TODO Auto-generated constructor stub
		super.addServicio("Combustible");
		super.addServicio("Grua");
		super.addServicio("Mecanico");
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return super.toString();
	}
}
