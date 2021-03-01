#include "Application.h"

static void button_down_short_fn(void) { app_log_info("button down short"); }
static void button_down_long_fn(void) { app_log_info("button down long"); }
static void button_down_very_long_fn(void) { app_log_info("button down very long"); }
static void double_press_fn(void) { app_log_info("double press"); }
static void button_up_fn(void) { app_log_info("button up"); }
static void init(void)
{
    PushButton.init();
    PushButton.register_button(
        (struct button_config) {
            .button_down_short = &button_down_short_fn,
            .button_down_long = &button_down_long_fn,
            .button_down_very_long = &button_down_very_long_fn,
            .button_down_double = &double_press_fn,
            .button_up = &button_up_fn,
            .gpio_pin = TEST_BTN_Pin,
            .gpio_port = TEST_BTN_GPIO_Port });
    app_log_info("application started!");
}
static void loop(void) { PushButton.loop(); }
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == TEST_BTN_Pin) {
        if (!PushButton.signal_state_change(GPIO_Pin, false)) {
            app_log_error("error signaling state change");
        }
    }
}

const struct application Application = {
    .init = init,
    .loop = loop,

};
