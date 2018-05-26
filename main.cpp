#include <getopt.h>
#include "libopenbeard/OpenBeardFunc.h"

#include <iostream>

void print_usage()
{
    std::cout   << "beardcalc "
                << "[ -h | --i-am-not-a-wizard ] "
                << "[ -l | --beard-length ] "
                << "[ -d | --beard-depth ] "
                << "[ -f | --face-coverage ] "
                << "[ --i-am-a-wizard ]"
                << std::endl;
}

int main( int argc, char * argv[] )
{

    int depth, length= 0;
    int coverage, followers = 0;

    int flags, opt;

    bool wizard_mode = false;
    bool show_help = false;

    while ( opt != -1 )
    {

        static struct option long_options[] =
                {
                        {"i-am-not-a-wizard",   no_argument,        0, 'h'},
                        {"i-am-a-wizard",       no_argument,        0, 'i'},
                        {"beard-depth",         required_argument,  0, 'd'},
                        {"beard-length",        required_argument,  0, 'l'},
                        {"face-coverage",       required_argument,  0, 'f'},
                        { 0, 0 }
                };

        int option_index = 0;

        opt = getopt_long(argc, argv, "hid:l:f:", long_options, &option_index);

        if (opt == -1)
            break;

        switch (opt)
        {
            case 0:
                if ( long_options[option_index].flag !=0 )
                    break;
            case 'h':
                show_help   = true;
                break;
            case 'i':
                wizard_mode = true;
                break;
            case 'd':
                depth = atoi(optarg);
                break;
            case 'l':
                length = atoi(optarg);
                break;
            case 'f':
                coverage = atoi(optarg);
                break;
            default:
                break;
        }
    }

    if ( show_help )
    {
        print_usage();
        return EXIT_SUCCESS;
    }

    if ( BeardDomamaru::calc_followers( depth, length, coverage, &followers ) )
    {
        if ( wizard_mode ) {
            // Reserve this mode for times of maximum insecurity.
            // The universe could literally explode.
            //  -C
            followers = int( followers * 1.25 );
        }
        std::cout << "Number of base followers:\t" << followers << std::endl;
        return EXIT_SUCCESS;
    } else {
        std::cerr << "Bro, do you even beard?" << std::endl;
        return EXIT_FAILURE;
    }


}