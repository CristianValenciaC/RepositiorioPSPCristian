package processbuilder;

import java.io.File;

public class Build1 {

	public static void main(String[] args) {
		String cmd[] = {"ping", "-c", "4", "www.educa.madrid.org"};
		try {
		ProcessBuilder pb = new ProcessBuilder(cmd);
		//redirección de la salida a un fichero de nombre output.txt
		pb.redirectOutput(new File("outputBuild1.txt"));
		
		pb.start();
		
		} catch(Exception ex) {
		ex.printStackTrace();
		}
	}
	
}
