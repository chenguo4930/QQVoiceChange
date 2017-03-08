package com.example.cheng.qqvoicechange;

import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import java.io.File;

public class MainActivity extends Activity {

    private String path;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "recoder.wav";
        File file = new File(path);
        Toast.makeText(this, "文件是否存在" + file.exists() + "path=" + path, Toast.LENGTH_LONG).show();
    }

    public void voice(View view) {
        switch (view.getId()) {
            case R.id.voice_old:
                Toast.makeText(this, "原声", Toast.LENGTH_SHORT).show();
                Log.e("tag","----------原生");
                EffectUtils.fix(path, EffectUtils.MODE_NORMAL);
                break;
            case R.id.voice_luoli:
                Log.e("tag","----------萝莉");
                Toast.makeText(this, "萝莉", Toast.LENGTH_SHORT).show();
                EffectUtils.fix(path, EffectUtils.MODE_LUOLI);

                break;
            case R.id.voice_dashu:
                Log.e("tag","---------大叔");
                Toast.makeText(this, "大叔", Toast.LENGTH_SHORT).show();
                EffectUtils.fix(path, EffectUtils.MODE_DASHU);
                break;
            case R.id.voice_kongling:
                Log.e("tag","----------空灵");
                Toast.makeText(this, "空灵", Toast.LENGTH_SHORT).show();
                EffectUtils.fix(path, EffectUtils.MODE_KONGLING);
                break;
            case R.id.voice_jingsong:
                Log.e("tag","----------惊悚");
                Toast.makeText(this, "惊悚", Toast.LENGTH_SHORT).show();
                EffectUtils.fix(path, EffectUtils.MODE_JINGSONG);
                break;
            case R.id.voice_gaoguai:
                Log.e("tag","----------搞怪");
                Toast.makeText(this, "搞怪", Toast.LENGTH_SHORT).show();
                EffectUtils.fix(path, EffectUtils.MODE_GAOGUAI);
                break;
            default:
        }
    }
}
