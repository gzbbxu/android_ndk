package com.example.socket_pool;

public class JniUtil {
	static{
		System.loadLibrary("sockettest");
	}
	public native void start();
}
