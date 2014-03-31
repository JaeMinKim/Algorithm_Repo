package com.lge.jjaem.rect.process;

import java.awt.Point;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;

import com.lge.jjaem.rect.model.RectModel;
import com.lge.jjaem.rect.util.IOManagerUtil;

public class RectProcess {
	/*
	 * member val
	 */
	private	HashMap<Point, Integer>	mPointsMap;
	private	List<Point>				mTotalPointsList;
	private	String					mInputFilePath;
	private	int						mInputRectCnt;
	private	List<String>			mInputFileDataStringList;
	private	int						mMaxRectArea;
	
		
	/*
	 * constructor
	 */
	public RectProcess(String inputFilePath) {
		// TODO Auto-generated constructor stub
		this.mPointsMap = new HashMap<Point, Integer>();
		this.mTotalPointsList = new ArrayList<Point>();
		this.mInputFilePath = inputFilePath;
		this.mInputRectCnt = 0;
		this.mInputFileDataStringList = null;
		this.mMaxRectArea = 0;
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
		
		/*
		 * get
		 */
		if (inputFileDataListItor.hasNext())
			this.mInputRectCnt = Integer.parseInt(inputFileDataListItor.next());
		
		/*
		 *  make rect data
		 */
		while(inputFileDataListItor.hasNext()){
			String inputString = inputFileDataListItor.next();
			String tokenInputArray[] = inputString.split(" ");
			
			RectModel rect = new RectModel(new Point(Integer.parseInt(tokenInputArray[0]), Integer.parseInt(tokenInputArray[1])),
					new Point(Integer.parseInt(tokenInputArray[2]), Integer.parseInt(tokenInputArray[3])));
			
			this.mMaxRectArea = (this.mMaxRectArea < rect.getRectAaea()) ? rect.getRectAaea() : this.mMaxRectArea;
			
			Iterator<Point> pointsItor = rect.getRectPointList().iterator();
			while(pointsItor.hasNext()){
				Point tmpPoint = pointsItor.next();
				
				if (this.mPointsMap.containsKey(tmpPoint)){
					int tmpCnt = this.mPointsMap.get(tmpPoint);
					this.mPointsMap.put(tmpPoint, (tmpCnt+ 1));
				}
				else if (!this.mPointsMap.containsKey(pointsItor.next())){
					this.mPointsMap.put(tmpPoint, 1);
				}
			}
			
			pointsItor = rect.getEdgePointList().iterator();
			while(pointsItor.hasNext()){
				Point tmpPoint = pointsItor.next();
				
				int tmpCnt = this.mPointsMap.get(tmpPoint);
				this.mPointsMap.put(tmpPoint, (tmpCnt+ 1));
			}
		}
		
	}
	
	
	public boolean isRect(Point p1, Point p2, Point p3, Point p4){
		return false;
	}
	
}
