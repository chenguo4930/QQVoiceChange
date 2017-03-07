#include <jni.h>
#include <string>
#include <fmod.hpp>
#include <unistd.h>

#define MODE_NORMAL  0
#define MODE_LUOLI 1
#define MODE_DASHU 2
#define MODE_JINGSONG 3
#define MODE_GAOGUAI 4
#define MODE_KONGLING 5

using namespace FMOD;

extern "C"
JNIEXPORT void JNICALL
Java_com_example_cheng_qqvoicechange_EffectUtils_fix(JNIEnv *env, jclass type_, jstring path_,
                                                     jint type) {
    System *system;
    Sound *sound;
    Channel *channel;
    DSP *dsp;
    bool isplayihng = true;
    //速率
    float frequency;

    System_Create(&system);
    system->init(32, FMOD_INIT_NORMAL, NULL);

    //C字符串
    //java string-> C char*
    const char *path_cstr = env->GetStringUTFChars(path_, NULL);
    system->createSound(path_cstr, FMOD_DEFAULT, NULL, &sound);

    try {
        switch (type) {
            case MODE_NORMAL:
                //播放，异步子线程
                system->playSound(sound, NULL, false, &channel);
                break;
            case MODE_LUOLI:
                //创建音效
                system->createDSPByPlugin(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
                //设置音调的值
                dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH, 2.5);

                system->playSound(sound, NULL, false, &channel);
                //添加音效
                channel->addDSP(0, dsp);
                break;
            case MODE_DASHU:
                //创建音效
                system->createDSPByPlugin(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
                //设置音调的值
                dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH, 0.8);

                system->playSound(sound, NULL, false, &channel);
                //添加音效
                channel->addDSP(0, dsp);
                break;
            case MODE_JINGSONG:
                //创建音效
                system->createDSPByPlugin(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
                //设置音调的值
                dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH, 2.5);

                system->playSound(sound, NULL, false, &channel);
                //添加音效
                channel->addDSP(0, dsp);
                break;
            case MODE_GAOGUAI:
                //创建音效
                system->createDSPByPlugin(FMOD_DSP_TYPE_NORMALIZE, &dsp);
                //设置音调的值
                system->playSound(sound, NULL, false, &channel);
                //添加音效
                channel->addDSP(0, dsp);
                channel->getFrequency(&frequency);
                frequency = frequency *1.6;
                channel->setFrequency(frequency);
                break;
            case MODE_KONGLING:
                //创建音效
                system->createDSPByPlugin(FMOD_DSP_TYPE_ECHO, &dsp);
                //设置音调的值
                dsp->setParameterFloat(FMOD_DSP_ECHO_DELAY, 300);
                dsp->setParameterFloat(FMOD_DSP_ECHO_FEEDBACK, 20);
                system->playSound(sound, NULL, false, &channel);
                //添加音效
                channel->addDSP(0, dsp);
                break;
        }
    } catch (...) {
        goto end;
    }

    //调用update才开始播放
    system->update();

    //检查是否播放完成
    while (isplayihng) {
        //当检测到播放完了，根据变量地址，给变量间接赋值
        channel->isPlaying(&isplayihng);
        sleep(1);
    }

    //释放
    end:
    system->close();
    system->release();

    env->ReleaseStringUTFChars(path_, path_cstr);

}

