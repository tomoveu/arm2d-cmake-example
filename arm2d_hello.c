/* Minimalistic arm2d demo that displays just default scene - loading circle */
#include <stdio.h>
#include "arm_2d_cfg.h"
#include <arm_2d_helper.h>
#include <arm_2d_scenes.h>
#include <arm_2d_disp_adapters.h>

int64_t arm_2d_helper_get_system_timestamp(void)
{
    /* TODO return get_system_ticks(); */
    return 0;
}

void Disp0_DrawBitmap(int16_t x, int16_t y, int16_t width,
                      int16_t height, const char *bitmap)
{
#if __DISP0_CFG_COLOUR_DEPTH__ == 8
    extern
    void __arm_2d_impl_gray8_to_rgb565( uint8_t *__RESTRICT pchSourceBase,
                                        int16_t iSourceStride,
                                        uint16_t *__RESTRICT phwTargetBase,
                                        int16_t iTargetStride,
                                        arm_2d_size_t *__RESTRICT ptCopySize);

    static uint16_t s_hwFrameBuffer[BENCHMARK_PFB_BLOCK_WIDTH * BENCHMARK_PFB_BLOCK_HEIGHT];

    arm_2d_size_t size = {
        .iWidth = width,
        .iHeight = height,
    };
    __arm_2d_impl_gray8_to_rgb565( (uint8_t *)bitmap,
                                    width,
                                    (uint16_t *)s_hwFrameBuffer,
                                    width,
                                    &size);
    GLCD_DrawBitmap(x, y, width, height, (const uint8_t *)s_hwFrameBuffer);
#elif __DISP0_CFG_COLOUR_DEPTH__ == 32
    extern
    void __arm_2d_impl_cccn888_to_rgb565(uint32_t *__RESTRICT pwSourceBase,
                                        int16_t iSourceStride,
                                        uint16_t *__RESTRICT phwTargetBase,
                                        int16_t iTargetStride,
                                        arm_2d_size_t *__RESTRICT ptCopySize);

    arm_2d_size_t size = {
        .iWidth = width,
        .iHeight = height,
    };
    __arm_2d_impl_cccn888_to_rgb565((uint32_t *)bitmap,
                                    width,
                                    (uint16_t *)bitmap,
                                    width,
                                    &size);
    GLCD_DrawBitmap(x, y, width, height, bitmap);
#else
    /* TODO
    GLCD_DrawBitmap(x, y, width, height, bitmap);
    */
#endif
}

/*----------------------------------------------------------------------------
  Main function
 *----------------------------------------------------------------------------*/
int main (void)
{
    arm_2d_init();

    printf("\r\nArm-2D Bare-metal Template\r\n");

    disp_adapter0_init();

    while (1) {
        disp_adapter0_task();
    }
}
