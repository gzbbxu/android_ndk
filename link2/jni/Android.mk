LOCAL_PATH := $(call my-dir)  


include $(CLEAR_VARS)

LOCAL_MODULE := jnitest  
LOCAL_SRC_FILES := libjnitest.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include		
include $(PREBUILT_SHARED_LIBRARY)  

include $(CLEAR_VARS)
LOCAL_ALLOW_UNDEFINED_SYMBOLS := true
LOCAL_MODULE    := linklist
LOCAL_SRC_FILES := testmain.c seqlist.c 
LOCAL_SHARED_LIBRARIES := libjnitest
LOCAL_LDLIBS := -llog 
include $(BUILD_SHARED_LIBRARY)