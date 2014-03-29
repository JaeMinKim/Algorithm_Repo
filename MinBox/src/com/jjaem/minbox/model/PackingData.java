package com.jjaem.minbox.model;

import java.awt.Point;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class PackingData {
	/*
	 * member val
	 */
	private int mBoxCnt;
	private List<ItemBox> mItemBoxList;

	
	/*
	 * construct
	 */
	public PackingData() {
		// TODO Auto-generated constructor stub
		this.mBoxCnt = 0;
		this.mItemBoxList = new ArrayList<ItemBox>();
	}

	
	/*
	 * getter & setter
	 */
	public int getmBoxCnt() {
		return mBoxCnt;
	}
	
	public void setmBoxCnt(int mBoxCnt) {
		this.mBoxCnt = mBoxCnt;
	}
	
	public List<ItemBox> getmItemBoxList() {
		return mItemBoxList;
	}
	
	public void addmItemBoxList(ItemBox ...itemBoxs) {
		Iterator<ItemBox> itemBoxListIter = Arrays.asList(itemBoxs).iterator();
		
		while(itemBoxListIter.hasNext()){
			this.mItemBoxList.add(itemBoxListIter.next());
		}
	}
}
