#!/bin/sh

interfaces=$(
  arp -n | awk '
    NR == 1 {next}
    {interfaces[$5]+=1}
    END {for (interface in interfaces){print(interface)}}
  '
);
for interface in $interfaces; do
  echo "Clearing ARP cache for $interface";
  sudo ip link set arp off dev $interface;
  sudo ip link set arp on  dev $interface;
done
