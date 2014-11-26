#!/usr/bin/ruby

require 'pp'

$DEBUG = false

def p(s)
  if $DEBUG
    puts s
    puts
  end
end


lib_name = ARGV[0]
p "searching for gneFrameworkVersion() symbol"

symbol_entries = %x(nm -am #{lib_name} 2>&1 | grep -i "private external .*_gneframeworkversion" -C 3)
p "matching entries:\n#{symbol_entries} "

cstring_addresses = symbol_entries.split("\n").select {|e| e.include?('__cstring')} 

p "cstring addresses:\n#{cstring_addresses}"

cstring_address = cstring_addresses.last.split.first

p "using last address: 0x#{cstring_address}"

version_number_entry = %x(otool -s __TEXT __cstring #{lib_name} | grep ^#{cstring_address})

p "record for version number:\n#{version_number_entry}"

version_number = version_number_entry.split.slice(1...-1).map {|n| n.to_i(16) - 0x30 }.join

puts version_number







