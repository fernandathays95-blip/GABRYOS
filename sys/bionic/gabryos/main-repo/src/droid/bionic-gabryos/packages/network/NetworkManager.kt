package com.gabryos.packages.network

import java.net.InetAddress

object NetworkManager {

    fun showStatus() {
        println("===== NETWORK STATUS =====")
        println("Pingando google.com...")
        try {
            val addr = InetAddress.getByName("google.com")
            if (addr.isReachable(2000)) println("Conectado: google.com alcançável")
            else println("Erro: google.com não alcançável")
        } catch (e: Exception) {
            println("Falha de rede: ${e.message}")
        }
    }

    fun testConnection(host: String) {
        println("Testando conexão com $host...")
        try {
            val addr = InetAddress.getByName(host)
            println(if (addr.isReachable(3000)) "Host alcançável" else "Host inacessível")
        } catch (e: Exception) {
            println("Erro ao testar host: ${e.message}")
        }
    }
}
