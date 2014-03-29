package com.jjaem.minbox.model;

import java.awt.Point;

public class Box {
	/*
	 * member val
	 */
	private int mWidth;
	private int mHeight;
	private Point mStartPoint;

	/*
	 * construct
	 */
	public Box() {
		// TODO Auto-generated constructor stub
		this.mWidth = 0;
		this.mHeight = 0;
		this.mStartPoint = new Point(0, 0);
	}
	
	/*
	 * getter & setter
	 */
	public int getmWidth() {
		return mWidth;
	}
	public void setmWidth(int mWidth) {
		this.mWidth = mWidth;
	}
	public int getmHeight() {
		return mHeight;
	}
	public void setmHeight(int mHeight) {
		this.mHeight = mHeight;
	}
	public Point getmStartPoint() {
		return mStartPoint;
	}
	public void setmStartPoint(Point mStartPoint) {
		this.mStartPoint = mStartPoint;
	}
}
