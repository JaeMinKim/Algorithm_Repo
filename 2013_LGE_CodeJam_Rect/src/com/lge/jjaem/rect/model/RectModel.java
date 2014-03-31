package com.lge.jjaem.rect.model;

import java.awt.Point;
import java.util.List;

public class RectModel {
	/*
	 * member val
	 */
	private	List<Point>	mRectPointList;
	private	List<Point>	mRectEdgePointList;
	private	int			mRectAaea;
	private	Point		mLeftDownPoint;
	private	Point		mRightUpPoint;
		
	/*
	 * constructor
	 */
	public RectModel(Point leftDownPoint, Point rightUpPoint){
		this.mLeftDownPoint = leftDownPoint;
		this.mRightUpPoint = rightUpPoint;
		
		this.calRectPoints();
	}
	
	/*
	 * getter & setter
	 */
	public List<Point> getRectPointList(){
		return null;
	}
	
	public List<Point> getEdgePointList(){
		return null;
	}
	
	public int getRectAaea(){
		return 0;
	}

	/*
	 * member method
	 */
	public void calRectPoints(){
		
	}
}
