import sys

m = (sys.argv[1])
__TEXT = (cmd for load_cmd, cmd, data in m.headers[0].commands
          if getattr(cmd, 'segname', '').rstrip('\0') == '__TEXT').next()
print '__TEXT segment: offset %x size %x' %(__TEXT.fileoff, __TEXT.filesize)
f = open(sys.argv[1], 'rb')
f.seek(__TEXT.fileoff)
open('__TEXT.bin', 'wb').write(f.read(__TEXT.filesize))