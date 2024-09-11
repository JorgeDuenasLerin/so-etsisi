@echo off

@rem problemas al descomprimir.

if not exist .\utilidades\qemu\qemu-system-x86_64w.exe goto :deleted
    rmdir /q /s utilidades\qemu

:deleted

git restore utilidades/qemu.7z.001
git restore utilidades/qemu.7z.002
git restore utilidades/qemu.7z.003
git restore utilidades/qemu.7z.004
git restore utilidades/qemu.7z.005

.\utilidades\7za.exe -o".\utilidades\" -aoa  x .\utilidades\qemu.7z.001

del utilidades\qemu.7z.*