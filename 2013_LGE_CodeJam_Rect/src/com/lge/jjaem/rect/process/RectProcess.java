package com.lge.jjaem.rect.process;

import java.awt.Point;
import java.util.ArrayList;
import java.util.List;

public class RectProcess {
	/*
	 * member val
	 */
	private	int			mPointsMap[][];
	private	List<Point>	mTotalPointsList;
	private	String		mInputFilePath;
	
		
	/*
	 * constructor
	 */
	public RectProcess(String inputFilePath) {
		// TODO Auto-generated constructor stub
		this.mInputFilePath = inputFilePath;
		this.mTotalPointsList = new ArrayList<Point>();
	}
	
	/*
	 * getter & setter
	 */

	/*
	 * member method
	 */
	public void readInputData(){
		
	}
	
	public boolean isRect(Point p1, Point p2, Point p3, Point p4){
		return false;
	}
	
}
