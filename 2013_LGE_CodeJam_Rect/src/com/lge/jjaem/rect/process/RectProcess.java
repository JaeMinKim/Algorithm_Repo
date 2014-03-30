package com.lge.jjaem.rect.process;

import java.awt.Point;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import com.lge.jjaem.rect.util.IOManagerUtil;

public class RectProcess {
	/*
	 * member val
	 */
	private	int				mPointsMap[][];
	private	List<Point>		mTotalPointsList;
	private	String			mInputFilePath;
	private	int				mInputRectCnt;
	private	List<String>	mInputFileDataStringList;
	
		
	/*
	 * constructor
	 */
	public RectProcess(String inputFilePath) {
		// TODO Auto-generated constructor stub
		this.mInputFilePath = inputFilePath;
		this.mTotalPointsList = new ArrayList<Point>();
		this.mInputFileDataStringList = null;
		this.mInputRectCnt = 0;
	}
	
	/*
	 * getter & setter
	 */

	/*
	 * member method
	 */
	public void readInputData(String inputFilePath){
		this.mInputFilePath = inputFilePath;
		this.readInputData();
	}

	public void readInputData(){
		try {
			this.mInputFileDataStringList = IOManagerUtil.fileReadFromFileByLine(this.mInputFilePath);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		if (this.mInputFileDataStringList == null)
			return;
		
		Iterator<String> inputFileDataListItor = this.mInputFileDataStringList.iterator();
		
	}
	
	
	public boolean isRect(Point p1, Point p2, Point p3, Point p4){
		return false;
	}
	
}
