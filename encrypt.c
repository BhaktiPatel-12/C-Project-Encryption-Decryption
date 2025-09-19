#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Invalid input\nTry '%s --help' or '%s -h' for more information.\n", argv[0], argv[0]);
        return 2;
    }

    FILE* inputFile = NULL;
    FILE* outputFile = NULL;
    char outputFileName[50];

    char key[27]; // Assuming a key of 26 characters plus null terminator
    int keySpecified = 0;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0)
        {
            printf("Usage: %s [file to be encrypted] -p [key] \n", argv[0]);
            printf("Note that the [key] should consist of 26 distinct characters.\nOptionally, use -o [output file name] to generate a custom output file.\n");
            return 0;
        }
       
        if (strcmp(argv[i], "-p") == 0)
        {
            if (i + 1 < argc && argv[i + 1][0] != '-')
            {
                strcpy(key, argv[i + 1]);
                if (strlen(key) != 26)
                {   
                    printf("Invalid input. The key must be exactly 26 characters long.\n");
                    return 2;
                }
                // Check for distinct characters
                for (int j = 0; j < 26; j++)
                {
                    for (int k = j + 1; k < 26; k++)
                    {
                        if (key[j] == key[k])
                        {    
                            printf("Invalid input. The key must contain distinct characters.\n");
                            return 2;
                        }
                    }
                }
                i++;
                
                keySpecified = 1;
            }
            else
            {
                printf("Invalid input. -p option requires a key.\n");
                return 2;
            }
        }
        
        if (strcmp(argv[i], "-o") == 0)
        {
            if (i + 1 < argc)
            {
                outputFile = fopen(argv[i + 1], "r");
                if (outputFile != NULL)
                {  
                    
                    fclose(outputFile);
                    char response;
                    printf("Output file '%s' already exists. Do you want to replace it? (y/n): ", argv[i + 1]);
                    scanf(" %c", &response);
                    if (response != 'y' && response != 'Y')
                    {
                        return 0; // User chose not to replace the file
                    }
                }
                outputFile = fopen(argv[i + 1], "w");
                if (outputFile == NULL)
                {
                    perror("Error opening output file");
                    return 2;
                }
                i++;
            }
            else
            { 
                printf("Invalid input. -o option requires an output file name.\n");
                return 2;
            }
        }
        // else 
        // {printf("for output file name requires option -o\n");}

        if (inputFile == NULL && argv[i][0] != '-')
        {  
            inputFile = fopen(argv[i], "r");
            if (inputFile == NULL)
            {
                perror("Error opening input file");
                return 2;
            }
        }
    }

    if (!keySpecified)
    {
        printf("Invalid input. -p option with a key is required.\n");
        return 2;
    }

    if (inputFile == NULL)
    {
        printf("Invalid input. No input file specified.\n");
        return 2;
    }

    // If outputFile was not specified, generate output file name
    if (outputFile == NULL)
    {
        sprintf(outputFileName, "%s_encrypted", argv[1]);
        outputFile = fopen(outputFileName, "w");
        if (outputFile == NULL)
        {
            perror("Error opening output file");
            return 2;
        }
    }

    // Encrypt and write to the output file
int c;
while ((c = fgetc(inputFile)) != EOF)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            int m = c - 'A';
            fputc(toupper(key[m]), outputFile);
        }
        else if (islower(c))
        {
            int m = c - 'a';
            fputc(tolower(key[m]), outputFile);
        }
   
    }
    else
    {
        fputc(c, outputFile); // Non-alphabet characters remain unchanged
    }
}
    fclose(inputFile);
    fclose(outputFile);

    printf("The file is ready after encryption\n");
    return 0;

}
