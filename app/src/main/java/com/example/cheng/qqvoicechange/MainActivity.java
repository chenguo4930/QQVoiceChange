package com.example.cheng.qqvoicechange;

import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.View;

import org.fmod.FMOD;

import java.io.File;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        FMOD.init(this);

        setContentView(R.layout.activity_main);
    }

    public void mFix(View btn) {
        String path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "jason.wav";
        EffectUtils.fix(path, EffectUtils.MODE_NORMAL);
        Log.d("jason", "mFix");
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        FMOD.close();
    }
}
