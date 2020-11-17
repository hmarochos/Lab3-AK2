#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

int main (int argc, char *argv[])
{
    int c;
    bool check_a = false;
    bool check_h = false;
    bool check_n = false;
    bool check_v = false;
    
    while (1)
    {
        static struct option long_options[] =
        {
            {"author",     no_argument,       0, 'a'},
            {"help",       no_argument,       0, 'h'},
            {"name",       no_argument,       0, 'n'},
            {"version",    no_argument,       0, 'v'},
            {0, 0, 0, 0}
        };
        
        int option_index = 0;
        
        c = getopt_long (argc, argv, "ahnvf:",
                         long_options, &option_index);
        
        if (c == -1)
            break;
        
        switch (c)
        {
            case 0:
                if (long_options[option_index].flag != 0)
                    break;
                printf ("option %s", long_options[option_index].name);
                if (optarg)
                    printf (" with arg %s", optarg);
                printf ("\n");
                break;
                
            case 'a':
                if (!check_a){
                    puts ("Author: Vlad Onischuk");
                    check_a = true;
                }
                break;
                
                
            case 'h':
                if (!check_h){
                    puts ("Keys:" \
                          "\n-a --author                       - project author" \
                          "\n-n --n                            - take file name" \
                          "\n-h --help                         - help" \
                          "\n-v --version                      - program's version");
                    check_h = true;
                }
                break;
                
            case 'n':
                if (!check_n){
                    puts("File name: Lab3\n");
                    check_n = true;
                }
                break;
                
            case 'v':
                if (!check_v){
                    printf("Version: 1.0\n");
                    check_v = true;
                }
                break;
                
            case '?':
                break;
                
            default:
                abort ();
        }
    }
    
    return 0;
}

