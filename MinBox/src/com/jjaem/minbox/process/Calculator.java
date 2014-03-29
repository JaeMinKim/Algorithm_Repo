package com.jjaem.minbox.process;

import com.jjaem.minbox.model.PackingBox;
import com.jjaem.minbox.model.PackingData;

public class Calculator {
	/*
	 * member val
	 */
	private PackingData mOrgPackingData;
	private PackingBox mResultPackingBox;
	
	
	/*
	 * construct
	 */
	public Calculator() {
		// TODO Auto-generated constructor stub
	}
	 
	public Calculator(PackingData packingData){
		this.mOrgPackingData = packingData;
	}

	
	
	/*
	 * getter & setter
	 */
	public PackingData getmOrgPackingData() {
		return mOrgPackingData;
	}
	
	public void setmOrgPackingData(PackingData mOrgPackingData) {
		this.mOrgPackingData = mOrgPackingData;
	}
	
	public PackingBox getmResultPackingBox() {
		return mResultPackingBox;
	}
	
	public void setmResultPackingBox(PackingBox mResultPackingBox) {
		this.mResultPackingBox = mResultPackingBox;
	}
	
	
	
	/*
	 * member method
	 */
}
    