# Sentry API - GABRYOS

Esta pasta contém a implementação básica da API Sentry para captura de erros no GABRYOS.

## Estrutura
- `SentryEvent` : representa um evento de log ou erro.
- `level` : nível do evento ("INFO", "WARN", "ERROR").

## Funções
- `sentry_init(dsn)` : inicializa a API com o DSN do Sentry.
- `sentry_capture_event(message, level, file, line)` : captura e loga um evento.
- `sentry_shutdown()` : encerra a API e libera recursos.

> Observação: atualmente os eventos são exibidos no console, mas podem ser enviados para um servidor Sentry real usando HTTP.
