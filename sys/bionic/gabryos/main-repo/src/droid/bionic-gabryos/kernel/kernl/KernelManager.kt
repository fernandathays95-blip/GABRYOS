// sys/bionic/gabryos/main-repo/src/droid/bionic-gabryos/kernel/kernl/KernelManager.kt
package com.gabryos.kernel

/**
 * KernelManager - wrapper Kotlin para funções nativas do kernl
 * Carrega a lib nativa "gabryskernl" (nome de exemplo)
 */
object KernelManager {
    init {
        System.loadLibrary("gabryskernl") // libgabryskernl.so
    }

    external fun nativeInit()
    external fun nativeGetInfo(): String
    external fun nativeTick(seconds: Int)
    external fun nativeRegisterDriver(name: String)
    external fun nativeLoadDrivers()
    external fun nativeListDrivers(): Array<String>

    // wrappers Kotlin-friendly
    fun initKernel() {
        nativeInit()
    }

    fun getInfo(): String {
        return nativeGetInfo()
    }

    fun tick(seconds: Int = 1) {
        nativeTick(seconds)
    }

    fun registerDriver(name: String) {
        nativeRegisterDriver(name)
    }

    fun loadDrivers() {
        nativeLoadDrivers()
    }

    fun listDrivers(): List<String> {
        return nativeListDrivers().toList()
    }
}
