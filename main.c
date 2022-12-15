#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char buffer[80];
    char dirname[80] = "/home/saibo-xu/sys/class/video4linux/";

    fp = popen("ls /home/saibo-xu/sys/class/video4linux/", "r");
    char filenames[80][80];
    int filesize = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s", buffer);
        if (buffer[strlen(buffer) - 1] == '\n')
        {
            buffer[strlen(buffer) - 1] = '\0';
        }
        strcpy(filenames[filesize], buffer);
        char _cmd[80] = "cat ";
        strcat(_cmd, dirname);
        strcat(_cmd, buffer);
        strcat(_cmd, "/name");
        FILE *cmd_fp = popen(_cmd, "r");
        fgets(buffer, sizeof(buffer), cmd_fp);
        if (strcmp(buffer, "rk3xxx: UVC DEPTH"))
        {
                }
        else if (strcmp(buffer, "rk3xxx: UVC RGB"))
        {
        }
        else if (strcmp(buffer, "rk3xxx: UVC IS"))
        {
        }

        filesize++;
    }

    fp = popen("cat /etc/passwd", "r");
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s", buffer);
    }

    return 0;
}
