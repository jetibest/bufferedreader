# br
Command line utility to read streams line by line or split stream in any delimiter separatable data packets.
This tool does not actually buffer any data, however, this could easily be implemented.
Future TODO includes support for regular expressions in the delimiter, and possibly backreferences to matched groups in the separator.

# Examples

    > echo -e "hello world" | br -d ' ' -s $'\n'
    hello
    world

    > echo -e "1,2,3,4,5" | br -d ','
    12345
    
    > echo -e "first second third" | br -n -d ' ' -s ','
    first, second, third
    
    > echo -e "#p1#p2#p3#p4" | br -n -h -d '#' -s $'\n'
    #p1
    #p2
    #p3
    #p4
    
    > echo -e "#joe#jane" | br -h -d '#' -s '@'
    @joe
    @jane


# Example MJPEG-stream frame by frame extraction

The `stderr` will contain the length of each frame, so while reading `stdout` you will know exactly how many bytes to skip to get the wole frame.

    > br -n -h -d $'\xff\xd8' -v -2 ',' <<EOF
    \xff\xd8_MJPEG_FRAME_DATA_AOEUAOEUAOEUAOEUAOEU_
    \xff\xd8_MJPEG_FRAME_DATA_AOUOAEUOEAU_
    \xff\xd8_MJPEG_FRAME_DATA_AOEUAOEUAOEUAOEUAOUEAOEUAOEUAOEU_
    EOF
    <stdout>
    \xff\xd8_MJPEG_FRAME_DATA_AOEUAOEUAOEUAOEUAOEU_
    \xff\xd8_MJPEG_FRAME_DATA_AOUOAEUOEAU_
    \xff\xd8_MJPEG_FRAME_DATA_AOEUAOEUAOEUAOEUAOUEAOEUAOEUAOEU_
    <stderr>
    42,33,53


# Example raw H264-stream frame by frame extraction

The `stderr` will contain the length of each frame, so while reading `stdout` you will know exactly how many bytes to skip to get the whole frame.

    > br -n -h -d $'\x00\x00\x00\x01' -v <<EOF
    \x00\x00\x00\x01_H264_FRAME_DATA_AOEUAOEUAOEUAOEUAOEU_
    \x00\x00\x00\x01_H264_FRAME_DATA_AOUOAEUOEAU_
    \x00\x00\x00\x01_H264_FRAME_DATA_AOEUAOEUAOEUAOEUAOUEAOEUAOEUAOEU_
    EOF
    <stdout>
    \x00\x00\x00\x01_H264_FRAME_DATA_AOEUAOEUAOEUAOEUAOEU_
    \x00\x00\x00\x01_H264_FRAME_DATA_AOUOAEUOEAU_
    \x00\x00\x00\x01_H264_FRAME_DATA_AOEUAOEUAOEUAOEUAOUEAOEUAOEUAOEU_
    <stderr>
    43
    34
    54


# Equivalence with other command line tools

    > tr 'x' 'y'
    > br -d $'x' -s $'y'
    
    > tr -d 'x'
    > br -d $'x'
    
    # TODO: Regular expressions not yet supported!
    > sed 's/x/y/g'
    > br -d 'x' -s 'y'


# Options

    Core options:
      --delimiter, -d      Set a delimiter to split the stream on.
      --no-strip, -n       Do not strip delimiter from stream.
      --separator, -s, -1  Set a custom delimiter for stdout.
      --verbose, -v        Enable stderr output.
    Quick options:
      --split            Alias of exclusive-flag.
      --header           Alias of prefix-flag and no-strip-flag.
    Advanced options:
      --prefix, -p       Delimiter comes first (e.g. <SOH>head,body<SOH>head,body).
      --exclusive, -e    Prevent ignoring leading and trailing delimiter.
    Default options:
      --delimiter '\n'         Split the stream on <LF>.
      --strip                  Delimiter is stripped from stdout.
      --suffix                 Delimiter comes last (e.g. line<LF>line<LF>).
      --inclusive              Leading and trailing delimiter is ignored.
      --separator, -s, -1 ''   Do not put a custom delimiter in stdout.
      -2 '\n'                  Numbers of stderr are delimited by <LF>.
