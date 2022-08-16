#!/bin/bash
qemu-system-x86_64 -boot d \
      -enable-kvm \
      -smp 4 \
	  -nodefaults \
	  -nographic \
      --bios /usr/share/edk2-ovmf/x64/OVMF.fd \
      -name fedora \
      -cpu host \
      -m 4G \
      -drive file=./fedora.qcow2,if=virtio,aio=native,cache.direct=on,cache=writeback \
      -object rng-random,id=rng0,filename=/dev/urandom \
      -device virtio-rng-pci,rng=rng0 \
      -serial stdio \
      -device virtio-balloon \
      -netdev nic,id=mynet0,type=user,hostfwd=tcp::9090-:9090\
      -boot menu=off \
      -device virtio-net-pci,netdev=mynet0,mac=52:55:00:d1:56:01
