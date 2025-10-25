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
import com.gabryos.ui.theme.GABRYOSTheme
import com.gabryos.packages.* // importa todos os apps

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
    val apps = remember { AppRegistry.getApps() }

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
        // Aqui você pode colocar um ícone padrão ou personalizado por app
        Image(
            painter = painterResource(id = android.R.drawable.sym_def_app_icon),
            contentDescription = "Ícone do app",
            modifier = Modifier.size(48.dp)
        )
        Spacer(modifier = Modifier.width(16.dp))
        Text(text = appName, fontSize = 20.sp, color = Color.White)
    }
}

// Classe que registra os apps
object AppRegistry {
    fun getApps(): List<AppInfo> {
        return listOf(
            AppInfo("App1") { App1.launchApp() },
            AppInfo("App2") { App2.launchApp() }
            // adicione todos os apps de packages aqui
        )
    }
}

// Classe para cada app
data class AppInfo(val name: String, val launch: () -> Unit)
