/*
 * Copyright (c) 2015 Sergi Granell (xerpi)
 */
/*
#include <string.h>

#include <psp2/display.h>
#include <psp2/ctrl.h>
#include <psp2/apputil.h>
#include <psp2/sysmodule.h>
#include <psp2/kernel/processmgr.h>

#include <ftpvita.h>

#include "utils.h"
#include "console.h"
*/

#include "ps4.h"

#define INFO(format, ...)\
	do {\
		char buffer[512];\
		int size = sprintf(buffer, format, ##__VA_ARGS__);\
	} while(0)


static void info_log(const char *s)
{
	//INFO(s);
}

#ifdef SHOW_DEBUG
static void debug_log(const char *s)
{
	DEBUG(s);
}
#endif

int _main(void)
{
/*
	char ps4_ip[16] = "192.168.0.17";
	unsigned short int ps4_port = 21;
	ftpvita_init(ps4_ip, &ps4_port);
*/
	int run = 1;
	char ps4_ip[16] = "192.168.0.17";
	unsigned short int ps4_port = 21;
/*
	SceCtrlData pad;
	SceAppUtilInitParam init_param;
	SceAppUtilBootParam boot_param;

	sceKernelPowerTick(SCE_KERNEL_POWER_TICK_DISABLE_AUTO_SUSPEND);
	sceKernelPowerTick(SCE_KERNEL_POWER_TICK_DISABLE_OLED_OFF);

	init_video();
	console_init();

	console_set_color(PURP);
	INFO("FTPVita by xerpi\n");
	console_set_color(CYAN);
	INFO("Press [] to exit\n");
	console_set_color(WHITE);

	sceSysmoduleLoadModule(SCE_SYSMODULE_NET);

	memset(&init_param, 0, sizeof(SceAppUtilInitParam));
	memset(&boot_param, 0, sizeof(SceAppUtilBootParam));
	sceAppUtilInit(&init_param, &boot_param);

	ftpvita_set_info_log_cb(info_log);
#ifdef SHOW_DEBUG
	ftpvita_set_debug_log_cb(debug_log);
#endif

	int y = console_get_y();
*/
	
	while (ftpvita_init(ps4_ip, &ps4_port) < 0 && run) {
		INFO("You have to enable Wi-Fi.\nPress X to continue.\n");
		while (run) {
/*
			sceCtrlPeekBufferPositive(0, &pad, 1);
			if (pad.buttons & SCE_CTRL_CROSS) break;
			else if (pad.buttons & SCE_CTRL_SQUARE) run = 0;
			sceDisplayWaitVblankStart();
*/
		}
		if (!run) {
			INFO("Exiting...\n");
			console_fini();
			end_video();
			return 0;
		}
		//console_set_y(y);
	}
	ftpvita_add_device("/");
	
	/*
	ftpvita_add_device("app0:");
	ftpvita_add_device("ux0:");
	ftpvita_add_device("ur0:");

	if (sceAppUtilMusicMount() == 0)
		ftpvita_add_device("music0:");
	if (sceAppUtilPhotoMount() == 0)
		ftpvita_add_device("photo0:");

	console_set_color(LIME);
	*/
	INFO("PS4 listening on IP %s Port %i\n", ps4_ip, ps4_port);
	/*	
	console_set_color(WHITE);

	console_set_top_margin(10 + 20*3);

	while (run) {
		sceCtrlPeekBufferPositive(0, &pad, 1);
		if (pad.buttons & SCE_CTRL_SQUARE) run = 0;
		sceDisplayWaitVblankStart();
	}
	*/
	INFO("Exiting...\n");
	ftpvita_fini();
/*
	sceAppUtilPhotoUmount();
	sceAppUtilMusicUmount();
	sceAppUtilShutdown();

	console_fini();
	end_video();
	sceKernelExitProcess(0);
*/
	return 0;
}
