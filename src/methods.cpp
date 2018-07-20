#include "methods.h"

void do_verbose_inclusive_prefix_nostrip(string &delimiter, string &separator1, string &separator2)
{
    int offset = 0;
    int delimc = 0;
    int delimn = delimiter.length();
    int flag = 1;
    char c;
    
    while(cin.get(c))
    {
        if(delimiter[delimc] == c)
        {
            ++delimc;
            
            if(delimc == delimn)
            {
                if(flag)
                {
                    if(offset)
                    {
                        cout << separator1;
                        cerr << offset << separator2;
                        offset = 0;
                    }
                    flag = 0;
                }
                else
                {
                    cout << separator1;
                    cerr << offset + delimn << separator2;
                    offset = 0;
                }
            }
        }
        else
        {
            if(delimc > 0)
            {
                for(int i=0;i<delimc;++i)
                {
                    cout << delimiter[i];
                }
                delimc = 0;
            }
            
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
        cerr << offset + delimc << separator2;
    }
    else if(offset)
    {
        if(flag)
        {
            cerr << offset << separator2;
        }
        else
        {
            cerr << offset + delimn << separator2;
        }
    }
    else if(flag)
    {
        cerr << 0 << separator2;
    }
}

void do_verbose_inclusive_prefix_strip(string &delimiter, string &separator1, string &separator2)
{
    int offset = 0;
    int delimc = 0;
    int delimn = delimiter.length();
    int flag = 1;
    char c;
    
    while(cin.get(c))
    {
        if(delimiter[delimc] == c)
        {
            ++delimc;
            
            if(delimc == delimn)
            {
                if(flag)
                {
                    if(offset)
                    {
                        cout << separator1;
                        cerr << offset << separator2;
                        offset = 0;
                    }
                    flag = 0;
                }
                else
                {
                    cout << separator1;
                    cerr << offset << separator2;
                    offset = 0;
                }
                delimc = 0;
            }
        }
        else
        {
            if(delimc > 0)
            {
                for(int i=0;i<delimc;++i)
                {
                    cout << delimiter[i];
                }
                delimc = 0;
            }
            
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
        
        cerr << offset + delimc << separator2;
    }
    else if(offset)
    {
        cerr << offset << separator2;
    }
    else
    {
        cerr << offset << separator2;
    }
}

void do_verbose_inclusive_suffix_nostrip(string &delimiter, string &separator1, string &separator2)
{
    int flag = 1;
    int offset = 0;
    int delimc = 0;
    int delimn = delimiter.length();
    char c;
    
    while(cin.get(c))
    {
        if(delimiter[delimc] == c)
        {
            ++delimc;
            
            if(delimc == delimn)
            {
                if(!flag || offset)
                {
                    cout << separator1;
                }
                cerr << offset + delimn << separator2;
                offset = 0;
                flag = 0;
            }
        }
        else
        {
            if(delimc > 0)
            {
                for(int i=0;i<delimc;++i)
                {
                    cout << delimiter[i];
                }
                delimc = 0;
            }
            
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
        
        if(offset)
        {
            cerr << offset + delimc << separator2;
        }
        else if(flag)
        {
            cerr << delimc << separator2;
        }
    }
    else
    {
        cerr << offset << separator2;
    }
}

void do_verbose_inclusive_suffix_strip(string &delimiter, string &separator1, string &separator2)
{
    int delimn = delimiter.length();
    int offset = 0;
    int delimc = 0;
    int flag = 1;
    int prepend = 0;
    char c;
    
    while(cin.get(c))
    {
        if(delimiter[delimc] == c)
        {
            ++delimc;
            
            if(delimc == delimn)
            {
                prepend = 1;
                cerr << offset << separator2;
                offset = 0;
                delimc = 0;
                flag = 0;
            }
        }
        else
        {
            if(prepend)
            {
                cout << separator1;
                prepend = 0;
            }
            if(delimc > 0)
            {
                for(int i=0;i<delimc;++i)
                {
                    cout << delimiter[i];
                }
                delimc = 0;
            }
            
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
    }
    if(offset || delimc || flag)
    {
        cerr << offset + delimc << separator2;
    }
}

void do_verbose_exclusive_prefix_nostrip(string &delimiter, string &separator1, string &separator2)
{
    int offset = 0;
    int delimc = 0;
    int delimn = delimiter.length();
    int flag = 1;
    char c;
    
    while(cin.get(c))
    {
        if(delimiter[delimc] == c)
        {
            ++delimc;
            
            if(delimc == delimn)
            {
                if(flag)
                {
                    if(offset)
                    {
                        cout << separator1;
                        cerr << offset << separator2;
                        offset = 0;
                    }
                    else
                    {
                        cout << separator1;
                        cerr << 0 << separator2;
                    }
                    flag = 0;
                }
                else
                {
                    cout << separator1;
                    cerr << offset + delimn << separator2;
                    offset = 0;
                }
            }
        }
        else
        {
            if(delimc > 0)
            {
                for(int i=0;i<delimc;++i)
                {
                    cout << delimiter[i];
                }
                delimc = 0;
            }
            
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
        cerr << offset + delimc << separator2;
    }
    else if(offset)
    {
        if(flag)
        {
            cerr << offset << separator2;
        }
        else
        {
            cerr << offset + delimn << separator2;
        }
    }
    else if(flag)
    {
        cerr << 0 << separator2;
    }
}

void do_verbose_exclusive_prefix_strip(string &delimiter, string &separator1, string &separator2)
{
    int offset = 0;
    int delimc = 0;
    int delimn = delimiter.length();
    int flag = 1;
    char c;
    
    while(cin.get(c))
    {
        if(delimiter[delimc] == c)
        {
            ++delimc;
            
            if(delimc == delimn)
            {
                if(flag)
                {
                    if(offset)
                    {
                        cout << separator1;
                        cerr << offset << separator2;
                        offset = 0;
                    }
                    else
                    {
                        cout << separator1;
                        cerr << offset << separator2;
                    }
                    flag = 0;
                }
                else
                {
                    cout << separator1;
                    cerr << offset << separator2;
                    offset = 0;
                }
                delimc = 0;
            }
        }
        else
        {
            if(delimc > 0)
            {
                for(int i=0;i<delimc;++i)
                {
                    cout << delimiter[i];
                }
                delimc = 0;
            }
            
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
        
        cerr << offset + delimc << separator2;
    }
    else if(offset)
    {
        cerr << offset << separator2;
    }
    else
    {
        cerr << offset << separator2;
    }
}

void do_verbose_exclusive_suffix_nostrip(string &delimiter, string &separator1, string &separator2)
{
    int flag = 1;
    int offset = 0;
    int delimc = 0;
    int delimn = delimiter.length();
    char c;
    
    while(cin.get(c))
    {
        if(delimiter[delimc] == c)
        {
            ++delimc;
            
            if(delimc == delimn)
            {
                if(!flag || offset)
                {
                    cout << separator1;
                }
                cerr << offset + delimn << separator2;
                offset = 0;
                flag = 0;
            }
        }
        else
        {
            if(delimc > 0)
            {
                for(int i=0;i<delimc;++i)
                {
                    cout << delimiter[i];
                }
                delimc = 0;
            }
            
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
        
        if(offset)
        {
            cerr << offset + delimc << separator2;
        }
        else if(flag)
        {
            cerr << delimc << separator2;
        }
        else
        {
            cerr << 0 << separator2;
        }
    }
    else
    {
        cerr << offset << separator2;
    }
}

void do_verbose_exclusive_suffix_strip(string &delimiter, string &separator1, string &separator2)
{
    int delimn = delimiter.length();
    int offset = 0;
    int delimc = 0;
    int flag = 1;
    char c;
    
    while(cin.get(c))
    {
        if(delimiter[delimc] == c)
        {
            ++delimc;
            
            if(delimc == delimn)
            {
                cout << separator1;
                cerr << offset << separator2;
                offset = 0;
                delimc = 0;
                flag = 0;
            }
        }
        else
        {
            if(delimc > 0)
            {
                for(int i=0;i<delimc;++i)
                {
                    cout << delimiter[i];
                }
                delimc = 0;
            }
            
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
    }
    if(offset || delimc || flag)
    {
        cerr << offset + delimc << separator2;
    }
    else
    {
        cerr << 0 << separator2;
    }
}

void do_inclusive_prefix_nostrip(string &delimiter, string &separator1, string &separator2)
{
    int offset = 0;
    int delimc = 0;
    int delimn = delimiter.length();
    int flag = 1;
    char c;
    
    while(cin.get(c))
    {
        if(delimiter[delimc] == c)
        {
            ++delimc;
            
            if(delimc == delimn)
            {
                if(flag)
                {
                    if(offset)
                    {
                        cout << separator1;
                        offset = 0;
                    }
                    flag = 0;
                }
                else
                {
                    cout << separator1;
                    offset = 0;
                }
            }
        }
        else
        {
            if(delimc > 0)
            {
                for(int i=0;i<delimc;++i)
                {
                    cout << delimiter[i];
                }
                delimc = 0;
            }
            
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
    }
}

void do_inclusive_prefix_strip(string &delimiter, string &separator1, string &separator2)
{
    int offset = 0;
    int delimc = 0;
    int delimn = delimiter.length();
    int flag = 1;
    char c;
    
    while(cin.get(c))
    {
        if(delimiter[delimc] == c)
        {
            ++delimc;
            
            if(delimc == delimn)
            {
                if(flag)
                {
                    if(offset)
                    {
                        cout << separator1;
                        offset = 0;
                    }
                    flag = 0;
                }
                else
                {
                    cout << separator1;
                    offset = 0;
                }
                delimc = 0;
            }
        }
        else
        {
            if(delimc > 0)
            {
                for(int i=0;i<delimc;++i)
                {
                    cout << delimiter[i];
                }
                delimc = 0;
            }
            
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
    }
}

void do_inclusive_suffix_nostrip(string &delimiter, string &separator1, string &separator2)
{
    int flag = 1;
    int offset = 0;
    int delimc = 0;
    int delimn = delimiter.length();
    char c;
    
    while(cin.get(c))
    {
        if(delimiter[delimc] == c)
        {
            ++delimc;
            
            if(delimc == delimn)
            {
                if(!flag || offset)
                {
                    cout << separator1;
                }
                offset = 0;
                flag = 0;
            }
        }
        else
        {
            if(delimc > 0)
            {
                for(int i=0;i<delimc;++i)
                {
                    cout << delimiter[i];
                }
                delimc = 0;
            }
            
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
    }
}

void do_inclusive_suffix_strip(string &delimiter, string &separator1, string &separator2)
{
    int delimn = delimiter.length();
    int offset = 0;
    int delimc = 0;
    int prepend = 0;
    char c;
    
    while(cin.get(c))
    {
        if(delimiter[delimc] == c)
        {
            ++delimc;
            
            if(delimc == delimn)
            {
                prepend = 1;
                offset = 0;
                delimc = 0;
            }
        }
        else
        {
            if(prepend)
            {
                cout << separator1;
                prepend = 0;
            }
            if(delimc > 0)
            {
                for(int i=0;i<delimc;++i)
                {
                    cout << delimiter[i];
                }
                delimc = 0;
            }
            
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
    }
}

void do_exclusive_prefix_nostrip(string &delimiter, string &separator1, string &separator2)
{
    int offset = 0;
    int delimc = 0;
    int delimn = delimiter.length();
    int flag = 1;
    char c;
    
    while(cin.get(c))
    {
        if(delimiter[delimc] == c)
        {
            ++delimc;
            
            if(delimc == delimn)
            {
                if(flag)
                {
                    if(offset)
                    {
                        cout << separator1;
                        offset = 0;
                    }
                    else
                    {
                        cout << separator1;
                    }
                    flag = 0;
                }
                else
                {
                    cout << separator1;
                    offset = 0;
                }
            }
        }
        else
        {
            if(delimc > 0)
            {
                for(int i=0;i<delimc;++i)
                {
                    cout << delimiter[i];
                }
                delimc = 0;
            }
            
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
    }
}

void do_exclusive_prefix_strip(string &delimiter, string &separator1, string &separator2)
{
    int offset = 0;
    int delimc = 0;
    int delimn = delimiter.length();
    int flag = 1;
    char c;
    
    while(cin.get(c))
    {
        if(delimiter[delimc] == c)
        {
            ++delimc;
            
            if(delimc == delimn)
            {
                if(flag)
                {
                    if(offset)
                    {
                        cout << separator1;
                        offset = 0;
                    }
                    else
                    {
                        cout << separator1;
                    }
                    flag = 0;
                }
                else
                {
                    cout << separator1;
                    offset = 0;
                }
                delimc = 0;
            }
        }
        else
        {
            if(delimc > 0)
            {
                for(int i=0;i<delimc;++i)
                {
                    cout << delimiter[i];
                }
                delimc = 0;
            }
            
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
    }
}

void do_exclusive_suffix_nostrip(string &delimiter, string &separator1, string &separator2)
{
    int flag = 1;
    int offset = 0;
    int delimc = 0;
    int delimn = delimiter.length();
    char c;
    
    while(cin.get(c))
    {
        if(delimiter[delimc] == c)
        {
            ++delimc;
            
            if(delimc == delimn)
            {
                if(!flag || offset)
                {
                    cout << separator1;
                }
                offset = 0;
                flag = 0;
            }
        }
        else
        {
            if(delimc > 0)
            {
                for(int i=0;i<delimc;++i)
                {
                    cout << delimiter[i];
                }
                delimc = 0;
            }
            
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
    }
}

void do_exclusive_suffix_strip(string &delimiter, string &separator1, string &separator2)
{
    int delimn = delimiter.length();
    int offset = 0;
    int delimc = 0;
    char c;
    
    while(cin.get(c))
    {
        if(delimiter[delimc] == c)
        {
            ++delimc;
            
            if(delimc == delimn)
            {
                cout << separator1;
                offset = 0;
                delimc = 0;
            }
        }
        else
        {
            if(delimc > 0)
            {
                for(int i=0;i<delimc;++i)
                {
                    cout << delimiter[i];
                }
                delimc = 0;
            }
            
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
    }
}
