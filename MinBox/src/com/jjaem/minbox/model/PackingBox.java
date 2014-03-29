package com.jjaem.minbox.model;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class PackingBox extends Box{
	/*
	 * member val
	 */
	private List<ItemBox> mItemBoxList;
	/*
	 * construct
	 */
	public PackingBox() {
		// TODO Auto-generated constructor stub
		this.mItemBoxList = new ArrayList<ItemBox>();
	}

	
	/*
	 * setter & setter
	 */
	public List<ItemBox> getmItemBoxList() {
		return mItemBoxList;
	}
	public void addmItemBoxList(ItemBox ...itemBoxs) {
		Iterator<ItemBox> itemBoxIter = Arrays.asList(itemBoxs).iterator();
		
		while(itemBoxIter.hasNext()){
			this.mItemBoxList.add(itemBoxIter.next());
		}
	}
}
