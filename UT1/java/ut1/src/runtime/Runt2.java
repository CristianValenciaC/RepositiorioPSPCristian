package runtime;

import java.io.*;

public class Runt2 {
	
	public static void main(String[] args) {
		Runtime r2 = Runtime.getRuntime();
		String comando = "cal 2003 -m 8";
		
		try {
			Process p = r2.exec(comando);
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
