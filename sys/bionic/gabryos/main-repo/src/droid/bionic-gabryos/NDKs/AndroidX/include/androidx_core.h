#ifndef ANDROIDX_CORE_H
#define ANDROIDX_CORE_H

#ifdef __cplusplus
extern "C" {
#endif

void androidx_initCore();
const char* androidx_getSystemProperty(const char* key);

#ifdef __cplusplus
}
#endif

#endif // ANDROIDX_CORE_H
