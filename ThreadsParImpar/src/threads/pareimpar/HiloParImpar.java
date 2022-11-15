package threads.pareimpar;

/*Crear una clase llamada HiloParImpar que implemente Runnable y tenga de atributo tipo de tal forma que:
Si el tipo es 1, mostrara los números pares del 1 al 100
Si el tipo es 2, mostrara los números impares del 101 al 200
La clase principal HiloParImparEjecutar creará 2 hilos. La salida del programa será:
HILO xx generando número par 2
HILO yy generando número impar 101
HILO yy generando número par 103
HILO xx generando número par 4*/

public class HiloParImpar implements Runnable{

	private int tipo;
	private static int valor = 1;
	
	public HiloParImpar() {
		this.tipo = valor++;
	}
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		switch(tipo) {
			case 1:
				for (int i = 2; i <= 100; i+=2) {
					System.out.println("HILO "+ Thread.currentThread().getId() + " generando numero par " + i);
				}
				break;
			case 2:
				for (int i = 101; i <= 200; i+=2) {
					System.out.println("HILO "+ Thread.currentThread().getId() + " generando numero par " + i);
				}
				break;
			default:
				System.out.println("No hay mas valores");
		}
			
		
	}

	
	
}
