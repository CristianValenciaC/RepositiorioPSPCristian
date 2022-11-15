package threads.pareimpar;

public class HiloParImparEjecutar {

	public static void main(String[] args) {
		HiloParImpar h1 = new HiloParImpar();
		Thread t1 = new Thread(h1);
		
		HiloParImpar h2 = new HiloParImpar();
		Thread t2 = new Thread(h2);
		
		t2.start();
		t1.start();
	}
	
}
