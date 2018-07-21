#include <iostream>
#include <string>
#include <vector>

using namespace std;

// For example: ffmpeg -input_format mjpeg -i /dev/video0 -f mpjpeg - | br -d '--ffmpeg' -f 'mpjpeg' | ...
void dompjpeg(string &boundary, string &separator1, string &separator2)
{
    string delimiter = boundary + "\r\n";
    size_t delimiter_offset = 0;
    bool header = false;
    string key;
    string value;
    int header_offset = 0;
    int bytecount = 0;
    char c;
    
    while(cin.get(c))
    {
        if(header)
        {
            if(header_offset == -1)
            {
                if(c == '\n')
                {
                    ++header_offset;
                }
            }
            else if(header_offset == 0)
            {
                if(c == '\r')
                {
                    if(key.length())
                    {
                        key.clear();
                        header_offset = -1;
                    }
                    else
                    {
                        header_offset = 10;
                    }
                }
                else if(c == ':')
                {
                    ++header_offset;
                }
                else
                {
                    key += tolower(c);
                }
            }
            else if(header_offset == 1)
            {
                if(c == '\r')
                {
                    header_offset = 2;
                }
                else if(c != ' ')
                {
                    value += c;
                }
            }
            else if(header_offset == 2)
            {
                if(c == '\n')
                {
                    if(key == "content-length")
                    {
                        bytecount = stoi(value);
                    }
                    
                    header_offset = 0;
                    key.clear();
                    value.clear();
                }
                else
                {
                    header_offset = 1;
                }
            }
            else if(header_offset == 10)
            {
                if(c == '\n')
                {
                    header_offset = 0;
                    header = false;
                    
                    if(bytecount)
                    {
                        char* buffer = new char[bytecount];
                        cin.read(buffer, bytecount);
                        if(cin)
                        {
                            cout << buffer << separator1;
                            cerr << bytecount << separator2;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        else if(c == delimiter[delimiter_offset])
        {
            ++delimiter_offset;
            if(delimiter_offset == delimiter.length())
            {
                header = true;
                delimiter_offset = 0;
            }
        }
    }
}

template<int prefix, int verbose, int inclusive, int nostrip> void dobr(string &delimiter, string &separator1, string &separator2)
{
    int offset = 0;
    int delimc = 0;
    int delimn = delimiter.length();
    int flag = 1;
    int prepend = 0;
    char c;
    bool match = false;
    
    while(cin.get(c))
    {
        match = delimiter[delimc] == c;
        if(!prefix)
        {
            if(prepend)
            {
                cout << separator1;
                prepend = 0;
            }
        }
        
        if(delimc > 0 && !match)
        {
            if(!prefix)
            {
                if(prepend)
                {
                    cout << separator1;
                    prepend = 0;
                }
            }
            
            for(int i=0;i<delimc;++i)
            {
                cout << delimiter[i];
            }
            offset += delimc;
            delimc = 0;
            match = delimiter[delimc] == c;
        }
        if(match)
        {
            ++delimc;
            
            if(delimc == delimn)
            {
                if(!prefix)
                {
                    if(nostrip)
                    {
                        for(int i=0;i<delimc;++i)
                        {
                            cout << delimiter[i];
                        }
                        if(!inclusive)
                        {
                            cout << separator1;
                        }
                        else
                        {
                            prepend = 1;
                        }
                        if(verbose)
                        {
                            cerr << offset + delimn << separator2;
                        }
                        offset = 0;
                        flag = 0;
                    }
                    else
                    {
                        if(!inclusive)
                        {
                            cout << separator1;
                        }
                        else
                        {
                            prepend = 1;
                        }
                        if(verbose)
                        {
                            cerr << offset << separator2;
                        }
                        offset = 0;
                        flag = 0;
                    }
                }
                else if(flag)
                {
                    if(offset)
                    {
                        cout << separator1;
                        if(verbose)
                        {
                            cerr << offset << separator2;
                        }
                        offset = 0;
                    }
                    else if(!inclusive)
                    {
                        cout << separator1;
                        if(verbose)
                        {
                            cerr << 0 << separator2;
                        }
                    }
                    flag = 0;
                }
                else
                {
                    cout << separator1;
                    if(nostrip)
                    {
                        if(verbose)
                        {
                            cerr << offset + delimn << separator2;
                        }
                    }
                    else
                    {
                        if(verbose)
                        {
                            cerr << offset << separator2;
                        }
                    }
                    offset = 0;
                }
                if(prefix && nostrip)
                {
                    for(int i=0;i<delimc;++i)
                    {
                        cout << delimiter[i];
                    }
                }
                delimc = 0;
            }
        }
        else
        {
            cout << c;
            ++offset;
        }
    }
    if(delimc > 0)
    {
        for(int i=0;i<delimc;++i)
        {
            cout << delimiter[i];
        }
        
        if(!prefix)
        {
            if(nostrip && inclusive)
            {
                if(offset)
                {
                    if(verbose)
                    {
                        cerr << offset + delimc << separator2;
                    }
                }
                else if(flag)
                {
                    if(verbose)
                    {
                        cerr << delimc << separator2;
                    }
                }
            }
            else if(verbose)
            {
                cerr << offset + delimc << separator2;
            }
        }
        else if(verbose)
        {
            cerr << offset + delimc << separator2;
        }
    }
    else if(!prefix)
    {
        if(inclusive)
        {
            if(!prepend)
            {
                if(verbose)
                {
                    cerr << offset << separator2;
                }
            }
        }
        else
        {
            if(verbose)
            {
                cerr << offset << separator2;
            }
        }
    }
    else if(!nostrip)
    {
        if(verbose)
        {
            cerr << offset << separator2;
        }
    }
    else if(offset)
    {
        if(flag)
        {
            if(verbose)
            {
                cerr << offset << separator2;
            }
        }
        else
        {
            if(verbose)
            {
                cerr << offset + delimn << separator2;
            }
        }
    }
    else if(flag)
    {
        if(verbose)
        {
            cerr << 0 << separator2;
        }
    }
    else if(match && !delimc)
    {
        if(verbose)
        {
            cerr << delimn << separator2;
        }
    }
}
