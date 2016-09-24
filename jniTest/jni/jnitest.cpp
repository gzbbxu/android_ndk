#include "com_example_jnitest_JniTest.h"
#include <android/log.h>
#include <string.h>
#include "curl/curl.h"
#include <stdio.h>
typedef struct curl_resp_data
{
    char buf[4096];
    int curlen;
    curl_resp_data(){
        curlen = 0;
    }
}curl_resp_data;

char* jstr2cstr(JNIEnv* env, jstring str)
{
    // get String class
    // get String Class Method "getBytes"
    // call method "getBytes"
    // calc bytes length
    // alloc memory
    // memcpy
    // return cstr

     char* pStr = NULL;

     jclass strClass = env->FindClass("java/lang/String");
     jstring encode = env->NewStringUTF("utf-8");
     jmethodID mid = env->GetMethodID(strClass, "getBytes", "(Ljava/lang/String;)[B");
     jbyteArray data = (jbyteArray)env->CallObjectMethod(str, mid, encode);
     jsize len = env->GetArrayLength(data);
     jbyte* buf = env->GetByteArrayElements(data, JNI_FALSE);

     if(len == 0)
        return NULL;

     pStr = new char[len+1];
     pStr[len] = 0;

     memcpy(pStr, buf, len);

     env->ReleaseByteArrayElements(data, buf, 0);
     return pStr;
}
size_t curl_callback(char* ptr, size_t n, size_t m, void* userdata)
{
     __android_log_print(ANDROID_LOG_ERROR, "jnitag", "回调被执行\n");
    curl_resp_data* data = (curl_resp_data*)userdata;

    int c = n * m;
    memcpy(data->buf+data->curlen, ptr, c);
    data->curlen += c;

    return c;
}
bool Login(const char *pUsername,const char * pPassword){
    __android_log_print(ANDROID_LOG_ERROR, "jnitag", "Login:%s,%s\n",pUsername,pPassword);
    CURLcode ret;
    curl_resp_data data;
    CURL* curl= curl_easy_init();
    curl_easy_setopt(curl,CURLOPT_URL,"http://www.weather.com.cn/data/sk/101010100.html");
//    curl_easy_setopt(curl, CURLOPT_POST, 1);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_callback);
       curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        __android_log_print(ANDROID_LOG_ERROR, "jnitag", "执行网络访问前\n");
    ret= curl_easy_perform(curl);
      __android_log_print(ANDROID_LOG_ERROR, "jnitag", "执行网络访问后\n");
      __android_log_print(ANDROID_LOG_ERROR, "jnitag", "result:%s\n",data.buf);
    if(ret !=CURLE_OK)
    {
        __android_log_print(ANDROID_LOG_ERROR, "jnitag", "Login:%d\n",(int)ret);
    }

    //封装json 还没有完成
    cJSON* root = cJSON_CreateObject();
    root = cJSON_Parse(data.buf);

    curl_easy_cleanup(curl);
	return true;
}

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNICALL Java_com_example_jnitest_JniTest_add
  (JNIEnv * env, jobject obj, jint x, jint y){
	int result = x + y;
	return result;
}

JNIEXPORT jboolean JNICALL Java_com_example_jnitest_JniTest_login
  (JNIEnv * env, jobject obj, jstring name, jstring password)
{
	const char * pUsername = jstr2cstr(env,name);
	const char * pPassword = jstr2cstr(env,password);
	bool ret = Login(pUsername,pPassword);
	delete []pUsername;
	delete [] pPassword;
	return ret;

}
#ifdef __cplusplus
}
#endif
