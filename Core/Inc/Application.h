#pragma once

#include "main.h"
#include "stm32f1xx_hal.h"
#include "PushButton.h"
#include "UartLogger.h"

struct application {
	void(*init)(void);
	void(*loop)(void);
};

extern const struct application Application;
