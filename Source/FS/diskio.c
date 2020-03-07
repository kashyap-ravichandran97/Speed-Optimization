/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for Petit FatFs (C)ChaN, 2014      */
/*-----------------------------------------------------------------------*/

#include "diskio.h"
#include "sd_io.h"
#include <string.h>

SD_DEV dev;

/*-----------------------------------------------------------------------*/
/* Initialize Disk Drive                                                 */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize(void) {
	DSTATUS stat;

	if (SD_Init(&dev) != SD_OK) {
		stat = RES_ERROR;
	} else {
		stat = RES_OK;
	}

	return stat;
}




/*-----------------------------------------------------------------------*/
/* Read Partial Sector                                                   */
/*-----------------------------------------------------------------------*/
inline DRESULT disk_readp(BYTE * buff,	/* Pointer to the destination object */
									 DWORD sector,	/* Sector number (LBA) */
									 UINT offset,	/* Offset in the sector */
									 UINT count		/* Byte count (bit15:destination) */
		) {
	DRESULT res;
	// SD_Read reads entire block, but only stores count bytes starting at offset
	if (SD_Read(&dev, buff, sector, offset, count) != SD_OK) {
		res = RES_ERROR;
	} else {
		res = RES_OK;
	}
	return res;
}

/*-----------------------------------------------------------------------*/
/* Write Partial Sector                                                  */
/*-----------------------------------------------------------------------*/

DRESULT disk_writep(const BYTE * buff,	/* Pointer to the data to be written, NULL:Initiate/Finalize write operation */
										DWORD sc		/* Sector number (LBA) or Number of bytes to send */
		) {
	DRESULT res;


	// AD
	// TODO: Need to port. SD_Write writes an entire sector, needs to be modified to just write specified number of bytes
	// Look into PFFS ports to see how this is done
	if (!buff) {
		if (sc) {

			// Initiate write process

		} else {

			// Finalize write process

		}
	} else {

		// Send data to the disk

	}

	return res;
}
