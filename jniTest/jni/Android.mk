LOCAL_PATH := $(call my-dir)  


include $(CLEAR_VARS)
LOCAL_MODULE := libcurl
LOCAL_SRC_FILES := libcurl.a
include $(PREBUILT_STATIC_LIBRARY)


include $(CLEAR_VARS)  
  
LOCAL_MODULE    := jnitest  
LOCAL_SRC_FILES := jnitest.cpp  cJSON.c
LOCAL_LDLIBS :=-llog -lz -lm
LOCAL_STATIC_LIBRARIES := libcurl
include $(BUILD_SHARED_LIBRARY)