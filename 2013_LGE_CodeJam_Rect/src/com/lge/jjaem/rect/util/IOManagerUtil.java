package com.lge.jjaem.rect.util;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class IOManagerUtil {
	public static List<String> fileReadFromFileByLine(String filePath) throws IOException{
		List<String> fileLineStringList = new ArrayList<String>();
		BufferedReader in = new BufferedReader(new FileReader(filePath));
		String lineString;

		while ((lineString = in.readLine()) != null) {
			fileLineStringList.add(lineString);
		}
		in.close();
		
		return fileLineStringList;
	}
}
