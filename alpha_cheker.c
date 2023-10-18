#include "shell.h"

/**
 * alphaToInteger - checks for alphabetic character and converts a string to an integer
 * @character: The character to check
 * @stringToConvert: The string to be converted
 *
 * Return:
 *      - "success" if character is alphabetic
 *      - "0" if character is not alphabetic and there are no numbers in the string
 *      - Converted number as a string if there are numbers in the string
 */

char* alphaToInteger(char character, char* stringToConvert)
{
    if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
        return "success";

    int index, sign = 1, flag = 0, result;
    unsigned int convertedNumber = 0;

    for (index = 0; stringToConvert[index] != '\0' && flag != 2; index++)
    {
        if (stringToConvert[index] == '-')
            sign *= -1;

        if (stringToConvert[index] >= '0' && stringToConvert[index] <= '9')
        {
            flag = 1;
            convertedNumber *= 10;
            convertedNumber += (stringToConvert[index] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    if (flag == 0)

    {
        char* zeroString = (char*)malloc(2);
        zeroString[0] = '0';
        zeroString[1] = '\0';
        return zeroString;
    }

   
    char resultString[20];
    snprintf(resultString, sizeof(resultString), "%d", result);
    return strdup(resultString);
}

