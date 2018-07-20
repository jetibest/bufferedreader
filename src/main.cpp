#include <iostream>
#include <string>
#include <vector>
#include "methods.h"

using namespace std;

void print_help()
{
    cout << "Usage: bufferedreader [options] >output 2>lengths" << endl <<
        "" << endl <<
        "The bufferedreader pipes the stdin to stdout, splitting the data into separate " << endl <<
        "data packets on the given delimiter. The stderr contains numbers indicating " << endl <<
        "the length of each data packet if verbose mode on." << endl <<
        "" << endl <<
        "Core options:" << endl <<
        "  --delimiter, -d      Set a delimiter to split the stream on." << endl <<
        "  --no-strip, -n       Do not strip delimiter from stream." << endl <<
        "  --separator, -s, -1  Set a custom delimiter for stdout." << endl <<
        "  --verbose, -v        Enable stderr output." << endl <<
        "Quick options:" << endl <<
        "  --split            Alias of exclusive-flag." << endl <<
        "  --header           Alias of prefix-flag and no-strip-flag." << endl <<
        "Advanced options:" << endl <<
        "  --prefix, -p       Delimiter comes first (e.g. <SOH>head,body<SOH>head,body)." << endl <<
        "  --exclusive, -e    Prevent ignoring leading and trailing delimiter." << endl <<
        "Default options:" << endl <<
        "  --delimiter '\\n'         Split the stream on <LF>." << endl <<
        "  --strip                  Delimiter is stripped from stdout." << endl <<
        "  --suffix                 Delimiter comes last (e.g. line<LF>line<LF>)." << endl <<
        "  --inclusive              Leading and trailing delimiter is ignored." << endl <<
        "  --separator, -s, -1 ''   Do not put a custom delimiter in stdout." << endl <<
        "  -2 '\\n'                  Numbers of stderr are delimited by <LF>." << endl <<
    endl;
}

int main(int argc, char* argv[])
{
    if(argc > 1)
    {
        string arg(argv[1]);
        if(arg == "--help" || arg == "-h")
        {
            print_help();
            return 0;
        }
    }

    int prefix = 0;
    int inclusive = 1;
    int nostrip = 0;
    int verbose = 0;
    string separator1("");
    string separator2("\n");
    string delimiter("\n");
    vector<string> outputs;

    {
        int i = 1;
        for(;i<argc;++i)
        {
            string arg(argv[i]);
            if(arg[0] != '-')
            {
                break;
            }
            if(arg == "--verbose" || arg == "-v")
            {
                verbose = 1;
            }
            else if(arg == "--split")
            {
                inclusive = 0;
            }
            else if(arg == "--no-strip" || arg == "-n")
            {
                nostrip = 1;
            }
            else if(arg == "--strip")
            {
                nostrip = 0;
            }
            else if(arg == "--header")
            {
                prefix = 1;
                nostrip = 1;
            }
            else if(arg == "--footer")
            {
                prefix = 0;
                nostrip = 1;
            }
            else if(arg == "--prefix" || arg == "-p")
            {
                prefix = 1;
            }
            else if(arg == "--suffix")
            {
                prefix = 0;
            }
            else if(arg == "--inclusive")
            {
                inclusive = 1;
            }
            else if(arg == "--exclusive" || arg == "-e")
            {
                inclusive = 0;
            }
            else if(arg == "--")
            {
                ++i;
                break;
            }
            else if(i + 1 < argc)
            {
                string value(argv[i + 1]);
                if(arg == "--delimiter" || arg == "-d")
                {
                    delimiter = value;
                    ++i;
                }
                else if(arg == "--separator" || arg == "-s" || arg == "-1")
                {
                    separator1 = value;
                    ++i;
                }
                else if(arg == "-2")
                {
                    separator2 = value;
                    ++i;
                }
            }
        }
        for(;i<argc;++i)
        {
            cerr << "Outputting to " << argv[i] << endl;
            outputs.push_back(argv[i]);
        }
    }

    if(verbose)
    {
        if(inclusive)
        {
            if(prefix)
            {
                if(nostrip)
                {
                    do_verbose_inclusive_prefix_nostrip(delimiter, separator1, separator2);
                }
                else
                {
                    do_verbose_inclusive_prefix_strip(delimiter, separator1, separator2);
                }
            }
            else
            {
                if(nostrip)
                {
                    do_verbose_inclusive_suffix_nostrip(delimiter, separator1, separator2);
                }
                else
                {
                    do_verbose_inclusive_suffix_strip(delimiter, separator1, separator2);
                }
            }
        }
        else
        {
            if(prefix)
            {
                if(nostrip)
                {
                    do_verbose_exclusive_prefix_nostrip(delimiter, separator1, separator2);
                }
                else
                {
                    do_verbose_exclusive_prefix_strip(delimiter, separator1, separator2);
                }
            }
            else
            {
                if(nostrip)
                {
                    do_verbose_exclusive_suffix_nostrip(delimiter, separator1, separator2);
                }
                else
                {
                    do_verbose_exclusive_suffix_strip(delimiter, separator1, separator2);
                }
            }
        }
    }
    else
    {
        if(inclusive)
        {
                if(prefix)
                {
                    if(nostrip)
                    {
                        do_inclusive_prefix_nostrip(delimiter, separator1, separator2);
                    }
                    else
                    {
                        do_inclusive_prefix_strip(delimiter, separator1, separator2);
                    }
                }
                else
                {
                    if(nostrip)
                    {
                        do_inclusive_suffix_nostrip(delimiter, separator1, separator2);
                    }
                    else
                    {
                        do_inclusive_suffix_strip(delimiter, separator1, separator2);
                    }
                }
        }
        else
        {
            if(prefix)
            {
                if(nostrip)
                {
                    do_exclusive_prefix_nostrip(delimiter, separator1, separator2);
                }
                else
                {
                    do_exclusive_prefix_strip(delimiter, separator1, separator2);
                }
            }
            else
            {
                if(nostrip)
                {
                    do_exclusive_suffix_nostrip(delimiter, separator1, separator2);
                }
                else
                {
                    do_exclusive_suffix_strip(delimiter, separator1, separator2);
                }
            }
        }
    }
    return 0;
}
