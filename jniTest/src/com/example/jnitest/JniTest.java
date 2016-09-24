package com.example.jnitest;

public class JniTest {
	static{
		System.loadLibrary("jnitest");
	}
	public native int add(int a ,int b);
	
	public native boolean login(String name,String password);
}
