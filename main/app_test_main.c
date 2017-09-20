#include "nvs.h"
#include "nvs_flash.h"

#include "gattc_demo.h"
#include "smartconfig_demo.h"

void app_main()
{
    // Initialize NVS.
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK( ret );

	smartconfig_demo_main();
	gattc_demo_main();
}

