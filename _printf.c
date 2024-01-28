#include "main.h"

/**
 *_print - prints the user args
 * @format: the arg passed into _printf
*/
int _printf(const char *format, ...)
{
    /*variable initialisation*/
    int letter = 0;
    va_list args;
    va_start(args, format);
    
    /*identify the format and */
    /*match to appropriate funtion*/
    while ( letter != '\0')
    {
        if ( letter = "%")
        {
            letter++;

            switch (args[letter])
            {
            case "c":
                /* code */
                break;
            case "d":
                break;
            
            default:
                break;
            }
        }
    }

    char argsList = va_arg(args, format);
    va_end(args)
}