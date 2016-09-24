package com.example.linklistjni;

import com.example.link2.R;

import android.support.v7.app.ActionBarActivity;
import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

public class MainActivity extends Activity {

	JniUtil util  = new JniUtil();
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}
	
	public void click(View view){
		Teacher t1 = new Teacher("zhang3", 12, 100);
		Teacher t2 = new Teacher("lisi", 22, 100);
		Teacher t3 = new Teacher("wangwu", 32, 100);
		util.testSo("zhang3", "lisi");
		
	//	util.test();
		/*int seqList= util.create(10);
		//util.insert(t1);
		Log.i("zhouke", "t1:"+t1);
		
		util.insertToSeq(t1);
		util.destory(seqList);*/
		//int address =(int) t1;
		//Log.i("zhouke", t1);
	}

}
