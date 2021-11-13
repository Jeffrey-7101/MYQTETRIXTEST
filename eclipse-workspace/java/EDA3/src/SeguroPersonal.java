
public class SeguroPersonal extends Seguro {
	

	public SeguroPersonal(double _monto, int _cantPersonas) {
		super("Personal",_monto, _cantPersonas);
		// TODO Auto-generated constructor stub
		super.addServicio("Ambulancia");
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return super.toString();
	}

}
