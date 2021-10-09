import sys

m = (sys.argv[1])
function = (cmd for load_cmd, cmd, data in m.headers[0].commands
          if getattr(cmd, 'segname', '').rstrip('\0') == 'function').next()
print 'function segment: offset %x size %x' %(function.fileoff, function.filesize)
f = open(sys.argv[1], 'rb')
f.seek(function.fileoff)
open('function.bin', 'wb').write(f.read(function.filesize))
