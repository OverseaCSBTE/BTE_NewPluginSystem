#include "shared\Main.h"

void LogSystem::PrintToConsole(const char* fmt, ...)
{
	va_list va;
	char buf[MaxMsgLen];
	unsigned int len;

	va_start(va, fmt);
	vsnprintf(buf, sizeof(buf), fmt, va);
	va_end(va);
	len = strlen(buf);
	if (len < sizeof(buf) - 2)
		strcat(buf, "\n");
	else
		buf[len - 1] = '\n';

	ServerPrint(buf);
}

void LogSystem::Error(const char* fmt, ...)
{
	va_list ap;
	char buf[MaxMsgLen];

	va_start(ap, fmt);
	vsnprintf(buf, sizeof(buf), fmt, ap);
	va_end(ap);

	MessageBox(NULL, buf, "Error", 0);
}