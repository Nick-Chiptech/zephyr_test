/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define SLEEP_TIME_MS   1000
#define LED0_NODE DT_ALIAS(led0)

const struct gpio_dt_spec bled = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int main(void)
{
    int rc;
	if (!gpio_is_ready_dt(&bled)) {return 0;}
	rc = gpio_pin_configure_dt(&bled, GPIO_OUTPUT_ACTIVE);
	if (rc < 0) return rc;

	while (1) 
    {
      rc = gpio_pin_toggle_dt(&bled);
      if (rc < 0)  return rc;
      k_msleep(SLEEP_TIME_MS);
	}
	return 0;
}
