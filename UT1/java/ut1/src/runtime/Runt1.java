package runtime;

import java.io.*;

public class Runt1 {
	
	public static void main(String[] args) {
		Runtime r = Runtime.getRuntime();
		String comando = "ping -c 4 www.educa.madrid.org";
		
		try {
			 Process p = r.exec(comando); //La salida del comando no va a la terminal

			 InputStream is = p.getInputStream();

			 //La salida del comando no va a la terminal sino al programa java
			 // Si queremos leer la salida, es decir mostrar devuelve el método exec
			 // debemos usar el objeto Process y su método getInputStream que nos
			 // permite leer la salida
			 BufferedReader br = new BufferedReader(new InputStreamReader(is));

			 String linea;
			 while ((linea=br.readLine())!=null)
			 System.out.println(linea);
			 br.close();

			} catch (Exception e) {
			System.out.println("Error en: "+comando);
			e.printStackTrace();
			}
	}

}
