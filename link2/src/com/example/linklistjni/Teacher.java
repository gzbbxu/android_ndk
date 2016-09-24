package com.example.linklistjni;

public class Teacher {
	public String name;
	public int age;
	public  int buf;
	public Teacher(String name, int age, int buf) {
		super();
		this.name = name;
		this.age = age;
		this.buf = buf;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public int getBuf() {
		return buf;
	}
	public void setBuf(int buf) {
		this.buf = buf;
	}
}
