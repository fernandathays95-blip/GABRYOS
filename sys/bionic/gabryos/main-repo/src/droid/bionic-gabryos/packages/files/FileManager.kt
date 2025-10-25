package com.gabryos.packages.files

import java.io.File

object FileManager {

    fun open() {
        println("===== FILE MANAGER =====")
        val root = File("/data/data/com.gabryos/files")
        listFiles(root)
    }

    private fun listFiles(dir: File, indent: String = "") {
        if (!dir.exists() || !dir.isDirectory) return
        dir.listFiles()?.forEach { file ->
            println("$indent- ${file.name} (${if (file.isDirectory) "DIR" else "FILE"})")
            if (file.isDirectory) listFiles(file, indent + "  ")
        }
    }

    fun createFile(name: String, content: String) {
        val file = File("/data/data/com.gabryos/files/$name")
        file.writeText(content)
        println("Arquivo $name criado com sucesso!")
    }

    fun deleteFile(name: String) {
        val file = File("/data/data/com.gabryos/files/$name")
        if (file.exists() && file.delete()) println("Arquivo $name deletado.")
        else println("Falha ao deletar $name.")
    }
}
