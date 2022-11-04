package processbuilder;

import java.io.File;

public class Build3 {

	public static void main(String[] args) {
		String cmd[] = {"ps", "aux", "--width", "30", "--sort", "-rss", "|", "head"};
		try {
		ProcessBuilder pb = new ProcessBuilder(cmd);
		//redirección de la salida a un fichero de nombre output.txt
		pb.redirectOutput(new File("outputBuild3.txt"));
		
		pb.start();
		
		} catch(Exception ex) {
		ex.printStackTrace();
		}
	}
}
