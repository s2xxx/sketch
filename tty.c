#include <stdio.h>      // standard input / output functions
#include <stdlib.h>
#include <string.h>     // string function definitions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <errno.h>      // Error number definitions
#include <termios.h>    // POSIX terminal control definitions

int usb = 0;
struct termios tty;

static void usage(char *prName)
{
	printf("Invalid usage: use %s ttyId pwSwName \n", prName);
}

int main(int argc, char *argv[])
{
	int rc = -1;

	char devName[12] = "/dev/ttyUSB";
	int devId = 0;

	if (3 == argc)
	{
		if (10 > (devId = atoi(argv[1])))
		{
			devName[11] = devId + '0';

			if (0 < (usb = open(devName, O_RDWR | O_NOCTTY | O_SYNC)))
			{
				if (0 == tcgetattr(usb, &tty) < 0)
				{
					cfsetospeed(&tty, (speed_t)B115200);
					cfsetispeed(&tty, (speed_t)B115200);

					tty.c_cflag |= (CLOCAL | CREAD);    /* ignore modem controls */
					tty.c_cflag &= ~CSIZE;
					tty.c_cflag |= CS8;         /* 8-bit characters */
					tty.c_cflag &= ~PARENB;     /* no parity bit */
					tty.c_cflag &= ~CSTOPB;     /* only need 1 stop bit */
					tty.c_cflag &= ~CRTSCTS;    /* no hardware flowcontrol */

					/* setup for non-canonical mode */
					tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
					tty.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
					tty.c_oflag &= ~OPOST;

					/* fetch bytes as they become available */
					tty.c_cc[VMIN] = 1;
					tty.c_cc[VTIME] = 1;

					if (0 == tcsetattr(usb, TCSANOW, &tty) != 0)
					{
						if (1 == write(usb, argv[2], 1))
						{
							tcdrain(usb);    /* delay for output */
							printf("Ok\n");
						}
						else
						{
							printf("Error from write: %d\n", errno);
						}
					}
					else
					{
						printf("Error from tcsetattr: %s\n", strerror(errno));
					}
				}
				else
				{
					printf("Error from tcgetattr: %s\n", strerror(errno));
				}
				close(usb);
			}
			else
			{
				printf("Error open usb (%s)\n", devName);
			}
		}
		else
		{
			printf("devId to big %i \n", devId);
			usage(argv[0]);
		}
	}
	else
	{
		usage(argv[0]);
	}
	return rc;
}
