package runtime;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;

public class Runt3 {

	public static void main(String[] args) {
		Runtime r3 = Runtime.getRuntime();
		String comando = "ps aux --width 30 --sort -rss | head";
		try {
			Process p = r3.exec(comando);
			InputStream is = p.getInputStream();
			BufferedReader br = new BufferedReader(new InputStreamReader(is));
	
			String linea;
			while ((linea=br.readLine())!=null)
			System.out.println(linea);
			
			br.close();
			
		}catch(Exception e) {
			e.printStackTrace();
		}
		
	}
	
}
