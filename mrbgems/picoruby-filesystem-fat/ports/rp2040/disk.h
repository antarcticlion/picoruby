#ifndef DISK_DEFINED_H_
#define DISK_DEFINED_H_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * 1280 KiB + 768 KiB == 2 MiB
 * Fully exhausts Raspberry Pi Pico ROM because it's 2 MiB.
 * (Other RP2040 board may have a bigger ROM)
 */
#if !defined(FLASH_TARGET_OFFSET)
#define FLASH_TARGET_OFFSET  0x00140000  /* 1280 KiB for program code */
#endif
#define FLASH_MMAP_ADDR      (XIP_BASE + FLASH_TARGET_OFFSET)
//#define FLASH_SECTOR_SIZE  4096  /* Already defined in hardware/flash.h */
#define FLASH_SECTOR_COUNT  192 /* Seems FatFS allows 192 as the minimum */

// XIP QSPI Flash size variation
#ifdef FLASH_XIP_QSPI_SIZE_MB
// If specified, use the Flash size setting for each.
//-----------------------------------------------------------------------------
#if   FLASH_XIP_QSPI_SIZE_MB == 4   /* Settings for 4MB QSPI FLASH on board */
#undef  FLASH_SECTOR_COUNT
#define FLASH_SECTOR_COUNT  704     /* 768KB + 2MB */
//-----------------------------------------------------------------------------
#elif FLASH_XIP_QSPI_SIZE_MB == 8   /* Settings for 8MB QSPI FLASH on board */
#undef  FLASH_SECTOR_COUNT
#define FLASH_SECTOR_COUNT  1728    /* 768KB + 2MB + 4MB */
//-----------------------------------------------------------------------------
#elif FLASH_XIP_QSPI_SIZE_MB == 16  /* Settings for 16MB QSPI FLASH on board */
#undef  FLASH_SECTOR_COUNT
#define FLASH_SECTOR_COUNT  3584    /* 768KB + 2MB + 4MB + 8MB*/
//-----------------------------------------------------------------------------
#endif
// If the specified number is anything other than 4 8 16, use the 2MiB setting.
#endif




#define SD_SECTOR_SIZE      512
/* SD SECTOR COUNT is dynamically decided by SD_disk_ioctl() */

#ifdef __cplusplus
}
#endif

#endif /* DISK_DEFINED_H_ */

