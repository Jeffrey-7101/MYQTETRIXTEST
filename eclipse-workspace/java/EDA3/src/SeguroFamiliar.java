
public class SeguroFamiliar extends Seguro {

	public SeguroFamiliar(double _monto, int _cantPersonas) {
		super("Familiar",_monto, _cantPersonas);
		// TODO Auto-generated constructor stub
		super.addServicio("Ambulancia");
		super.addServicio("Medico de Cabecera");
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return super.toString();
	}
}
