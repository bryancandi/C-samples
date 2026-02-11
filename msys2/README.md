## MSYS2 Setup on Windows x64 (MINGW64 & UCRT64)

```powershell
winget install MSYS2.MSYS2
```

### MSYS2
```powershell
# Update MSYS2 core system (first run)
pacman -Syu
# Close the terminal completely
# Reopen MSYS2 shell and finish updating
pacman -Syu
# Install MSYS build tools (make, find, etc.)
pacman -S --needed base-devel
```

### MINGW64
```powershell
pacman -S mingw-w64-x86_64-gcc
pacman -S mingw-w64-x86_64-clang
# For the complete MINGW64 toolchain:
pacman -S mingw-w64-x86_64-toolchain
```

### UCRT64
```powershell
pacman -S mingw-w64-ucrt-x86_64-gcc
pacman -S mingw-w64-ucrt-x86_64-clang
# For the complete UCRT64 toolchain:
pacman -S mingw-w64-ucrt-x86_64-toolchain
```

### Set Environment PATH
*Using the PowerShell scripts is safer and recommended, since it avoids overriding Windows tools globally.*

```powershell
# Use provided PowerShell scripts to temporarily include MSYS2 tools and toolchains in PATH
# (modifies PATH only for the current PowerShell session)
# Run in your PowerShell terminal:
.\mingw64-env.ps1   # for MINGW64 toolchain
.\ucrt64-env.ps1    # for UCRT64 toolchain
```

```powershell
# Alternatively, add to your user environment PATH (persistent)
# WARNING: Adding C:\msys64\usr\bin globally can override Windows tools (find, sort, etc.)
# Only include ONE toolchain in PATH at a time: MINGW64 OR UCRT64
C:\msys64\usr\bin
# AND
C:\msys64\mingw64\bin
# OR
C:\msys64\ucrt64\bin
```

### MSVCRT vs UCRT
- [MSYS2 Environments](https://www.msys2.org/docs/environments/)
