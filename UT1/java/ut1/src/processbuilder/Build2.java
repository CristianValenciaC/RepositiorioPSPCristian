package processbuilder;

import java.io.File;

public class Build2 {

	public static void main(String[] args) {
		String cmd[] = {"cal", "2003", "-m", "8"};
		try {
		ProcessBuilder pb = new ProcessBuilder(cmd);
		//redirección de la salida a un fichero de nombre output.txt
		pb.redirectOutput(new File("outputBuild2.txt"));
		
		pb.start();
		
		} catch(Exception ex) {
		ex.printStackTrace();
		}
	}
	
}
