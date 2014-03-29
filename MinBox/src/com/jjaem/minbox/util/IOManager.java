package com.jjaem.minbox.util;

import java.awt.Point;
import java.util.Iterator;

import com.jjaem.minbox.model.ItemBox;
import com.jjaem.minbox.model.PackingBox;
import com.jjaem.minbox.model.PackingData;

public class IOManager {
	private static PackingData packingData = new PackingData();
	
	public static PackingData getPackingData(){
		// set defalut data
		packingData.setmBoxCnt(2);
		
		ItemBox itemBox1 = new ItemBox(1);
		ItemBox itemBox2 = new ItemBox(2);
		
		itemBox1.setmWidth(2);
		itemBox1.setmHeight(4);
		itemBox2.setmWidth(5);
		itemBox2.setmHeight(2);
		
		packingData.addmItemBoxList(itemBox1, itemBox2);
		
		return packingData;
	}
	
	public static void printPackingBoxData(PackingBox resultPackingBox){
		System.out.println("OUTPUT = ");
		System.out.println(resultPackingBox.getmWidth()+ " "+ resultPackingBox.getmHeight());
		
		Iterator<ItemBox> itemBoxIter = resultPackingBox.getmItemBoxList().iterator();
		
		while(itemBoxIter.hasNext()){
			ItemBox itemBox = itemBoxIter.next();
			
			System.out.println(itemBox.getmStartPoint().getX()+ " "+ itemBox.getmStartPoint().getY()+ " "+ itemBox.getmShape());
		}
	}

}
