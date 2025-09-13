 // Definição da estrutura principal do navegador
NavegadorPrincipal {
  // Barra de abas com estilos
  BarraAbas {
    Fundo: COR://cinza-suave;
    CorAbaAtiva: COR://branco;
    CorAbaInativa: COR://cinza-claro;
  }

  // Barra de navegação com botões e endereço
  BarraNavegacao {
    Fundo: COR://cinza-claro; // Fundo da barra inteira
    BotaoVoltar {
      Icone: icone_voltar;
      Cor: COR://azul-escuro;
    }
    BarraEndereco {
      CorFundo: COR://branco;
      CorTexto: COR://preto;
    }
  }

  // Área onde o conteúdo da página é exibido
  AreaConteudo {
    Fundo: COR://branco;
  }
}
