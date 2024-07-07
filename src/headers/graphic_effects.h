#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "video.h"

void draw_checker_pattern(volatile void *fb, int cube_size, bool offset);