package com.jjaem.minbox.model;

public class ItemBox extends Box{
	/*
	 * member val
	 */
	private int mItemBoxId;
	private int mShape;

	
	/*
	 * construct
	 */
	public ItemBox(int itemId) {
		// TODO Auto-generated constructor stub
		this.mItemBoxId = itemId;
		this.mShape = 0;
	}

	public int getmShape() {
		return mShape;
	}

	
	/*
	 * getter & setter
	 */
	public void setmShape(int mShape) {
		this.mShape = mShape;
	}	
}
