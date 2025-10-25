// sys/bionic/gabryos/main-repo/src/droid/bionic-gabryos/kernel/kernl/kernl_jni.cc
#include <jni.h>
#include <string>
#include "kernl_boot.h"
#include "kernl_log.h"
#include <vector>

using namespace kernl_log;

extern "C" {

// JNI: void nativeInit()
JNIEXPORT void JNICALL
Java_com_gabryos_kernel_KernelManager_nativeInit(JNIEnv* env, jobject thiz) {
    kernl_init();
    kernl_memory_init();
}

// JNI: String nativeGetInfo()
JNIEXPORT jstring JNICALL
Java_com_gabryos_kernel_KernelManager_nativeGetInfo(JNIEnv* env, jobject thiz) {
    const KernelInfo* info = kernl_get_info();
    char buf[256];
    snprintf(buf, sizeof(buf), "%s v%u.%u uptime=%llu",
             info->name, info->versionMajor, info->versionMinor, (unsigned long long)info->uptimeSeconds);
    return env->NewStringUTF(buf);
}

// JNI: void nativeTick(int seconds)
JNIEXPORT void JNICALL
Java_com_gabryos_kernel_KernelManager_nativeTick(JNIEnv* env, jobject thiz, jint seconds) {
    kernl_tick((uint32_t)seconds);
}

// JNI helper: register a fake driver
JNIEXPORT void JNICALL
Java_com_gabryos_kernel_KernelManager_nativeRegisterDriver(JNIEnv* env, jobject thiz, jstring jname) {
    const char* name = env->GetStringUTFChars(jname, nullptr);
    kernl_register_driver(name);
    env->ReleaseStringUTFChars(jname, name);
}

// JNI: load drivers
JNIEXPORT void JNICALL
Java_com_gabryos_kernel_KernelManager_nativeLoadDrivers(JNIEnv* env, jobject thiz) {
    kernl_load_drivers();
}

// JNI: list drivers -> returns Java String[]
JNIEXPORT jobjectArray JNICALL
Java_com_gabryos_kernel_KernelManager_nativeListDrivers(JNIEnv* env, jobject thiz) {
    const int MAX = 32;
    char out[MAX][64];
    int count = kernl_list_drivers(out, MAX);
    jclass strClass = env->FindClass("java/lang/String");
    jobjectArray arr = env->NewObjectArray(count, strClass, nullptr);
    for (int i = 0; i < count; ++i) {
        env->SetObjectArrayElement(arr, i, env->NewStringUTF(out[i]));
    }
    return arr;
}

} // extern "C"
