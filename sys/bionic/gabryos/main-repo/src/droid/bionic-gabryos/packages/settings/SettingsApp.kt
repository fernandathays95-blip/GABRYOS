package com.gabryos.packages.settings

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.background
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.gabryos.ui.GABRYOSTheme
import com.gabryos.packages.systeminfo.SystemInfo
import com.gabryos.packages.files.FileManager
import com.gabryos.packages.network.NetworkManager
import com.gabryos.packages.security.SecurityManager
import kotlin.random.Random

/**
 * SettingsApp - Aplicativo de configurações do GABRYOS
 * O app mostra várias opções de configuração do sistema e módulos
 */
class SettingsApp : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            GABRYOSTheme {
                Surface(modifier = Modifier.fillMaxSize(), color = MaterialTheme.colorScheme.background) {
                    SettingsScreen()
                }
            }
        }
    }
}

@Composable
fun SettingsScreen() {
    val options = remember { loadOptions() }

    Column(modifier = Modifier.fillMaxSize().background(Color.Black)) {
        Text(
            text = "Configurações do GABRYOS",
            fontSize = 24.sp,
            color = Color.White,
            modifier = Modifier.padding(16.dp)
        )

        LazyColumn(modifier = Modifier.fillMaxSize()) {
            items(options) { option ->
                SettingsItem(option.name, option.action)
            }
        }
    }
}

@Composable
fun SettingsItem(name: String, action: () -> Unit) {
    Row(
        modifier = Modifier
            .fillMaxWidth()
            .clickable { action() }
            .padding(16.dp),
        verticalAlignment = Alignment.CenterVertically
    ) {
        Text(text = name, fontSize = 20.sp, color = Color.Green)
    }
}

// Data class para cada opção de configuração
data class SettingsOption(val name: String, val action: () -> Unit)

// Função que carrega as opções de configurações
fun loadOptions(): List<SettingsOption> {
    return listOf(
        SettingsOption("Informações do Sistema") { SystemInfo.showInfo() },
        SettingsOption("Gerenciador de Arquivos") { FileManager.open() },
        SettingsOption("Rede e Internet") { NetworkManager.showStatus() },
        SettingsOption("Segurança e Permissões") { SecurityManager.checkPermissions() },
        SettingsOption("Ajustes Aleatórios") { randomSetting() }
    )
}

// Exemplo de função interna com várias linhas de código
fun randomSetting() {
    println("Executando configuração aleatória...")
    val values = List(10) { Random.nextInt(0, 100) }
    val sum = values.sum()
    val max = values.maxOrNull() ?: 0
    val min = values.minOrNull() ?: 0
    println("Valores: $values")
    println("Soma: $sum | Máximo: $max | Mínimo: $min")
}
