#include "com_example_linklistjni_JniUtil.h"
#include "com_example_jnitest_JniTest.h"
#include <android/log.h>
#include "seqlist.h"
typedef struct _Teacher{
	char name[64];
	int age;
	int buf;
}Teacher;
JNIEXPORT void JNICALL Java_com_example_linklistjni_JniUtil_testSo
  (JNIEnv * env, jobject obj, jstring name, jstring password){
	Java_com_example_jnitest_JniTest_login(env, obj, name,  password);
}
JNIEXPORT void JNICALL Java_com_example_linklistjni_JniUtil_test
  (JNIEnv * env, jobject obj){
	__android_log_print(ANDROID_LOG_ERROR, "jnitag", "test函数被调用\n");
	SeqList * seqList;
		int ret;
		int i;
		Teacher t1,t2,t3;
		t1.age =10;
		t2.age =20;
		t3.age =30;
		seqList =  SeqList_create(10);
		ret =  SeqList_Insert(seqList,&t1,0);
		ret =  SeqList_Insert(seqList,&t2,0);
		ret =  SeqList_Insert(seqList,&t3,0);
		__android_log_print(ANDROID_LOG_ERROR, "jnitag", "length = %d\n",SeqList_Length(seqList));
		//遍历循环
		for(i=0;i<SeqList_Length(seqList);i++){
			Teacher * tmp=(Teacher*) SeqList_Get(seqList,i);
			__android_log_print(ANDROID_LOG_ERROR, "jnitag", "age:%d\n",tmp->age);
		}
		SeqList_Destory(seqList);

		__android_log_print(ANDROID_LOG_ERROR, "jnitag", "test函数被调用完毕\n");
}
JNIEXPORT jint JNICALL Java_com_example_linklistjni_JniUtil_create
  (JNIEnv * env, jobject obj, jint capacity){
	SeqList * seqList;
	__android_log_print(ANDROID_LOG_ERROR, "jnitag", "create %d\n",capacity);
	seqList =  SeqList_create(capacity);
	if(seqList==NULL){
		return -1;
	}
	return (jint)seqList;
}
JNIEXPORT void JNICALL Java_com_example_linklistjni_JniUtil_destory
  (JNIEnv * env, jobject obj, jint seqList){
	SeqList_Destory((SeqList*)seqList);
	__android_log_print(ANDROID_LOG_ERROR, "jnitag", "销毁 \n");

}
/**
 * 插入
 */
JNIEXPORT void JNICALL Java_com_example_linklistjni_JniUtil_insert
  (JNIEnv * env, jobject obj, jobject teacher){
	__android_log_print(ANDROID_LOG_ERROR, "jnitag", "开始插入\n");
   jclass clazz;
   jfieldID fid;
   clazz= (*env)->GetObjectClass(env,teacher);
   if(0 == clazz){
	   __android_log_print(ANDROID_LOG_ERROR, "jnitag", "GetObjectClass error\n");
	   return ;
   }
   //(*GetFieldID)(JNIEnv*, jclass, const char*, const char*);
   ///fid = (*env) ->GetFieldID(env,clazz,"name",);
   //(*GetFieldID)(JNIEnv*, jclass, const char*, const char*);
   //fid = (*env)->GetFieldID(env,clazz,);
   fid = (*env)->GetFieldID(env,clazz,"name","Ljava/lang/String;");
   __android_log_print(ANDROID_LOG_ERROR, "jnitag", "insrt2 \n");

   (*env)->SetObjectField(env,teacher,fid,(*env)->NewStringUTF(env,"jniZhang3"));
   __android_log_print(ANDROID_LOG_ERROR, "jnitag", "insrt3 \n");
}
JNIEXPORT void JNICALL Java_com_example_linklistjni_JniUtil_insertToSeq
  (JNIEnv * env , jobject obj, jobject teacher){
	//__android_log_print(ANDROID_LOG_ERROR, "jnitag", "insertToSeq:%d\n",(void*)teacher);
}

