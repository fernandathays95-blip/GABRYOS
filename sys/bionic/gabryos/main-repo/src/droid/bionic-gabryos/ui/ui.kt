package com.gabryos.ui

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.Image
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import java.io.File

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            GABRYOSTheme {
                Surface(modifier = Modifier.fillMaxSize(), color = MaterialTheme.colorScheme.background) {
                    LauncherScreen()
                }
            }
        }
    }
}

@Composable
fun LauncherScreen() {
    val apps = remember { loadApps() }

    Column(modifier = Modifier.fillMaxSize()) {
        Text(
            text = "GABRYOS - Aplicativos",
            fontSize = 24.sp,
            color = Color.White,
            modifier = Modifier.padding(16.dp)
        )

        LazyColumn(modifier = Modifier.fillMaxSize()) {
            items(apps) { app ->
                AppItem(appName = app.name, onClick = { app.launch() })
            }
        }
    }
}

@Composable
fun AppItem(appName: String, onClick: () -> Unit) {
    Row(
        modifier = Modifier
            .fillMaxWidth()
            .clickable { onClick() }
            .padding(16.dp),
        verticalAlignment = Alignment.CenterVertically
    ) {
        Image(
            painter = painterResource(id = android.R.drawable.sym_def_app_icon),
            contentDescription = "Ícone do app",
            modifier = Modifier.size(48.dp)
        )
        Spacer(modifier = Modifier.width(16.dp))
        Text(text = appName, fontSize = 20.sp, color = Color.White)
    }
}

// Classe que representa cada app
data class AppInfo(val name: String, val launch: () -> Unit)

// Função que varre a pasta packages e cria os AppInfo
fun loadApps(): List<AppInfo> {
    val appsDir = File("/data/data/com.gabryos/files/packages") // caminho interno do Android
    if (!appsDir.exists() || !appsDir.isDirectory) return emptyList()

    return appsDir.listFiles { file -> file.extension == "kt" }?.map { file ->
        AppInfo(
            name = file.nameWithoutExtension,
            launch = { launchApp(file.nameWithoutExtension) }
        )
    } ?: emptyList()
}

// Função que simula o lançamento do app
fun launchApp(appName: String) {
    println("🚀 Lançando app: $appName")
    // Aqui você integraria a execução real do app
}
