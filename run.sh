#!/bin/bash

testcase()
{
	local flags="$1"
	local str="$2"
	echo -e "Using string:  $str"
	echo -ne $str | build/bufferedreader $flags >/tmp/test.a 2>/tmp/test.b
	echo -e "Output:        $(cat /tmp/test.a)"
	echo -e "Lengths:\n$(cat /tmp/test.b)"
	rm -f /tmp/test.a 2>/dev/null
	rm -f /tmp/test.b 2>/dev/null
}
testcases()
{
	local flags="$1"
	echo -e "### Using flags:   $flags"
	testcase "$flags" ""
	testcase "$flags" "waza"
	testcase "$flags" "waz,"
	testcase "$flags" ",."
	testcase "$flags" ","
	testcase "$flags" ",.waza,.separate,.these,.words,."
	testcase "$flags" "waza,.separate,.these,.words"
	echo
}

if [[ "$1" == "1" ]] || [[ "$1" == "" ]]
then
	testcases "-d ,. --verbose --inclusive --no-strip --prefix -1 @ -2 ,"
	testcases "-d ,. --verbose --exclusive --no-strip --prefix -1 @ -2 ,"
fi

if [[ "$1" == "2" ]] || [[ "$1" == "" ]]
then
	testcases "-d ,. --verbose --inclusive --strip --prefix -1 @ -2 ,"
	testcases "-d ,. --verbose --exclusive --strip --prefix -1 @ -2 ,"
fi

if [[ "$1" == "3" ]] || [[ "$1" == "" ]]
then
	testcases "-d ,. --verbose --inclusive --no-strip --suffix -1 @ -2 ,"
	testcases "-d ,. --verbose --exclusive --no-strip --suffix -1 @ -2 ,"
fi

if [[ "$1" == "4" ]] || [[ "$1" == "" ]]
then
	testcases "-d ,. --verbose --inclusive --strip --suffix -1 @ -2 ,"
	testcases "-d ,. --verbose --exclusive --strip --suffix -1 @ -2 ,"
fi

