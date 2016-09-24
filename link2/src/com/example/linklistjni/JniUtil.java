package com.example.linklistjni;

public class JniUtil {
	static{
		System.loadLibrary("jnitest");
		System.loadLibrary("linklist");
		
	}
	public native void test();
	/**
	 * 
	 * @return 返回SeqList int 类型
	 */
	public native int  create(int capacity);
	
	public native void destory(int seqList);
	//测试
	public native void insert(Teacher t);
	
	public native void insertToSeq(Teacher t);
	
	public native void testSo(String name,String password);
	
}
