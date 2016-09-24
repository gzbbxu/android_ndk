package com.example.jnitest;

import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;


public class MainActivity extends ActionBarActivity {
	private Button btn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btn = (Button) findViewById(R.id.button1);
        btn.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				JniTest test = new JniTest();
				Log.d("zhouke", "start");
				//int result =test.add(3, 4);
				boolean flag= test.login("zhang3", "123456");
				Log.d("zhouke", "success:"+flag);
			}
		});
    }

    

 
}
