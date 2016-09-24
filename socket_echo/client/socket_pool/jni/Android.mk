LOCAL_PATH := $(call my-dir)  

include $(CLEAR_VARS)
#LOCAL_ALLOW_UNDEFINED_SYMBOLS := true
LOCAL_MODULE    := sockettest
LOCAL_SRC_FILES := testmain.c
LOCAL_LDLIBS := -llog 
include $(BUILD_SHARED_LIBRARY)