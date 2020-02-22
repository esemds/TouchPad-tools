#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){

	//check amount of passed arguments
	if ( argc == 1 ){
		//if no arguments are passed, tell to use -h or --help option for usage
		printf("touchpad_config is a tool that let\'s you easily configure your laptop\'s touchpad.\n");
		printf("You didn't pass any arguments, use \'touchpad_config -h\' or \'touchpad_config --help\' for help\n");
	}else if ( argc > 1 ){
		//check if asking for help
		if ( strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0 ){ 
			//show command usage
			printf("touchpad_config is a tool that let\'s you easily configure your laptop\'s touchpad.\n");
			printf("Usage: touchpad_config <options> [device id(optional)]\n\n");
			printf("Options: (without brackets)\n");
			printf("touchpad_config (-h, --help)			shows this help message\n");
			printf("touchpad_config (-l, --list)			shows a list of input devices\n");
			printf("touchpad_config (-e, --enable) [device id]	enables tap to click and natural scrolling\n");
			printf("touchpad_config (-d, --disable)	[device id]	disables tap to click and natural scrolling\n");
			printf("\nNote that it is optional to give a device id. If not provided,\nthe program will default to SynPS/2 Synaptics TouchPad.\n");
			printf("Use the -l or --list option to see available devices.\n");
			printf("When specifying a device, enter the device's id, or the full name as displayed in quotes.\n");
			printf("Example:\n\ttouchpad_config -e 12\n");
		}else if ( strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--list") == 0 ){ //check if -l or --list
			//show list of input devices
			system("xinput list | grep pointer");
		}else if ( strcmp(argv[1], "-e") == 0 || strcmp(argv[1], "--enable") == 0 ){	//check if -e or --enable
			//enable tap to click and natural scrolling

			//first check if device is provided
			if (argc > 2){
				printf("Enabling tap to click.\n");
				char enableTapping[256];
				snprintf(enableTapping, sizeof(enableTapping)+1, "xinput set-prop %s \"libinput Tapping Enabled\" 1", argv[2]);
				system(enableTapping);
				printf("Enabling natural scrolling\n");
				char enableNaturalScrolling[256];
				snprintf(enableNaturalScrolling, sizeof(enableNaturalScrolling)+1, "xinput set-prop %s \"libinput Natural Scrolling Enabled\" 1", argv[2]);
				system(enableNaturalScrolling);
			}else{
				printf("Enabling tap to click.\n");
				system("xinput set-prop \"SynPS/2 Synaptics TouchPad\" \"libinput Tapping Enabled\" 1");
				printf("Enabling natural scrolling\n");
				system("xinput set-prop \"SynPS/2 Synaptics TouchPad\" \"libinput Natural Scrolling Enabled\" 1");
			}
		}else if ( strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--disable") == 0 ){//check if -d or --disable
			//disable tap to click and natural scrolling

			//first check if device is provided
			if (argc > 2){
				printf("Disabling tap to click.\n");
				char disableTapping[256];
				snprintf(disableTapping, sizeof(disableTapping)+1, "xinput set-prop %s \"libinput Tapping Enabled\" 0", argv[2]);
				system(disableTapping);
				printf("Disabling natural scrolling\n");
				char disableNaturalScrolling[256];
				snprintf(disableNaturalScrolling, sizeof(disableNaturalScrolling)+1, "xinput set-prop %s \"libinput Natural Scrolling Enabled\" 0", argv[2]);
				system(disableNaturalScrolling);
			}else{
				printf("Disabling tap to click.\n");
				system("xinput set-prop \"SynPS/2 Synaptics TouchPad\" \"libinput Tapping Enabled\" 0");
				printf("Disabling natural scrolling\n");
				system("xinput set-prop \"SynPS/2 Synaptics TouchPad\" \"libinput Natural Scrolling Enabled\" 0");
			}
		}else{
			printf("Option not recognised.\nUse \'touchpad_config -h\' or \'touchpad_config --help\' to see available options.\n");
		}
	}

	return 0;
}

