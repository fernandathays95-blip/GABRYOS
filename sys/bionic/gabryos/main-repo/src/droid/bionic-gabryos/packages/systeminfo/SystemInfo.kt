package com.gabryos.packages.systeminfo

import android.os.Build
import android.util.Log

object SystemInfo {

    fun showInfo() {
        println("===== GABRYOS SYSTEM INFO =====")
        println("Marca: ${Build.BRAND}")
        println("Modelo: ${Build.MODEL}")
        println("SDK: ${Build.VERSION.SDK_INT}")
        println("Versão: ${Build.VERSION.RELEASE}")
        println("CPU ABI: ${Build.SUPPORTED_ABIS.joinToString()}")
        println("Memória total: ${getTotalMemory()} MB")
        println("Espaço livre: ${getFreeMemory()} MB")
    }

    private fun getTotalMemory(): Long {
        return Runtime.getRuntime().totalMemory() / (1024 * 1024)
    }

    private fun getFreeMemory(): Long {
        return Runtime.getRuntime().freeMemory() / (1024 * 1024)
    }

    fun logSystemStatus() {
        Log.d("SystemInfo", "CPU: ${Build.HARDWARE}, Board: ${Build.BOARD}")
    }
}
